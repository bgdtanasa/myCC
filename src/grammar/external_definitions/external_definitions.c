#include "external_definitions.h"

gr_t gr_elem_translation_unit = {
  .type                 = GR_ELEM_TRANSLATION_UNIT,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_EXTERNAL_DECLARATION,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_TRANSLATION_UNIT,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_EXTERNAL_DECLARATION,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_external_declaration = {
  .type                 = GR_ELEM_EXTERNAL_DECLARATION,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_FUNCTION_DEFINITION,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DECLARATION,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_function_definition = {
  .type                 = GR_ELEM_FUNCTION_DEFINITION,
  .no_rules             = 1u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 4u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ATTRIBUTE_SPECIFIER_SEQUENCE,
          .is_mandatory = 0u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_DECLARATION_SPECIFIER,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_DECLARATOR,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_FUNCTION_BODY,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_function_body = {
  .type                 = GR_ELEM_FUNCTION_BODY,
  .no_rules             = 1u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_COMPOUND_STATEMENT,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_start = {
  .type                 = GR_ELEM_START,
  .no_rules             = 1u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_TRANSLATION_UNIT,
          .is_mandatory = 1u
        }
      }
    }
  }
};

