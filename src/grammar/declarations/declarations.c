#include "declarations.h"

gr_t gr_elem_declaration = {
  .type                 = GR_ELEM_DECLARATION,
  .no_rules             = 4u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DECLARATION_SPECIFIERS,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_INIT_DECLARATOR_LIST,
          .is_mandatory = 0u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_SEPARATOR_SEMICOLON,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 4u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ATTRIBUTE_SPECIFIER_SEQUENCE,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_DECLARATION_SPECIFIERS,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_INIT_DECLARATOR_LIST,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_SEPARATOR_SEMICOLON,
          .is_mandatory = 1u
        }
      }
    },
    [ 2u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_STATIC_ASSERT_DECLARATION,
          .is_mandatory = 1u
        }
      }
    },
    [ 3u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ATTRIBUTE_DECLARATION,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_declaration_specifiers = {
  .type                 = GR_ELEM_DECLARATION_SPECIFIERS,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DECLARATION_SPECIFIER,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_ATTRIBUTE_SPECIFIER_SEQUENCE,
          .is_mandatory = 0u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DECLARATION_SPECIFIER,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_DECLARATION_SPECIFIERS,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_declaration_specifier = {
  .type                 = GR_ELEM_DECLARATION_SPECIFIER,
  .no_rules             = 3u,
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
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_TYPE_SPECIFIER_QUALIFIER,
          .is_mandatory = 1u
        }
      }
    },
    [ 2u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_FUNCTION_SPECIFIER,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_init_declarator_list = {
  .type                 = GR_ELEM_INIT_DECLARATOR_LIST,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_INIT_DECLARATOR,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_INIT_DECLARATOR_LIST,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_LIST_DELIMITER,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_INIT_DECLARATOR,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_init_declarator = {
  .type                 = GR_ELEM_INIT_DECLARATOR,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DECLARATOR,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DECLARATOR,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_OPERATOR_ASSIGNMENT_BASIC,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_INITIALIZER,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_attribute_declaration = {
  .type                 = GR_ELEM_ATTRIBUTE_DECLARATION,
  .no_rules             = 1u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ATTRIBUTE_SPECIFIER_SEQUENCE,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_SEPARATOR_SEMICOLON,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_storage_class_specifier = {
  .type                 = GR_ELEM_STORAGE_CLASS_SPECIFIER,
  .no_rules             = 7u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_AUTO,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_CONSTEXPR,
          .is_mandatory = 1u
        }
      }
    },
    [ 2u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_EXTERN,
          .is_mandatory = 1u
        }
      }
    },
    [ 3u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_REGISTER,
          .is_mandatory = 1u
        }
      }
    },
    [ 4u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_STATIC,
          .is_mandatory = 1u
        }
      }
    },
    [ 5u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_THREAD_LOCAL,
          .is_mandatory = 1u
        }
      }
    },
    [ 6u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_TYPEDEF,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_type_specifier = {
  .type                 = GR_ELEM_TYPE_SPECIFIER,
  .no_rules             = 23u,
  .rule_idx             = 0u,
  .rules                = {
    [  0u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_VOID,
          .is_mandatory = 1u
        }
      }
    },
    [  1u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_SINT8,
          .is_mandatory = 1u
        }
      }
    },
    [  2u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_UINT8,
          .is_mandatory = 1u
        }
      }
    },
    [  3u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_SINT16,
          .is_mandatory = 1u
        }
      }
    },
    [  4u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_UINT16,
          .is_mandatory = 1u
        }
      }
    },
    [  5u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_SINT32,
          .is_mandatory = 1u
        }
      }
    },
    [  6u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_UINT32,
          .is_mandatory = 1u
        }
      }
    },
    [  7u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_SINT64,
          .is_mandatory = 1u
        }
      }
    },
    [  8u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_UINT64,
          .is_mandatory = 1u
        }
      }
    },
    [  9u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_FLOAT32,
          .is_mandatory = 1u
        }
      }
    },
    [ 10u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_FLOAT64,
          .is_mandatory = 1u
        }
      }
    },
    [ 11u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_FLOAT128,
          .is_mandatory = 1u
        }
      }
    },
    [ 12u ]             = {
      .no_elems         = 4u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD__BITINT,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_OPEN,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_CONSTANT_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_CLOSED,
          .is_mandatory = 1u
        }
      }
    },
    [ 13u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_BOOL,
          .is_mandatory = 1u
        }
      }
    },
    [ 14u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD__COMPLEX,
          .is_mandatory = 1u
        }
      }
    },
    [ 15u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD__DECIMAL128,
          .is_mandatory = 1u
        }
      }
    },
    [ 16u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD__DECIMAL64,
          .is_mandatory = 1u
        }
      }
    },
    [ 17u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD__DECIMAL32,
          .is_mandatory = 1u
        }
      }
    },
    [ 18u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ATOMIC_TYPE_SPECIFIER,
          .is_mandatory = 1u
        }
      }
    },
    [ 19u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_STRUCT_OR_UNION_SPECIFIER,
          .is_mandatory = 1u
        }
      }
    },
    [ 20u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ENUM_SPECIFIER,
          .is_mandatory = 1u
        }
      }
    },
    [ 21u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_TYPEDEF_NAME,
          .is_mandatory = 1u
        }
      }
    },
    [ 22u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_TYPEOF_SPECIFIER,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_struct_or_union_specifier = {
  .type                 = GR_ELEM_STRUCT_OR_UNION_SPECIFIER,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 6u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_STRUCT_OR_UNION,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_ATTRIBUTE_SPECIFIER_SEQUENCE,
          .is_mandatory = 0u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_IDENTIFIER,
          .is_mandatory = 0u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_BODY_BEGIN,
          .is_mandatory = 1u
        },
        [ 4u ]          = {
          .type         = GR_ELEM_MEMBER_DECLARATION_LIST,
          .is_mandatory = 1u
        },
        [ 5u ]          = {
          .type         = GR_ELEM_BODY_END,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_STRUCT_OR_UNION,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_ATTRIBUTE_SPECIFIER_SEQUENCE,
          .is_mandatory = 0u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_IDENTIFIER,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_struct_or_union = {
  .type                 = GR_ELEM_STRUCT_OR_UNION,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_STRUCT,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_UNION,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_member_declaration_list = {
  .type                 = GR_ELEM_MEMBER_DECLARATION_LIST,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_MEMBER_DECLARATION,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_MEMBER_DECLARATION_LIST,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_MEMBER_DECLARATION,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_member_declaration = {
  .type                 = GR_ELEM_MEMBER_DECLARATION,
  .no_rules             = 2u,
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
          .type         = GR_ELEM_SPECIFIER_QUALIFIER_LIST,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_MEMBER_DECLARATOR_LIST,
          .is_mandatory = 0u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_SEPARATOR_SEMICOLON,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_STATIC_ASSERT_DECLARATION,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_specifier_qualifier_list = {
  .type                 = GR_ELEM_SPECIFIER_QUALIFIER_LIST,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_TYPE_SPECIFIER_QUALIFIER,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_ATTRIBUTE_SPECIFIER_SEQUENCE,
          .is_mandatory = 0u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_TYPE_SPECIFIER_QUALIFIER,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_SPECIFIER_QUALIFIER_LIST,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_type_specifier_qualifier = {
  .type                 = GR_ELEM_TYPE_SPECIFIER_QUALIFIER,
  .no_rules             = 3u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_TYPE_SPECIFIER,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_TYPE_QUALIFIER,
          .is_mandatory = 1u
        }
      }
    },
    [ 2u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ALIGNMENT_SPECIFIER,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_member_declarator_list = {
  .type                 = GR_ELEM_MEMBER_DECLARATOR_LIST,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_MEMBER_DECLARATOR,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_MEMBER_DECLARATOR_LIST,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_LIST_DELIMITER,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_MEMBER_DECLARATOR,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_member_declarator = {
  .type                 = GR_ELEM_MEMBER_DECLARATOR,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DECLARATOR,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DECLARATOR,
          .is_mandatory = 0u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_BIT_FIELD_WIDTH_DECLARATION_STRUCT_OR_UNION,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_CONSTANT_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_enum_specifier = {
  .type                 = GR_ELEM_ENUM_SPECIFIER,
  .no_rules             = 3u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 7u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_ENUM,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_ATTRIBUTE_SPECIFIER_SEQUENCE,
          .is_mandatory = 0u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_IDENTIFIER,
          .is_mandatory = 0u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_ENUM_TYPE_SPECIFIER,
          .is_mandatory = 0u
        },
        [ 4u ]          = {
          .type         = GR_ELEM_BODY_BEGIN,
          .is_mandatory = 1u
        },
        [ 5u ]          = {
          .type         = GR_ELEM_ENUMERATOR_LIST,
          .is_mandatory = 1u
        },
        [ 6u ]          = {
          .type         = GR_ELEM_BODY_END,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 8u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_ENUM,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_ATTRIBUTE_SPECIFIER_SEQUENCE,
          .is_mandatory = 0u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_IDENTIFIER,
          .is_mandatory = 0u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_ENUM_TYPE_SPECIFIER,
          .is_mandatory = 0u
        },
        [ 4u ]          = {
          .type         = GR_ELEM_BODY_BEGIN,
          .is_mandatory = 1u
        },
        [ 5u ]          = {
          .type         = GR_ELEM_ENUMERATOR_LIST,
          .is_mandatory = 1u
        },
        [ 6u ]          = {
          .type         = GR_ELEM_LIST_DELIMITER,
          .is_mandatory = 1u
        },
        [ 7u ]          = {
          .type         = GR_ELEM_BODY_END,
          .is_mandatory = 1u
        }
      }
    },
    [ 2u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_ENUM,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_IDENTIFIER,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_ENUM_TYPE_SPECIFIER,
          .is_mandatory = 0u
        }
      }
    }
  }
};

gr_t gr_elem_enumerator_list= {
  .type                 = GR_ELEM_ENUMERATOR_LIST,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ENUMERATOR,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ENUMERATOR_LIST,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_LIST_DELIMITER,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_ENUMERATOR,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_enumerator= {
  .type                 = GR_ELEM_ENUMERATOR,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ENUMERATION_CONSTANT,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_ATTRIBUTE_SPECIFIER_SEQUENCE,
          .is_mandatory = 0u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 4u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ENUMERATION_CONSTANT,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_ATTRIBUTE_SPECIFIER_SEQUENCE,
          .is_mandatory = 0u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_OPERATOR_ASSIGNMENT_BASIC,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_CONSTANT_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_enum_type_specifier = {
  .type                 = GR_ELEM_ENUM_TYPE_SPECIFIER,
  .no_rules             = 1u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_SEPARATOR_COLON,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_SPECIFIER_QUALIFIER_LIST,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_atomic_type_specifier = {
  .type                 = GR_ELEM_ATOMIC_TYPE_SPECIFIER,
  .no_rules             = 1u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD__ATOMIC,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_OPEN,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_TYPE_NAME,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_CLOSED,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_typeof_specifier = {
  .type                 = GR_ELEM_TYPEOF_SPECIFIER,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 4u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_TYPEOF,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_OPEN,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_TYPEOF_SPECIFIER_ARGUMENT,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_CLOSED,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 4u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_TYPEOF_UNQUAL,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_OPEN,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_TYPEOF_SPECIFIER_ARGUMENT,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_CLOSED,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_typeof_specifier_argument = {
  .type                 = GR_ELEM_TYPEOF_SPECIFIER_ARGUMENT,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_EXPRESSION,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_TYPE_NAME,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_type_qualifier = {
  .type                 = GR_ELEM_TYPE_QUALIFIER,
  .no_rules             = 4u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_CONST,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_RESTRICT,
          .is_mandatory = 1u
        }
      }
    },
    [ 2u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_VOLATILE,
          .is_mandatory = 1u
        }
      }
    },
    [ 3u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD__ATOMIC,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_function_specifier = {
  .type                 = GR_ELEM_FUNCTION_SPECIFIER,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_INLINE,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD__NORETURN,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_alignment_specifier = {
  .type                 = GR_ELEM_ALIGNMENT_SPECIFIER,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 4u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_ALIGNAS,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_OPEN,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_TYPE_NAME,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_CLOSED,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 4u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_ALIGNAS,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_OPEN,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_CONSTANT_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_CLOSED,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_declarator = {
  .type                 = GR_ELEM_DECLARATOR,
  .no_rules             = 1u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_POINTER,
          .is_mandatory = 0u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_DIRECT_DECLARATOR,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_direct_declarator = {
  .type                 = GR_ELEM_DIRECT_DECLARATOR,
  .no_rules             = 7u,
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
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DECLARATOR_BINDER_BEGIN,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_DECLARATOR,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_DECLARATOR_BINDER_END,
          .is_mandatory = 1u
        }
      }
    },
    [ 2u ]              = {
      .no_elems         = 5u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIRECT_DECLARATOR,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_BEGIN,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_TYPE_QUALIFIER_LIST,
          .is_mandatory = 0u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_ASSIGNMENT_EXPRESSION,
          .is_mandatory = 0u
        },
        [ 4u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_END,
          .is_mandatory = 1u
        }
      }
    },
    [ 3u ]              = {
      .no_elems         = 6u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIRECT_DECLARATOR,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_BEGIN,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_KEYWORD_STATIC,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_TYPE_QUALIFIER_LIST,
          .is_mandatory = 0u
        },
        [ 4u ]          = {
          .type         = GR_ELEM_ASSIGNMENT_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 5u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_END,
          .is_mandatory = 1u
        }
      }
    },
    [ 4u ]              = {
      .no_elems         = 6u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIRECT_DECLARATOR,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_BEGIN,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_TYPE_QUALIFIER_LIST,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_KEYWORD_STATIC,
          .is_mandatory = 1u
        },
        [ 4u ]          = {
          .type         = GR_ELEM_ASSIGNMENT_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 5u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_END,
          .is_mandatory = 1u
        }
      }
    },
    [ 5u ]              = {
      .no_elems         = 5u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIRECT_DECLARATOR,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_BEGIN,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_TYPE_QUALIFIER_LIST,
          .is_mandatory = 0u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_PLACEHOLDER_VLA,
          .is_mandatory = 1u
        },
        [ 4u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_END,
          .is_mandatory = 1u
        }
      }
    },
    [ 6u ]              = {
      .no_elems         = 4u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIRECT_DECLARATOR,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_DECLARATOR_FUNCTION_BEGIN,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_PARAMETER_TYPE_LIST,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_DECLARATOR_FUNCTION_END,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_array_declarator = {
  .type                 = GR_ELEM_ARRAY_DECLARATOR,
  .no_rules             = 4u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 5u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIRECT_DECLARATOR,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_BEGIN,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_TYPE_QUALIFIER_LIST,
          .is_mandatory = 0u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_ASSIGNMENT_EXPRESSION,
          .is_mandatory = 0u
        },
        [ 4u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_END,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 6u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIRECT_DECLARATOR,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_BEGIN,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_KEYWORD_STATIC,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_TYPE_QUALIFIER_LIST,
          .is_mandatory = 0u
        },
        [ 4u ]          = {
          .type         = GR_ELEM_ASSIGNMENT_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 5u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_END,
          .is_mandatory = 1u
        }
      }
    },
    [ 2u ]              = {
      .no_elems         = 6u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIRECT_DECLARATOR,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_BEGIN,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_TYPE_QUALIFIER_LIST,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_KEYWORD_STATIC,
          .is_mandatory = 1u
        },
        [ 4u ]          = {
          .type         = GR_ELEM_ASSIGNMENT_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 5u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_END,
          .is_mandatory = 1u
        }
      }
    },
    [ 3u ]              = {
      .no_elems         = 5u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIRECT_DECLARATOR,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_BEGIN,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_TYPE_QUALIFIER_LIST,
          .is_mandatory = 0u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_PLACEHOLDER_VLA,
          .is_mandatory = 1u
        },
        [ 4u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_END,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_function_declarator = {
  .type                 = GR_ELEM_FUNCTION_DECLARATOR,
  .no_rules             = 1u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 4u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIRECT_DECLARATOR,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_OPEN,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_PARAMETER_TYPE_LIST,
          .is_mandatory = 0u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_CLOSED,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_pointer = {
  .type                 = GR_ELEM_POINTER,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DECLARATOR_POINTER,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_ATTRIBUTE_SPECIFIER_SEQUENCE,
          .is_mandatory = 0u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_TYPE_QUALIFIER_LIST,
          .is_mandatory = 0u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 4u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DECLARATOR_POINTER,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_ATTRIBUTE_SPECIFIER_SEQUENCE,
          .is_mandatory = 0u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_TYPE_QUALIFIER_LIST,
          .is_mandatory = 0u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_POINTER,
          .is_mandatory = 1u
        }
      }
    },
  }
};

