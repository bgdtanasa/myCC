#include "constants.h"

gr_t gr_elem_digit = {
  .type                 = GR_ELEM_DIGIT,
  .no_rules             = 10u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_0,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_1,
          .is_mandatory = 1u
        }
      }
    },
    [ 2u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_2,
          .is_mandatory = 1u
        }
      }
    },
    [ 3u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_3,
          .is_mandatory = 1u
        }
      }
    },
    [ 4u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_4,
          .is_mandatory = 1u
        }
      }
    },
    [ 5u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_5,
          .is_mandatory = 1u
        }
      }
    },
    [ 6u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_6,
          .is_mandatory = 1u
        }
      }
    },
    [ 7u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_7,
          .is_mandatory = 1u
        }
      }
    },
    [ 8u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_8,
          .is_mandatory = 1u
        }
      }
    },
    [ 9u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_9,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_non_zero_digit = {
  .type                 = GR_ELEM_NON_ZERO_DIGIT,
  .no_rules             = 9u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_1,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_2,
          .is_mandatory = 1u
        }
      }
    },
    [ 2u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_3,
          .is_mandatory = 1u
        }
      }
    },
    [ 3u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_4,
          .is_mandatory = 1u
        }
      }
    },
    [ 4u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_5,
          .is_mandatory = 1u
        }
      }
    },
    [ 5u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_6,
          .is_mandatory = 1u
        }
      }
    },
    [ 6u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_7,
          .is_mandatory = 1u
        }
      }
    },
    [ 7u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_8,
          .is_mandatory = 1u
        }
      }
    },
    [ 8u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_9,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_octal_digit = {
  .type                 = GR_ELEM_OCTAL_DIGIT,
  .no_rules             = 8u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_0,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_1,
          .is_mandatory = 1u
        }
      }
    },
    [ 2u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_2,
          .is_mandatory = 1u
        }
      }
    },
    [ 3u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_3,
          .is_mandatory = 1u
        }
      }
    },
    [ 4u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_4,
          .is_mandatory = 1u
        }
      }
    },
    [ 5u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_5,
          .is_mandatory = 1u
        }
      }
    },
    [ 6u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_6,
          .is_mandatory = 1u
        }
      }
    },
    [ 7u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_7,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_hexadecimal_digit = {
  .type                 = GR_ELEM_HEXADECIMAL_DIGIT,
  .no_rules             = 22u,
  .rule_idx             = 0u,
  .rules                = {
    [  0u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_0,
          .is_mandatory = 1u
        }
      }
    },
    [  1u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_1,
          .is_mandatory = 1u
        }
      }
    },
    [  2u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_2,
          .is_mandatory = 1u
        }
      }
    },
    [  3u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_3,
          .is_mandatory = 1u
        }
      }
    },
    [  4u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_4,
          .is_mandatory = 1u
        }
      }
    },
    [  5u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_5,
          .is_mandatory = 1u
        }
      }
    },
    [  6u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_6,
          .is_mandatory = 1u
        }
      }
    },
    [  7u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_7,
          .is_mandatory = 1u
        }
      }
    },
    [  8u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_8,
          .is_mandatory = 1u
        }
      }
    },
    [  9u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_9,
          .is_mandatory = 1u
        }
      }
    },
    [ 10u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_a,
          .is_mandatory = 1u
        }
      }
    },
    [ 11u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_b,
          .is_mandatory = 1u
        }
      }
    },
    [ 12u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_c,
          .is_mandatory = 1u
        }
      }
    },
    [ 13u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_d,
          .is_mandatory = 1u
        }
      }
    },
    [ 14u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_e,
          .is_mandatory = 1u
        }
      }
    },
    [ 15u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_f,
          .is_mandatory = 1u
        }
      }
    },
    [ 16u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_A,
          .is_mandatory = 1u
        }
      }
    },
    [ 17u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_B,
          .is_mandatory = 1u
        }
      }
    },
    [ 18u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_C,
          .is_mandatory = 1u
        }
      }
    },
    [ 19u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_D,
          .is_mandatory = 1u
        }
      }
    },
    [ 20u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_E,
          .is_mandatory = 1u
        }
      }
    },
    [ 21u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_F,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_binary_digit = {
  .type                 = GR_ELEM_BINARY_DIGIT,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_0,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_1,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_digit_sequence = {
  .type                 = GR_ELEM_DIGIT_SEQUENCE,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_SEQUENCE,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_SEPARATOR_APOSTROPHE,
          .is_mandatory = 0u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_DIGIT,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_hexadecimal_digit_sequence = {
  .type                 = GR_ELEM_HEXADECIMAL_DIGIT_SEQUENCE,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_HEXADECIMAL_DIGIT,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_HEXADECIMAL_DIGIT_SEQUENCE,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_SEPARATOR_APOSTROPHE,
          .is_mandatory = 0u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_HEXADECIMAL_DIGIT,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_c_char = {
  .type                 = GR_ELEM_C_CHAR,
  .no_rules             = 63u,
  .rule_idx             = 0u,
  .rules                = {
    [  0u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_a,
          .is_mandatory = 1u
        }
      }
    },
    [  1u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_b,
          .is_mandatory = 1u
        }
      }
    },
    [  2u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_c,
          .is_mandatory = 1u
        }
      }
    },
    [  3u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_d,
          .is_mandatory = 1u
        }
      }
    },
    [  4u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_e,
          .is_mandatory = 1u
        }
      }
    },
    [  5u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_f,
          .is_mandatory = 1u
        }
      }
    },
    [  6u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_g,
          .is_mandatory = 1u
        }
      }
    },
    [  7u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_h,
          .is_mandatory = 1u
        }
      }
    },
    [  8u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_i,
          .is_mandatory = 1u
        }
      }
    },
    [  9u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_j,
          .is_mandatory = 1u
        }
      }
    },
    [ 10u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_k,
          .is_mandatory = 1u
        }
      }
    },
    [ 11u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_l,
          .is_mandatory = 1u
        }
      }
    },
    [ 12u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_m,
          .is_mandatory = 1u
        }
      }
    },
    [ 13u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_n,
          .is_mandatory = 1u
        }
      }
    },
    [ 14u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_o,
          .is_mandatory = 1u
        }
      }
    },
    [ 15u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_p,
          .is_mandatory = 1u
        }
      }
    },
    [ 16u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_q,
          .is_mandatory = 1u
        }
      }
    },
    [ 17u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_r,
          .is_mandatory = 1u
        }
      }
    },
    [ 18u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_s,
          .is_mandatory = 1u
        }
      }
    },
    [ 19u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_t,
          .is_mandatory = 1u
        }
      }
    },
    [ 20u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_u,
          .is_mandatory = 1u
        }
      }
    },
    [ 21u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_v,
          .is_mandatory = 1u
        }
      }
    },
    [ 22u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_w,
          .is_mandatory = 1u
        }
      }
    },
    [ 23u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_x,
          .is_mandatory = 1u
        }
      }
    },
    [ 24u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_y,
          .is_mandatory = 1u
        }
      }
    },
    [ 25u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_z,
          .is_mandatory = 1u
        }
      }
    },
    [ 26u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_A,
          .is_mandatory = 1u
        }
      }
    },
    [ 27u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_B,
          .is_mandatory = 1u
        }
      }
    },
    [ 28u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_C,
          .is_mandatory = 1u
        }
      }
    },
    [ 29u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_D,
          .is_mandatory = 1u
        }
      }
    },
    [ 30u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_E,
          .is_mandatory = 1u
        }
      }
    },
    [ 31u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_F,
          .is_mandatory = 1u
        }
      }
    },
    [ 32u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_G,
          .is_mandatory = 1u
        }
      }
    },
    [ 33u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_H,
          .is_mandatory = 1u
        }
      }
    },
    [ 34u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_I,
          .is_mandatory = 1u
        }
      }
    },
    [ 35u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_J,
          .is_mandatory = 1u
        }
      }
    },
    [ 36u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_K,
          .is_mandatory = 1u
        }
      }
    },
    [ 37u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_L,
          .is_mandatory = 1u
        }
      }
    },
    [ 38u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_M,
          .is_mandatory = 1u
        }
      }
    },
    [ 39u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_N,
          .is_mandatory = 1u
        }
      }
    },
    [ 40u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_O,
          .is_mandatory = 1u
        }
      }
    },
    [ 41u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_P,
          .is_mandatory = 1u
        }
      }
    },
    [ 42u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_Q,
          .is_mandatory = 1u
        }
      }
    },
    [ 43u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_R,
          .is_mandatory = 1u
        }
      }
    },
    [ 44u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_S,
          .is_mandatory = 1u
        }
      }
    },
    [ 45u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_T,
          .is_mandatory = 1u
        }
      }
    },
    [ 46u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_U,
          .is_mandatory = 1u
        }
      }
    },
    [ 47u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_V,
          .is_mandatory = 1u
        }
      }
    },
    [ 48u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_W,
          .is_mandatory = 1u
        }
      }
    },
    [ 49u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_X,
          .is_mandatory = 1u
        }
      }
    },
    [ 50u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_Y,
          .is_mandatory = 1u
        }
      }
    },
    [ 51u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_Z,
          .is_mandatory = 1u
        }
      }
    },
    [ 52u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_0,
          .is_mandatory = 1u
        }
      }
    },
    [ 53u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_1,
          .is_mandatory = 1u
        }
      }
    },
    [ 54u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_2,
          .is_mandatory = 1u
        }
      }
    },
    [ 55u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_3,
          .is_mandatory = 1u
        }
      }
    },
    [ 56u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_4,
          .is_mandatory = 1u
        }
      }
    },
    [ 57u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_5,
          .is_mandatory = 1u
        }
      }
    },
    [ 58u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_6,
          .is_mandatory = 1u
        }
      }
    },
    [ 59u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_7,
          .is_mandatory = 1u
        }
      }
    },
    [ 60u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_8,
          .is_mandatory = 1u
        }
      }
    },
    [ 61u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_9,
          .is_mandatory = 1u
        }
      }
    },
    [ 62u ]             = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ESCAPE_SEQUENCE,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_c_char_sequence = {
  .type                 = GR_ELEM_C_CHAR_SEQUENCE,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_C_CHAR,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_C_CHAR_SEQUENCE,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_C_CHAR,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_escape_sequence = {
  .type                 = GR_ELEM_ESCAPE_SEQUENCE,
  .no_rules             = 3u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_SIMPLE_ESCAPE_SEQUENCE,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_OCTAL_ESCAPE_SEQUENCE,
          .is_mandatory = 1u
        }
      }
    },
    [ 2u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_HEXADECIMAL_ESCAPE_SEQUENCE,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_simple_escape_sequence = {
  .type                 = GR_ELEM_SIMPLE_ESCAPE_SEQUENCE,
  .no_rules             = 10u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ESCAPE_a,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ESCAPE_b,
          .is_mandatory = 1u
        }
      }
    },
    [ 2u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ESCAPE_f,
          .is_mandatory = 1u
        }
      }
    },
    [ 3u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ESCAPE_n,
          .is_mandatory = 1u
        }
      }
    },
    [ 4u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ESCAPE_r,
          .is_mandatory = 1u
        }
      }
    },
    [ 5u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ESCAPE_t,
          .is_mandatory = 1u
        }
      }
    },
    [ 6u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ESCAPE_v,
          .is_mandatory = 1u
        }
      }
    },
    [ 7u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ESCAPE_QUOTE,
          .is_mandatory = 1u
        }
      }
    },
    [ 8u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ESCAPE_APOSTROPHE,
          .is_mandatory = 1u
        }
      }
    },
    [ 9u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ESCAPE_BACKSLASH,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_octal_escape_sequence = {
  .type                 = GR_ELEM_OCTAL_ESCAPE_SEQUENCE,
  .no_rules             = 3u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_SEPARATOR_BACKSLASH,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_OCTAL_DIGIT,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_SEPARATOR_BACKSLASH,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_OCTAL_DIGIT,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_OCTAL_DIGIT,
          .is_mandatory = 1u
        }
      }
    },
    [ 2u ]              = {
      .no_elems         = 4u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_SEPARATOR_BACKSLASH,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_OCTAL_DIGIT,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_OCTAL_DIGIT,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_OCTAL_DIGIT,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_hexadecimal_escape_sequence = {
  .type                 = GR_ELEM_HEXADECIMAL_ESCAPE_SEQUENCE,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_SEPARATOR_BACKSLASH,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_NON_DIGIT_x,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_HEXADECIMAL_DIGIT,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_HEXADECIMAL_ESCAPE_SEQUENCE,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_HEXADECIMAL_DIGIT,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_constant = {
  .type                 = GR_ELEM_CONSTANT,
  .no_rules             = 5u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_INTEGER_CONSTANT,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_FLOATING_CONSTANT,
          .is_mandatory = 1u
        }
      }
    },
    [ 2u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ENUMERATION_CONSTANT,
          .is_mandatory = 1u
        }
      }
    },
    [ 3u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_CHARACTER_CONSTANT,
          .is_mandatory = 1u
        }
      }
    },
    [ 4u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_PREDEFINED_CONSTANT,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_integer_constant = {
  .type                 = GR_ELEM_INTEGER_CONSTANT,
  .no_rules             = 4u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DECIMAL_CONSTANT,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_INTEGER_SUFFIX,
          .is_mandatory = 0u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_OCTAL_CONSTANT,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_INTEGER_SUFFIX,
          .is_mandatory = 0u
        }
      }
    },
    [ 2u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_HEXADECIMAL_CONSTANT,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_INTEGER_SUFFIX,
          .is_mandatory = 0u
        }
      }
    },
    [ 3u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_BINARY_CONSTANT,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_INTEGER_SUFFIX,
          .is_mandatory = 0u
        }
      }
    }
  }
};

