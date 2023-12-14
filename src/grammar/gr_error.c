#include "gr.h"

void gr_error_report(gr_stack_t* const gr_stack) {
  (void) gr_stack;

  //gr_stack->flags &= ~GR_STACK_FLAGS_SKIP_PRINT;
}

void gr_error_print_style(const gr_rule_t* const rule) {
  unsigned int no_tabs = 0u;

  for (unsigned int i = 0u; i < rule->no_elems; i++) {
    if (rule->elems[ i ].is_marked == 1u) {
      fprintf(stdout,
              "\033[0;32m%s\033[0m ",
              &rule->elems[ i ].token->name[ 0u ]);

      if (rule->elems[ i ].type < GR_ELEM_COMPLEX) {
        if (gr_elem_info[ rule->elems[ i ].type ].tokens[ 0u ] == TOKEN_SEPARATOR_BRACKET_CURLY_OPEN) {
          no_tabs += 2u;
        }
        if (gr_elem_info[ rule->elems[ i ].type ].tokens[ 0u ] == TOKEN_SEPARATOR_BRACKET_CURLY_CLOSED) {
          no_tabs -= 2u;
        }

        if ((gr_elem_info[ rule->elems[ i ].type ].tokens[ 0u ] == TOKEN_SEPARATOR_SEMICOLON) ||
            (gr_elem_info[ rule->elems[ i ].type ].tokens[ 0u ] == TOKEN_SEPARATOR_BRACKET_CURLY_OPEN) ||
            (gr_elem_info[ rule->elems[ i ].type ].tokens[ 0u ] == TOKEN_SEPARATOR_BRACKET_CURLY_CLOSED)) {
          fprintf(stdout, "\n");
          for (unsigned int j = 0u; j < no_tabs; j++) {
            fprintf(stdout, " ");
          }
        }
      }
    }
  }
  fprintf(stdout, "\033[37;1m==================================================\033[0m\n");
}
