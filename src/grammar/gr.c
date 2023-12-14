#include "gr.h"

#include <time.h>

#define GR_CONTEXT_MAX_IDX (32)

#define GR_REG_CALLBACKS_RUN(ctx_id)                                                                  \
  if (context_idx == (ctx_id)) {                                                                      \
    if ((gr_child->type == GR_ELEM_DECLARATOR) && (parser_callback_declarator != NULL)) {             \
      parser_callback_declarator(gr_child);                                                           \
    }                                                                                                 \
    if ((gr_child->type == GR_ELEM_INIT_DECLARATOR) && (parser_callback_init_declarator != NULL)) {   \
      parser_callback_init_declarator(gr_child);                                                      \
    }                                                                                                 \
    if ((gr_child->type == GR_ELEM_DECLARATION) && (parser_callback_declaration != NULL)) {           \
      parser_callback_declaration(gr_child);                                                          \
    }                                                                                                 \
    if ((gr_child->type == GR_ELEM_FUNCTION_BODY) && (parser_callback_function_body != NULL)) {       \
      parser_callback_function_body(gr_child);                                                        \
    }                                                                                                 \
    if ((gr_child->type == GR_ELEM_TRANSLATION_UNIT) && (parser_callback_translation_unit != NULL)) { \
      parser_callback_translation_unit(gr_child);                                                     \
    }                                                                                                 \
  }                                                                                                   \

typedef struct {
  unsigned int   no_tokens;
  const token_t* tokens[ GR_MAX_NO_TOKENS ];
} gr_token_buffer_t;

typedef struct {
  gr_stack_t        gr_stack;
  gr_token_buffer_t gr_token_buffer;

  unsigned int      no_tokens;
} gr_context_t;

static signed int   context_idx     = -1;
static signed int   context_idx_max = -1;
static gr_context_t gr_context[ GR_CONTEXT_MAX_IDX ];

static gr_stack_t*        gr_stack;
static gr_token_buffer_t* gr_token_buffer;

static gr_rule_t rule_buffer_a;
static gr_rule_t rule_buffer_b[ GR_MAX_NO_RULES ];

static parser_callback_fn_t parser_callback_declarator;
static parser_callback_fn_t parser_callback_init_declarator;
static parser_callback_fn_t parser_callback_declaration;
static parser_callback_fn_t parser_callback_function_body;
static parser_callback_fn_t parser_callback_translation_unit;

static void token_buffer_add(const token_t* const token);
static void token_buffer_del(void);

static unsigned int rule_is_matched(gr_t* const gr);
static void         rule_adjust(gr_t* const gr, const unsigned int partial);
static void         rule_restore(gr_t* const gr);
static unsigned int rule_is_subset(const gr_rule_t* const a, const gr_rule_t* const b);
static void         rule_mark(gr_rule_t* const a, const gr_rule_t* const b);
static void         rule_generate_rules(gr_t* const gr, const unsigned int no_recursive_rules);
static void         rule_generate_recursive_rules(gr_t* const gr);
static void         rule_inflate(const gr_t* const gr);

static unsigned int gr_is_done(gr_t* const gr);

static gr_match_code_t do_match_main_context(const token_t* const token);
static gr_t*           do_match_new_context(gr_t* const gr, const unsigned int rule_idx);

static void token_buffer_add(const token_t* const token) {
  for (signed int i = ((signed int) (gr_token_buffer->no_tokens)) - 1; i >= 0; i--) {
    gr_token_buffer->tokens[ i + 1 ] = gr_token_buffer->tokens[ i ];
  }
  gr_token_buffer->no_tokens++;
  if (gr_token_buffer->no_tokens >= GR_MAX_NO_TOKENS) {
    if (GR_DEBUG_LEVEL_ERROR >= GR_DEBUG_LEVEL) {
      fprintf(stdout,
              "error[at line %6u in %s] :: no more space in the token buffer :: %3u %3u\n",
              ((unsigned int) (__LINE__)),
              __PRETTY_FUNCTION__,
              gr_token_buffer->no_tokens,
              GR_MAX_NO_TOKENS);
    }
  }
  gr_token_buffer->tokens[ 0u ] = token;
}

static void token_buffer_del(void) {
  for (signed int i = 0; i < ((signed int) (gr_token_buffer->no_tokens)) - 1; i++) {
    gr_token_buffer->tokens[ i ] = gr_token_buffer->tokens[ i + 1 ];
  }
  gr_token_buffer->no_tokens--;
  gr_token_buffer->tokens[ gr_token_buffer->no_tokens ] = NULL;
}