gr_t gr_elem_decimal_constant = {
  .type                 = GR_ELEM_DECIMAL_CONSTANT,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_ZERO_DIGIT,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DECIMAL_CONSTANT,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_SEPARATOR_APOSTROPHE,
          .is_mandatory = 0u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_DIGIT,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_octal_constant = {
  .type                 = GR_ELEM_OCTAL_CONSTANT,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_0,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_OCTAL_CONSTANT,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_SEPARATOR_APOSTROPHE,
          .is_mandatory = 0u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_OCTAL_DIGIT,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_hexadecimal_constant = {
  .type                 = GR_ELEM_HEXADECIMAL_CONSTANT,
  .no_rules             = 1u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_HEXADECIMAL_PREFIX,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_HEXADECIMAL_DIGIT_SEQUENCE,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_binary_constant = {
  .type                 = GR_ELEM_BINARY_CONSTANT,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_BINARY_PREFIX,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_BINARY_DIGIT,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_BINARY_CONSTANT,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_SEPARATOR_APOSTROPHE,
          .is_mandatory = 0u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_BINARY_DIGIT,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_hexadecimal_prefix = {
  .type                 = GR_ELEM_HEXADECIMAL_PREFIX,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_0,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_NON_DIGIT_x,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_0,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_NON_DIGIT_X,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_binary_prefix = {
  .type                 = GR_ELEM_BINARY_PREFIX,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_0,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_NON_DIGIT_b,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_0,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_NON_DIGIT_B,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_integer_suffix = {
  .type                 = GR_ELEM_INTEGER_SUFFIX,
  .no_rules             = 6u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_UNSIGNED_SUFFIX,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_LONG_SUFFIX,
          .is_mandatory = 0u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_UNSIGNED_SUFFIX,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_LONG_SUFFIX,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_LONG_SUFFIX,
          .is_mandatory = 1u
        }
      }
    },
    [ 2u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_UNSIGNED_SUFFIX,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_BIT_PRECISE_INT_SUFFIX,
          .is_mandatory = 1u
        }
      }
    },
    [ 3u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_LONG_SUFFIX,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_UNSIGNED_SUFFIX,
          .is_mandatory = 0u
        }
      }
    },
    [ 4u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_LONG_SUFFIX,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_LONG_SUFFIX,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_UNSIGNED_SUFFIX,
          .is_mandatory = 0u
        }
      }
    },
    [ 5u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_BIT_PRECISE_INT_SUFFIX,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_UNSIGNED_SUFFIX,
          .is_mandatory = 0u
        }
      }
    }
  }
};

