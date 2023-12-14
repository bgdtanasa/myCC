#include "gr.h"

#include "constants.h"
#include "expressions.h"
#include "declarations.h"
#include "statements.h"
#include "external_definitions.h"

gr_elem_info_t gr_elem_info[ GR_ELEM_MAX_NO_ELEMS ]        = {
  [ GR_ELEM_INVALID ]                                      = {
    .name                                                  = "invalid",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_INVALID
    }
  },

  // Simple gr_elems that translate directly into one token
  [ GR_ELEM_NON_DIGIT_a ]                                  = {
    .name                                                  = "a",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_a
    }
  },
  [ GR_ELEM_NON_DIGIT_b ]                                  = {
    .name                                                  = "b",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_b
    }
  },
  [ GR_ELEM_NON_DIGIT_c ]                                  = {
    .name                                                  = "c",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_c
    }
  },
  [ GR_ELEM_NON_DIGIT_d ]                                  = {
    .name                                                  = "d",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_d
    }
  },
  [ GR_ELEM_NON_DIGIT_e ]                                  = {
    .name                                                  = "e",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_e
    }
  },
  [ GR_ELEM_NON_DIGIT_f ]                                  = {
    .name                                                  = "f",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_f
    }
  },
  [ GR_ELEM_NON_DIGIT_g ]                                  = {
    .name                                                  = "g",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_g
    }
  },
  [ GR_ELEM_NON_DIGIT_h ]                                  = {
    .name                                                  = "h",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_h
    }
  },
  [ GR_ELEM_NON_DIGIT_i ]                                  = {
    .name                                                  = "i",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_i
    }
  },
  [ GR_ELEM_NON_DIGIT_j ]                                  = {
    .name                                                  = "j",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_j
    }
  },
  [ GR_ELEM_NON_DIGIT_k ]                                  = {
    .name                                                  = "k",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_k
    }
  },
  [ GR_ELEM_NON_DIGIT_l ]                                  = {
    .name                                                  = "l",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_l
    }
  },
  [ GR_ELEM_NON_DIGIT_m ]                                  = {
    .name                                                  = "m",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_m
    }
  },
  [ GR_ELEM_NON_DIGIT_n ]                                  = {
    .name                                                  = "n",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_n
    }
  },
  [ GR_ELEM_NON_DIGIT_o ]                                  = {
    .name                                                  = "o",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_o
    }
  },
  [ GR_ELEM_NON_DIGIT_p ]                                  = {
    .name                                                  = "p",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_p
    }
  },
  [ GR_ELEM_NON_DIGIT_q ]                                  = {
    .name                                                  = "q",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_q
    }
  },
  [ GR_ELEM_NON_DIGIT_r ]                                  = {
    .name                                                  = "r",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_r
    }
  },
  [ GR_ELEM_NON_DIGIT_s ]                                  = {
    .name                                                  = "s",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_s
    }
  },
  [ GR_ELEM_NON_DIGIT_t ]                                  = {
    .name                                                  = "t",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_t
    }
  },
  [ GR_ELEM_NON_DIGIT_u ]                                  = {
    .name                                                  = "u",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_u
    }
  },
  [ GR_ELEM_NON_DIGIT_v ]                                  = {
    .name                                                  = "v",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_v
    }
  },
  [ GR_ELEM_NON_DIGIT_w ]                                  = {
    .name                                                  = "w",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_w
    }
  },
  [ GR_ELEM_NON_DIGIT_x ]                                  = {
    .name                                                  = "x",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_x
    }
  },
  [ GR_ELEM_NON_DIGIT_y ]                                  = {
    .name                                                  = "y",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_y
    }
  },
  [ GR_ELEM_NON_DIGIT_z ]                                  = {
    .name                                                  = "z",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_z
    }
  },
  [ GR_ELEM_NON_DIGIT_A ]                                  = {
    .name                                                  = "A",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_A
    }
  },
  [ GR_ELEM_NON_DIGIT_B ]                                  = {
    .name                                                  = "B",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_B
    }
  },
  [ GR_ELEM_NON_DIGIT_C ]                                  = {
    .name                                                  = "C",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_C
    }
  },
  [ GR_ELEM_NON_DIGIT_D ]                                  = {
    .name                                                  = "D",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_D
    }
  },
  [ GR_ELEM_NON_DIGIT_E ]                                  = {
    .name                                                  = "E",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_E
    }
  },
  [ GR_ELEM_NON_DIGIT_F ]                                  = {
    .name                                                  = "F",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_F
    }
  },
  [ GR_ELEM_NON_DIGIT_G ]                                  = {
    .name                                                  = "G",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_G
    }
  },
  [ GR_ELEM_NON_DIGIT_H ]                                  = {
    .name                                                  = "H",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_H
    }
  },
  [ GR_ELEM_NON_DIGIT_I ]                                  = {
    .name                                                  = "I",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_I
    }
  },
  [ GR_ELEM_NON_DIGIT_J ]                                  = {
    .name                                                  = "J",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_J
    }
  },
  [ GR_ELEM_NON_DIGIT_K ]                                  = {
    .name                                                  = "K",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_K
    }
  },
  [ GR_ELEM_NON_DIGIT_L ]                                  = {
    .name                                                  = "L",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_L
    }
  },
  [ GR_ELEM_NON_DIGIT_M ]                                  = {
    .name                                                  = "M",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_M
    }
  },
  [ GR_ELEM_NON_DIGIT_N ]                                  = {
    .name                                                  = "N",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_N
    }
  },
  [ GR_ELEM_NON_DIGIT_O ]                                  = {
    .name                                                  = "O",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_O
    }
  },
  [ GR_ELEM_NON_DIGIT_P ]                                  = {
    .name                                                  = "P",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_P
    }
  },
  [ GR_ELEM_NON_DIGIT_Q ]                                  = {
    .name                                                  = "Q",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_Q
    }
  },
  [ GR_ELEM_NON_DIGIT_R ]                                  = {
    .name                                                  = "R",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_R
    }
  },
  [ GR_ELEM_NON_DIGIT_S ]                                  = {
    .name                                                  = "S",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_S
    }
  },
  [ GR_ELEM_NON_DIGIT_T ]                                  = {
    .name                                                  = "T",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_T
    }
  },
  [ GR_ELEM_NON_DIGIT_U ]                                  = {
    .name                                                  = "U",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_U
    }
  },
  [ GR_ELEM_NON_DIGIT_V ]                                  = {
    .name                                                  = "V",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_V
    }
  },
  [ GR_ELEM_NON_DIGIT_W ]                                  = {
    .name                                                  = "W",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_W
    }
  },
  [ GR_ELEM_NON_DIGIT_X ]                                  = {
    .name                                                  = "X",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_X
    }
  },
  [ GR_ELEM_NON_DIGIT_Y ]                                  = {
    .name                                                  = "Y",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_Y
    }
  },
  [ GR_ELEM_NON_DIGIT_Z ]                                  = {
    .name                                                  = "Z",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_NON_DIGIT_Z
    }
  },
  [ GR_ELEM_DIGIT_0 ]                                      = {
    .name                                                  = "0",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_DIGIT_0
    }
  },
  [ GR_ELEM_DIGIT_1 ]                                      = {
    .name                                                  = "1",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_DIGIT_1
    }
  },
  [ GR_ELEM_DIGIT_2 ]                                      = {
    .name                                                  = "2",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_DIGIT_2
    }
  },
  [ GR_ELEM_DIGIT_3 ]                                      = {
    .name                                                  = "3",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_DIGIT_3
    }
  },
  [ GR_ELEM_DIGIT_4 ]                                      = {
    .name                                                  = "4",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_DIGIT_4
    }
  },
  [ GR_ELEM_DIGIT_5 ]                                      = {
    .name                                                  = "5",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_DIGIT_5
    }
  },
  [ GR_ELEM_DIGIT_6 ]                                      = {
    .name                                                  = "6",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_DIGIT_6
    }
  },
  [ GR_ELEM_DIGIT_7 ]                                      = {
    .name                                                  = "7",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_DIGIT_7
    }
  },
  [ GR_ELEM_DIGIT_8 ]                                      = {
    .name                                                  = "8",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_DIGIT_8
    }
  },
  [ GR_ELEM_DIGIT_9 ]                                      = {
    .name                                                  = "9",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_DIGIT_9
    }
  },
  // Keywords
  [ GR_ELEM_KEYWORD_ALIGNAS ]                              = {
    .name                                                  = "alignas",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_ALIGNAS
    }
  },
  [ GR_ELEM_KEYWORD_ALIGNOF ]                              = {
    .name                                                  = "alignof",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_ALIGNOF
    }
  },
  [ GR_ELEM_KEYWORD_AUTO ]                                 = {
    .name                                                  = "auto",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_AUTO
    }
  },
  [ GR_ELEM_KEYWORD_BOOL ]                                 = {
    .name                                                  = "bool",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_BOOL
    }
  },
  [ GR_ELEM_KEYWORD_BREAK ]                                = {
    .name                                                  = "break",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_BREAK
    }
  },
  [ GR_ELEM_KEYWORD_CASE ]                                 = {
    .name                                                  = "case",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_CASE
    }
  },
  [ GR_ELEM_KEYWORD_CHAR ]                                 = {
    .name                                                  = "char",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_CHAR
    }
  },
  [ GR_ELEM_KEYWORD_CONST ]                                = {
    .name                                                  = "const",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_CONST
    }
  },
  [ GR_ELEM_KEYWORD_CONSTEXPR ]                            = {
    .name                                                  = "constexpr",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_CONSTEXPR
    }
  },
  [ GR_ELEM_KEYWORD_CONTINUE ]                             = {
    .name                                                  = "continue",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_CONTINUE
    }
  },
  [ GR_ELEM_KEYWORD_DEFAULT ]                              = {
    .name                                                  = "default",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_DEFAULT
    }
  },
  [ GR_ELEM_KEYWORD_DO ]                                   = {
    .name                                                  = "do",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_DO
    }
  },
  [ GR_ELEM_KEYWORD_DOUBLE ]                               = {
    .name                                                  = "double",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_DOUBLE
    }
  },
  [ GR_ELEM_KEYWORD_ELSE ]                                 = {
    .name                                                  = "else",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_ELSE
    }
  },
  [ GR_ELEM_KEYWORD_ENUM ]                                 = {
    .name                                                  = "enum",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_ENUM
    }
  },
  [ GR_ELEM_KEYWORD_EXTERN ]                               = {
    .name                                                  = "extern",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_EXTERN
    }
  },
  [ GR_ELEM_KEYWORD_FALSE ]                                = {
    .name                                                  = "false",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_FALSE
    }
  },
  [ GR_ELEM_KEYWORD_FLOAT ]                                = {
    .name                                                  = "float",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_FLOAT
    }
  },
  [ GR_ELEM_KEYWORD_FOR ]                                  = {
    .name                                                  = "for",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_FOR
    }
  },
  [ GR_ELEM_KEYWORD_GOTO ]                                 = {
    .name                                                  = "goto",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_GOTO
    }
  },
  [ GR_ELEM_KEYWORD_IF ]                                   = {
    .name                                                  = "if",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_IF
    }
  },
  [ GR_ELEM_KEYWORD_INLINE ]                               = {
    .name                                                  = "inline",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_INLINE
    }
  },
  [ GR_ELEM_KEYWORD_INT ]                                  = {
    .name                                                  = "int",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_INT
    }
  },
  [ GR_ELEM_KEYWORD_LONG ]                                 = {
    .name                                                  = "long",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_LONG
    }
  },
  [ GR_ELEM_KEYWORD_NULLPTR ]                              = {
    .name                                                  = "nullptr",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_NULLPTR
    }
  },
  [ GR_ELEM_KEYWORD_REGISTER ]                             = {
    .name                                                  = "register",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_REGISTER
    }
  },
  [ GR_ELEM_KEYWORD_RESTRICT ]                             = {
    .name                                                  = "restrict",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_RESTRICT
    }
  },
  [ GR_ELEM_KEYWORD_RETURN ]                               = {
    .name                                                  = "return",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_RETURN
    }
  },
  [ GR_ELEM_KEYWORD_SHORT ]                                = {
    .name                                                  = "short",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_SHORT
    }
  },
  [ GR_ELEM_KEYWORD_SIGNED ]                               = {
    .name                                                  = "signed",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_SIGNED
    }
  },
  [ GR_ELEM_KEYWORD_SIZEOF ]                               = {
    .name                                                  = "sizeof",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_SIZEOF
    }
  },
  [ GR_ELEM_KEYWORD_STATIC ]                               = {
    .name                                                  = "static",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_STATIC
    }
  },
  [ GR_ELEM_KEYWORD_STATIC_ASSERT ]                        = {
    .name                                                  = "static_assert",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_STATIC_ASSERT
    }
  },
  [ GR_ELEM_KEYWORD_STRUCT ]                               = {
    .name                                                  = "struct",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_STRUCT
    }
  },
  [ GR_ELEM_KEYWORD_SWITCH ]                               = {
    .name                                                  = "switch",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_SWITCH
    }
  },
  [ GR_ELEM_KEYWORD_THREAD_LOCAL ]                         = {
    .name                                                  = "thread_local",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_THREAD_LOCAL
    }
  },
  [ GR_ELEM_KEYWORD_TRUE ]                                 = {
    .name                                                  = "true",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_TRUE
    }
  },
  [ GR_ELEM_KEYWORD_TYPEDEF ]                              = {
    .name                                                  = "typedef",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_TYPEDEF
    }
  },
  [ GR_ELEM_KEYWORD_TYPEOF ]                               = {
    .name                                                  = "typeof",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_TYPEOF
    }
  },
  [ GR_ELEM_KEYWORD_TYPEOF_UNQUAL ]                        = {
    .name                                                  = "typeof_unqual",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_TYPEOF_UNQUAL
    }
  },
  [ GR_ELEM_KEYWORD_UNION ]                                = {
    .name                                                  = "union",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_UNION
    }
  },
  [ GR_ELEM_KEYWORD_UNSIGNED ]                             = {
    .name                                                  = "unsigned",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_UNSIGNED
    }
  },
  [ GR_ELEM_KEYWORD_VOID ]                                 = {
    .name                                                  = "void",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_VOID
    }
  },
  [ GR_ELEM_KEYWORD_VOLATILE ]                             = {
    .name                                                  = "volatile",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_VOLATILE
    }
  },
  [ GR_ELEM_KEYWORD_WHILE ]                                = {
    .name                                                  = "while",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_WHILE
    }
  },
  [ GR_ELEM_KEYWORD__ATOMIC ]                              = {
    .name                                                  = "_Atomic",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD__ATOMIC
    }
  },
  [ GR_ELEM_KEYWORD__BITINT ]                              = {
    .name                                                  = "_Bitint",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD__BITINT
    }
  },
  [ GR_ELEM_KEYWORD__COMPLEX ]                             = {
    .name                                                  = "_Complex",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD__COMPLEX
    }
  },
  [ GR_ELEM_KEYWORD__DECIMAL128 ]                          = {
    .name                                                  = "_Decimal128",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD__DECIMAL128
    }
  },
  [ GR_ELEM_KEYWORD__DECIMAL64 ]                           = {
    .name                                                  = "_Decimal64",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD__DECIMAL64
    }
  },
  [ GR_ELEM_KEYWORD__DECIMAL32 ]                           = {
    .name                                                  = "_Decimal32",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD__DECIMAL32
    }
  },
  [ GR_ELEM_KEYWORD__GENERIC ]                             = {
    .name                                                  = "_Generic",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD__GENERIC
    }
  },
  [ GR_ELEM_KEYWORD__IMAGINARY ]                           = {
    .name                                                  = "_Imaginary",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD__IMAGINARY
    }
  },
  [ GR_ELEM_KEYWORD__NORETURN ]                            = {
    .name                                                  = "_Noreturn",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD__NORETURN
    }
  },
  [ GR_ELEM_KEYWORD_SINT8 ]                                = {
    .name                                                  = "sint8_t",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_SINT8
    }
  },
  [ GR_ELEM_KEYWORD_UINT8 ]                                = {
    .name                                                  = "uint8_t",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_UINT8
    }
  },
  [ GR_ELEM_KEYWORD_SINT16 ]                               = {
    .name                                                  = "sint16_t",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_SINT16
    }
  },
  [ GR_ELEM_KEYWORD_UINT16 ]                               = {
    .name                                                  = "uint16_t",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_UINT16
    }
  },
  [ GR_ELEM_KEYWORD_SINT32 ]                               = {
    .name                                                  = "sint32_t",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_SINT32
    }
  },
  [ GR_ELEM_KEYWORD_UINT32 ]                               = {
    .name                                                  = "uint32_t",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_UINT32
    }
  },
  [ GR_ELEM_KEYWORD_SINT64 ]                               = {
    .name                                                  = "sint64_t",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_SINT64
    }
  },
  [ GR_ELEM_KEYWORD_UINT64 ]                               = {
    .name                                                  = "uint64_t",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_UINT64
    }
  },
  [ GR_ELEM_KEYWORD_FLOAT32 ]                              = {
    .name                                                  = "float32_t",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_FLOAT32
    }
  },
  [ GR_ELEM_KEYWORD_FLOAT64 ]                              = {
    .name                                                  = "float64_t",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_FLOAT64
    }
  },
  [ GR_ELEM_KEYWORD_FLOAT128 ]                             = {
    .name                                                  = "float128_t",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_KEYWORD_FLOAT128
    }
  },
  // Separators
  [ GR_ELEM_SEPARATOR_BRACKET_ROUND_OPEN ]                 = {
    .name                                                  = "(",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_BRACKET_ROUND_OPEN
    }
  },
  [ GR_ELEM_SEPARATOR_BRACKET_ROUND_CLOSED ]               = {
    .name                                                  = ")",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_BRACKET_ROUND_CLOSED
    }
  },
  [ GR_ELEM_SEPARATOR_QUOTE ]                              = {
    .name                                                  = "\"",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_QUOTE
    }
  },
  [ GR_ELEM_SEPARATOR_APOSTROPHE ]                         = {
    .name                                                  = "'",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_APOSTROPHE
    }
  },
  [ GR_ELEM_SEPARATOR_PLUS ]                               = {
    .name                                                  = "+",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_PLUS
    }
  },
  [ GR_ELEM_SEPARATOR_MINUS ]                              = {
    .name                                                  = "-",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_MINUS
    }
  },
  [ GR_ELEM_SEPARATOR_PERIOD ]                             = {
    .name                                                  = ".",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_PERIOD
    }
  },
  [ GR_ELEM_SEPARATOR_COLON ]                              = {
    .name                                                  = ":",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_COLON
    }
  },
  [ GR_ELEM_SEPARATOR_SEMICOLON ]                          = {
    .name                                                  = ";",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_SEMICOLON
    }
  },
  [ GR_ELEM_SEPARATOR_BACKSLASH ]                          = {
    .name                                                  = "\\",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_BACKSLASH
    }
  },
  // Escape sequences
  [ GR_ELEM_ESCAPE_a ]                                     = {
    .name                                                  = "\\a",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_ESCAPE_a
    }
  },
  [ GR_ELEM_ESCAPE_b ]                                     = {
    .name                                                  = "\\b",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_ESCAPE_b
    }
  },
  [ GR_ELEM_ESCAPE_f ]                                     = {
    .name                                                  = "\\f",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_ESCAPE_f
    }
  },
  [ GR_ELEM_ESCAPE_n ]                                     = {
    .name                                                  = "\\n",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_ESCAPE_n
    }
  },
  [ GR_ELEM_ESCAPE_r ]                                     = {
    .name                                                  = "\\r",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_ESCAPE_r
    }
  },
  [ GR_ELEM_ESCAPE_t ]                                     = {
    .name                                                  = "\\t",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_ESCAPE_t
    }
  },
  [ GR_ELEM_ESCAPE_v ]                                     = {
    .name                                                  = "\\v",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_ESCAPE_v
    }
  },
  [ GR_ELEM_ESCAPE_x ]                                     = {
    .name                                                  = "\\x",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_ESCAPE_x
    }
  },
  [ GR_ELEM_ESCAPE_QUOTE ]                                  = {
    .name                                                  = "\\\"",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_ESCAPE_QUOTE
    }
  },
  [ GR_ELEM_ESCAPE_APOSTROPHE ]                            = {
    .name                                                  = "\\\'",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_ESCAPE_APOSTROPHE
    }
  },
  [ GR_ELEM_ESCAPE_BACKSLASH ]                             = {
    .name                                                  = "\\\\",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_ESCAPE_BACKSLASH
    }
  },
  [ GR_ELEM_ESCAPE_QUESTION_MARK ]                         = {
    .name                                                  = "\\?",
    .no_tokens                                             = 1u,
    .tokens                                                = {
    [ 0u ]                                               = TOKEN_ESCAPE_QUESTION_MARK
    }
  },
  // Operators
  [ GR_ELEM_OPERATOR_POSTFIX_INCREMENT ]                   = {
    .name                                                  = "++",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_OPERATOR_INCREMENT
    }
  },
  [ GR_ELEM_OPERATOR_POSTFIX_DECREMENT ]                   = {
    .name                                                  = "--",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_OPERATOR_DECREMENT
    }
  },
  [ GR_ELEM_OPERATOR_PREFIX_INCREMENT ]                    = {
    .name                                                  = "++",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_OPERATOR_INCREMENT
    }
  },
  [ GR_ELEM_OPERATOR_PREFIX_DECREMENT ]                    = {
    .name                                                  = "--",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_OPERATOR_DECREMENT
    }
  },
  [ GR_ELEM_OPERATOR_ASSIGNMENT_BASIC ]                    = {
    .name                                                  = "=",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_OPERATOR_ASSIGNMENT_BASIC
    }
  },
  [ GR_ELEM_OPERATOR_ASSIGNMENT_ADDITION ]                 = {
    .name                                                  = "+=",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_OPERATOR_ASSIGNMENT_ADDITION
    }
  },
  [ GR_ELEM_OPERATOR_ASSIGNMENT_SUBTRACTION ]              = {
    .name                                                  = "-=",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_OPERATOR_ASSIGNMENT_SUBTRACTION
    }
  },
  [ GR_ELEM_OPERATOR_ASSIGNMENT_MULTIPLICATION ]           = {
    .name                                                  = "*=",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_OPERATOR_ASSIGNMENT_MULTIPLICATION
    }
  },
  [ GR_ELEM_OPERATOR_ASSIGNMENT_DIVISION ]                 = {
    .name                                                  = "/=",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_OPERATOR_ASSIGNMENT_DIVISION
    }
  },
  [ GR_ELEM_OPERATOR_ASSIGNMENT_MODULO ]                  = {
    .name                                                  = "%=",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_OPERATOR_ASSIGNMENT_MODULO
    }
  },
  [ GR_ELEM_OPERATOR_ASSIGNMENT_BITWISE_AND ]              = {
    .name                                                  = "&=",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_OPERATOR_ASSIGNMENT_BITWISE_AND
    }
  },
  [ GR_ELEM_OPERATOR_ASSIGNMENT_BITWISE_OR ]               = {
    .name                                                  = "|=",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_OPERATOR_ASSIGNMENT_BITWISE_OR
    }
  },
  [ GR_ELEM_OPERATOR_ASSIGNMENT_BITWISE_XOR ]              = {
    .name                                                  = "^=",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_OPERATOR_ASSIGNMENT_BITWISE_XOR
    }
  },
  [ GR_ELEM_OPERATOR_ASSIGNMENT_BITWISE_SHIFT_LEFT ]       = {
    .name                                                  = "<<=",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_OPERATOR_ASSIGNMENT_BITWISE_SHIFT_LEFT
    }
  },
  [ GR_ELEM_OPERATOR_ASSIGNMENT_BITWISE_SHIFT_RIGHT ]      = {
    .name                                                  = ">>=",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_OPERATOR_ASSIGNMENT_BITWISE_SHIFT_RIGHT
    }
  },
  [ GR_ELEM_OPERATOR_ARITHMETIC_UNARY_PLUS ]               = {
    .name                                                  = "+",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_PLUS
    }
  },
  [ GR_ELEM_OPERATOR_ARITHMETIC_UNARY_MINUS ]              = {
    .name                                                  = "-",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_MINUS
    }
  },
  [ GR_ELEM_OPERATOR_ARITHMETIC_ADDITION ]                 = {
    .name                                                  = "+",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_PLUS
    }
  },
  [ GR_ELEM_OPERATOR_ARITHMETIC_SUBTRACTION ]              = {
    .name                                                  = "-",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_MINUS
    }
  },
  [ GR_ELEM_OPERATOR_ARITHMETIC_PRODUCT ]                  = {
    .name                                                  = "*",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_ASTERISK
    }
  },
  [ GR_ELEM_OPERATOR_ARITHMETIC_DIVISION ]                 = {
    .name                                                  = "/",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_OPERATOR_ARITHMETIC_DIVISION
    }
  },
  [ GR_ELEM_OPERATOR_ARITHMETIC_REMAINDER ]                = {
    .name                                                  = "%",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_OPERATOR_ARITHMETIC_REMAINDER
    }
  },
  [ GR_ELEM_OPERATOR_ARITHMETIC_BITWISE_NOT ]              = {
    .name                                                  = "~",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_OPERATOR_ARITHMETIC_BITWISE_NOT
    }
  },
  [ GR_ELEM_OPERATOR_ARITHMETIC_BITWISE_AND ]              = {
    .name                                                  = "&",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_AMPERSAND
    }
  },
  [ GR_ELEM_OPERATOR_ARITHMETIC_BITWISE_OR ]               = {
    .name                                                  = "|",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_OPERATOR_ARITHMETIC_BITWISE_OR
    }
  },
  [ GR_ELEM_OPERATOR_ARITHMETIC_BITWISE_XOR ]              = {
    .name                                                  = "^",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_OPERATOR_ARITHMETIC_BITWISE_XOR
    }
  },
  [ GR_ELEM_OPERATOR_ARITHMETIC_BITWISE_SHIFT_LEFT ]       = {
    .name                                                  = "<<",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_OPERATOR_ARITHMETIC_BITWISE_SHIFT_LEFT
    }
  },
  [ GR_ELEM_OPERATOR_ARITHMETIC_BITWISE_SHIFT_RIGHT ]      = {
    .name                                                  = ">>",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_OPERATOR_ARITHMETIC_BITWISE_SHIFT_RIGHT
    }
  },
  [ GR_ELEM_OPERATOR_LOGICAL_NOT ]                         = {
    .name                                                  = "!",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_OPERATOR_LOGICAL_NOT
    }
  },
  [ GR_ELEM_OPERATOR_LOGICAL_AND ]                         = {
    .name                                                  = "&&",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_OPERATOR_LOGICAL_AND
    }
  },
  [ GR_ELEM_OPERATOR_LOGICAL_OR ]                          = {
    .name                                                  = "||",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_OPERATOR_LOGICAL_OR
    }
  },
  [ GR_ELEM_OPERATOR_COMPARISON_EQUAL_TO ]                 = {
    .name                                                  = "==",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_OPERATOR_COMPARISON_EQUAL_TO
    }
  },
  [ GR_ELEM_OPERATOR_COMPARISON_NOT_EQUAL_TO ]             = {
    .name                                                  = "!=",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_OPERATOR_COMPARISON_NOT_EQUAL_TO
    }
  },
  [ GR_ELEM_OPERATOR_COMPARISON_LESS_THAN ]                = {
    .name                                                  = "<",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_OPERATOR_COMPARISON_LESS_THAN
    }
  },
  [ GR_ELEM_OPERATOR_COMPARISON_LESS_THAN_OR_EQUAL_TO ]    = {
    .name                                                  = "<=",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_OPERATOR_COMPARISON_LESS_THAN_OR_EQUAL_TO
    }
  },
  [ GR_ELEM_OPERATOR_COMPARISON_GREATER_THAN ]             = {
    .name                                                  = ">",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_OPERATOR_COMPARISON_GREATER_THAN
    }
  },
  [ GR_ELEM_OPERATOR_COMPARISON_GREATER_THAN_OR_EQUAL_TO ] = {
    .name                                                  = ">=",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_OPERATOR_COMPARISON_GREATER_THAN_OR_EQUAL_TO
    }
  },
  [ GR_ELEM_OPERATOR_FUNCTION_CALL_BEGIN ]                 = {
    .name                                                  = "(",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_BRACKET_ROUND_OPEN
    }
  },
  [ GR_ELEM_OPERATOR_FUNCTION_CALL_END ]                   = {
    .name                                                  = ")",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_BRACKET_ROUND_CLOSED
    }
  },
  [ GR_ELEM_OPERATOR_ACCESS_ARRAY_SUBSCRIPT_BEGIN ]        = {
    .name                                                  = "[",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_BRACKET_SQUARE_OPEN
    }
  },
  [ GR_ELEM_OPERATOR_ACCESS_ARRAY_SUBSCRIPT_END ]          = {
    .name                                                  = "]",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_BRACKET_SQUARE_CLOSED
    }
  },
  [ GR_ELEM_OPERATOR_ACCESS_POINTER_DEREFERENCE ]          = {
    .name                                                  = "*",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_ASTERISK
    }
  },
  [ GR_ELEM_OPERATOR_ACCESS_ADDRESS_OF ]                   = {
    .name                                                  = "&",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_AMPERSAND
    }
  },
  [ GR_ELEM_OPERATOR_ACCESS_FIELD ]                        = {
    .name                                                  = ".",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_PERIOD
    }
  },
  [ GR_ELEM_OPERATOR_ACCESS_FIELD_VIA_POINTER ]            = {
    .name                                                  = "->",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_OPERATOR_ACCESS_FIELD_VIA_POINTER
    }
  },
  [ GR_ELEM_OPERATOR_COMMA ]                               = {
    .name                                                  = ",",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_COMMA
    }
  },
  [ GR_ELEM_OPERATOR_CONDITIONAL_PART_ONE ]                = {
    .name                                                  = "?",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_OPERATOR_CONDITIONAL_PART_ONE
    }
  },
  [ GR_ELEM_OPERATOR_CONDITIONAL_PART_TWO ]                = {
    .name                                                  = ":",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_COLON
    }
  },
  // Body
  [ GR_ELEM_BODY_BEGIN ]                                   = {
    .name                                                  = "{",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_BRACKET_CURLY_OPEN
    }
  },
  [ GR_ELEM_BODY_END ]                                     = {
    .name                                                  = "}",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_BRACKET_CURLY_CLOSED
    }
  },
  // Compound Literals
  [ GR_ELEM_COMPOUND_LITERAL_BEGIN ]                       = {
    .name                                                  = "(",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_BRACKET_ROUND_OPEN
    }
  },
  [ GR_ELEM_COMPOUND_LITERAL_END ]                         = {
    .name                                                  = ")",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_BRACKET_ROUND_CLOSED
    }
  },
  // Declarators
  [ GR_ELEM_DECLARATOR_POINTER ]                           = {
    .name                                                  = "*",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_ASTERISK
    }
  },
  [ GR_ELEM_DECLARATOR_BINDER_BEGIN ]                      = {
    .name                                                  = "(",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_BRACKET_ROUND_OPEN
    }
  },
  [ GR_ELEM_DECLARATOR_BINDER_END ]                        = {
    .name                                                  = ")",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_BRACKET_ROUND_CLOSED
    }
  },
  [ GR_ELEM_DECLARATOR_ARRAY_BEGIN ]                       = {
    .name                                                  = "[",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_BRACKET_SQUARE_OPEN
    }
  },
  [ GR_ELEM_DECLARATOR_ARRAY_END ]                         = {
    .name                                                  = "]",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_BRACKET_SQUARE_CLOSED
    }
  },
  [ GR_ELEM_DECLARATOR_FUNCTION_BEGIN ]                    = {
    .name                                                  = "(",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_BRACKET_ROUND_OPEN
    }
  },
  [ GR_ELEM_DECLARATOR_FUNCTION_END ]                      = {
    .name                                                  = ")",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_BRACKET_ROUND_CLOSED
    }
  },
  // Designators
  [ GR_ELEM_DESIGNATOR_ARRAY_ELEM_BEGIN ]                  = {
    .name                                                  = "[",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_BRACKET_SQUARE_OPEN
    }
  },
  [ GR_ELEM_DESIGNATOR_ARRAY_ELEM_END ]                    = {
    .name                                                  = "]",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_BRACKET_SQUARE_CLOSED
    }
  },
  [ GR_ELEM_DESIGNATOR_STRUCT_OR_UNION_MEMBER ]            = {
    .name                                                  = ".",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_PERIOD
    }
  },
  // Lists
  [ GR_ELEM_LIST_DELIMITER ]                               = {
    .name                                                  = ",",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_COMMA
    }
  },
  // Placeholders
  [ GR_ELEM_PLACEHOLDER_VLA ]                              = {
    .name                                                  = "*",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_ASTERISK
    }
  },
  // Parameters
  [ GR_ELEM_PARAMETER_VARIADIC_ARGS ]                      = {
    .name                                                  = "...",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_PARAMETER_VARIADIC_ARGS
    }
  },
  // Labels
  [ GR_ELEM_LABEL_DECLARATION ]                            = {
    .name                                                  = ":",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_COLON
    }
  },
  // Bit Fields
  [ GR_ELEM_BIT_FIELD_WIDTH_DECLARATION_STRUCT_OR_UNION ]  = {
    .name                                                  = ":",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_SEPARATOR_COLON
    }
  },
  // Identifiers
  [ GR_ELEM_IDENTIFIER ]                                   = {
    .name                                                  = "identifier",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_IDENTIFIER
    }
  },
  [ GR_ELEM_IDENTIFIER_TYPEDEF ]                           = {
    .name                                                  = "identifier-typedef",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_IDENTIFIER_TYPEDEF
    }
  },
  // Attributes
  [ GR_ELEM_ATTRIBUTE_DELIMITER_BEGIN ]                    = {
    .name                                                  = "[[",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_ATTRIBUTE_DELIMITER_BEGIN
    }
  },
  [ GR_ELEM_ATTRIBUTE_DELIMITER_END ]                      = {
    .name                                                  = "]]",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_ATTRIBUTE_DELIMITER_END
    }
  },
  [ GR_ELEM_ATTRIBUTE_SCOPE ]                              = {
    .name                                                  = "::",
    .no_tokens                                             = 1u,
    .tokens                                                = {
      [ 0u ]                                               = TOKEN_ATTRIBUTE_SCOPE
    }
  },

  // Complex gr_elems that do not translate directly into tokens
  [ GR_ELEM_DIGIT ]                                        = {
    .name                                                  = "digit"
  },
  [ GR_ELEM_NON_ZERO_DIGIT ]                               = {
    .name                                                  = "non-zero-digit"
  },
  [ GR_ELEM_OCTAL_DIGIT ]                                  = {
    .name                                                  = "octal-digit"
  },
  [ GR_ELEM_HEXADECIMAL_DIGIT ]                            = {
    .name                                                  = "hexadecimal-digit"
  },
  [ GR_ELEM_BINARY_DIGIT ]                                 = {
    .name                                                  = "binary-digit"
  },
  [ GR_ELEM_DIGIT_SEQUENCE ]                               = {
    .name                                                  = "digit-sequence"
  },
  [ GR_ELEM_HEXADECIMAL_DIGIT_SEQUENCE ]                   = {
    .name                                                  = "hexadecimal-digit-sequence"
  },
  [ GR_ELEM_C_CHAR ]                                       = {
    .name                                                  = "c-char"
  },
  [ GR_ELEM_C_CHAR_SEQUENCE ]                              = {
    .name                                                  = "c-char-sequence"
  },
  [ GR_ELEM_ESCAPE_SEQUENCE ]                              = {
    .name                                                  = "escape-sequence"
  },
  [ GR_ELEM_SIMPLE_ESCAPE_SEQUENCE ]                       = {
    .name                                                  = "simple-escape-sequence"
  },
  [ GR_ELEM_OCTAL_ESCAPE_SEQUENCE ]                        = {
    .name                                                  = "octal-escape-sequence"
  },
  [ GR_ELEM_HEXADECIMAL_ESCAPE_SEQUENCE ]                  = {
    .name                                                  = "hexadecimal-escape-sequence"
  },
  [ GR_ELEM_CONSTANT ]                                     = {
    .name                                                  = "constant"
  },
  [ GR_ELEM_INTEGER_CONSTANT ]                             = {
    .name                                                  = "integer-constant"
  },
  [ GR_ELEM_DECIMAL_CONSTANT ]                             = {
    .name                                                  = "decimal-constant"
  },
  [ GR_ELEM_OCTAL_CONSTANT ]                               = {
    .name                                                  = "octal-constant"
  },
  [ GR_ELEM_HEXADECIMAL_CONSTANT ]                         = {
    .name                                                  = "hexadecimal-constant"
  },
  [ GR_ELEM_BINARY_CONSTANT ]                              = {
    .name                                                  = "binary-constant"
  },
  [ GR_ELEM_HEXADECIMAL_PREFIX ]                           = {
    .name                                                  = "hexadecimal-prefix"
  },
  [ GR_ELEM_BINARY_PREFIX ]                                = {
    .name                                                  = "binary-prefix"
  },
  [ GR_ELEM_INTEGER_SUFFIX ]                               = {
    .name                                                  = "integer-suffix"
  },
  [ GR_ELEM_BIT_PRECISE_INT_SUFFIX ]                       = {
    .name                                                  = "bit-precise-int-suffix"
  },
  [ GR_ELEM_UNSIGNED_SUFFIX ]                              = {
    .name                                                  = "unsigned-suffix"
  },
  [ GR_ELEM_LONG_SUFFIX ]                                  = {
    .name                                                  = "long-suffix"
  },
  [ GR_ELEM_LONG_LONG_SUFFIX ]                             = {
    .name                                                  = "long-long-suffix"
  },
  [ GR_ELEM_FLOATING_CONSTANT ]                            = {
    .name                                                  = "floating-constant"
  },
  [ GR_ELEM_DECIMAL_FLOATING_CONSTANT ]                    = {
    .name                                                  = "decimal-floating-constant"
  },
  [ GR_ELEM_HEXADECIMAL_FLOATING_CONSTANT ]                = {
    .name                                                  = "hexadecimal-floating-constant"
  },
  [ GR_ELEM_FRACTIONAL_CONSTANT ]                          = {
    .name                                                  = "fractional-constant"
  },
  [ GR_ELEM_EXPONENT_PART ]                                = {
    .name                                                  = "exponent-part"
  },
  [ GR_ELEM_SIGN ]                                         = {
    .name                                                  = "sign"
  },
  [ GR_ELEM_HEXADECIMAL_FRACTIONAL_CONSTANT ]              = {
    .name                                                  = "hexadecimal-fractional-constant"
  },
  [ GR_ELEM_BINARY_EXPONENT_PART ]                         = {
    .name                                                  = "exponent-part"
  },
  [ GR_ELEM_FLOATING_SUFFIX ]                              = {
    .name                                                  = "floating-suffix"
  },
  [ GR_ELEM_ENUMERATION_CONSTANT ]                         = {
    .name                                                  = "enumeration-constant"
  },
  [ GR_ELEM_CHARACTER_CONSTANT ]                           = {
    .name                                                  = "character-constant"
  },
  [ GR_ELEM_ENCODING_PREFIX ]                              = {
    .name                                                  = "encoding-prefix"
  },
  [ GR_ELEM_PREDEFINED_CONSTANT ]                          = {
    .name                                                  = "predefined-constant"
  },
  [ GR_ELEM_STRING_CONSTANT ]                              = {
    .name                                                  = "string-constant"
  },
  [ GR_ELEM_PRIMARY_EXPRESSION ]                           = {
    .name                                                  = "primary-expression"
  },
  [ GR_ELEM_GENERIC_SELECTION ]                            = {
    .name                                                  = "generic-selection"
  },
  [ GR_ELEM_GENERIC_ASSOC_LIST ]                           = {
    .name                                                  = "generic-assoc-list"
  },
  [ GR_ELEM_GENERIC_ASSOC ]                                = {
    .name                                                  = "generic-assoc"
  },
  [ GR_ELEM_POSTFIX_EXPRESSION ]                           = {
    .name                                                  = "postfix-expression"
  },
  [ GR_ELEM_ARGUMENT_EXPRESSION_LIST ]                     = {
    .name                                                  = "argument-expression-list"
  },
  [ GR_ELEM_COMPOUND_LITERAL ]                             = {
    .name                                                  = "compound-literal"
  },
  [ GR_ELEM_STORAGE_CLASS_SPECIFIERS ]                     = {
    .name                                                  = "storage-class-specifiers"
  },
  [ GR_ELEM_UNARY_EXPRESSION ]                             = {
    .name                                                  = "unary-expression"
  },
  [ GR_ELEM_UNARY_OPERATOR ]                               = {
    .name                                                  = "unary-operator"
  },
  [ GR_ELEM_CAST_EXPRESSION ]                              = {
    .name                                                  = "cast-expression"
  },
  [ GR_ELEM_MULTIPLICATIVE_EXPRESSION ]                    = {
    .name                                                  = "multiplicative-expression"
  },
  [ GR_ELEM_ADDITIVE_EXPRESSION ]                          = {
    .name                                                  = "additive-expression"
  },
  [ GR_ELEM_SHIFT_EXPRESSION ]                             = {
    .name                                                  = "shift-expression"
  },
  [ GR_ELEM_RELATIONAL_EXPRESSION ]                        = {
    .name                                                  = "relational-expression"
  },
  [ GR_ELEM_EQUALITY_EXPRESSION ]                          = {
    .name                                                  = "equality-expression"
  },
  [ GR_ELEM_AND_EXPRESSION ]                               = {
    .name                                                  = "AND-expression"
  },
  [ GR_ELEM_XOR_EXPRESSION ]                               = {
    .name                                                  = "XOR-expression"
  },
  [ GR_ELEM_OR_EXPRESSION ]                                = {
    .name                                                  = "OR-expression"
  },
  [ GR_ELEM_LOGICAL_AND_EXPRESSION ]                       = {
    .name                                                  = "logical-AND-expression"
  },
  [ GR_ELEM_LOGICAL_OR_EXPRESSION ]                        = {
    .name                                                  = "logical-OR-expression"
  },
  [ GR_ELEM_CONDITIONAL_EXPRESSION ]                       = {
    .name                                                  = "conditional-expression"
  },
  [ GR_ELEM_ASSIGNMENT_EXPRESSION ]                        = {
    .name                                                  = "assignment-expression"
  },
  [ GR_ELEM_ASSIGNMENT_OPERATOR ]                          = {
    .name                                                  = "assignment-operator"
  },
  [ GR_ELEM_EXPRESSION ]                                   = {
    .name                                                  = "expression"
  },
  [ GR_ELEM_CONSTANT_EXPRESSION ]                          = {
    .name                                                  = "constant-expression"
  },
  [ GR_ELEM_DECLARATION ]                                  = {
    .name                                                  = "declaration"
  },
  [ GR_ELEM_DECLARATION_SPECIFIERS ]                       = {
    .name                                                  = "declaration-specifiers"
  },
  [ GR_ELEM_DECLARATION_SPECIFIER ]                        = {
    .name                                                  = "declaration-specifier"
  },
  [ GR_ELEM_INIT_DECLARATOR_LIST ]                         = {
    .name                                                  = "init-declarator-list"
  },
  [ GR_ELEM_INIT_DECLARATOR ]                              = {
    .name                                                  = "init-declarator"
  },
  [ GR_ELEM_ATTRIBUTE_DECLARATION ]                        = {
    .name                                                  = "attribute-declaration"
  },
  [ GR_ELEM_STORAGE_CLASS_SPECIFIER ]                      = {
    .name                                                  = "storage-class-specifier"
  },
  [ GR_ELEM_TYPE_SPECIFIER ]                               = {
    .name                                                  = "type-specifier"
  },
  [ GR_ELEM_STRUCT_OR_UNION_SPECIFIER ]                    = {
    .name                                                  = "struct-or-union-specifier"
  },
  [ GR_ELEM_STRUCT_OR_UNION ]                              = {
    .name                                                  = "struct-or-union"
  },
  [ GR_ELEM_MEMBER_DECLARATION_LIST ]                      = {
    .name                                                  = "member-declaration-list"
  },
  [ GR_ELEM_MEMBER_DECLARATION ]                           = {
    .name                                                  = "member-declaration"
  },
  [ GR_ELEM_SPECIFIER_QUALIFIER_LIST ]                     = {
    .name                                                  = "specifier-qualifier-list"
  },
  [ GR_ELEM_TYPE_SPECIFIER_QUALIFIER ]                     = {
    .name                                                  = "type-specifier-qualifier"
  },
  [ GR_ELEM_MEMBER_DECLARATOR_LIST ]                       = {
    .name                                                  = "member-declarator-list"
  },
  [ GR_ELEM_MEMBER_DECLARATOR ]                            = {
    .name                                                  = "member-declarator"
  },
  [ GR_ELEM_ENUM_SPECIFIER ]                               = {
    .name                                                  = "enum-specifier"
  },
  [ GR_ELEM_ENUMERATOR_LIST ]                              = {
    .name                                                  = "enumerator-list"
  },
  [ GR_ELEM_ENUMERATOR ]                                   = {
    .name                                                  = "enumerator"
  },
  [ GR_ELEM_ENUM_TYPE_SPECIFIER ]                          = {
    .name                                                  = "enum-type-specifier"
  },
  [ GR_ELEM_ATOMIC_TYPE_SPECIFIER ]                        = {
    .name                                                  = "atomic-type-specifier"
  },
  [ GR_ELEM_TYPEOF_SPECIFIER ]                             = {
    .name                                                  = "typeof-specifier"
  },
  [ GR_ELEM_TYPEOF_SPECIFIER_ARGUMENT ]                    = {
    .name                                                  = "typeof-specifier-argument"
  },
  [ GR_ELEM_TYPE_QUALIFIER ]                               = {
    .name                                                  = "type-qualifier"
  },
  [ GR_ELEM_FUNCTION_SPECIFIER ]                           = {
    .name                                                  = "function-specifier"
  },
  [ GR_ELEM_ALIGNMENT_SPECIFIER ]                          = {
    .name                                                  = "alignment-specifier"
  },
  [ GR_ELEM_DECLARATOR ]                                   = {
    .name                                                  = "declarator"
  },
  [ GR_ELEM_DIRECT_DECLARATOR ]                            = {
    .name                                                  = "direct-declarator"
  },
  [ GR_ELEM_ARRAY_DECLARATOR ]                             = {
    .name                                                  = "array-declarator"
  },
  [ GR_ELEM_FUNCTION_DECLARATOR ]                          = {
    .name                                                  = "function-declarator"
  },
  [ GR_ELEM_POINTER ]                                      = {
    .name                                                  = "pointer"
  },
  [ GR_ELEM_TYPE_QUALIFIER_LIST ]                          = {
    .name                                                  = "type-qualifier-list"
  },
  [ GR_ELEM_PARAMETER_TYPE_LIST ]                          = {
    .name                                                  = "parameter-type-list"
  },
  [ GR_ELEM_PARAMETER_LIST ]                               = {
    .name                                                  = "parameter-list"
  },
  [ GR_ELEM_PARAMETER_DECLARATION ]                        = {
    .name                                                  = "parameter-declaration"
  },
  [ GR_ELEM_TYPE_NAME ]                                    = {
    .name                                                  = "type-name"
  },
  [ GR_ELEM_ABSTRACT_DECLARATOR ]                          = {
    .name                                                  = "abstract-declarator"
  },
  [ GR_ELEM_DIRECT_ABSTRACT_DECLARATOR ]                   = {
    .name                                                  = "direct-abstract-declarator"
  },
  [ GR_ELEM_ARRAY_ABSTRACT_DECLARATOR ]                    = {
    .name                                                  = "array-abstract-declarator"
  },
  [ GR_ELEM_FUNCTION_ABSTRACT_DECLARATOR ]                 = {
    .name                                                  = "function-abstract-declarator"
  },
  [ GR_ELEM_BRACED_INITIALIZER ]                           = {
    .name                                                  = "braced-initiliazer"
  },
  [ GR_ELEM_TYPEDEF_NAME ]                                 = {
    .name                                                  = "typedef-name"
  },
  [ GR_ELEM_INITIALIZER ]                                  = {
    .name                                                  = "initializer"
  },
  [ GR_ELEM_INITIALIZER_LIST ]                             = {
    .name                                                  = "initializer-list"
  },
  [ GR_ELEM_DESIGNATION ]                                  = {
    .name                                                  = "designation"
  },
  [ GR_ELEM_DESIGNATOR_LIST ]                              = {
    .name                                                  = "designator-list"
  },
  [ GR_ELEM_DESIGNATOR ]                                   = {
    .name                                                  = "designator"
  },
  [ GR_ELEM_STATIC_ASSERT_DECLARATION ]                    = {
    .name                                                  = "static-assert-declaration"
  },
  [ GR_ELEM_ATTRIBUTE_SPECIFIER_SEQUENCE ]                 = {
    .name                                                  = "attribute-specifier-sequence"
  },
  [ GR_ELEM_ATTRIBUTE_SPECIFIER ]                          = {
    .name                                                  = "attribute-specifier"
  },
  [ GR_ELEM_ATTRIBUTE_LIST ]                               = {
    .name                                                  = "attribute-list"
  },
  [ GR_ELEM_ATTRIBUTE ]                                    = {
    .name                                                  = "attribute"
  },
  [ GR_ELEM_ATTRIBUTE_TOKEN ]                              = {
    .name                                                  = "attribute-token"
  },
  [ GR_ELEM_STANDARD_ATTRIBUTE ]                           = {
    .name                                                  = "standard-attribute"
  },
  [ GR_ELEM_ATTRIBUTE_PREFIXED_TOKEN ]                     = {
    .name                                                  = "attribute-prefixed-token"
  },
  [ GR_ELEM_ATTRIBUTE_PREFIX ]                             = {
    .name                                                  = "attribute-prefix"
  },
  [ GR_ELEM_ATTRIBUTE_ARGUMENT_CLAUSE ]                    = {
    .name                                                  = "attribute-argument-clause"
  },
  [ GR_ELEM_BALANCED_TOKEN_SEQUENCE ]                      = {
    .name                                                  = "balanced-token-sequence"
  },
  [ GR_ELEM_BALANCED_TOKEN ]                               = {
    .name                                                  = "balanced-token"
  },
  [ GR_ELEM_STATEMENT ]                                    = {
    .name                                                  = "statement"
  },
  [ GR_ELEM_UNLABELED_STATEMENT ]                          = {
    .name                                                  = "unlabeled-statement"
  },
  [ GR_ELEM_PRIMARY_BLOCK ]                                = {
    .name                                                  = "primary-block"
  },
  [ GR_ELEM_SECONDARY_BLOCK ]                              = {
    .name                                                  = "secondary-block"
  },
  [ GR_ELEM_LABEL ]                                        = {
    .name                                                  = "label"
  },
  [ GR_ELEM_LABELED_STATEMENT ]                            = {
    .name                                                  = "labeled-statement"
  },
  [ GR_ELEM_COMPOUND_STATEMENT ]                           = {
    .name                                                  = "compound-statement"
  },
  [ GR_ELEM_BLOCK_ITEM_LIST ]                              = {
    .name                                                  = "block-item-list"
  },
  [ GR_ELEM_BLOCK_ITEM ]                                   = {
    .name                                                  = "block-item"
  },
  [ GR_ELEM_EXPRESSION_STATEMENT ]                         = {
    .name                                                  = "expression-statement"
  },
  [ GR_ELEM_SELECTION_STATEMENT ]                          = {
    .name                                                  = "selection-statement"
  },
  [ GR_ELEM_ITERATION_STATEMENT ]                          = {
    .name                                                  = "iteration-statement"
  },
  [ GR_ELEM_JUMP_STATEMENT ]                               = {
    .name                                                  = "jump-statement"
  },
  [ GR_ELEM_TRANSLATION_UNIT ]                             = {
    .name                                                  = "translation-unit"
  },
  [ GR_ELEM_EXTERNAL_DECLARATION ]                         = {
    .name                                                  = "external-declaration"
  },
  [ GR_ELEM_FUNCTION_DEFINITION ]                          = {
    .name                                                  = "function-definition"
  },
  [ GR_ELEM_FUNCTION_BODY ]                                = {
    .name                                                  = "function-body"
  },

  [ GR_ELEM_START ]                                        = {
    .name                                                  = "start"
  }
};