// 2u :: the rule is fully matched
// 1u :: the rule is partially matched
// 0u :: the rule is not matched
static unsigned int rule_is_matched(gr_t* const gr) {
  if ((gr != NULL) && (gr->no_rules >= 1u)) {
    gr_rule_t* const rule = &gr->rules[ gr->rule_idx ];

    // Recursive rules can't be matched
    if (gr->type == rule->elems[ 0u ].type) {
      return 0u;
    }

    //rule->last_token_matched = TOKEN_INVALID;
    //rule->last_elem_matched  = 0u;
    rule->no_matched_elems   = 0u;
    for (unsigned int i = 0u; i <= rule->elem_idx; i++) {
      if ((rule->elems[ i ].is_mandatory == 1u) && (rule->elems[ i ].is_marked == 0u)) {
        return 0u;
      }

      if (rule->elems[ i ].is_marked == 1u) {
        //rule->last_token_matched = rule->elems[ i ].token->type;
        //rule->last_elem_matched  = i;
        rule->no_matched_elems++;
      }
    }

    for (unsigned int i = rule->elem_idx + 1u; i < rule->no_elems; i++) {
      if (rule->elems[ i ].is_mandatory == 1u) {
        return 1u;
      }
    }

    if (gr->flags & GR_ELEM_FLAGS_LAST_RULE_MATCHED) {
      if (gr->rules[ gr->rule_idx ].no_matched_elems > gr->rules[ gr->flag_values.last_rule_matched ].no_matched_elems) {
        gr->flag_values.last_rule_matched  = gr->rule_idx;
      }
    } else {
      gr->flags                           |= GR_ELEM_FLAGS_LAST_RULE_MATCHED;
      gr->flag_values.last_rule_matched    = gr->rule_idx;
    }
    return 2u;
  }
  return 0u;
}

static void rule_adjust(gr_t* const gr, const unsigned int partial) {
  if ((gr != NULL) && (gr->no_rules >= 1u)) {
    gr_rule_t* const rule = &gr->rules[ gr->rule_idx ];
    signed int       i    = ((signed int) (gr->no_tokens)) - 1;
    signed int       j    = ((signed int) (rule->no_elems)) - 1;

    // There is nothing to adjust if we reached the recursive rules.
    if (gr->type == rule->elems[ 0u ].type) {
      return;
    }

    // Evaluate the current rule.
    rule_is_matched(gr);
    // Re-insert all tokens back into the token_buffer when the current rule has no matched elements.
    if (rule->no_matched_elems == 0u) {
      for (; i >= 0; i--) {
        // Re-insert the given token into the token_buffer.
        token_buffer_add(gr->tokens[ i ]);

         // Remove the given token from all levels of the stack.
        for (unsigned int k = 0u; k < gr_stack->elem_idx; k++) {
          gr_stack->elems[ k ]->tokens[ gr_stack->elems[ k ]->no_tokens ] = NULL;
          gr_stack->elems[ k ]->no_tokens--;
        }
      }
      goto rule_adjust_end;
    }

    // Traverse the "seen" tokens in reverse order.
    for (; i >= 0; i--) {
      // Traverse the grammatical elements of the current rule in reverse order.
      for (; j >= 0; j--) {
        if (rule->elems[ j ].is_marked == 1u) {
          // Marked grammatical elements that don't match the last "seen" token
          // need to be reinserted into the token buffer.
          //
          // Restart decision will be taken taken based on these reinsertions.
          if ((gr->tokens[ i ]->type != rule->elems[ j ].token->type) || (partial == 0u)) {
            // Re-insert the given token into the token_buffer.
            token_buffer_add(gr->tokens[ i ]);

             // Remove the given token from all levels of the stack.
            for (unsigned int k = 0u; k < gr_stack->elem_idx; k++) {
              gr_stack->elems[ k ]->tokens[ gr_stack->elems[ k ]->no_tokens ] = NULL;
              gr_stack->elems[ k ]->no_tokens--;
            }
          }

          if (gr->tokens[ i ]->type == rule->elems[ j ].token->type) {
            // Partial readjustments stops when the last "seen" token
            // matches the current marked element.
            if (partial == 1u) {
              goto rule_adjust_end;
            }
          }

          // Break this loop and check the next token.
          break;
        }
      }
    }

rule_adjust_end:
    // Unwind all the rules that are a superset of the current rule.
    for (signed int k = ((signed int) (gr->rule_idx)) + 1; k < ((signed int) (gr->no_rules)); k++) {
      if (gr->type == gr->rules[ k ].elems[ 0 ].type) {
        break;
      }

      if (rule_is_subset(&gr->rules[ k ], rule) == 1u) {
        gr->rules[ k ].elem_idx = ((unsigned int) (j));
        for (signed int l = j + 1; l < ((signed int) (gr->rules[ k ].no_elems)); l++) {
          if (gr->rules[ k ].elems[ l ].is_marked == 1u) {
            gr->rules[ k ].elems[ l ].is_marked = 0u;
            gr->rules[ k ].elems[ l ].token     = TOKEN_INVALID;
          }
        }
      }
    }
    // Re-match the current rule based on the previous adjustments.
    rule_is_matched(gr);
  }
}

static void rule_restore(gr_t* const gr) {
  if ((gr != NULL) && (gr->no_rules >= 1u)) {
    if (gr->flags & GR_ELEM_FLAGS_LAST_RULE_MATCHED) {
      // Restore rule_idx so that it points to the last rule matched.
      gr->rule_idx = gr->flag_values.last_rule_matched;
    } else {
      gr_shift_rules_down(gr);
    }
    // Adjust the current rule with respect to the "seen" tokens.
    rule_adjust(gr, 1u);
  }
}