gr_t gr_elem_bit_precise_int_suffix = {
  .type                 = GR_ELEM_BIT_PRECISE_INT_SUFFIX,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_w,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_NON_DIGIT_b,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_W,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_NON_DIGIT_B,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_unsigned_suffix = {
  .type                 = GR_ELEM_UNSIGNED_SUFFIX,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_u,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_U,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_long_suffix = {
  .type                 = GR_ELEM_LONG_SUFFIX,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_l,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_L,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_long_long_suffix = {
  .type                 = GR_ELEM_LONG_LONG_SUFFIX,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_l,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_NON_DIGIT_l,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_L,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_NON_DIGIT_L,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_floating_constant = {
  .type                 = GR_ELEM_FLOATING_CONSTANT,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DECIMAL_FLOATING_CONSTANT,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_HEXADECIMAL_FLOATING_CONSTANT,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_decimal_floating_constant = {
  .type                 = GR_ELEM_DECIMAL_FLOATING_CONSTANT,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_FRACTIONAL_CONSTANT,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_EXPONENT_PART,
          .is_mandatory = 0u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_FLOATING_SUFFIX,
          .is_mandatory = 0u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_SEQUENCE,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_EXPONENT_PART,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_FLOATING_SUFFIX,
          .is_mandatory = 0u
        }
      }
    }
  }
};

gr_t gr_elem_hexadecimal_floating_constant = {
  .type                 = GR_ELEM_HEXADECIMAL_FLOATING_CONSTANT,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 4u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_HEXADECIMAL_PREFIX,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_HEXADECIMAL_FRACTIONAL_CONSTANT,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_BINARY_EXPONENT_PART,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_FLOATING_SUFFIX,
          .is_mandatory = 0u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 4u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_HEXADECIMAL_PREFIX,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_HEXADECIMAL_DIGIT_SEQUENCE,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_BINARY_EXPONENT_PART,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_FLOATING_SUFFIX,
          .is_mandatory = 0u
        }
      }
    }
  }
};