gr_t gr_elem_type_qualifier_list = {
  .type                 = GR_ELEM_TYPE_QUALIFIER_LIST,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_TYPE_QUALIFIER,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_TYPE_QUALIFIER_LIST,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_TYPE_QUALIFIER,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_parameter_type_list = {
  .type                 = GR_ELEM_PARAMETER_TYPE_LIST,
  .no_rules             = 3u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_PARAMETER_LIST,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_PARAMETER_LIST,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_LIST_DELIMITER,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_PARAMETER_VARIADIC_ARGS,
          .is_mandatory = 1u
        }
      }
    },
    [ 2u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_PARAMETER_VARIADIC_ARGS,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_parameter_list = {
  .type                 = GR_ELEM_PARAMETER_LIST,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_PARAMETER_DECLARATION,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_PARAMETER_LIST,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_LIST_DELIMITER,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_PARAMETER_DECLARATION,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_parameter_declaration = {
  .type                 = GR_ELEM_PARAMETER_DECLARATION,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ATTRIBUTE_SPECIFIER_SEQUENCE,
          .is_mandatory = 0u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_DECLARATION_SPECIFIERS,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_DECLARATOR,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ATTRIBUTE_SPECIFIER_SEQUENCE,
          .is_mandatory = 0u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_DECLARATION_SPECIFIERS,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_ABSTRACT_DECLARATOR,
          .is_mandatory = 0u
        }
      }
    }
  }
};

