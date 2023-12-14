#include "gr.h"

unsigned char gr_elem_token_graph[ GR_ELEM_MAX_NO_ELEMS ][ GR_MAX_NO_RULES ][ TOKEN_MAX_NO_TOKENS ];

static gr_stack_t    gr_stack_internal = {
  .elem_idx                            = 0u,
  .elems                               = {
    [ 0u ]                             = NULL
  }
};
static gr_stack_t*   gr_stack          = &gr_stack_internal;
static unsigned char gr_graph_marked[ GR_ELEM_MAX_NO_ELEMS ];

static void gr_graph_generate_elem(void) {
  if (gr_stack_is_empty(gr_stack) == 0u) {
    gr_t* const gr_parent = gr_stack_peek(gr_stack);

    gr_graph_marked[ gr_parent->type ] = 1u;
    if (gr_parent->no_rules == 0u) {
      for (unsigned int i = 0u; i < gr_stack->elem_idx - 1u; i++) {
        if (gr_elem_info[ gr_parent->type ].no_tokens == 1u) {
          gr_elem_token_graph[ gr_stack->elems[ i ]->type ][ gr_stack->elems[ i ]->rule_idx ][ gr_elem_info[ gr_parent->type ].tokens[ 0u ] ] = 1u;
        }
      }
    } else {
      unsigned int i = 0u;

      while (i < gr_parent->no_rules) {
        const gr_rule_t* const rule = &gr_parent->rules[ i ];

        gr_parent->rule_idx = i;
        for (unsigned int j = 0u; j < rule->no_elems; j++) {
          for (unsigned int k = 0u; k < j; k++) {
            if (rule->elems[ k ].is_mandatory == 1u) {
              goto gr_graph_generate_elem_next_rule;
            }
          }

          if (gr_graph_marked[ rule->elems[ j ].type ] == 0u) {
            gr_t* gr_child = gr_elem_get(rule->elems[ j ].type);

            gr_stack_push(gr_stack, gr_child);
            gr_graph_generate_elem();
            gr_free(gr_stack_pop(gr_stack));
          }
        }

gr_graph_generate_elem_next_rule:
        i++;
      }
    }
  }
}

void gr_graph_generate(void) {
  for (unsigned int i = ((unsigned int) (GR_ELEM_COMPLEX)); i < ((unsigned int) (GR_ELEM_MAX_NO_ELEMS)); i++) {
    memset(&gr_stack_internal,     0, sizeof(gr_stack_internal));
    memset(&gr_graph_marked[ 0u ], 0, sizeof(gr_graph_marked));

    gr_stack_push(gr_stack, gr_elem_get(((gr_elem_type_t) (i))));
    gr_graph_generate_elem();
    gr_free(gr_stack_pop(gr_stack));
  }
}
