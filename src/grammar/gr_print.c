#include "gr.h"

void gr_rule_print(const gr_rule_t* const rule) {
  for (unsigned int k = 0u; k < rule->no_elems; k++) {
    if (rule->elems[ k ].is_marked == 0u) {
      if (rule->flags & GR_RULE_FLAGS_SKIP_NON_MARKED) {
        continue;
      }

      if (rule->elems[ k ].is_mandatory == 1u) {
        fprintf(stdout,
                "\033[0;31m%-12s \033[0m ",
                gr_elem_info[ rule->elems[ k ].type ].name);
      } else {
        fprintf(stdout,
                "\033[0;33m%-12s \033[0m ",
                gr_elem_info[ rule->elems[ k ].type ].name);
      }
    } else {
      fprintf(stdout,
              "\033[0;32m%-12s \033[0m ",
              &rule->elems[ k ].token->name[ 0u ]);
    }
  }
  fprintf(stdout, "\n");
}

void gr_print(const gr_t* const gr) {
  fprintf(stdout,
          "\033[37;1m%-26s\033[0m :: R = %2u E = %2u :: %08x %2u :: %2u :: %3u :: %016llx\n",
          gr_elem_info[ gr->type ].name,
          gr->rule_idx,
          gr->rules[ gr->rule_idx ].elem_idx,
          gr->flags,
          gr->flag_values.last_rule_matched,
          //token_type_name[ gr->rules[ gr->rule_idx ].last_token_matched ],
          //gr->rules[ gr->rule_idx ].last_elem_matched,
          gr->rules[ gr->rule_idx ].no_matched_elems,
          gr->no_tokens,
          ((unsigned long long) (gr->parent)));
#if 1
  for (unsigned int j = 0u; j < gr->no_tokens; j++) {
    fprintf(stdout, "%16s ", &gr->tokens[ j ]->name[ 0u ]);
    if (((j + 1u) % 8u) == 0u) {
      fprintf(stdout, "\n");
    }
  }
  fprintf(stdout, "\n");
#endif

  for (unsigned int j = 0u; j < gr->no_rules; j++) {
    fprintf(stdout,
            "%2u %u :: \t",
            j,
            gr->rules[ j ].is_expanded);

    gr_rule_print(&gr->rules[ j ]);
  }
}

void gr_stack_print(const gr_stack_t* const gr_stack) {
  if (gr_stack != NULL) {
    if (gr_stack->flags & GR_STACK_FLAGS_SKIP_PRINT) {
      return;
    }
    if (gr_stack_is_empty(gr_stack) == 1u) {
      return;
    }

    for (signed int i = ((signed int) (gr_stack->elem_idx)) - 1; i >= 0 ; i--) {
      gr_t* const gr = gr_stack->elems[ i ];

      fprintf(stdout,
              "\033[37;1m%3d/%3u\033[0m :: %3u :: ",
              ((signed int) (gr_stack->elem_idx)) - i,
              gr_stack->elem_idx,
              gr_stack->elem_idx_max);
      gr_print(gr);
    }
  }
  fprintf(stdout, "\033[37;1m==================================================\033[0m\n");
}