gr_t gr_elem_type_name = {
  .type                 = GR_ELEM_TYPE_NAME,
  .no_rules             = 1u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_SPECIFIER_QUALIFIER_LIST,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_ABSTRACT_DECLARATOR,
          .is_mandatory = 0u
        }
      }
    }
  }
};

gr_t gr_elem_abstract_declarator = {
  .type                 = GR_ELEM_ABSTRACT_DECLARATOR,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_POINTER,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_POINTER,
          .is_mandatory = 0u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_DIRECT_ABSTRACT_DECLARATOR,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_direct_abstract_declarator = {
  .type                 = GR_ELEM_DIRECT_ABSTRACT_DECLARATOR,
  .no_rules             = 11u,
  .rule_idx             = 0u,
  .rules                = {
    [  0u ]             = {
      .no_elems         = 4u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_BEGIN,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_TYPE_QUALIFIER_LIST,
          .is_mandatory = 0u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_ASSIGNMENT_EXPRESSION,
          .is_mandatory = 0u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_END,
          .is_mandatory = 1u
        }
      }
    },
    [  1u ]             = {
      .no_elems         = 5u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_BEGIN,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_KEYWORD_STATIC,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_TYPE_QUALIFIER_LIST,
          .is_mandatory = 0u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_ASSIGNMENT_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 4u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_END,
          .is_mandatory = 1u
        }
      }
    },
    [  2u ]             = {
      .no_elems         = 5u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_BEGIN,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_TYPE_QUALIFIER_LIST,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_KEYWORD_STATIC,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_ASSIGNMENT_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 4u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_END,
          .is_mandatory = 1u
        }
      }
    },
    [  3u ]             = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_BEGIN,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_PLACEHOLDER_VLA,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_END,
          .is_mandatory = 1u
        }
      }
    },
    [  4u ]             = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DECLARATOR_FUNCTION_BEGIN,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_PARAMETER_TYPE_LIST,
          .is_mandatory = 0u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_DECLARATOR_FUNCTION_END,
          .is_mandatory = 1u
        }
      }
    },
    [  5u ]             = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DECLARATOR_BINDER_BEGIN,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_ABSTRACT_DECLARATOR,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_DECLARATOR_BINDER_END,
          .is_mandatory = 1u
        }
      }
    },
    [  6u ]             = {
      .no_elems         = 5u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIRECT_ABSTRACT_DECLARATOR,
          .is_mandatory = 0u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_BEGIN,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_TYPE_QUALIFIER_LIST,
          .is_mandatory = 0u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_ASSIGNMENT_EXPRESSION,
          .is_mandatory = 0u
        },
        [ 4u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_END,
          .is_mandatory = 1u
        }
      }
    },
    [  7u ]             = {
      .no_elems         = 6u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIRECT_ABSTRACT_DECLARATOR,
          .is_mandatory = 0u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_BEGIN,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_KEYWORD_STATIC,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_TYPE_QUALIFIER_LIST,
          .is_mandatory = 0u
        },
        [ 4u ]          = {
          .type         = GR_ELEM_ASSIGNMENT_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 5u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_END,
          .is_mandatory = 1u
        }
      }
    },
    [  8u ]             = {
      .no_elems         = 6u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIRECT_ABSTRACT_DECLARATOR,
          .is_mandatory = 0u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_BEGIN,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_TYPE_QUALIFIER_LIST,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_KEYWORD_STATIC,
          .is_mandatory = 1u
        },
        [ 4u ]          = {
          .type         = GR_ELEM_ASSIGNMENT_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 5u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_END,
          .is_mandatory = 1u
        }
      }
    },
    [  9u ]             = {
      .no_elems         = 4u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIRECT_ABSTRACT_DECLARATOR,
          .is_mandatory = 0u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_BEGIN,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_PLACEHOLDER_VLA,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_END,
          .is_mandatory = 1u
        }
      }
    },
    [ 10u ]             = {
      .no_elems         = 4u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIRECT_ABSTRACT_DECLARATOR,
          .is_mandatory = 0u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_DECLARATOR_FUNCTION_BEGIN,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_PARAMETER_TYPE_LIST,
          .is_mandatory = 0u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_DECLARATOR_FUNCTION_END,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_array_abstract_declarator = {
  .type                 = GR_ELEM_ARRAY_ABSTRACT_DECLARATOR,
  .no_rules             = 8u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 4u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_BEGIN,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_TYPE_QUALIFIER_LIST,
          .is_mandatory = 0u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_ASSIGNMENT_EXPRESSION,
          .is_mandatory = 0u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_END,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 5u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_BEGIN,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_KEYWORD_STATIC,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_TYPE_QUALIFIER_LIST,
          .is_mandatory = 0u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_ASSIGNMENT_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 4u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_END,
          .is_mandatory = 1u
        }
      }
    },
    [ 2u ]              = {
      .no_elems         = 5u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_BEGIN,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_TYPE_QUALIFIER_LIST,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_KEYWORD_STATIC,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_ASSIGNMENT_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 4u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_END,
          .is_mandatory = 1u
        }
      }
    },
    [ 3u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_BEGIN,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_PLACEHOLDER_VLA,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_END,
          .is_mandatory = 1u
        }
      }
    },
    [ 4u ]              = {
      .no_elems         = 5u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIRECT_ABSTRACT_DECLARATOR,
          .is_mandatory = 0u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_BEGIN,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_TYPE_QUALIFIER_LIST,
          .is_mandatory = 0u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_ASSIGNMENT_EXPRESSION,
          .is_mandatory = 0u
        },
        [ 4u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_END,
          .is_mandatory = 1u
        }
      }
    },
    [ 5u ]              = {
      .no_elems         = 6u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIRECT_ABSTRACT_DECLARATOR,
          .is_mandatory = 0u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_BEGIN,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_KEYWORD_STATIC,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_TYPE_QUALIFIER_LIST,
          .is_mandatory = 0u
        },
        [ 4u ]          = {
          .type         = GR_ELEM_ASSIGNMENT_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 5u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_END,
          .is_mandatory = 1u
        }
      }
    },
    [ 6u ]              = {
      .no_elems         = 6u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIRECT_ABSTRACT_DECLARATOR,
          .is_mandatory = 0u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_BEGIN,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_TYPE_QUALIFIER_LIST,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_KEYWORD_STATIC,
          .is_mandatory = 1u
        },
        [ 4u ]          = {
          .type         = GR_ELEM_ASSIGNMENT_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 5u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_END,
          .is_mandatory = 1u
        }
      }
    },
    [ 7u ]              = {
      .no_elems         = 4u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIRECT_ABSTRACT_DECLARATOR,
          .is_mandatory = 0u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_BEGIN,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_PLACEHOLDER_VLA,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_DECLARATOR_ARRAY_END,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_function_abstract_declarator = {
  .type                 = GR_ELEM_FUNCTION_ABSTRACT_DECLARATOR,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_OPEN,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_PARAMETER_TYPE_LIST,
          .is_mandatory = 0u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_CLOSED,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
       .no_elems         = 4u,
       .elem_idx         = 0u,
       .elems            = {
         [ 0u ]          = {
           .type         = GR_ELEM_DIRECT_ABSTRACT_DECLARATOR,
           .is_mandatory = 0u
         },
         [ 1u ]          = {
           .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_OPEN,
           .is_mandatory = 1u
         },
         [ 2u ]          = {
           .type         = GR_ELEM_PARAMETER_TYPE_LIST,
           .is_mandatory = 0u
         },
         [ 3u ]          = {
           .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_CLOSED,
           .is_mandatory = 1u
         }
       }
     },
  }
};