static unsigned int rule_is_subset(const gr_rule_t* const a, const gr_rule_t* const b) {
  // Make sure rule b is a subset of rule a up to the current grammatical element of rule b.
  //
  // rule_b :: b_0 b_1 ... b_{elem_idx} ... b_{no_elems - 1u}
  //            =   =       =
  // rule_a :: a_0 a_1 ... a_{elem_idx} a_{elem_idx + 1u} ... a_{no_elems - 1u}
  if (b->elem_idx < a->no_elems) {
    for (unsigned int i = 0u; i <= b->elem_idx; i++) {
      if (a->elems[ i ].type != b->elems[ i ].type) {
        // Different simple grammatical elements can be matched by the same token.
        if ((gr_elem_info[ a->elems[ i ].type ].no_tokens == 1u) && (gr_elem_info[ b->elems[ i ].type ].no_tokens == 1u)) {
          if (gr_elem_info[ a->elems[ i ].type ].tokens[ 0u ] != gr_elem_info[ b->elems[ i ].type ].tokens[ 0u ]) {
            return 0u;
          }
        } else {
          return 0u;
        }
      }
    }
  } else {
    return 0u;
  }

  return 1u;
}

static void rule_mark(gr_rule_t* const a, const gr_rule_t* const b) {
  if (rule_is_subset(a, b) == 1u) {
    // The grammatical element of rule a may or may not be mandatory.
    if (a->elems[ b->elem_idx ].is_marked == 1u) {
      // Something is wrong if this element is already marked.
      if (GR_DEBUG_LEVEL_ERROR >= GR_DEBUG_LEVEL) {
        fprintf(stdout,
                "error[at line %6u in %s] :: element already marked\n",
                ((unsigned int) (__LINE__)),
                __PRETTY_FUNCTION__);
      }
    }

    // Mark this grammatical element and break the loop.
    a->elem_idx                       = b->elem_idx;
    a->elems[ a->elem_idx ].token     = b->elems[ b->elem_idx ].token;
    a->elems[ a->elem_idx ].is_marked = b->elems[ b->elem_idx ].is_marked;
  }
}

static void rule_generate_rules(gr_t* const gr, const unsigned int no_recursive_rules) {
  if ((gr != NULL) && (gr->no_rules >= 1u) && (no_recursive_rules >= 1u)) {
    const unsigned int n = gr->rule_idx + 1u;

    // Make room for the newly generated rules.
    for (unsigned int i = 0u; i < no_recursive_rules; i++) {
      gr_shift_rules_up(gr);
    }

    // Generated new rules based on the rules from rule_buffer_a and rule_buffer_b.
    for (unsigned int i = 0u; i < no_recursive_rules; i++) {
      unsigned int m = 0u;

      gr->rules[ n + i ].no_elems = rule_buffer_a.no_elems + rule_buffer_b[ i ].no_elems - 1u;
      gr->rules[ n + i ].elem_idx = rule_buffer_a.elem_idx;
      for (unsigned int a = 0u; a < rule_buffer_a.no_elems; a++) {
        gr->rules[ n + i ].elems[ m ] = rule_buffer_a.elems[ a ];
        m++;
      }
      for (unsigned int b = 1u; b < rule_buffer_b[ i ].no_elems; b++) {
        gr->rules[ n + i ].elems[ m ] = rule_buffer_b[ i ].elems[ b ];
        m++;
      }
    }
  }
}

static void rule_generate_recursive_rules(gr_t* const gr) {
  if ((gr != NULL) && (gr->no_rules >= 1u)) {
    // Save a reference to the current rule.
    const unsigned int rule_idx           = gr->rule_idx;
    gr_rule_t* const   rule               = &gr->rules[ rule_idx ];
    unsigned int       is_expanded        = (rule->is_expanded == 0u) ? (1u) : (0u);
    unsigned int       no_recursive_rules = 0u;

    // There are no rules to expand if we already reached the recursive rules.
    if (gr->type == rule->elems[ 0u ].type) {
      return;
    }

    // Clear the rule buffers.
    memset(&rule_buffer_a, 0, sizeof(rule_buffer_a));
    memset(&rule_buffer_b, 0, sizeof(rule_buffer_b));

    // Should the given rule be expanded?
    if (rule_is_matched(gr) >= 1u) {
      if (is_expanded == 1u) {
        if (rule->flags & GR_RULE_FLAGS_SKIP_EXPAND) {
          is_expanded = 0u;
        } else {
          // The current rule is saved in the rule_buffer_a buffer.
          memcpy(&rule_buffer_a, rule, sizeof(gr_rule_t));
        }
      }
    } else {
      is_expanded = 0u;
    }

    for (unsigned int i = rule_idx + 1u; i < gr->no_rules; i++) {
      if (gr->type == gr->rules[ i ].elems[ 0u ].type) {
        if (is_expanded == 1u) {
          // The recursive rules are saved in the rule_buffer_b buffer.
          memcpy(&rule_buffer_b[ no_recursive_rules ], &gr->rules[ i ], sizeof(gr_rule_t));
          no_recursive_rules++;
        }
      } else {
        // Non-recursive rules are updated based on the current rule.
        rule_mark(&gr->rules[ i ], rule);
      }
    }

    if (is_expanded == 1u) {
      rule_generate_rules(gr, no_recursive_rules);

      rule->is_expanded = (no_recursive_rules >= 1u) ? (1u) : (0u);
    }
  }
}

