#include "expressions.h"

gr_t gr_elem_primary_expression = {
  .type                 = GR_ELEM_PRIMARY_EXPRESSION,
  .no_rules             = 5u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_IDENTIFIER,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_CONSTANT,
          .is_mandatory = 1u
        }
      }
    },
    [ 2u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_STRING_CONSTANT,
          .is_mandatory = 1u
        }
      }
    },
    [ 3u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_OPEN,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_CLOSED,
          .is_mandatory = 1u
        }
      }
    },
    [ 4u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_GENERIC_SELECTION,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_generic_selection = {
  .type                 = GR_ELEM_GENERIC_SELECTION,
  .no_rules             = 1u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 6u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD__GENERIC,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_OPEN,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_ASSIGNMENT_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_LIST_DELIMITER,
          .is_mandatory = 1u
        },
        [ 4u ]          = {
          .type         = GR_ELEM_GENERIC_ASSOC_LIST,
          .is_mandatory = 1u
        },
        [ 5u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_CLOSED,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_generic_assoc_list = {
  .type                 = GR_ELEM_GENERIC_ASSOC_LIST,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_GENERIC_ASSOC,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_GENERIC_ASSOC_LIST,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_LIST_DELIMITER,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_GENERIC_ASSOC,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_generic_assoc = {
  .type                 = GR_ELEM_GENERIC_ASSOC,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_TYPE_NAME,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_SEPARATOR_COLON,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_ASSIGNMENT_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_DEFAULT,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_SEPARATOR_COLON,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_ASSIGNMENT_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_postfix_expression = {
  .type                 = GR_ELEM_POSTFIX_EXPRESSION,
  .no_rules             = 8u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_PRIMARY_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .flags            = GR_RULE_FLAGS_SKIP_EXPAND,
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_COMPOUND_LITERAL,
          .is_mandatory = 1u
        }
      }
    },
    [ 2u ]              = {
      .no_elems         = 4u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_POSTFIX_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_OPERATOR_ACCESS_ARRAY_SUBSCRIPT_BEGIN,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_OPERATOR_ACCESS_ARRAY_SUBSCRIPT_END,
          .is_mandatory = 1u
        }
      }
    },
    [ 3u ]              = {
      .no_elems         = 4u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_POSTFIX_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_OPERATOR_FUNCTION_CALL_BEGIN,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_ARGUMENT_EXPRESSION_LIST,
          .is_mandatory = 0u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_OPERATOR_FUNCTION_CALL_END,
          .is_mandatory = 1u
        }
      }
    },
    [ 4u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_POSTFIX_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_OPERATOR_ACCESS_FIELD,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_IDENTIFIER,
          .is_mandatory = 1u
        }
      }
    },
    [ 5u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_POSTFIX_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_OPERATOR_ACCESS_FIELD_VIA_POINTER,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_IDENTIFIER,
          .is_mandatory = 1u
        }
      }
    },
    [ 6u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_POSTFIX_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_OPERATOR_POSTFIX_INCREMENT,
          .is_mandatory = 1u
        }
      }
    },
    [ 7u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_POSTFIX_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_OPERATOR_POSTFIX_DECREMENT,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_argument_expression_list = {
  .type                 = GR_ELEM_ARGUMENT_EXPRESSION_LIST,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ASSIGNMENT_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ARGUMENT_EXPRESSION_LIST,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_LIST_DELIMITER,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_ASSIGNMENT_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_compound_literal = {
  .type                 = GR_ELEM_COMPOUND_LITERAL,
  .no_rules             = 1u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 5u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_OPEN,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_STORAGE_CLASS_SPECIFIERS,
          .is_mandatory = 0u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_TYPE_NAME,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_CLOSED,
          .is_mandatory = 1u
        },
        [ 4u ]          = {
          .type         = GR_ELEM_BRACED_INITIALIZER,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_storage_class_specifiers = {
  .type                 = GR_ELEM_STORAGE_CLASS_SPECIFIERS,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_STORAGE_CLASS_SPECIFIER,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_STORAGE_CLASS_SPECIFIERS,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_STORAGE_CLASS_SPECIFIER,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_unary_expression = {
  .type                 = GR_ELEM_UNARY_EXPRESSION,
  .no_rules             = 7u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_POSTFIX_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_OPERATOR_PREFIX_INCREMENT,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_UNARY_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    },
    [ 2u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_OPERATOR_PREFIX_DECREMENT,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_UNARY_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    },
    [ 3u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_UNARY_OPERATOR,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_CAST_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    },
    [ 4u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_SIZEOF,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_UNARY_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    },
    [ 5u ]              = {
      .no_elems         = 4u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_SIZEOF,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_OPERATOR_FUNCTION_CALL_BEGIN,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_TYPE_NAME,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_OPERATOR_FUNCTION_CALL_END,
          .is_mandatory = 1u
        }
      }
    },
    [ 6u ]              = {
      .no_elems         = 4u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_ALIGNOF,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_OPERATOR_FUNCTION_CALL_BEGIN,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_TYPE_NAME,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_OPERATOR_FUNCTION_CALL_END,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_unary_operator = {
  .type                 = GR_ELEM_UNARY_OPERATOR,
  .no_rules             = 6u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_OPERATOR_ARITHMETIC_UNARY_PLUS,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_OPERATOR_ARITHMETIC_UNARY_MINUS,
          .is_mandatory = 1u
        }
      }
    },
    [ 2u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_OPERATOR_ARITHMETIC_BITWISE_NOT,
          .is_mandatory = 1u
        }
      }
    },
    [ 3u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_OPERATOR_LOGICAL_NOT,
          .is_mandatory = 1u
        }
      }
    },
    [ 4u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_OPERATOR_ACCESS_POINTER_DEREFERENCE,
          .is_mandatory = 1u
        }
      }
    },
    [ 5u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_OPERATOR_ACCESS_ADDRESS_OF,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_cast_expression = {
  .type                 = GR_ELEM_CAST_EXPRESSION,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_UNARY_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 4u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_COMPOUND_LITERAL_BEGIN,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_TYPE_NAME,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_COMPOUND_LITERAL_END,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_CAST_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_multiplicative_expression = {
  .type                 = GR_ELEM_MULTIPLICATIVE_EXPRESSION,
  .no_rules             = 4u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_CAST_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_MULTIPLICATIVE_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_OPERATOR_ARITHMETIC_PRODUCT,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_CAST_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    },
    [ 2u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_MULTIPLICATIVE_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_OPERATOR_ARITHMETIC_DIVISION,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_CAST_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    },
    [ 3u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_MULTIPLICATIVE_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_OPERATOR_ARITHMETIC_REMAINDER,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_CAST_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_additive_expression = {
  .type                 = GR_ELEM_ADDITIVE_EXPRESSION,
  .no_rules             = 3u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_MULTIPLICATIVE_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ADDITIVE_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_OPERATOR_ARITHMETIC_ADDITION,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_MULTIPLICATIVE_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    },
    [ 2u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ADDITIVE_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_OPERATOR_ARITHMETIC_SUBTRACTION,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_MULTIPLICATIVE_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_shift_expression = {
  .type                 = GR_ELEM_SHIFT_EXPRESSION,
  .no_rules             = 3u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ADDITIVE_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_SHIFT_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_OPERATOR_ARITHMETIC_BITWISE_SHIFT_LEFT,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_ADDITIVE_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    },
    [ 2u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_SHIFT_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_OPERATOR_ARITHMETIC_BITWISE_SHIFT_RIGHT,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_ADDITIVE_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_relational_expression = {
  .type                 = GR_ELEM_RELATIONAL_EXPRESSION,
  .no_rules             = 5u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_SHIFT_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_RELATIONAL_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_OPERATOR_COMPARISON_LESS_THAN,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_SHIFT_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    },
    [ 2u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_RELATIONAL_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_OPERATOR_COMPARISON_GREATER_THAN,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_SHIFT_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    },
    [ 3u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_RELATIONAL_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_OPERATOR_COMPARISON_LESS_THAN_OR_EQUAL_TO,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_SHIFT_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    },
    [ 4u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_RELATIONAL_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_OPERATOR_COMPARISON_GREATER_THAN_OR_EQUAL_TO,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_SHIFT_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_equality_expression = {
  .type                 = GR_ELEM_EQUALITY_EXPRESSION,
  .no_rules             = 3u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_RELATIONAL_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_EQUALITY_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_OPERATOR_COMPARISON_EQUAL_TO,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_RELATIONAL_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    },
    [ 2u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_EQUALITY_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_OPERATOR_COMPARISON_NOT_EQUAL_TO,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_RELATIONAL_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_and_expression = {
  .type                 = GR_ELEM_AND_EXPRESSION,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_EQUALITY_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_AND_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_OPERATOR_ARITHMETIC_BITWISE_AND,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_EQUALITY_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_xor_expression = {
  .type                 = GR_ELEM_XOR_EXPRESSION,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_AND_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_XOR_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_OPERATOR_ARITHMETIC_BITWISE_XOR,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_AND_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_or_expression = {
  .type                 = GR_ELEM_OR_EXPRESSION,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_XOR_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_OR_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_OPERATOR_ARITHMETIC_BITWISE_OR,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_XOR_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_logical_and_expression = {
  .type                 = GR_ELEM_LOGICAL_AND_EXPRESSION,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_OR_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_LOGICAL_AND_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_OPERATOR_LOGICAL_AND,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_OR_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_logical_or_expression = {
  .type                 = GR_ELEM_LOGICAL_OR_EXPRESSION,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_LOGICAL_AND_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_LOGICAL_OR_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_OPERATOR_LOGICAL_OR,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_LOGICAL_AND_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_conditional_expression = {
  .type                 = GR_ELEM_CONDITIONAL_EXPRESSION,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_LOGICAL_OR_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 5u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_LOGICAL_OR_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_OPERATOR_CONDITIONAL_PART_ONE,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_OPERATOR_CONDITIONAL_PART_TWO,
          .is_mandatory = 1u
        },
        [ 4u ]          = {
          .type         = GR_ELEM_CONDITIONAL_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_assignment_expression = {
  .type                 = GR_ELEM_ASSIGNMENT_EXPRESSION,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_CONDITIONAL_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_UNARY_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_ASSIGNMENT_OPERATOR,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_ASSIGNMENT_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_assignment_operator = {
  .type                 = GR_ELEM_ASSIGNMENT_OPERATOR,
  .no_rules             = 11u,
  .rule_idx             = 0u,
  .rules                = {
    [  0u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_OPERATOR_ASSIGNMENT_BASIC,
          .is_mandatory = 1u
        }
      }
    },
    [  1u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_OPERATOR_ASSIGNMENT_ADDITION,
          .is_mandatory = 1u
        }
      }
    },
    [  2u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_OPERATOR_ASSIGNMENT_SUBTRACTION,
          .is_mandatory = 1u
        }
      }
    },
    [  3u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_OPERATOR_ASSIGNMENT_MULTIPLICATION,
          .is_mandatory = 1u
        }
      }
    },
    [  4u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_OPERATOR_ASSIGNMENT_DIVISION,
          .is_mandatory = 1u
        }
      }
    },
    [  5u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_OPERATOR_ASSIGNMENT_MODULO,
          .is_mandatory = 1u
        }
      }
    },
    [  6u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_OPERATOR_ASSIGNMENT_BITWISE_AND,
          .is_mandatory = 1u
        }
      }
    },
    [  7u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_OPERATOR_ASSIGNMENT_BITWISE_OR,
          .is_mandatory = 1u
        }
      }
    },
    [  8u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_OPERATOR_ASSIGNMENT_BITWISE_XOR,
          .is_mandatory = 1u
        }
      }
    },
    [  9u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_OPERATOR_ASSIGNMENT_BITWISE_SHIFT_LEFT,
          .is_mandatory = 1u
        }
      }
    },
    [ 10u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_OPERATOR_ASSIGNMENT_BITWISE_SHIFT_RIGHT,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_expression = {
  .type                 = GR_ELEM_EXPRESSION,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ASSIGNMENT_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_OPERATOR_COMMA,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_ASSIGNMENT_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_constant_expression = {
  .type                 = GR_ELEM_CONSTANT_EXPRESSION,
  .no_rules             = 1u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_CONDITIONAL_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    }
  }
};