gr_t* gr_elem_get(const gr_elem_type_t elem_type) {
  gr_t* gr = NULL;

  if ((elem_type == GR_ELEM_INVALID) || (elem_type >= GR_ELEM_MAX_NO_ELEMS)) {
    return NULL;
  }

  gr = gr_alloc();
  if (gr != NULL) {
    if (elem_type < GR_ELEM_COMPLEX) {
      // Simple gr_elems that translate directly into one token
      gr->type = elem_type;
    } else {
      switch (elem_type) {
        // Complex gr_elems that do not translate directly into tokens
        case GR_ELEM_DIGIT:
          memcpy(gr, &gr_elem_digit, sizeof(gr_t));
          break;

        case GR_ELEM_NON_ZERO_DIGIT:
          memcpy(gr, &gr_elem_non_zero_digit, sizeof(gr_t));
          break;

        case GR_ELEM_OCTAL_DIGIT:
          memcpy(gr, &gr_elem_octal_digit, sizeof(gr_t));
          break;

        case GR_ELEM_HEXADECIMAL_DIGIT:
          memcpy(gr, &gr_elem_hexadecimal_digit, sizeof(gr_t));
          break;

        case GR_ELEM_BINARY_DIGIT:
          memcpy(gr, &gr_elem_binary_digit, sizeof(gr_t));
          break;

        case GR_ELEM_DIGIT_SEQUENCE:
          memcpy(gr, &gr_elem_digit_sequence, sizeof(gr_t));
          break;

        case GR_ELEM_HEXADECIMAL_DIGIT_SEQUENCE:
          memcpy(gr, &gr_elem_hexadecimal_digit_sequence, sizeof(gr_t));
          break;

        case GR_ELEM_C_CHAR:
          memcpy(gr, &gr_elem_c_char, sizeof(gr_t));
          break;

        case GR_ELEM_C_CHAR_SEQUENCE:
          memcpy(gr, &gr_elem_c_char_sequence, sizeof(gr_t));
          break;

        case GR_ELEM_ESCAPE_SEQUENCE:
          memcpy(gr, &gr_elem_escape_sequence, sizeof(gr_t));
          break;

        case GR_ELEM_SIMPLE_ESCAPE_SEQUENCE:
          memcpy(gr, &gr_elem_simple_escape_sequence, sizeof(gr_t));
          break;

        case GR_ELEM_OCTAL_ESCAPE_SEQUENCE:
          memcpy(gr, &gr_elem_octal_escape_sequence, sizeof(gr_t));
          break;

        case GR_ELEM_HEXADECIMAL_ESCAPE_SEQUENCE:
          memcpy(gr, &gr_elem_hexadecimal_escape_sequence, sizeof(gr_t));
          break;

        case GR_ELEM_CONSTANT:
          memcpy(gr, &gr_elem_constant, sizeof(gr_t));
          break;

        case GR_ELEM_INTEGER_CONSTANT:
          memcpy(gr, &gr_elem_integer_constant, sizeof(gr_t));
          break;

        case GR_ELEM_DECIMAL_CONSTANT:
          memcpy(gr, &gr_elem_decimal_constant, sizeof(gr_t));
          break;

        case GR_ELEM_OCTAL_CONSTANT:
          memcpy(gr, &gr_elem_octal_constant, sizeof(gr_t));
          break;

        case GR_ELEM_HEXADECIMAL_CONSTANT:
          memcpy(gr, &gr_elem_hexadecimal_constant, sizeof(gr_t));
          break;

        case GR_ELEM_BINARY_CONSTANT:
          memcpy(gr, &gr_elem_binary_constant, sizeof(gr_t));
          break;

        case GR_ELEM_HEXADECIMAL_PREFIX:
          memcpy(gr, &gr_elem_hexadecimal_prefix, sizeof(gr_t));
          break;

        case GR_ELEM_BINARY_PREFIX:
          memcpy(gr, &gr_elem_binary_prefix, sizeof(gr_t));
          break;

        case GR_ELEM_INTEGER_SUFFIX:
          memcpy(gr, &gr_elem_integer_suffix, sizeof(gr_t));
          break;

        case GR_ELEM_BIT_PRECISE_INT_SUFFIX:
          memcpy(gr, &gr_elem_bit_precise_int_suffix, sizeof(gr_t));
          break;

        case GR_ELEM_UNSIGNED_SUFFIX:
          memcpy(gr, &gr_elem_unsigned_suffix, sizeof(gr_t));
          break;

        case GR_ELEM_LONG_SUFFIX:
          memcpy(gr, &gr_elem_long_suffix, sizeof(gr_t));
          break;

        case GR_ELEM_LONG_LONG_SUFFIX:
          memcpy(gr, &gr_elem_long_long_suffix, sizeof(gr_t));
          break;

        case GR_ELEM_FLOATING_CONSTANT:
          memcpy(gr, &gr_elem_floating_constant, sizeof(gr_t));
          break;

        case GR_ELEM_DECIMAL_FLOATING_CONSTANT:
          memcpy(gr, &gr_elem_decimal_floating_constant, sizeof(gr_t));
          break;

        case GR_ELEM_HEXADECIMAL_FLOATING_CONSTANT:
          memcpy(gr, &gr_elem_hexadecimal_floating_constant, sizeof(gr_t));
          break;

        case GR_ELEM_FRACTIONAL_CONSTANT:
          memcpy(gr, &gr_elem_fractional_constant, sizeof(gr_t));
          break;

        case GR_ELEM_EXPONENT_PART:
          memcpy(gr, &gr_elem_exponent_part, sizeof(gr_t));
          break;

        case GR_ELEM_SIGN:
          memcpy(gr, &gr_elem_sign, sizeof(gr_t));
          break;

        case GR_ELEM_HEXADECIMAL_FRACTIONAL_CONSTANT:
          memcpy(gr, &gr_elem_hexadecimal_fractional_constant, sizeof(gr_t));
          break;

        case GR_ELEM_BINARY_EXPONENT_PART:
          memcpy(gr, &gr_elem_binary_exponent_part, sizeof(gr_t));
          break;

        case GR_ELEM_FLOATING_SUFFIX:
          memcpy(gr, &gr_elem_floating_suffix, sizeof(gr_t));
          break;

        case GR_ELEM_ENUMERATION_CONSTANT:
          memcpy(gr, &gr_elem_enumeration_constant, sizeof(gr_t));
          break;

        case GR_ELEM_CHARACTER_CONSTANT:
          memcpy(gr, &gr_elem_character_constant, sizeof(gr_t));
          break;

        case GR_ELEM_ENCODING_PREFIX:
          memcpy(gr, &gr_elem_encoding_prefix, sizeof(gr_t));
          break;

        case GR_ELEM_PREDEFINED_CONSTANT:
          memcpy(gr, &gr_elem_predefined_constant, sizeof(gr_t));
          break;

        case GR_ELEM_STRING_CONSTANT:
          memcpy(gr, &gr_elem_string_constant, sizeof(gr_t));
          break;

        case GR_ELEM_PRIMARY_EXPRESSION:
          memcpy(gr, &gr_elem_primary_expression, sizeof(gr_t));
          break;

        case GR_ELEM_GENERIC_SELECTION:
          memcpy(gr, &gr_elem_generic_selection, sizeof(gr_t));
          break;

        case GR_ELEM_GENERIC_ASSOC_LIST:
          memcpy(gr, &gr_elem_generic_assoc_list, sizeof(gr_t));
          break;

        case GR_ELEM_GENERIC_ASSOC:
          memcpy(gr, &gr_elem_generic_assoc, sizeof(gr_t));
          break;

        case GR_ELEM_POSTFIX_EXPRESSION:
          memcpy(gr, &gr_elem_postfix_expression, sizeof(gr_t));
          break;

        case GR_ELEM_ARGUMENT_EXPRESSION_LIST:
          memcpy(gr, &gr_elem_argument_expression_list, sizeof(gr_t));
          break;

        case GR_ELEM_COMPOUND_LITERAL:
          memcpy(gr, &gr_elem_compound_literal, sizeof(gr_t));
          break;

        case GR_ELEM_STORAGE_CLASS_SPECIFIERS:
          memcpy(gr, &gr_elem_storage_class_specifiers, sizeof(gr_t));
          break;

        case GR_ELEM_UNARY_EXPRESSION:
          memcpy(gr, &gr_elem_unary_expression, sizeof(gr_t));
          break;

        case GR_ELEM_UNARY_OPERATOR:
          memcpy(gr, &gr_elem_unary_operator, sizeof(gr_t));
          break;

        case GR_ELEM_CAST_EXPRESSION:
          memcpy(gr, &gr_elem_cast_expression, sizeof(gr_t));
          break;

        case GR_ELEM_MULTIPLICATIVE_EXPRESSION:
          memcpy(gr, &gr_elem_multiplicative_expression, sizeof(gr_t));
          break;

        case GR_ELEM_ADDITIVE_EXPRESSION:
          memcpy(gr, &gr_elem_additive_expression, sizeof(gr_t));
          break;

        case GR_ELEM_SHIFT_EXPRESSION:
          memcpy(gr, &gr_elem_shift_expression, sizeof(gr_t));
          break;

        case GR_ELEM_RELATIONAL_EXPRESSION:
          memcpy(gr, &gr_elem_relational_expression, sizeof(gr_t));
          break;

        case GR_ELEM_EQUALITY_EXPRESSION:
          memcpy(gr, &gr_elem_equality_expression, sizeof(gr_t));
          break;

        case GR_ELEM_AND_EXPRESSION:
          memcpy(gr, &gr_elem_and_expression, sizeof(gr_t));
          break;

        case GR_ELEM_XOR_EXPRESSION:
          memcpy(gr, &gr_elem_xor_expression, sizeof(gr_t));
          break;

        case GR_ELEM_OR_EXPRESSION:
          memcpy(gr, &gr_elem_or_expression, sizeof(gr_t));
          break;

        case GR_ELEM_LOGICAL_AND_EXPRESSION:
          memcpy(gr, &gr_elem_logical_and_expression, sizeof(gr_t));
          break;

        case GR_ELEM_LOGICAL_OR_EXPRESSION:
          memcpy(gr, &gr_elem_logical_or_expression, sizeof(gr_t));
          break;

        case GR_ELEM_CONDITIONAL_EXPRESSION:
          memcpy(gr, &gr_elem_conditional_expression, sizeof(gr_t));
          break;

        case GR_ELEM_ASSIGNMENT_EXPRESSION:
          memcpy(gr, &gr_elem_assignment_expression, sizeof(gr_t));
          break;

        case GR_ELEM_ASSIGNMENT_OPERATOR:
          memcpy(gr, &gr_elem_assignment_operator, sizeof(gr_t));
          break;

        case GR_ELEM_EXPRESSION:
          memcpy(gr, &gr_elem_expression, sizeof(gr_t));
          break;

        case GR_ELEM_CONSTANT_EXPRESSION:
          memcpy(gr, &gr_elem_constant_expression, sizeof(gr_t));
          break;

        case GR_ELEM_DECLARATION:
          memcpy(gr, &gr_elem_declaration, sizeof(gr_t));
          break;

        case GR_ELEM_DECLARATION_SPECIFIERS:
          memcpy(gr, &gr_elem_declaration_specifiers, sizeof(gr_t));
          break;

        case GR_ELEM_DECLARATION_SPECIFIER:
          memcpy(gr, &gr_elem_declaration_specifier, sizeof(gr_t));
          break;

        case GR_ELEM_INIT_DECLARATOR_LIST:
          memcpy(gr, &gr_elem_init_declarator_list, sizeof(gr_t));
          break;

        case GR_ELEM_INIT_DECLARATOR:
          memcpy(gr, &gr_elem_init_declarator, sizeof(gr_t));
          break;

        case GR_ELEM_ATTRIBUTE_DECLARATION:
          memcpy(gr, &gr_elem_attribute_declaration, sizeof(gr_t));
          break;

        case GR_ELEM_STORAGE_CLASS_SPECIFIER:
          memcpy(gr, &gr_elem_storage_class_specifier, sizeof(gr_t));
          break;

        case GR_ELEM_TYPE_SPECIFIER:
          memcpy(gr, &gr_elem_type_specifier, sizeof(gr_t));
          break;

        case GR_ELEM_STRUCT_OR_UNION_SPECIFIER:
          memcpy(gr, &gr_elem_struct_or_union_specifier, sizeof(gr_t));
          break;

        case GR_ELEM_STRUCT_OR_UNION:
          memcpy(gr, &gr_elem_struct_or_union, sizeof(gr_t));
          break;

        case GR_ELEM_MEMBER_DECLARATION_LIST:
          memcpy(gr, &gr_elem_member_declaration_list, sizeof(gr_t));
          break;

        case GR_ELEM_MEMBER_DECLARATION:
          memcpy(gr, &gr_elem_member_declaration, sizeof(gr_t));
          break;

        case GR_ELEM_SPECIFIER_QUALIFIER_LIST:
          memcpy(gr, &gr_elem_specifier_qualifier_list, sizeof(gr_t));
          break;

        case GR_ELEM_TYPE_SPECIFIER_QUALIFIER:
          memcpy(gr, &gr_elem_type_specifier_qualifier, sizeof(gr_t));
          break;

        case GR_ELEM_MEMBER_DECLARATOR_LIST:
          memcpy(gr, &gr_elem_member_declarator_list, sizeof(gr_t));
          break;

        case GR_ELEM_MEMBER_DECLARATOR:
          memcpy(gr, &gr_elem_member_declarator, sizeof(gr_t));
          break;

        case GR_ELEM_ENUM_SPECIFIER:
          memcpy(gr, &gr_elem_enum_specifier, sizeof(gr_t));
          break;

        case GR_ELEM_ENUMERATOR_LIST:
          memcpy(gr, &gr_elem_enumerator_list, sizeof(gr_t));
          break;

        case GR_ELEM_ENUMERATOR:
          memcpy(gr, &gr_elem_enumerator, sizeof(gr_t));
          break;

        case GR_ELEM_ENUM_TYPE_SPECIFIER:
          memcpy(gr, &gr_elem_enum_type_specifier, sizeof(gr_t));
          break;

        case GR_ELEM_ATOMIC_TYPE_SPECIFIER:
          memcpy(gr, &gr_elem_atomic_type_specifier, sizeof(gr_t));
          break;

        case GR_ELEM_TYPEOF_SPECIFIER:
          memcpy(gr, &gr_elem_typeof_specifier, sizeof(gr_t));
          break;

        case GR_ELEM_TYPEOF_SPECIFIER_ARGUMENT:
          memcpy(gr, &gr_elem_typeof_specifier_argument, sizeof(gr_t));
          break;

        case GR_ELEM_TYPE_QUALIFIER:
          memcpy(gr, &gr_elem_type_qualifier, sizeof(gr_t));
          break;

        case GR_ELEM_FUNCTION_SPECIFIER:
          memcpy(gr, &gr_elem_function_specifier, sizeof(gr_t));
          break;

        case GR_ELEM_ALIGNMENT_SPECIFIER:
          memcpy(gr, &gr_elem_alignment_specifier, sizeof(gr_t));
          break;

        case GR_ELEM_DECLARATOR:
          memcpy(gr, &gr_elem_declarator, sizeof(gr_t));
          break;

        case GR_ELEM_DIRECT_DECLARATOR:
          memcpy(gr, &gr_elem_direct_declarator, sizeof(gr_t));
          break;

        case GR_ELEM_ARRAY_DECLARATOR:
          memcpy(gr, &gr_elem_array_declarator, sizeof(gr_t));
          break;

        case GR_ELEM_FUNCTION_DECLARATOR:
          memcpy(gr, &gr_elem_function_declarator, sizeof(gr_t));
          break;

        case GR_ELEM_POINTER:
          memcpy(gr, &gr_elem_pointer, sizeof(gr_t));
          break;

        case GR_ELEM_TYPE_QUALIFIER_LIST:
          memcpy(gr, &gr_elem_type_qualifier_list, sizeof(gr_t));
          break;

        case GR_ELEM_PARAMETER_TYPE_LIST:
          memcpy(gr, &gr_elem_parameter_type_list, sizeof(gr_t));
          break;

        case GR_ELEM_PARAMETER_LIST:
          memcpy(gr, &gr_elem_parameter_list, sizeof(gr_t));
          break;

        case GR_ELEM_PARAMETER_DECLARATION:
          memcpy(gr, &gr_elem_parameter_declaration, sizeof(gr_t));
          break;

        case GR_ELEM_TYPE_NAME:
          memcpy(gr, &gr_elem_type_name, sizeof(gr_t));
          break;

        case GR_ELEM_ABSTRACT_DECLARATOR:
          memcpy(gr, &gr_elem_abstract_declarator, sizeof(gr_t));
          break;

        case GR_ELEM_DIRECT_ABSTRACT_DECLARATOR:
          memcpy(gr, &gr_elem_direct_abstract_declarator, sizeof(gr_t));
          break;

        case GR_ELEM_ARRAY_ABSTRACT_DECLARATOR:
          memcpy(gr, &gr_elem_array_abstract_declarator, sizeof(gr_t));
          break;

        case GR_ELEM_FUNCTION_ABSTRACT_DECLARATOR:
          memcpy(gr, &gr_elem_function_abstract_declarator, sizeof(gr_t));
          break;

        case GR_ELEM_TYPEDEF_NAME:
          memcpy(gr, &gr_elem_typedef_name, sizeof(gr_t));
          break;

        case GR_ELEM_BRACED_INITIALIZER:
          memcpy(gr, &gr_elem_braced_initializer, sizeof(gr_t));
          break;

        case GR_ELEM_INITIALIZER:
          memcpy(gr, &gr_elem_initializer, sizeof(gr_t));
          break;

        case GR_ELEM_INITIALIZER_LIST:
          memcpy(gr, &gr_elem_initializer_list, sizeof(gr_t));
          break;

        case GR_ELEM_DESIGNATION:
          memcpy(gr, &gr_elem_designation, sizeof(gr_t));
          break;

        case GR_ELEM_DESIGNATOR_LIST:
          memcpy(gr, &gr_elem_designator_list, sizeof(gr_t));
          break;

        case GR_ELEM_DESIGNATOR:
          memcpy(gr, &gr_elem_designator, sizeof(gr_t));
          break;

        case GR_ELEM_STATIC_ASSERT_DECLARATION:
          memcpy(gr, &gr_elem_static_assert_declaration, sizeof(gr_t));
          break;

        case GR_ELEM_ATTRIBUTE_SPECIFIER_SEQUENCE:
          memcpy(gr, &gr_elem_attribute_specifier_sequence, sizeof(gr_t));
          break;

        case GR_ELEM_ATTRIBUTE_SPECIFIER:
          memcpy(gr, &gr_elem_attribute_specifier, sizeof(gr_t));
          break;

        case GR_ELEM_ATTRIBUTE_LIST:
          memcpy(gr, &gr_elem_attribute_list, sizeof(gr_t));
          break;

        case GR_ELEM_ATTRIBUTE:
          memcpy(gr, &gr_elem_attribute, sizeof(gr_t));
          break;

        case GR_ELEM_ATTRIBUTE_TOKEN:
          memcpy(gr, &gr_elem_attribute_token, sizeof(gr_t));
          break;

        case GR_ELEM_STANDARD_ATTRIBUTE:
          memcpy(gr, &gr_elem_standard_attribute, sizeof(gr_t));
          break;

        case GR_ELEM_ATTRIBUTE_PREFIXED_TOKEN:
          memcpy(gr, &gr_elem_attribute_prefixed_token, sizeof(gr_t));
          break;

        case GR_ELEM_ATTRIBUTE_PREFIX:
          memcpy(gr, &gr_elem_attribute_prefix, sizeof(gr_t));
          break;

        case GR_ELEM_ATTRIBUTE_ARGUMENT_CLAUSE:
          memcpy(gr, &gr_elem_attribute_argument_clause, sizeof(gr_t));
          break;

        case GR_ELEM_BALANCED_TOKEN_SEQUENCE:
          memcpy(gr, &gr_elem_balanced_token_sequence, sizeof(gr_t));
          break;

        case GR_ELEM_BALANCED_TOKEN:
          memcpy(gr, &gr_elem_balanced_token, sizeof(gr_t));
          break;

        case GR_ELEM_STATEMENT:
          memcpy(gr, &gr_elem_statement, sizeof(gr_t));
          break;

        case GR_ELEM_UNLABELED_STATEMENT:
          memcpy(gr, &gr_elem_unlabeled_statement, sizeof(gr_t));
          break;

        case GR_ELEM_PRIMARY_BLOCK:
          memcpy(gr, &gr_elem_primary_block, sizeof(gr_t));
          break;

        case GR_ELEM_SECONDARY_BLOCK:
          memcpy(gr, &gr_elem_secondary_block, sizeof(gr_t));
          break;

        case GR_ELEM_LABEL:
          memcpy(gr, &gr_elem_label, sizeof(gr_t));
          break;

        case GR_ELEM_LABELED_STATEMENT:
          memcpy(gr, &gr_elem_labeled_statement, sizeof(gr_t));
          break;

        case GR_ELEM_COMPOUND_STATEMENT:
          memcpy(gr, &gr_elem_compound_statement, sizeof(gr_t));
          break;

        case GR_ELEM_BLOCK_ITEM_LIST:
          memcpy(gr, &gr_elem_block_item_list, sizeof(gr_t));
          break;

        case GR_ELEM_BLOCK_ITEM:
          memcpy(gr, &gr_elem_block_item, sizeof(gr_t));
          break;

        case GR_ELEM_EXPRESSION_STATEMENT:
          memcpy(gr, &gr_elem_expression_statement, sizeof(gr_t));
          break;

        case GR_ELEM_SELECTION_STATEMENT:
          memcpy(gr, &gr_elem_selection_statement, sizeof(gr_t));
          break;

        case GR_ELEM_ITERATION_STATEMENT:
          memcpy(gr, &gr_elem_iteration_statement, sizeof(gr_t));
          break;

        case GR_ELEM_JUMP_STATEMENT:
          memcpy(gr, &gr_elem_jump_statement, sizeof(gr_t));
          break;

        case GR_ELEM_TRANSLATION_UNIT:
          memcpy(gr, &gr_elem_translation_unit, sizeof(gr_t));
          break;

        case GR_ELEM_EXTERNAL_DECLARATION:
          memcpy(gr, &gr_elem_external_declaration, sizeof(gr_t));
          break;

        case GR_ELEM_FUNCTION_DEFINITION:
          memcpy(gr, &gr_elem_function_definition, sizeof(gr_t));
          break;

        case GR_ELEM_FUNCTION_BODY:
          memcpy(gr, &gr_elem_function_body, sizeof(gr_t));
          break;

        case GR_ELEM_START:
          memcpy(gr, &gr_elem_start, sizeof(gr_t));
          break;

        default:
          gr_free(gr);
          gr = NULL;
          break;
      }
    }
  }

  return gr;
}