static void rule_inflate(const gr_t* const gr_child) {
  if ((gr_child != NULL) && (gr_child->no_rules >= 1u)) {
    const unsigned int     rule_idx_child = gr_child->rule_idx;
    const gr_rule_t* const rule_child     = &gr_child->rules[ rule_idx_child ];
    gr_t* const            gr_parent      = gr_child->parent;

    // Callback invocation.
    GR_REG_CALLBACKS_RUN(0);

    if (gr_parent != NULL) {
      unsigned int rule_idx_parent = gr_parent->rule_idx;

      // Inflate all the rules in the parent.
      for (; rule_idx_parent < gr_parent->no_rules; rule_idx_parent++) {
        gr_rule_t* const rule_parent     = &gr_parent->rules[ rule_idx_parent ];
        unsigned int     elem_idx_parent = rule_parent->elem_idx;

        if (gr_child->type == rule_parent->elems[ elem_idx_parent ].type) {
          for (unsigned int i = 0u; i < rule_child->no_elems; i++) {
            if (i >= 1u) {
              for (signed int j = ((signed int) (rule_parent->no_elems)) - 1; j >= ((signed int) (elem_idx_parent)); j--) {
                rule_parent->elems[ j + 1 ] = rule_parent->elems[ j ];
              }
              rule_parent->no_elems++;
              if (rule_parent->no_elems >= GR_MAX_NO_ELEMS) {
                if (GR_DEBUG_LEVEL_ERROR >= GR_DEBUG_LEVEL) {
                  fprintf(stdout,
                          "error[at line %6u in %s] :: no more space in the rule :: %3u %3u :: %s\n",
                          ((unsigned int) (__LINE__)),
                          __PRETTY_FUNCTION__,
                          rule_parent->no_elems,
                          GR_MAX_NO_ELEMS,
                          gr_elem_info[ gr_parent->type ].name);
                }
              }
            }

            rule_parent->elems[ elem_idx_parent ] = rule_child->elems[ i ];
            if (i >= 1u) {
              if (rule_child->elems[ i ].is_marked == 1u) {
                rule_parent->elem_idx = elem_idx_parent;
              }
            }
            elem_idx_parent++;
          }
        }
      }
      // Update the current rule of parent after inflation.
      gr_parent->flags                         &= ~GR_ELEM_FLAGS_LAST_RULE_MATCHED;
      gr_parent->flag_values.last_rule_matched  = 0u;
      rule_is_matched(gr_parent);
    } else {
      if ((context_idx == 0u) && (GR_DEBUG_LEVEL_ERROR >= GR_DEBUG_LEVEL)) {
        fprintf(stdout,
                "error[at line %6u in %s] :: inflating null grammatical element\n",
                ((unsigned int) (__LINE__)),
                __PRETTY_FUNCTION__);
      }
    }
  }
}

static unsigned int gr_is_done(gr_t* const gr) {
  if (gr == NULL) {
    return 0u;
  }

  if ((gr->no_rules == 0u) && (gr->no_tokens == 1u)) {
    return 1u;
  }

  if (gr->flags & GR_ELEM_FLAGS_LAST_RULE_MATCHED) {
    const unsigned int     rule_idx = gr->rule_idx;
    const gr_rule_t* const rule     = &gr->rules[ rule_idx ];
    const unsigned int     elem_idx = rule->elem_idx;

    if (rule_idx != gr->flag_values.last_rule_matched) {
      return 0u;
    }

    if ((rule_idx == gr->no_rules - 1u) && (elem_idx == rule->no_elems - 1u)) {
      return 1u;
    }
    //if (rule->elems[ elem_idx ].type == GR_ELEM_SEPARATOR_SEMICOLON) {
    //  return 1u;
    //}
  }
  return 0u;
}

static gr_match_code_t do_match_token_graph_simple(const gr_elem_type_t gr_elem_type, const token_type_t token_type) {
  if (gr_elem_type < GR_ELEM_COMPLEX) {
    return (gr_elem_info[ gr_elem_type ].tokens[ 0u ] == token_type) ? (GR_MATCH_CODE_FOUND) : (GR_MATCH_CODE_FOUND_NOT);
  } else {
    for (unsigned int i = 0u; i < GR_MAX_NO_RULES; i++) {
      if (gr_elem_token_graph[ gr_elem_type ][ i ][ token_type ] == 1u) {
        return GR_MATCH_CODE_FOUND;
      }
    }
  }

  return GR_MATCH_CODE_FOUND_NOT;
}

static gr_match_code_t do_match_token_graph_complex(const gr_t* const gr, const token_type_t token_type) {
  if (gr->no_rules == 0u) {
    return do_match_token_graph_simple(gr->type, token_type);
  }

  for (unsigned int i = gr->rule_idx; i < gr->no_rules; i++) {
    const gr_rule_t* const rule = &gr->rules[ i ];

    for (unsigned int j = rule->elem_idx; j < rule->no_elems; j++) {
      if (do_match_token_graph_simple(rule->elems[ j ].type, token_type) == GR_MATCH_CODE_FOUND) {
        return GR_MATCH_CODE_FOUND;
      }
    }
  }

  return GR_MATCH_CODE_FOUND_NOT;
}

