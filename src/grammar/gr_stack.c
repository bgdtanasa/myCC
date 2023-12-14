#include "gr.h"

void gr_stack_clear(gr_stack_t* const gr_stack) {
  while (gr_stack_is_empty(gr_stack) == 0u) {
    gr_free(gr_stack_pop(gr_stack));
  }
}