gr_t gr_elem_typedef_name = {
  .type                 = GR_ELEM_TYPEDEF_NAME,
  .no_rules             = 1u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_IDENTIFIER_TYPEDEF,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_braced_initializer = {
  .type                 = GR_ELEM_BRACED_INITIALIZER,
  .no_rules             = 3u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_BODY_BEGIN,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_BODY_END,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_BODY_BEGIN,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_INITIALIZER_LIST,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_BODY_END,
          .is_mandatory = 1u
        }
      }
    },
    [ 2u ]              = {
      .no_elems         = 4u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_BODY_BEGIN,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_INITIALIZER_LIST,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_LIST_DELIMITER,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_BODY_END,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_initializer = {
  .type                 = GR_ELEM_INITIALIZER,
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
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_BRACED_INITIALIZER,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_initializer_list = {
  .type                 = GR_ELEM_INITIALIZER_LIST,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DESIGNATION,
          .is_mandatory = 0u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_INITIALIZER,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 4u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_INITIALIZER_LIST,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_LIST_DELIMITER,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_DESIGNATION,
          .is_mandatory = 0u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_INITIALIZER,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_designation = {
  .type                 = GR_ELEM_DESIGNATION,
  .no_rules             = 1u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DESIGNATOR_LIST,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_OPERATOR_ASSIGNMENT_BASIC,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_designator_list = {
  .type                 = GR_ELEM_DESIGNATOR_LIST,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DESIGNATOR,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DESIGNATOR_LIST,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_DESIGNATOR,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_designator = {
  .type                 = GR_ELEM_DESIGNATOR,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DESIGNATOR_ARRAY_ELEM_BEGIN,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_CONSTANT_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_DESIGNATOR_ARRAY_ELEM_END,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DESIGNATOR_STRUCT_OR_UNION_MEMBER,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_IDENTIFIER,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_static_assert_declaration = {
  .type                 = GR_ELEM_STATIC_ASSERT_DECLARATION,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 7u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_STATIC_ASSERT,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_OPEN,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_CONSTANT_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_LIST_DELIMITER,
          .is_mandatory = 1u
        },
        [ 4u ]          = {
          .type         = GR_ELEM_STRING_CONSTANT,
          .is_mandatory = 1u
        },
        [ 5u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_CLOSED,
          .is_mandatory = 1u
        },
        [ 6u ]          = {
          .type         = GR_ELEM_SEPARATOR_SEMICOLON,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 5u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_STATIC_ASSERT,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_OPEN,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_CONSTANT_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_CLOSED,
          .is_mandatory = 1u
        },
        [ 4u ]          = {
          .type         = GR_ELEM_SEPARATOR_SEMICOLON,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_attribute_specifier_sequence = {
  .type                 = GR_ELEM_ATTRIBUTE_SPECIFIER_SEQUENCE,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ATTRIBUTE_SPECIFIER,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ATTRIBUTE_SPECIFIER_SEQUENCE,
          .is_mandatory = 0u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_ATTRIBUTE_SPECIFIER,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_attribute_specifier = {
  .type                 = GR_ELEM_ATTRIBUTE_SPECIFIER,
  .no_rules             = 1u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ATTRIBUTE_DELIMITER_BEGIN,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_ATTRIBUTE_LIST,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_ATTRIBUTE_DELIMITER_END,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_attribute_list = {
  .type                 = GR_ELEM_ATTRIBUTE_LIST,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ATTRIBUTE,
          .is_mandatory = 0u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ATTRIBUTE_LIST,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_LIST_DELIMITER,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_ATTRIBUTE,
          .is_mandatory = 0u
        }
      }
    }
  }
};

gr_t gr_elem_attribute = {
  .type                 = GR_ELEM_ATTRIBUTE,
  .no_rules             = 1u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ATTRIBUTE_TOKEN,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_ATTRIBUTE_ARGUMENT_CLAUSE,
          .is_mandatory = 0u
        }
      }
    }
  }
};

gr_t gr_elem_attribute_token = {
  .type                 = GR_ELEM_ATTRIBUTE_TOKEN,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_STANDARD_ATTRIBUTE,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ATTRIBUTE_PREFIXED_TOKEN,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_standard_attribute = {
  .type                 = GR_ELEM_STANDARD_ATTRIBUTE,
  .no_rules             = 1u,
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
    }
  }
};