static gr_match_code_t do_match_lo(const token_t* const token) {
  gr_t*           gr_parent;
  gr_match_code_t ret;

  gr_parent = gr_stack_peek(gr_stack);
  if (gr_is_done(gr_parent) == 1u) {
    rule_inflate(gr_parent);

    gr_parent = gr_stack_pop_and_peek(gr_stack);
  }
  ret = do_match_token_graph_complex(gr_parent, token->type);

  if (ret == GR_MATCH_CODE_FOUND_NOT) {
    return ret;
  }

  if (gr_parent->no_rules >= 1u) {
    unsigned int   rule_idx;
    gr_rule_t*     rule;
    unsigned int   elem_idx;
    gr_elem_type_t elem_type;

do_match_lo_again:
    rule_idx  = gr_parent->rule_idx;
    rule      = &gr_parent->rules[ rule_idx ];
    elem_idx  = rule->elem_idx;
    elem_type = rule->elems[ elem_idx ].type;

    if (elem_type == GR_ELEM_INVALID) {
      return GR_MATCH_CODE_FOUND_NOT;
    }

    // The recursive rules are skipped as they have previously been expanded.
    if (gr_parent->type == rule->elems[ 0u ].type) {
      // Reaching this point means in fact no match was possible.
      return GR_MATCH_CODE_FOUND_NOT;
    }

    if (rule->elems[ elem_idx ].is_marked == 1u) {
      // A marked grammatical element can't be matched again.
      if (gr_set_next_rule_elem(gr_parent) == 1u) {
        goto do_match_lo_again;
      } else {
        if (gr_set_next_rule(gr_parent) == 1u) {
          goto do_match_lo_again;
        } else {
          return GR_MATCH_CODE_FOUND_NOT;
        }
      }
    } else {
      // We don't explore a new rule while already having a fully matched one.
      if ((gr_parent->flags & GR_ELEM_FLAGS_LAST_RULE_MATCHED) && (elem_idx == 0u)) {
        return GR_MATCH_CODE_FOUND_NOT;
      }

      // Try to match against a non-marked grammatical elements.
      gr_t* const gr_child = gr_elem_get(elem_type);

      gr_child->parent = gr_parent;
      gr_stack_push(gr_stack, gr_child);
      ret = do_match_lo(token);
      if (ret == GR_MATCH_CODE_FOUND) {
        unsigned int no_matched_elems = 0u;

        // Despite the match, this rule must have all tokens seen before marked as well.
        for (unsigned int i = 0u; i < rule->no_elems; i++) {
          if (rule->elems[ i ].is_marked == 1u) {
            no_matched_elems++;
          }
        }
        if (gr_parent->no_tokens > no_matched_elems) {
          gr_free(gr_stack_pop(gr_stack));
          return GR_MATCH_CODE_FOUND_NOT;
        } else {
          // Mark the current grammatical element.
          rule->elems[ elem_idx ].token     = token;
          rule->elems[ elem_idx ].is_marked = 1u;

          // Callback invocation.
          GR_REG_CALLBACKS_RUN(0);

          // Update the last rule matched based on the previous marking.
          if (rule_is_matched(gr_parent) == 0u) {
            if (GR_DEBUG_LEVEL_ERROR >= GR_DEBUG_LEVEL) {
              fprintf(stdout,
                      "error[at line %6u in %s] :: rule not matched\n",
                      ((unsigned int) (__LINE__)),
                      __PRETTY_FUNCTION__);
            }
          }

          // Expand the recursive rules (if applicable).
          rule_generate_recursive_rules(gr_parent);

          return GR_MATCH_CODE_FOUND;
        }
      } else {
        gr_free(gr_stack_pop(gr_stack));

        // Traverse the rest of grammatical elements.
        if (rule_is_matched(gr_parent) >= 1u) {
          if (gr_set_next_rule_elem(gr_parent) == 1u) {
            goto do_match_lo_again;
          } else {
            if (gr_set_next_rule(gr_parent) == 1u) {
              goto do_match_lo_again;
            }
          }
        } else {
          if (gr_set_next_rule(gr_parent) == 1u) {
            goto do_match_lo_again;
          }
        }
      }
    }
  }

  return ret;
}

