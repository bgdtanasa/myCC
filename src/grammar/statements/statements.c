#include "statements.h"

gr_t gr_elem_statement = {
  .type                 = GR_ELEM_STATEMENT,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_LABELED_STATEMENT,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_UNLABELED_STATEMENT,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_unlabeled_statement = {
  .type                 = GR_ELEM_UNLABELED_STATEMENT,
  .no_rules             = 3u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_EXPRESSION_STATEMENT,
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
          .type         = GR_ELEM_PRIMARY_BLOCK,
          .is_mandatory = 1u
        }
      }
    },
    [ 2u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ATTRIBUTE_SPECIFIER_SEQUENCE,
          .is_mandatory = 0u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_JUMP_STATEMENT,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_primary_block = {
  .type                 = GR_ELEM_PRIMARY_BLOCK,
  .no_rules             = 3u,
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
    },
    [ 1u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_SELECTION_STATEMENT,
          .is_mandatory = 1u
        }
      }
    },
    [ 2u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ITERATION_STATEMENT,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_secondary_block = {
  .type                 = GR_ELEM_SECONDARY_BLOCK,
  .no_rules             = 1u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_STATEMENT,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_label= {
  .type                 = GR_ELEM_LABEL,
  .no_rules             = 3u,
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
          .type         = GR_ELEM_IDENTIFIER,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_SEPARATOR_COLON,
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
          .is_mandatory = 0u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_KEYWORD_CASE,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_CONSTANT_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_SEPARATOR_COLON,
          .is_mandatory = 1u
        }
      }
    },
    [ 2u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ATTRIBUTE_SPECIFIER_SEQUENCE,
          .is_mandatory = 0u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_KEYWORD_DEFAULT,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_SEPARATOR_COLON,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_labeled_statement = {
  .type                 = GR_ELEM_LABELED_STATEMENT,
  .no_rules             = 1u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_LABEL,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_STATEMENT,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_compound_statement = {
  .type                 = GR_ELEM_COMPOUND_STATEMENT,
  .no_rules             = 1u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_BODY_BEGIN,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_BLOCK_ITEM_LIST,
          .is_mandatory = 0u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_BODY_END,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_block_item_list = {
  .type                 = GR_ELEM_BLOCK_ITEM_LIST,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_BLOCK_ITEM,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_BLOCK_ITEM_LIST,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_BLOCK_ITEM,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_block_item = {
  .type                 = GR_ELEM_BLOCK_ITEM,
  .no_rules             = 3u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DECLARATION,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_UNLABELED_STATEMENT,
          .is_mandatory = 1u
        }
      }
    },
    [ 2u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_LABEL,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_expression_statement = {
  .type                 = GR_ELEM_EXPRESSION_STATEMENT,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_EXPRESSION,
          .is_mandatory = 0u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_SEPARATOR_SEMICOLON,
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
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_SEPARATOR_SEMICOLON,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_selection_statement = {
  .type                 = GR_ELEM_SELECTION_STATEMENT,
  .no_rules             = 3u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 5u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_IF,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_OPEN,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_CLOSED,
          .is_mandatory = 1u
        },
        [ 4u ]          = {
          .type         = GR_ELEM_SECONDARY_BLOCK,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 7u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_IF,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_OPEN,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_CLOSED,
          .is_mandatory = 1u
        },
        [ 4u ]          = {
          .type         = GR_ELEM_SECONDARY_BLOCK,
          .is_mandatory = 1u
        },
        [ 5u ]          = {
          .type         = GR_ELEM_KEYWORD_ELSE,
          .is_mandatory = 1u
        },
        [ 6u ]          = {
          .type         = GR_ELEM_SECONDARY_BLOCK,
          .is_mandatory = 1u
        }
      }
    },
    [ 2u ]              = {
      .no_elems         = 5u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_SWITCH,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_OPEN,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_CLOSED,
          .is_mandatory = 1u
        },
        [ 4u ]          = {
          .type         = GR_ELEM_SECONDARY_BLOCK,
          .is_mandatory = 1u
        }
      }
    },
  }
};

gr_t gr_elem_iteration_statement = {
  .type                 = GR_ELEM_ITERATION_STATEMENT,
  .no_rules             = 4u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 5u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_WHILE,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_OPEN,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_EXPRESSION,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_CLOSED,
          .is_mandatory = 1u
        },
        [ 4u ]          = {
          .type         = GR_ELEM_SECONDARY_BLOCK,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 7u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_DO,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_SECONDARY_BLOCK,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_KEYWORD_WHILE,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_OPEN,
          .is_mandatory = 1u
        },
        [ 4u ]          = {
          .type         = GR_ELEM_EXPRESSION,
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
    [ 2u ]              = {
      .no_elems         = 9u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_FOR,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_OPEN,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_EXPRESSION,
          .is_mandatory = 0u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_SEPARATOR_SEMICOLON,
          .is_mandatory = 1u
        },
        [ 4u ]          = {
          .type         = GR_ELEM_EXPRESSION,
          .is_mandatory = 0u
        },
        [ 5u ]          = {
          .type         = GR_ELEM_SEPARATOR_SEMICOLON,
          .is_mandatory = 1u
        },
        [ 6u ]          = {
          .type         = GR_ELEM_EXPRESSION,
          .is_mandatory = 0u
        },
        [ 7u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_CLOSED,
          .is_mandatory = 1u
        },
        [ 8u ]          = {
          .type         = GR_ELEM_SECONDARY_BLOCK,
          .is_mandatory = 1u
        }
      }
    },
    [ 3u ]              = {
      .no_elems         = 8u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_FOR,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_OPEN,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_DECLARATION,
          .is_mandatory = 0u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_EXPRESSION,
          .is_mandatory = 0u
        },
        [ 4u ]          = {
          .type         = GR_ELEM_SEPARATOR_SEMICOLON,
          .is_mandatory = 1u
        },
        [ 5u ]          = {
          .type         = GR_ELEM_EXPRESSION,
          .is_mandatory = 0u
        },
        [ 6u ]          = {
          .type         = GR_ELEM_SEPARATOR_BRACKET_ROUND_CLOSED,
          .is_mandatory = 1u
        },
        [ 7u ]          = {
          .type         = GR_ELEM_SECONDARY_BLOCK,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_jump_statement = {
  .type                 = GR_ELEM_JUMP_STATEMENT,
  .no_rules             = 4u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_GOTO,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_IDENTIFIER,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_SEPARATOR_SEMICOLON,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_CONTINUE,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_SEPARATOR_SEMICOLON,
          .is_mandatory = 1u
        }
      }
    },
    [ 2u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_BREAK,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_SEPARATOR_SEMICOLON,
          .is_mandatory = 1u
        }
      }
    },
    [ 3u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_RETURN,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_EXPRESSION,
          .is_mandatory = 0u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_SEPARATOR_SEMICOLON,
          .is_mandatory = 1u
        }
      }
    }
  }
};