gr_t gr_elem_fractional_constant = {
  .type                 = GR_ELEM_FRACTIONAL_CONSTANT,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_SEQUENCE,
          .is_mandatory = 0u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_SEPARATOR_PERIOD,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_DIGIT_SEQUENCE,
          .is_mandatory = 0u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_DIGIT_SEQUENCE,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_SEPARATOR_PERIOD,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_exponent_part = {
  .type                 = GR_ELEM_EXPONENT_PART,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_e,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_SIGN,
          .is_mandatory = 0u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_DIGIT_SEQUENCE,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_E,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_SIGN,
          .is_mandatory = 0u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_DIGIT_SEQUENCE,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_sign = {
  .type                 = GR_ELEM_SIGN,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_SEPARATOR_PLUS,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_SEPARATOR_MINUS,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_hexadecimal_fractional_constant = {
  .type                 = GR_ELEM_HEXADECIMAL_FRACTIONAL_CONSTANT,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_HEXADECIMAL_DIGIT_SEQUENCE,
          .is_mandatory = 0u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_SEPARATOR_PERIOD,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_HEXADECIMAL_DIGIT_SEQUENCE,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_HEXADECIMAL_DIGIT_SEQUENCE,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_SEPARATOR_PERIOD,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_binary_exponent_part = {
  .type                 = GR_ELEM_BINARY_EXPONENT_PART,
  .no_rules             = 2u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_p,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_SIGN,
          .is_mandatory = 0u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_DIGIT_SEQUENCE,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 3u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_P,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_SIGN,
          .is_mandatory = 0u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_DIGIT_SEQUENCE,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_floating_suffix = {
  .type                 = GR_ELEM_FLOATING_SUFFIX,
  .no_rules             = 10u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_f,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_l,
          .is_mandatory = 1u
        }
      }
    },
    [ 2u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_F,
          .is_mandatory = 1u
        }
      }
    },
    [ 3u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_L,
          .is_mandatory = 1u
        }
      }
    },
    [ 4u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_d,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_NON_DIGIT_f,
          .is_mandatory = 1u
        }
      }
    },
    [ 5u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_d,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_NON_DIGIT_d,
          .is_mandatory = 1u
        }
      }
    },
    [ 6u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_d,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_NON_DIGIT_l,
          .is_mandatory = 1u
        }
      }
    },
    [ 7u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_D,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_NON_DIGIT_F,
          .is_mandatory = 1u
        }
      }
    },
    [ 8u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_D,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_NON_DIGIT_D,
          .is_mandatory = 1u
        }
      }
    },
    [ 9u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_D,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_NON_DIGIT_L,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_enumeration_constant = {
  .type                 = GR_ELEM_ENUMERATION_CONSTANT,
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

gr_t gr_elem_character_constant = {
  .type                 = GR_ELEM_CHARACTER_CONSTANT,
  .no_rules             = 1u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 4u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ENCODING_PREFIX,
          .is_mandatory = 0u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_SEPARATOR_APOSTROPHE,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_C_CHAR_SEQUENCE,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_SEPARATOR_APOSTROPHE,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_encoding_prefix = {
  .type                 = GR_ELEM_ENCODING_PREFIX,
  .no_rules             = 4u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 2u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_u,
          .is_mandatory = 1u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_DIGIT_8,
          .is_mandatory = 0u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_u,
          .is_mandatory = 1u
        }
      }
    },
    [ 2u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_U,
          .is_mandatory = 1u
        }
      }
    },
    [ 3u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_L,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_predefined_constant = {
  .type                 = GR_ELEM_PREDEFINED_CONSTANT,
  .no_rules             = 3u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_FALSE,
          .is_mandatory = 1u
        }
      }
    },
    [ 1u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_TRUE,
          .is_mandatory = 1u
        }
      }
    },
    [ 2u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_KEYWORD_NULLPTR,
          .is_mandatory = 1u
        }
      }
    },
    [ 3u ]              = {
      .no_elems         = 1u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_NON_DIGIT_L,
          .is_mandatory = 1u
        }
      }
    }
  }
};

gr_t gr_elem_string_constant = {
  .type                 = GR_ELEM_STRING_CONSTANT,
  .no_rules             = 1u,
  .rule_idx             = 0u,
  .rules                = {
    [ 0u ]              = {
      .no_elems         = 4u,
      .elem_idx         = 0u,
      .elems            = {
        [ 0u ]          = {
          .type         = GR_ELEM_ENCODING_PREFIX,
          .is_mandatory = 0u
        },
        [ 1u ]          = {
          .type         = GR_ELEM_SEPARATOR_QUOTE,
          .is_mandatory = 1u
        },
        [ 2u ]          = {
          .type         = GR_ELEM_C_CHAR_SEQUENCE,
          .is_mandatory = 1u
        },
        [ 3u ]          = {
          .type         = GR_ELEM_SEPARATOR_QUOTE,
          .is_mandatory = 1u
        }
      }
    }
  }
};