static gr_match_code_t do_match_mi(void) {
  gr_match_code_t ret = do_match_lo(gr_token_buffer->tokens[ 0u ]);
  gr_t*           gr  = gr_stack_peek(gr_stack);

  if (ret == GR_MATCH_CODE_FOUND_NOT) {
    rule_restore(gr);

do_match_mi_partial_match_until:
    // Get the status of the current rule.
    switch (rule_is_matched(gr)) {
      // The rule is fully matched.
      case 2u: {
          const gr_rule_t* const rule     = &gr->rules[ gr->rule_idx ];
          const unsigned int     elem_idx = rule->elem_idx + 1u;

          for (unsigned int i = gr->rule_idx; i < gr->no_rules; i++) {
            if (gr->type == gr->rules[ i ].elems[ 0u ].type) {
              break;
            }

            if (rule_is_subset(&gr->rules[ i ], rule) == 1u) {
              // There can still be optional grammatical elements that could be matched by the current token.
              for (unsigned int j = elem_idx; j < gr->rules[ i ].no_elems; j++) {
                if (do_match_token_graph_simple(gr->rules[ i ].elems[ j ].type, gr_token_buffer->tokens[ 0u ]->type) == GR_MATCH_CODE_FOUND) {
                  // Set the current rule.
                  gr->rule_idx = i;
                  // Do partial restart with respect to the current rule.
                  goto do_match_mi_partial_match_found;
                }

                if (gr->rules[ i ].elems[ j ].is_mandatory == 1u) {
                  // Break this search at first mandatory grammatical element.
                  break;
                }
              }
            } else {
              // Check this rule in a new context.
              if (do_match_new_context(gr, i) == gr) {
                return GR_MATCH_CODE_FOUND;
              }
            }
          }

          // We couldn't find other rules that match to next token to be seen.
          rule_inflate(gr);
          gr = gr_stack_pop_and_peek(gr_stack);
          if (gr == NULL) {
            if ((context_idx == 0u) && (GR_DEBUG_LEVEL_WARNING >= GR_DEBUG_LEVEL)) {
              fprintf(stdout,
                      "warning[at line %6u in %s] :: empty stack after inflate\n",
                      ((unsigned int) (__LINE__)),
                      __PRETTY_FUNCTION__);
            }
            return GR_MATCH_CODE_GRAMMAR_END;
          }
          goto do_match_mi_partial_match_until;
        }
        break;

      // The rule is partially matched.
      case 1u: {
do_match_mi_partial_match_found:
          ret = GR_MATCH_CODE_RESTART_PARTIAL;
          rule_adjust(gr, 1u);
        }
        break;

      // The rule can't be matched by the "seen" tokens.
      case 0u: {
          ret = GR_MATCH_CODE_RESTART_FULL;
          rule_adjust(gr, 0u);

          gr = gr_stack_pop_and_peek(gr_stack);
          if (gr != NULL) {
            // Remove all the rules that for sure can't be matched by the "seen" tokens.
            memcpy(&rule_buffer_a, &gr->rules[ gr->rule_idx ], sizeof(gr_rule_t));
            for (; gr->no_rules >= 1u; ) {
              if (rule_is_subset(&gr->rules[ gr->rule_idx ], &rule_buffer_a) == 1u) {
                gr_shift_rules_down(gr);
              } else {
                break;
              }
            }

            if ((gr->no_rules == 0u) ||
                (gr->type == gr->rules[ gr->rule_idx ].elems[ 0u ].type) ||
                (gr->rules[ gr->rule_idx ].elems[ 0u ].type == GR_ELEM_INVALID)) {
              // After the previous removals, the grammatical element may be unusable.
              if (GR_DEBUG_LEVEL_WARNING >= GR_DEBUG_LEVEL) {
                fprintf(stdout,
                        "warning[at line %6u in %s] :: unusable grammatical element in context %2u :: %3u :: %s\n",
                        ((unsigned int) (__LINE__)),
                        __PRETTY_FUNCTION__,
                        context_idx,
                        gr->no_rules,
                        gr_elem_info[ gr->type ].name);
              }

              // Restart the partial match finding.
              goto do_match_mi_partial_match_until;
            } else {
              // After the previous removals, there will be a new current rule which
              // needs to partially be adjusted.
              rule_adjust(gr, 1u);
            }
          } else {
            return GR_MATCH_CODE_GRAMMAR_END;
          }
        }
        break;

      default:
        return GR_MATCH_CODE_GRAMMAR_END;
        break;
    }
  }

  return ret;
}

static gr_match_code_t do_match_hi(void) {
  const gr_t* gr;

  while (gr_token_buffer->no_tokens >= 1u) {
    if (gr_stack_is_empty(gr_stack) == 1u) {
      return GR_MATCH_CODE_GRAMMAR_END;
    }
    const gr_match_code_t ret = do_match_mi();

    if (ret == GR_MATCH_CODE_FOUND) {
      // Update all the grammatical elements in the stack with the newly "seen" token.
      for (unsigned int i = 0u; i <= gr_context[ context_idx + 1 ].no_tokens; i++) {
        for (unsigned int j = 0u; j < gr_stack->elem_idx; j++) {
          const unsigned int no_tokens = gr_stack->elems[ j ]->no_tokens;

          gr_stack->elems[ j ]->tokens[ no_tokens ] = gr_token_buffer->tokens[ 0u ];
          gr_stack->elems[ j ]->no_tokens           = no_tokens + 1u;

          if (gr_stack->elems[ j ]->no_tokens >= GR_MAX_NO_TOKENS) {
            if (GR_DEBUG_LEVEL_ERROR >= GR_DEBUG_LEVEL) {
              fprintf(stdout,
                      "error[at line %6u in %s] :: no more space in the stack element :: %3u %3u :: %s\n",
                      ((unsigned int) (__LINE__)),
                      __PRETTY_FUNCTION__,
                      gr_stack->elems[ j ]->no_tokens,
                      GR_MAX_NO_TOKENS,
                      gr_elem_info[ gr_stack->elems[ j ]->type ].name);
            }
          }
        }
        // Remove the current token from the token buffer as is has been "seen".
        token_buffer_del();
      }
      gr_context[ context_idx + 1 ].no_tokens = 0u;

      // Remove the grammatical elements that have no rules to be explored.
      gr = gr_stack_peek(gr_stack);
      if (gr->no_rules == 0u) {
        gr = gr_stack_pop_and_peek(gr_stack);
        if (gr == NULL) {
          return GR_MATCH_CODE_GRAMMAR_END;
        }
      }
    } else if (ret == GR_MATCH_CODE_RESTART_PARTIAL) {
      continue;
    } else if (ret == GR_MATCH_CODE_RESTART_FULL) {
      continue;
    } else {
      return ret;
    }
  }

  return GR_MATCH_CODE_FOUND;
}