gr_t gr_elem_attribute_prefixed_token = {
  .type                 = GR_ELEM_ATTRIBUTE_PREFIXED_TOKEN,
  .no_rules             = 1u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ATTRIBUTE_PREFIX,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_ATTRIBUTE_SCOPE,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_IDENTIFIER,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_attribute_prefix = {
  .type                 = GR_ELEM_ATTRIBUTE_PREFIX,
  .no_rules             = 1u,
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
    }
  }
};

gr_t gr_elem_attribute_argument_clause = {
  .type                 = GR_ELEM_ATTRIBUTE_ARGUMENT_CLAUSE,
  .no_rules             = 1u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_OPEN,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_BALANCED_TOKEN_SEQUENCE,
          .is_mandatory = 0u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_CLOSED,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_balanced_token_sequence = {
  .type                 = GR_ELEM_BALANCED_TOKEN_SEQUENCE,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_BALANCED_TOKEN,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_BALANCED_TOKEN_SEQUENCE,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_BALANCED_TOKEN,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_balanced_token = {
  .type                 = GR_ELEM_BALANCED_TOKEN,
  .no_rules             = 3u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_OPEN,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_BALANCED_TOKEN_SEQUENCE,
          .is_mandatory = 0u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_CLOSED,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_BODY_BEGIN,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_BALANCED_TOKEN_SEQUENCE,
          .is_mandatory = 0u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_BODY_END,
          .is_mandatory = 1u
        }
      }
    },
    [ 2u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_IDENTIFIER,
          .is_mandatory = 1u
        }
      }
    }
  }
};