static gr_match_code_t do_match(const token_t* const token) {
  gr_match_code_t ret = GR_MATCH_CODE_FOUND_NOT;

  if (gr_stack != NULL) {
    token_buffer_add(token);

    ret = do_match_hi();
    if (ret == GR_MATCH_CODE_FOUND) {
      gr_t* gr;

do_match_inflate:
      gr = gr_stack_peek(gr_stack);
      if (gr_is_done(gr) == 1u) {
        rule_inflate(gr);
        gr_free(gr_stack_pop(gr_stack));
        if (gr_stack->elem_idx >= 2u) {
          goto do_match_inflate;
        }
      }
      if (gr->rules[ gr->rule_idx ].elems[ gr->rules[ gr->rule_idx ].elem_idx ].type == GR_ELEM_SEPARATOR_SEMICOLON) {
        rule_inflate(gr);
        gr_free(gr_stack_pop(gr_stack));
      }
    } else {
      gr_error_report(gr_stack);
    }

    gr_stack_print(gr_stack);
  }

  return ret;
}

static gr_match_code_t do_match_main_context(const token_t* const token) {
  return do_match(token);
}

static gr_t* do_match_new_context(gr_t* const gr, const unsigned int rule_idx) {
  if ((gr == NULL) || (gr->no_rules == 0u) || (rule_idx >= gr->no_rules)) {
    return NULL;
  }

  struct timespec    a           = {};
  struct timespec    b           = {};
  unsigned long long contex_time = 0llu;

  clock_gettime(CLOCK_MONOTONIC, &a);

  gr_t*                          gr_ret               = NULL;
  gr_t* const                    gr_start             = gr_alloc();
  const gr_token_buffer_t* const gr_token_buffer_prev = gr_token_buffer;
  unsigned int                   i                    = 0u;

  // Allocate a new context.
  context_idx++;
  if (GR_DEBUG_LEVEL_INFO >= GR_DEBUG_LEVEL) {
    fprintf(stdout,
            "info[at line %6u in %s] :: context begin %3u/%3u %s\n",
            ((unsigned int) (__LINE__)),
            __PRETTY_FUNCTION__,
            context_idx,
            context_idx_max,
            gr_elem_info[ gr->type ].name);
  }
  gr_stack        = &gr_context[ context_idx ].gr_stack;
  gr_token_buffer = &gr_context[ context_idx ].gr_token_buffer;
  context_idx_max = (context_idx > context_idx_max) ? (context_idx) : (context_idx_max);

  // Clear this context.
  memset(gr_stack,        0, sizeof(gr_stack_t));
  memset(gr_token_buffer, 0, sizeof(gr_token_buffer_t));
  // Set appropriate flags for this context.
  gr_stack->flags |= GR_STACK_FLAGS_SKIP_PRINT;

  // Initialize the starting grammatical element of this context.
  memcpy(gr_start, gr, sizeof(gr_t));
  gr_start->rule_idx                      = rule_idx;
  gr_start->flags                         = 0u;
  gr_start->flag_values.last_rule_matched = 0u;
  gr_start->no_tokens                     = 0u;
  for (unsigned int i = 0u; i < GR_MAX_NO_TOKENS; i++) {
   gr_start->tokens[ i ]                  = NULL;
  }
  gr_start->parent                        = NULL;
  // Initialize the stack of this context.
  gr_stack_push(gr_stack, gr_start);

  // Match the "seen" tokens from the previous context.
  for (; i < gr->no_tokens; i++) {
    if (do_match(gr->tokens[ i ]) != GR_MATCH_CODE_FOUND) {
      goto do_match_new_context_end;
    }
  }
  if (i == gr->no_tokens) {
    for (i = 0u; i < gr_token_buffer_prev->no_tokens; i++) {
      if (do_match(gr_token_buffer_prev->tokens[ i ]) != GR_MATCH_CODE_FOUND) {
        goto do_match_new_context_end;
      } else {
        gr_context[ context_idx ].no_tokens = i;
        if ((gr_stack->elem_idx == 1u) && (gr_is_done(gr_stack->elems[ 0u ]) == 1u)) {
          goto do_match_new_context_success;
        }
      }
    }
    if (i == gr_token_buffer_prev->no_tokens) {
      // Inflate this context.
      while (gr_stack->elem_idx >= 2u) {
        rule_inflate(gr_stack_peek(gr_stack));
        gr_free(gr_stack_pop(gr_stack));
      }
do_match_new_context_success:
      // Point to the inflated grammatical element that completed this context.
      gr_ret = gr_stack_peek(gr_stack);
      // Adjust this grammatical element so that it can be used by the previous context.
      gr_ret->no_tokens = gr->no_tokens;
      for (unsigned int i = gr_ret->no_tokens; i < GR_MAX_NO_TOKENS; i++) {
        if (gr_ret->tokens[ i ] != NULL) {
          gr_ret->tokens[ i ] = NULL;
        } else {
          break;
        }
      }
      gr_ret->parent = gr->parent;
      // Return this grammatical element to the previous context.
      memcpy(gr, gr_ret, sizeof(gr_t));
      //
      gr_ret = gr;
    }
  }

do_match_new_context_end:
  if (GR_DEBUG_LEVEL_INFO >= GR_DEBUG_LEVEL) {
    fprintf(stdout,
            (gr_ret == NULL) ? ("info[at line %6u in %s] :: context unsuccessful %3u/%3u :: %3u :: %32s\n") :
                               ("info[at line %6u in %s] :: context   successful %3u/%3u :: %3u :: %32s\n"),
            ((unsigned int) (__LINE__)),
            __PRETTY_FUNCTION__,
            context_idx,
            context_idx_max,
            gr_stack->elem_idx_max,
            gr_elem_info[ gr->type ].name);
  }
  if (GR_DEBUG_LEVEL_INFO >= GR_DEBUG_LEVEL) {
    fprintf(stdout,
            "info[at line %6u in %s] :: context end   %3u/%3u %s\n",
            ((unsigned int) (__LINE__)),
            __PRETTY_FUNCTION__,
            context_idx,
            context_idx_max,
            gr_elem_info[ gr->type ].name);
  }

  // Clear the stack of this context.
  gr_stack_clear(gr_stack);

  // Restore the previous context.
  context_idx--;
  gr_stack        = &gr_context[ context_idx ].gr_stack;
  gr_token_buffer = &gr_context[ context_idx ].gr_token_buffer;

  clock_gettime(CLOCK_MONOTONIC, &b);
  contex_time = (((unsigned long long) (b.tv_sec - a.tv_sec)) * 1000000000llu + ((unsigned long long) (b.tv_nsec - a.tv_nsec))) / 1000000llu;

  if (contex_time >= 5llu) {
    //fprintf(stdout, "[ %2u ] Context time = %12llu ms :: %32s\n", context_idx, contex_time, gr_elem_info[ gr->type ].name);
  }

  return gr_ret;
}

gr_match_code_t gr_match(const token_t* const token) {
  if (context_idx == -1) {
    context_idx++;
    context_idx_max = context_idx;

    gr_stack        = &gr_context[ context_idx ].gr_stack;
    gr_token_buffer = &gr_context[ context_idx ].gr_token_buffer;
  } else if (context_idx != 0) {
    if (GR_DEBUG_LEVEL_ERROR >= GR_DEBUG_LEVEL) {
      fprintf(stdout,
              "error[at line %6u in %s] :: unexpected context %3u/%3u\n",
              ((unsigned int) (__LINE__)),
              __PRETTY_FUNCTION__,
              context_idx,
              context_idx_max);
    }
  }

  if ((context_idx == 0) && (gr_stack_is_empty(gr_stack) == 1u)) {
    // Clear this context.
    memset(gr_stack,        0, sizeof(gr_stack_t));
    memset(gr_token_buffer, 0, sizeof(gr_token_buffer_t));
    // Set appropriate flags for this context.
    gr_stack->flags |= GR_STACK_FLAGS_SKIP_PRINT;

    gr_stack_push(gr_stack, gr_elem_get(GR_ELEM_START));
  }

  return do_match_main_context(token);
}

void gr_deliver(void) {
  const gr_t* gr;

  while (gr_stack->elem_idx >= 2u) {
    rule_inflate(gr_stack_peek(gr_stack));
    gr_free(gr_stack_pop(gr_stack));
  }
  gr = gr_stack_peek(gr_stack);
  if (gr != NULL) {
    gr_error_print_style(&gr->rules[ gr->rule_idx ]);
  }

  fprintf(stdout, "context_idx_max        = %10d\n", context_idx_max);
  fprintf(stdout, "no_tokens              = %10u\n", gr_stack->elems[ 0u ]->no_tokens);
  fprintf(stdout, "elem_idx_max           = %10u\n", gr_stack->elem_idx_max);
  fprintf(stdout, "sizeof(gr_context_t)   = %10u\n", ((unsigned int) (sizeof(gr_context_t))));

  //gr_stack->flags &= ~GR_STACK_FLAGS_SKIP_PRINT;
  gr_stack_print(gr_stack);
  gr_stack_clear(gr_stack);
}

void gr_reg_callback_declarator(parser_callback_fn_t const parser_callback_fn) {
  parser_callback_declarator = parser_callback_fn;
}

void gr_reg_callback_init_declarator(parser_callback_fn_t const parser_callback_fn) {
  parser_callback_init_declarator = parser_callback_fn;
}

void gr_reg_callback_declaration(parser_callback_fn_t const parser_callback_fn) {
  parser_callback_declaration = parser_callback_fn;
}

void gr_reg_callback_function_body(parser_callback_fn_t const parser_callback_fn) {
  parser_callback_function_body = parser_callback_fn;
}

void gr_reg_callback_translation_unit(parser_callback_fn_t const parser_callback_fn) {
  parser_callback_translation_unit = parser_callback_fn;
}
