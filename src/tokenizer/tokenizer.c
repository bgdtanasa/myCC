#include "tokenizer.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef enum {
  TOKENIZER_MODE_CHAR,
  TOKENIZER_MODE_LONGEST_MATCH,
} tokenizer_mode_t;

typedef struct {
  const token_type_t       type;
  const char* const        name;
} token_keyword_t;

typedef struct {
  const token_type_t type;
  const char* const  name;
  const char* const  alias;
} token_keyword_basic_type_t;

token_identifier_typedef_t token_identifier_typedefs = {
  .no_identifiers = 1u,
  .identifiers    = {
    "__builtin_va_list"
  }
};
const char* const token_type_name[ ] = {
  [ TOKEN_INVALID ]                                      = "invalid",
  //
  [ TOKEN_NON_DIGIT_a ]                                  = "a",
  [ TOKEN_NON_DIGIT_b ]                                  = "b",
  [ TOKEN_NON_DIGIT_c ]                                  = "c",
  [ TOKEN_NON_DIGIT_d ]                                  = "d",
  [ TOKEN_NON_DIGIT_e ]                                  = "e",
  [ TOKEN_NON_DIGIT_f ]                                  = "f",
  [ TOKEN_NON_DIGIT_g ]                                  = "g",
  [ TOKEN_NON_DIGIT_h ]                                  = "h",
  [ TOKEN_NON_DIGIT_i ]                                  = "i",
  [ TOKEN_NON_DIGIT_j ]                                  = "j",
  [ TOKEN_NON_DIGIT_k ]                                  = "k",
  [ TOKEN_NON_DIGIT_l ]                                  = "l",
  [ TOKEN_NON_DIGIT_m ]                                  = "m",
  [ TOKEN_NON_DIGIT_n ]                                  = "n",
  [ TOKEN_NON_DIGIT_o ]                                  = "o",
  [ TOKEN_NON_DIGIT_p ]                                  = "p",
  [ TOKEN_NON_DIGIT_q ]                                  = "q",
  [ TOKEN_NON_DIGIT_r ]                                  = "r",
  [ TOKEN_NON_DIGIT_s ]                                  = "s",
  [ TOKEN_NON_DIGIT_t ]                                  = "t",
  [ TOKEN_NON_DIGIT_u ]                                  = "u",
  [ TOKEN_NON_DIGIT_v ]                                  = "v",
  [ TOKEN_NON_DIGIT_w ]                                  = "w",
  [ TOKEN_NON_DIGIT_x ]                                  = "x",
  [ TOKEN_NON_DIGIT_y ]                                  = "y",
  [ TOKEN_NON_DIGIT_z ]                                  = "z",
  [ TOKEN_NON_DIGIT_A ]                                  = "A",
  [ TOKEN_NON_DIGIT_B ]                                  = "B",
  [ TOKEN_NON_DIGIT_C ]                                  = "C",
  [ TOKEN_NON_DIGIT_D ]                                  = "D",
  [ TOKEN_NON_DIGIT_E ]                                  = "E",
  [ TOKEN_NON_DIGIT_F ]                                  = "F",
  [ TOKEN_NON_DIGIT_G ]                                  = "G",
  [ TOKEN_NON_DIGIT_H ]                                  = "H",
  [ TOKEN_NON_DIGIT_I ]                                  = "I",
  [ TOKEN_NON_DIGIT_J ]                                  = "J",
  [ TOKEN_NON_DIGIT_K ]                                  = "K",
  [ TOKEN_NON_DIGIT_L ]                                  = "L",
  [ TOKEN_NON_DIGIT_M ]                                  = "M",
  [ TOKEN_NON_DIGIT_N ]                                  = "N",
  [ TOKEN_NON_DIGIT_O ]                                  = "O",
  [ TOKEN_NON_DIGIT_P ]                                  = "P",
  [ TOKEN_NON_DIGIT_Q ]                                  = "Q",
  [ TOKEN_NON_DIGIT_R ]                                  = "R",
  [ TOKEN_NON_DIGIT_S ]                                  = "S",
  [ TOKEN_NON_DIGIT_T ]                                  = "T",
  [ TOKEN_NON_DIGIT_U ]                                  = "U",
  [ TOKEN_NON_DIGIT_V ]                                  = "V",
  [ TOKEN_NON_DIGIT_W ]                                  = "W",
  [ TOKEN_NON_DIGIT_X ]                                  = "X",
  [ TOKEN_NON_DIGIT_Y ]                                  = "Y",
  [ TOKEN_NON_DIGIT_Z ]                                  = "Z",
  [ TOKEN_DIGIT_0 ]                                      = "0",
  [ TOKEN_DIGIT_1 ]                                      = "1",
  [ TOKEN_DIGIT_2 ]                                      = "2",
  [ TOKEN_DIGIT_3 ]                                      = "3",
  [ TOKEN_DIGIT_4 ]                                      = "4",
  [ TOKEN_DIGIT_5 ]                                      = "5",
  [ TOKEN_DIGIT_6 ]                                      = "6",
  [ TOKEN_DIGIT_7 ]                                      = "7",
  [ TOKEN_DIGIT_8 ]                                      = "8",
  [ TOKEN_DIGIT_9 ]                                      = "9",
  // Keywords
  [ TOKEN_IS_KEYWORD_BEGIN ]                             = "",
  [ TOKEN_KEYWORD_ALIGNAS ]                              = "alignas",
  [ TOKEN_KEYWORD_ALIGNOF ]                              = "alignof",
  [ TOKEN_KEYWORD_AUTO ]                                 = "auto",
  [ TOKEN_KEYWORD_BOOL ]                                 = "bool",
  [ TOKEN_KEYWORD_BREAK ]                                = "break",
  [ TOKEN_KEYWORD_CASE ]                                 = "case",
  [ TOKEN_KEYWORD_CHAR ]                                 = "char",
  [ TOKEN_KEYWORD_CONST ]                                = "const",
  [ TOKEN_KEYWORD_CONSTEXPR ]                            = "constexpr",
  [ TOKEN_KEYWORD_CONTINUE ]                             = "continue",
  [ TOKEN_KEYWORD_DEFAULT ]                              = "default",
  [ TOKEN_KEYWORD_DO ]                                   = "do",
  [ TOKEN_KEYWORD_DOUBLE ]                               = "double",
  [ TOKEN_KEYWORD_ELSE ]                                 = "else",
  [ TOKEN_KEYWORD_ENUM ]                                 = "enum",
  [ TOKEN_KEYWORD_EXTERN ]                               = "extern",
  [ TOKEN_KEYWORD_FALSE ]                                = "false",
  [ TOKEN_KEYWORD_FLOAT ]                                = "float",
  [ TOKEN_KEYWORD_FOR ]                                  = "for",
  [ TOKEN_KEYWORD_GOTO ]                                 = "goto",
  [ TOKEN_KEYWORD_IF ]                                   = "if",
  [ TOKEN_KEYWORD_INLINE ]                               = "inline",
  [ TOKEN_KEYWORD_INT ]                                  = "int",
  [ TOKEN_KEYWORD_LONG ]                                 = "long",
  [ TOKEN_KEYWORD_NULLPTR ]                              = "nullptr",
  [ TOKEN_KEYWORD_REGISTER ]                             = "register",
  [ TOKEN_KEYWORD_RESTRICT ]                             = "restrict",
  [ TOKEN_KEYWORD_RETURN ]                               = "return",
  [ TOKEN_KEYWORD_SHORT ]                                = "short",
  [ TOKEN_KEYWORD_SIGNED ]                               = "signed",
  [ TOKEN_KEYWORD_SIZEOF ]                               = "sizeof",
  [ TOKEN_KEYWORD_STATIC ]                               = "static",
  [ TOKEN_KEYWORD_STATIC_ASSERT ]                        = "static_assert",
  [ TOKEN_KEYWORD_STRUCT ]                               = "struct",
  [ TOKEN_KEYWORD_SWITCH ]                               = "switch",
  [ TOKEN_KEYWORD_THREAD_LOCAL ]                         = "thread_local",
  [ TOKEN_KEYWORD_TRUE ]                                 = "true",
  [ TOKEN_KEYWORD_TYPEDEF ]                              = "typedef",
  [ TOKEN_KEYWORD_TYPEOF ]                               = "typeof",
  [ TOKEN_KEYWORD_TYPEOF_UNQUAL ]                        = "typeof_unqual",
  [ TOKEN_KEYWORD_UNION ]                                = "union",
  [ TOKEN_KEYWORD_UNSIGNED ]                             = "unsigned",
  [ TOKEN_KEYWORD_VOID ]                                 = "void",
  [ TOKEN_KEYWORD_VOLATILE ]                             = "volatile",
  [ TOKEN_KEYWORD_WHILE ]                                = "while",
  [ TOKEN_KEYWORD__ATOMIC ]                              = "_Atomic",
  [ TOKEN_KEYWORD__BITINT ]                              = "_BitInt",
  [ TOKEN_KEYWORD__COMPLEX ]                             = "_Complex",
  [ TOKEN_KEYWORD__DECIMAL128 ]                          = "_Decimal128",
  [ TOKEN_KEYWORD__DECIMAL64 ]                           = "_Decimal64",
  [ TOKEN_KEYWORD__DECIMAL32 ]                           = "_Decimal32",
  [ TOKEN_KEYWORD__GENERIC ]                             = "_Generic",
  [ TOKEN_KEYWORD__IMAGINARY ]                           = "_Imaginary",
  [ TOKEN_KEYWORD__NORETURN ]                            = "_NoReturn",
  [ TOKEN_KEYWORD_SIGNED_CHAR ]                          = "signed char",
  [ TOKEN_KEYWORD_SIGNED_SHORT_INT ]                     = "signed short int",
  [ TOKEN_KEYWORD_SIGNED_INT ]                           = "signed int",
  [ TOKEN_KEYWORD_SIGNED_LONG_INT ]                      = "signed long int",
  [ TOKEN_KEYWORD_SIGNED_LONG_LONG_INT ]                 = "signed long long int",
  [ TOKEN_KEYWORD_UNSIGNED_CHAR ]                        = "unsigned char",
  [ TOKEN_KEYWORD_UNSIGNED_SHORT_INT ]                   = "unsigned short int",
  [ TOKEN_KEYWORD_UNSIGNED_INT ]                         = "unsigned int",
  [ TOKEN_KEYWORD_UNSIGNED_LONG_INT ]                    = "unsigned long int",
  [ TOKEN_KEYWORD_UNSIGNED_LONG_LONG_INT ]               = "unsigned long long int",
  [ TOKEN_KEYWORD_LONG_DOUBLE ]                          = "long double",
  [ TOKEN_KEYWORD_SINT8 ]                                = "sint8_t",
  [ TOKEN_KEYWORD_UINT8 ]                                = "uint8_t",
  [ TOKEN_KEYWORD_SINT16 ]                               = "sint16_t",
  [ TOKEN_KEYWORD_UINT16 ]                               = "uint16_t",
  [ TOKEN_KEYWORD_SINT32 ]                               = "sint32_t",
  [ TOKEN_KEYWORD_UINT32 ]                               = "uint32_t",
  [ TOKEN_KEYWORD_SINT64 ]                               = "sint64_t",
  [ TOKEN_KEYWORD_UINT64 ]                               = "uint64_t",
  [ TOKEN_KEYWORD_FLOAT32 ]                              = "float32_t",
  [ TOKEN_KEYWORD_FLOAT64 ]                              = "float64_t",
  [ TOKEN_KEYWORD_FLOAT128 ]                             = "float128_t",
  [ TOKEN_IS_KEYWORD_END ]                               = "",
  // Separators
  [ TOKEN_IS_SEPARATOR_BEGIN ]                           = "",
  [ TOKEN_SEPARATOR_BRACKET_ROUND_OPEN ]                 = "(",
  [ TOKEN_SEPARATOR_BRACKET_ROUND_CLOSED ]               = ")",
  [ TOKEN_SEPARATOR_BRACKET_SQUARE_OPEN ]                = "[",
  [ TOKEN_SEPARATOR_BRACKET_SQUARE_CLOSED ]              = "]",
  [ TOKEN_SEPARATOR_BRACKET_CURLY_OPEN ]                 = "{",
  [ TOKEN_SEPARATOR_BRACKET_CURLY_CLOSED ]               = "}",
  [ TOKEN_SEPARATOR_SPACE ]                              = " ",
  [ TOKEN_SEPARATOR_QUOTE ]                              = "\"",
  [ TOKEN_SEPARATOR_AMPERSAND ]                          = "&",
  [ TOKEN_SEPARATOR_APOSTROPHE ]                         = "'",
  [ TOKEN_SEPARATOR_ASTERISK ]                           = "*",
  [ TOKEN_SEPARATOR_PLUS ]                               = "+",
  [ TOKEN_SEPARATOR_COMMA ]                              = ",",
  [ TOKEN_SEPARATOR_MINUS ]                              = "-",
  [ TOKEN_SEPARATOR_PERIOD ]                             = ".",
  [ TOKEN_SEPARATOR_COLON ]                              = ":",
  [ TOKEN_SEPARATOR_SEMICOLON ]                          = ";",
  [ TOKEN_SEPARATOR_BACKSLASH ]                          = "\\",
  [ TOKEN_IS_SEPARATOR_END ]                             = "",
  // Escape sequences
  [ TOKEN_ESCAPE_a ]                                     = "\\a",
  [ TOKEN_ESCAPE_b ]                                     = "\\b",
  [ TOKEN_ESCAPE_f ]                                     = "\\f",
  [ TOKEN_ESCAPE_n ]                                     = "\\n",
  [ TOKEN_ESCAPE_r ]                                     = "\\r",
  [ TOKEN_ESCAPE_t ]                                     = "\\t",
  [ TOKEN_ESCAPE_v ]                                     = "\\v",
  [ TOKEN_ESCAPE_x ]                                     = "\\x",
  [ TOKEN_ESCAPE_QUOTE ]                                 = "\\\"",
  [ TOKEN_ESCAPE_APOSTROPHE ]                            = "\\\'",
  [ TOKEN_ESCAPE_BACKSLASH ]                             = "\\\\",
  [ TOKEN_ESCAPE_QUESTION_MARK ]                         = "\\?",
  // Operators
  [ TOKEN_IS_OPERATOR_BEGIN ]                            = "",
  [ TOKEN_OPERATOR_ASSIGNMENT_BASIC ]                    = "=",
  [ TOKEN_OPERATOR_ASSIGNMENT_ADDITION ]                 = "+=",
  [ TOKEN_OPERATOR_ASSIGNMENT_SUBTRACTION ]              = "-=",
  [ TOKEN_OPERATOR_ASSIGNMENT_MULTIPLICATION ]           = "*=",
  [ TOKEN_OPERATOR_ASSIGNMENT_DIVISION ]                 = "/=",
  [ TOKEN_OPERATOR_ASSIGNMENT_MODULO ]                   = "%=",
  [ TOKEN_OPERATOR_ASSIGNMENT_BITWISE_AND ]              = "&=",
  [ TOKEN_OPERATOR_ASSIGNMENT_BITWISE_OR ]               = "|=",
  [ TOKEN_OPERATOR_ASSIGNMENT_BITWISE_XOR ]              = "^=",
  [ TOKEN_OPERATOR_ASSIGNMENT_BITWISE_SHIFT_LEFT ]       = "<<=",
  [ TOKEN_OPERATOR_ASSIGNMENT_BITWISE_SHIFT_RIGHT ]      = ">>=",
  [ TOKEN_OPERATOR_INCREMENT ]                           = "++",
  [ TOKEN_OPERATOR_DECREMENT ]                           = "--",
  [ TOKEN_OPERATOR_ARITHMETIC_UNARY_PLUS ]               = "+",
  [ TOKEN_OPERATOR_ARITHMETIC_UNARY_MINUS ]              = "-",
  [ TOKEN_OPERATOR_ARITHMETIC_ADDITION ]                 = "+",
  [ TOKEN_OPERATOR_ARITHMETIC_SUBTRACTION ]              = "-",
  [ TOKEN_OPERATOR_ARITHMETIC_PRODUCT ]                  = "*",
  [ TOKEN_OPERATOR_ARITHMETIC_DIVISION ]                 = "/",
  [ TOKEN_OPERATOR_ARITHMETIC_REMAINDER ]                = "%",
  [ TOKEN_OPERATOR_ARITHMETIC_BITWISE_NOT ]              = "~",
  [ TOKEN_OPERATOR_ARITHMETIC_BITWISE_AND ]              = "&",
  [ TOKEN_OPERATOR_ARITHMETIC_BITWISE_OR ]               = "|",
  [ TOKEN_OPERATOR_ARITHMETIC_BITWISE_XOR ]              = "^",
  [ TOKEN_OPERATOR_ARITHMETIC_BITWISE_SHIFT_LEFT ]       = "<<",
  [ TOKEN_OPERATOR_ARITHMETIC_BITWISE_SHIFT_RIGHT ]      = ">>",
  [ TOKEN_OPERATOR_LOGICAL_NOT ]                         = "!",
  [ TOKEN_OPERATOR_LOGICAL_AND ]                         = "&&",
  [ TOKEN_OPERATOR_LOGICAL_OR ]                          = "||",
  [ TOKEN_OPERATOR_COMPARISON_EQUAL_TO ]                 = "==",
  [ TOKEN_OPERATOR_COMPARISON_NOT_EQUAL_TO ]             = "!=",
  [ TOKEN_OPERATOR_COMPARISON_LESS_THAN ]                = "<",
  [ TOKEN_OPERATOR_COMPARISON_LESS_THAN_OR_EQUAL_TO ]    = "<=",
  [ TOKEN_OPERATOR_COMPARISON_GREATER_THAN ]             = ">",
  [ TOKEN_OPERATOR_COMPARISON_GREATER_THAN_OR_EQUAL_TO ] = ">=",
  [ TOKEN_OPERATOR_FUNCTION_CALL_BEGIN ]                 = "(",
  [ TOKEN_OPERATOR_FUNCTION_CALL_END ]                   = ")",
  [ TOKEN_OPERATOR_ACCESS_ARRAY_SUBSCRIPT_BEGIN ]        = "[",
  [ TOKEN_OPERATOR_ACCESS_ARRAY_SUBSCRIPT_END ]          = "]",
  [ TOKEN_OPERATOR_ACCESS_POINTER_DEREFERENCE ]          = "*",
  [ TOKEN_OPERATOR_ACCESS_ADDRESS_OF ]                   = "&",
  [ TOKEN_OPERATOR_ACCESS_FIELD ]                        = ".",
  [ TOKEN_OPERATOR_ACCESS_FIELD_VIA_POINTER ]            = "->",
  [ TOKEN_OPERATOR_COMMA ]                               = ",",
  [ TOKEN_OPERATOR_CONDITIONAL_PART_ONE ]                = "?",
  [ TOKEN_OPERATOR_CONDITIONAL_PART_TWO ]                = ":",
  [ TOKEN_IS_OPERATOR_END ]                              = "",
  // Body
  [ TOKEN_BODY_BEGIN ]                                   = "{",
  [ TOKEN_BODY_END ]                                     = "}",
  // Compound Literals
  [ TOKEN_COMPOUND_LITERAL_BEGIN ]                       = "(",
  [ TOKEN_COMPOUND_LITERAL_END ]                         = ")",
  // Declarators
  [ TOKEN_DECLARATOR_POINTER ]                           = "*",
  [ TOKEN_DECLARATOR_BINDER_BEGIN ]                      = "(",
  [ TOKEN_DECLARATOR_BINDER_END ]                        = ")",
  [ TOKEN_DECLARATOR_ARRAY_BEGIN ]                       = "[",
  [ TOKEN_DECLARATOR_ARRAY_END ]                         = "]",
  [ TOKEN_DECLARATOR_FUNCTION_BEGIN ]                    = "(",
  [ TOKEN_DECLARATOR_FUNCTION_END ]                      = ")",
  // Designators
  [ TOKEN_DESIGNATOR_ARRAY_ELEM_BEGIN ]                  = "[",
  [ TOKEN_DESIGNATOR_ARRAY_ELEM_END ]                    = "]",
  [ TOKEN_DESIGNATOR_STRUCT_OR_UNION_MEMBER ]            = ".",
  // Lists
  [ TOKEN_LIST_DELIMITER ]                               = ",",
  // Placeholders
  [ TOKEN_PLACEHOLDER_VLA ]                              = "*",
  // Parameters
  [ TOKEN_PARAMETER_VARIADIC_ARGS ]                      = "...",
  // Labels
  [ TOKEN_LABEL_DECLARATION ]                            = ":",
  // Bit Fields
  [ TOKEN_BIT_FIELD_WIDTH_DECLARATION_STRUCT_OR_UNION ]  = ":",
  // Identifiers
  [ TOKEN_IDENTIFIER ]                                   = "identifier",
  [ TOKEN_IDENTIFIER_TYPEDEF ]                           = "identifier_typedef",
  // Attributes
  [ TOKEN_ATTRIBUTE_DELIMITER_BEGIN ]                    = "[[",
  [ TOKEN_ATTRIBUTE_DELIMITER_END ]                      = "]]",
  [ TOKEN_ATTRIBUTE_SCOPE ]                              = "::",
  //
  [ TOKEN_MAX_NO_TOKENS ]                                = ""
};

static token_keyword_t keywords[  ] = {
  [  0u ] = {
    .type = TOKEN_KEYWORD_ALIGNAS,
    .name = "alignas",
  },
  [  1u ] = {
    .type = TOKEN_KEYWORD_ALIGNOF,
    .name = "alignof",
  },
  [  2u ] = {
    .type = TOKEN_KEYWORD_AUTO,
    .name = "auto",
  },
  [  3u ] = {
    .type = TOKEN_KEYWORD_BOOL,
    .name = "bool",
  },
  [  4u ] = {
    .type = TOKEN_KEYWORD_BREAK,
    .name = "break",
  },
  [  5u ] = {
    .type = TOKEN_KEYWORD_CASE,
    .name = "case",
  },
  [  6u ] = {
    .type = TOKEN_KEYWORD_CHAR,
    .name = "char",
  },
  [  7u ] = {
    .type = TOKEN_KEYWORD_CONST,
    .name = "const",
  },
  [  8u ] = {
    .type = TOKEN_KEYWORD_CONSTEXPR,
    .name = "constexpr",
  },
  [  9u ] = {
    .type = TOKEN_KEYWORD_CONTINUE,
    .name = "continue",
  },
  [ 10u ] = {
    .type = TOKEN_KEYWORD_DEFAULT,
    .name = "default",
  },
  [ 11u ] = {
    .type = TOKEN_KEYWORD_DO,
    .name = "do",
  },
  [ 12u ] = {
    .type = TOKEN_KEYWORD_DOUBLE,
    .name = "double",
  },
  [ 13u ] = {
    .type = TOKEN_KEYWORD_ELSE,
    .name = "else",
  },
  [ 14u ] = {
    .type = TOKEN_KEYWORD_ENUM,
    .name = "enum",
  },
  [ 15u ] = {
    .type = TOKEN_KEYWORD_EXTERN,
    .name = "extern",
  },
  [ 16u ] = {
    .type = TOKEN_KEYWORD_FALSE,
    .name = "false",
  },
  [ 17u ] = {
    .type = TOKEN_KEYWORD_FLOAT,
    .name = "float",
  },
  [ 18u ] = {
    .type = TOKEN_KEYWORD_FOR,
    .name = "for",
  },
  [ 19u ] = {
    .type = TOKEN_KEYWORD_GOTO,
    .name = "goto",
  },
  [ 20u ] = {
    .type = TOKEN_KEYWORD_IF,
    .name = "if",
  },
  [ 21u ] = {
    .type = TOKEN_KEYWORD_INLINE,
    .name = "inline",
  },
  [ 22u ] = {
    .type = TOKEN_KEYWORD_INT,
    .name = "int",
  },
  [ 23u ] = {
    .type = TOKEN_KEYWORD_LONG,
    .name = "long",
  },
  [ 24u ] = {
    .type = TOKEN_KEYWORD_REGISTER,
    .name = "register",
  },
  [ 25u ] = {
    .type = TOKEN_KEYWORD_RESTRICT,
    .name = "restrict",
  },
  [ 26u ] = {
    .type = TOKEN_KEYWORD_RETURN,
    .name = "return",
  },
  [ 27u ] = {
    .type = TOKEN_KEYWORD_SHORT,
    .name = "short",
  },
  [ 28u ] = {
    .type = TOKEN_KEYWORD_SIGNED,
    .name = "signed",
  },
  [ 29u ] = {
    .type = TOKEN_KEYWORD_SIZEOF,
    .name = "sizeof",
  },
  [ 30u ] = {
    .type = TOKEN_KEYWORD_STATIC,
    .name = "static",
  },
  [ 31u ] = {
    .type = TOKEN_KEYWORD_STATIC_ASSERT,
    .name = "static_assert",
  },
  [ 32u ] = {
    .type = TOKEN_KEYWORD_STRUCT,
    .name = "struct",
  },
  [ 33u ] = {
    .type = TOKEN_KEYWORD_SWITCH,
    .name = "switch",
  },
  [ 34u ] = {
    .type = TOKEN_KEYWORD_THREAD_LOCAL,
    .name = "thread_local",
  },
  [ 35u ] = {
    .type = TOKEN_KEYWORD_TRUE,
    .name = "true",
  },
  [ 36u ] = {
    .type = TOKEN_KEYWORD_TYPEDEF,
    .name = "typedef",
  },
  [ 37u ] = {
    .type = TOKEN_KEYWORD_TYPEOF,
    .name = "typeof",
  },
  [ 38u ] = {
    .type = TOKEN_KEYWORD_TYPEOF_UNQUAL,
    .name = "typeof_unqual",
  },
  [ 39u ] = {
    .type = TOKEN_KEYWORD_UNION,
    .name = "union",
  },
  [ 40u ] = {
    .type = TOKEN_KEYWORD_UNSIGNED,
    .name = "unsigned",
  },
  [ 41u ] = {
    .type = TOKEN_KEYWORD_VOID,
    .name = "void",
  },
  [ 42u ] = {
    .type = TOKEN_KEYWORD_VOLATILE,
    .name = "volatile",
  },
  [ 43u ] = {
    .type = TOKEN_KEYWORD_WHILE,
    .name = "while",
  },
  [ 44u ] = {
    .type = TOKEN_KEYWORD__ATOMIC,
    .name = "_Atomic",
  },
  [ 45u ] = {
    .type = TOKEN_KEYWORD__BITINT,
    .name = "_BitInt",
  },
  [ 46u ] = {
    .type = TOKEN_KEYWORD__COMPLEX,
    .name = "_Complex",
  },
  [ 47u ] = {
    .type = TOKEN_KEYWORD__DECIMAL128,
    .name = "_Decimal128",
  },
  [ 48u ] = {
    .type = TOKEN_KEYWORD__DECIMAL64,
    .name = "_Decimal64",
  },
  [ 49u ] = {
    .type = TOKEN_KEYWORD__DECIMAL32,
    .name = "_Decimal32",
  },
  [ 50u ] = {
    .type = TOKEN_KEYWORD__GENERIC,
    .name = "_Generic",
  },
  [ 51u ] = {
    .type = TOKEN_KEYWORD__IMAGINARY,
    .name = "_Imaginary",
  },
  [ 52u ] = {
    .type = TOKEN_KEYWORD__NORETURN,
    .name = "_Noreturn",
  },

  // Alternative Spelling
  [ 53u ] = {
    .type = TOKEN_KEYWORD_ALIGNAS,
    .name = "_Alignas",
  },
  [ 54u ] = {
    .type = TOKEN_KEYWORD_ALIGNOF,
    .name = "_Alignof",
  },
  [ 55u ] = {
    .type = TOKEN_KEYWORD_BOOL,
    .name = "_Bool",
  },
  [ 56u ] = {
    .type = TOKEN_KEYWORD_STATIC_ASSERT,
    .name = "_Static_assert",
  },
  [ 57u ] = {
    .type = TOKEN_KEYWORD_THREAD_LOCAL,
    .name = "_Thread_local",
  },

  // End of array marker
  [ 58u ] = {
    .type = TOKEN_INVALID,
    .name = NULL,
  },
};

static token_keyword_basic_type_t basic_types[  ] = {
  [  0u ] = {
    .type  = TOKEN_KEYWORD_UINT64,
    .name  = "unsigned long long int",
    .alias = "uint64_t"
  },
  [  1u ] = {
    .type  = TOKEN_KEYWORD_UINT64,
    .name  = "long unsigned long int",
    .alias = "uint64_t"
  },
  [  2u ] = {
    .type  = TOKEN_KEYWORD_UINT64,
    .name  = "long long unsigned int",
    .alias = "uint64_t"
  },
  [  3u ] = {
    .type  = TOKEN_KEYWORD_UINT64,
    .name  = "long long int unsigned",
    .alias = "uint64_t"
  },
  [  4u ] = {
    .type  = TOKEN_KEYWORD_UINT64,
    .name  = "int long long unsigned",
    .alias = "uint64_t"
  },
  [  5u ] = {
    .type  = TOKEN_KEYWORD_UINT64,
    .name  = "long int long unsigned",
    .alias = "uint64_t"
  },
  [  6u ] = {
    .type  = TOKEN_KEYWORD_UINT64,
    .name  = "int unsigned long long",
    .alias = "uint64_t"
  },
  [  7u ] = {
    .type  = TOKEN_KEYWORD_UINT64,
    .name  = "unsigned int long long",
    .alias = "uint64_t"
  },
  [  8u ] = {
    .type  = TOKEN_KEYWORD_UINT64,
    .name  = "long int unsigned long",
    .alias = "uint64_t"
  },
  [  9u ] = {
    .type  = TOKEN_KEYWORD_UINT64,
    .name  = "int long unsigned long",
    .alias = "uint64_t"
  },
  [ 10u ] = {
    .type  = TOKEN_KEYWORD_UINT64,
    .name  = "unsigned long int long",
    .alias = "uint64_t"
  },
  [ 11u ] = {
    .type  = TOKEN_KEYWORD_UINT64,
    .name  = "long unsigned int long",
    .alias = "uint64_t"
  },

  [ 12u ] = {
    .type  = TOKEN_KEYWORD_SINT64,
    .name  = "signed long long int",
    .alias = "sint64_t"
  },
  [ 13u ] = {
    .type  = TOKEN_KEYWORD_SINT64,
    .name  = "long signed long int",
    .alias = "sint64_t"
  },
  [ 14u ] = {
    .type  = TOKEN_KEYWORD_SINT64,
    .name  = "long long signed int",
    .alias = "sint64_t"
  },
  [ 15u ] = {
    .type  = TOKEN_KEYWORD_SINT64,
    .name  = "long long int signed",
    .alias = "sint64_t"
  },
  [ 16u ] = {
    .type  = TOKEN_KEYWORD_SINT64,
    .name  = "int long long signed",
    .alias = "sint64_t"
  },
  [ 17u ] = {
    .type  = TOKEN_KEYWORD_SINT64,
    .name  = "long int long signed",
    .alias = "sint64_t"
  },
  [ 18u ] = {
    .type  = TOKEN_KEYWORD_SINT64,
    .name  = "int signed long long",
    .alias = "sint64_t"
  },
  [ 19u ] = {
    .type  = TOKEN_KEYWORD_SINT64,
    .name  = "signed int long long",
    .alias = "sint64_t"
  },
  [ 20u ] = {
    .type  = TOKEN_KEYWORD_SINT64,
    .name  = "long int signed long",
    .alias = "sint64_t"
  },
  [ 21u ] = {
    .type  = TOKEN_KEYWORD_SINT64,
    .name  = "int long signed long",
    .alias = "sint64_t"
  },
  [ 22u ] = {
    .type  = TOKEN_KEYWORD_SINT64,
    .name  = "signed long int long",
    .alias = "sint64_t"
  },
  [ 23u ] = {
    .type  = TOKEN_KEYWORD_SINT64,
    .name  = "long signed int long",
    .alias = "sint64_t"
  },

  [ 24u ] = {
    .type  = TOKEN_KEYWORD_UINT64,
    .name  = "unsigned long long",
    .alias = "uint64_t"
  },
  [ 25u ] = {
    .type  = TOKEN_KEYWORD_UINT64,
    .name  = "long unsigned long",
    .alias = "uint64_t"
  },
  [ 26u ] = {
    .type  = TOKEN_KEYWORD_UINT64,
    .name  = "long long unsigned",
    .alias = "uint64_t"
  },

  [ 27u ] = {
    .type  = TOKEN_KEYWORD_UINT16,
    .name  = "unsigned short int",
    .alias = "uint16_t"
  },
  [ 28u ] = {
    .type  = TOKEN_KEYWORD_UINT16,
    .name  = "short unsigned int",
    .alias = "uint16_t"
  },
  [ 29u ] = {
    .type  = TOKEN_KEYWORD_UINT16,
    .name  = "int unsigned short",
    .alias = "uint16_t"
  },
  [ 30u ] = {
    .type  = TOKEN_KEYWORD_UINT16,
    .name  = "unsigned int short",
    .alias = "uint16_t"
  },
  [ 31u ] = {
    .type  = TOKEN_KEYWORD_UINT16,
    .name  = "short int unsigned",
    .alias = "uint16_t"
  },
  [ 32u ] = {
    .type  = TOKEN_KEYWORD_UINT16,
    .name  = "int short unsigned",
    .alias = "uint16_t"
  },

  [ 33u ] = {
    .type  = TOKEN_KEYWORD_UINT64,
    .name  = "unsigned long int",
    .alias = "uint64_t"
  },
  [ 34u ] = {
    .type  = TOKEN_KEYWORD_UINT64,
    .name  = "long unsigned int",
    .alias = "uint64_t"
  },
  [ 35u ] = {
    .type  = TOKEN_KEYWORD_UINT64,
    .name  = "int unsigned long",
    .alias = "uint64_t"
  },
  [ 36u ] = {
    .type  = TOKEN_KEYWORD_UINT64,
    .name  = "unsigned int long",
    .alias = "uint64_t"
  },
  [ 37u ] = {
    .type  = TOKEN_KEYWORD_UINT64,
    .name  = "long int unsigned",
    .alias = "uint64_t"
  },
  [ 38u ] = {
    .type  = TOKEN_KEYWORD_UINT64,
    .name  = "int long unsigned",
    .alias = "uint64_t"
  },

  [ 39u ] = {
    .type  = TOKEN_KEYWORD_SINT64,
    .name  = "signed long long",
    .alias = "sint64_t"
  },
  [ 40u ] = {
    .type  = TOKEN_KEYWORD_SINT64,
    .name  = "long signed long",
    .alias = "sint64_t"
  },
  [ 41u ] = {
    .type  = TOKEN_KEYWORD_SINT64,
    .name  = "long long signed",
    .alias = "sint64_t"
  },

  [ 42u ] = {
    .type  = TOKEN_KEYWORD_SINT16,
    .name  = "signed short int",
    .alias = "sint16_t"
  },
  [ 43u ] = {
    .type  = TOKEN_KEYWORD_SINT16,
    .name  = "short signed int",
    .alias = "sint16_t"
  },
  [ 44u ] = {
    .type  = TOKEN_KEYWORD_SINT16,
    .name  = "int signed short",
    .alias = "sint16_t"
  },
  [ 45u ] = {
    .type  = TOKEN_KEYWORD_SINT16,
    .name  = "signed int short",
    .alias = "sint16_t"
  },
  [ 46u ] = {
    .type  = TOKEN_KEYWORD_SINT16,
    .name  = "short int signed",
    .alias = "sint16_t"
  },
  [ 47u ] = {
    .type  = TOKEN_KEYWORD_SINT16,
    .name  = "int short signed",
    .alias = "sint16_t"
  },

  [ 48u ] = {
    .type  = TOKEN_KEYWORD_SINT64,
    .name  = "signed long int",
    .alias = "sint64_t"
  },
  [ 49u ] = {
    .type  = TOKEN_KEYWORD_SINT64,
    .name  = "long signed int",
    .alias = "sint64_t"
  },
  [ 50u ] = {
    .type  = TOKEN_KEYWORD_SINT64,
    .name  = "int signed long",
    .alias = "sint64_t"
  },
  [ 51u ] = {
    .type  = TOKEN_KEYWORD_SINT64,
    .name  = "signed int long",
    .alias = "sint64_t"
  },
  [ 52u ] = {
    .type  = TOKEN_KEYWORD_SINT64,
    .name  = "long int signed",
    .alias = "sint64_t"
  },
  [ 53u ] = {
    .type  = TOKEN_KEYWORD_SINT64,
    .name  = "int long signed",
    .alias = "sint64_t"
  },

  [ 54u ] = {
    .type  = TOKEN_KEYWORD_UINT16,
    .name  = "unsigned short",
    .alias = "uint16_t"
  },
  [ 55u ] = {
    .type  = TOKEN_KEYWORD_UINT16,
    .name  = "short unsigned",
    .alias = "uint16_t"
  },

  [ 56u ] = {
    .type  = TOKEN_KEYWORD_UINT64,
    .name  = "unsigned long",
    .alias = "uint64_t"
  },
  [ 57u ] = {
    .type  = TOKEN_KEYWORD_UINT64,
    .name  = "long unsigned",
    .alias = "uint64_t"
  },

  [ 58u ] = {
    .type  = TOKEN_KEYWORD_UINT8,
    .name  = "unsigned char",
    .alias = "uint8_t"
  },
  [ 59u ] = {
    .type  = TOKEN_KEYWORD_UINT8,
    .name  = "char unsigned",
    .alias = "uint8_t"
  },

  [ 60u ] = {
    .type  = TOKEN_KEYWORD_SINT64,
    .name  = "long long int",
    .alias = "sint64_t"
  },
  [ 61u ] = {
    .type  = TOKEN_KEYWORD_SINT64,
    .name  = "int long long",
    .alias = "sint64_t"
  },
  [ 62u ] = {
    .type  = TOKEN_KEYWORD_SINT64,
    .name  = "long int long",
    .alias = "sint64_t"
  },

  [ 63u ] = {
    .type  = TOKEN_KEYWORD_UINT32,
    .name  = "unsigned int",
    .alias = "uint32_t"
  },
  [ 64u ] = {
    .type  = TOKEN_KEYWORD_UINT32,
    .name  = "int unsigned",
    .alias = "uint32_t"
  },

  [ 65u ] = {
    .type  = TOKEN_KEYWORD_SINT16,
    .name  = "signed short",
    .alias = "sint16_t"
  },
  [ 66u ] = {
    .type  = TOKEN_KEYWORD_SINT16,
    .name  = "short signed",
    .alias = "sint16_t"
  },

  [ 67u ] = {
    .type  = TOKEN_KEYWORD_SINT64,
    .name  = "signed long",
    .alias = "sint64_t"
  },
  [ 68u ] = {
    .type  = TOKEN_KEYWORD_SINT64,
    .name  = "long signed",
    .alias = "sint64_t"
  },

  [ 69u ] = {
    .type  = TOKEN_KEYWORD_SINT8,
    .name  = "signed char",
    .alias = "sint8_t"
  },
  [ 70u ] = {
    .type  = TOKEN_KEYWORD_SINT8,
    .name  = "char signed",
    .alias = "sint8_t"
  },

  [ 71u ] = {
    .type  = TOKEN_KEYWORD_FLOAT128,
    .name  = "long double",
    .alias = "float128_t"
  },
  [ 72u ] = {
    .type  = TOKEN_KEYWORD_FLOAT128,
    .name  = "double long",
    .alias = "float128_t"
  },

  [ 73u ] = {
    .type  = TOKEN_KEYWORD_SINT32,
    .name  = "signed int",
    .alias = "sint32_t"
  },
  [ 74u ] = {
    .type  = TOKEN_KEYWORD_SINT32,
    .name  = "int signed",
    .alias = "sint32_t"
  },

  [ 75u ] = {
    .type  = TOKEN_KEYWORD_SINT64,
    .name  = "long long",
    .alias = "sint64_t"
  },

  [ 76u ] = {
    .type  = TOKEN_KEYWORD_SINT16,
    .name  = "short int",
    .alias = "sint16_t"
  },
  [ 77u ] = {
    .type  = TOKEN_KEYWORD_SINT16,
    .name  = "int short",
    .alias = "sint16_t"
  },

  [ 78u ] = {
    .type  = TOKEN_KEYWORD_SINT64,
    .name  = "long int",
    .alias = "sint64_t"
  },
  [ 79u ] = {
    .type  = TOKEN_KEYWORD_SINT64,
    .name  = "int long",
    .alias = "sint64_t"
  },

  [ 80u ] = {
    .type  = TOKEN_KEYWORD_SINT8,
    .name  = "char",
    .alias = "sint8_t"
  },
  [ 81u ] = {
    .type  = TOKEN_KEYWORD_SINT16,
    .name  = "short",
    .alias = "sint16_t"
  },
  [ 82u ] = {
    .type  = TOKEN_KEYWORD_SINT32,
    .name  = "signed",
    .alias = "sint32_t"
  },
  [ 83u ] = {
    .type  = TOKEN_KEYWORD_SINT32,
    .name  = "int",
    .alias = "sint32_t"
  },
  [ 84u ] = {
    .type  = TOKEN_KEYWORD_SINT64,
    .name  = "long",
    .alias = "sint64_t"
  },
  [ 85u ] = {
    .type  = TOKEN_KEYWORD_UINT32,
    .name  = "unsigned",
    .alias = "uint32_t"
  },

  [ 86u ] = {
    .type  = TOKEN_KEYWORD_FLOAT32,
    .name  = "float",
    .alias = "float32_t"
  },
  [ 87u ] = {
    .type  = TOKEN_KEYWORD_FLOAT64,
    .name  = "double",
    .alias = "float64_t"
  },

  [ 88u ] = {
    .type  = TOKEN_INVALID,
    .name  = NULL,
    .alias = NULL
  }
};

static tokenizer_mode_t tokenizer_mode = TOKENIZER_MODE_LONGEST_MATCH;

static unsigned char buffer[ 1024u ];

static unsigned char* raw_read_ahead(const unsigned char* const src_code,
                                     const off_t                pos,
                                     const off_t                max_pos,
                                     const unsigned int         max_no_chars) {
  unsigned int i = 0u;

  for (; i < max_no_chars; i++) {
    const off_t new_pos = pos + ((off_t) (i));

    if (new_pos >= max_pos) {
      break;
    }
    buffer[ i ] = src_code[ new_pos ];
  }
  buffer[ i ] = '\0';

  return &buffer[ 0u ];
}

static unsigned char* read_ahead(const unsigned char* const src_code,
                                 const off_t                pos,
                                 const off_t                max_pos) {
  const off_t max_i = pos + ((off_t) (sizeof(buffer)));
  off_t       i     = pos;
  const off_t max_j = ((off_t) (strlen(basic_types[ 0u ].name))) + ((off_t) (1u));
  off_t       j     = ((off_t) (0u));

  for (; i < max_i; i++) {
    const unsigned char curr_c = src_code[ i ];

    if (i >= max_pos) {
      break;
    }
    if (j >= max_j) {
      break;
    }

    if ((curr_c != ' ') && (curr_c != '\n') && (curr_c != '\t')) {
      if (('a' <= curr_c) && ((curr_c <= 'z'))) {
        buffer[ j ] = curr_c;
        j++;
      } else {
        break;
      }
    } else {
      if (j >= ((off_t) (1u))) {
        const unsigned char prev_c = buffer[ j - ((off_t) (1u)) ];

        if (('a' <= prev_c) && ((prev_c <= 'z'))) {
          buffer[ j ] = ' ';
          j++;
        }
      }
    }
  }
  buffer[ j ] = '\0';

  return &buffer[ 0u ];
}

token_t* get_token(const unsigned char* const src_code,
                   off_t* const               pos,
                   const off_t                max_pos,
                   unsigned int               get_flags) {
  if ((src_code == NULL) || (pos == NULL)) {
    return NULL;
  } else {
    off_t tmp_pos = *pos;

    if ((tmp_pos < ((off_t) (0))) || (tmp_pos >= max_pos)) {
      return NULL;
    } else {
      unsigned int token_name_pos = 0u;
      token_t*     token          = (token_t*) malloc(sizeof(token_t));

      if (token == NULL) {
        return NULL;
      }
      token->type           = TOKEN_INVALID;
      memset(&token->name[ 0u ], '\0', TOKEN_NAME_MAX_LENGTH);
      token->flags          = 0u;
      token->no_burn_tokens = 0u;
      token->pos            = tmp_pos;

      for (; tmp_pos < max_pos; tmp_pos++) {
        const unsigned char c = src_code[ tmp_pos ];

        if (c == '\n') {
          continue;
        }
        // Ignore white spaces in the beginning of the source code as
        // long as we didn't yet filled in the current token with characters.
        if (((c == ' ') || (c == '\t')) && (token_name_pos == 0u)) {
          continue;
        }

        switch (token->type) {
          case TOKEN_IDENTIFIER:
            if ((c == '_') || ((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')) || ((c >= '0') && (c <= '9'))) {
              token->name[ token_name_pos ] = c;
              token_name_pos++;
              continue;
            } else {
              goto return_token;
            }
            break;

          default:
            break;
        }

        if ((c == '_') || ((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z'))) {
          if (tokenizer_mode == TOKENIZER_MODE_LONGEST_MATCH) {
            token->type                   = TOKEN_IDENTIFIER;
            token->name[ token_name_pos ] = c;
            token_name_pos++;
            continue;
          } else {
            if ((c >= 'a') && (c <= 'z')) {
              token->type       = ((token_type_t) (((unsigned int) (TOKEN_NON_DIGIT_a)) + ((unsigned int) (c - 'a'))));
              token->name[ 0u ] = c;
              tmp_pos += ((off_t) (1u));
            } else if ((c >= 'A') && (c <= 'Z')) {
              token->type       = ((token_type_t) (((unsigned int) (TOKEN_NON_DIGIT_A)) + ((unsigned int) (c - 'A'))));
              token->name[ 0u ] = c;
              tmp_pos += ((off_t) (1u));
            }
          }
        }

        if ((c >= '0') && (c <= '9')) {
          token->type       = ((token_type_t) (((unsigned int) (TOKEN_DIGIT_0)) + ((unsigned int) (c - '0'))));
          token->name[ 0u ] = c;
          tmp_pos += ((off_t) (1u));

          tokenizer_mode = TOKENIZER_MODE_CHAR;
        }

        // In the order of their ASCII code
        {
          const size_t   max_no_chars = strlen("...");
          unsigned char* buffer       = raw_read_ahead(src_code, tmp_pos, max_pos, ((unsigned int) (max_no_chars)) + 1u);

          // Perform longest match for different operators
          if (c == ' ') {
            // error
          } else if (c == '!') {
            if (strncmp(((char*) (buffer)), "!=", ((size_t) (2u))) == 0) {
              token->type       = TOKEN_OPERATOR_COMPARISON_NOT_EQUAL_TO;
              token->name[ 0u ] = '!';
              token->name[ 1u ] = '=';
              tmp_pos += ((off_t) (2u));
            } else {
              token->type       = TOKEN_OPERATOR_LOGICAL_NOT;
              token->name[ 0u ] = '!';
              tmp_pos += ((off_t) (1u));
            }

            tokenizer_mode = TOKENIZER_MODE_LONGEST_MATCH;
          } else if (c == '"') {
            token->type       = TOKEN_SEPARATOR_QUOTE;
            token->name[ 0u ] = '"';
            tmp_pos += ((off_t) (1u));

            tokenizer_mode = TOKENIZER_MODE_CHAR;
          } else if (c == '%') {
            if (strncmp(((char*) (buffer)), "%=", ((size_t) (2u))) == 0) {
              token->type       = TOKEN_OPERATOR_ASSIGNMENT_MODULO;
              token->name[ 0u ] = '%';
              token->name[ 1u ] = '=';
              tmp_pos += ((off_t) (2u));
            } else {
              token->type       = TOKEN_OPERATOR_ARITHMETIC_REMAINDER;
              token->name[ 0u ] = '%';
              tmp_pos += ((off_t) (1u));
            }

            tokenizer_mode = TOKENIZER_MODE_LONGEST_MATCH;
          } else if (c == '&') {
            if (strncmp(((char*) (buffer)), "&&", ((size_t) (2u))) == 0) {
              token->type       = TOKEN_OPERATOR_LOGICAL_AND;
              token->name[ 0u ] = '&';
              token->name[ 1u ] = '&';
              tmp_pos += ((off_t) (2u));
            } else if (strncmp(((char*) (buffer)), "&=", ((size_t) (2u))) == 0) {
              token->type       = TOKEN_OPERATOR_ASSIGNMENT_BITWISE_AND;
              token->name[ 0u ] = '&';
              token->name[ 1u ] = '=';
              tmp_pos += ((off_t) (2u));
            } else {
              token->type       = TOKEN_SEPARATOR_AMPERSAND;
              token->name[ 0u ] = '&';
              tmp_pos += ((off_t) (1u));
            }

            tokenizer_mode = TOKENIZER_MODE_LONGEST_MATCH;
          } else if (c == '\'') {
            token->type       = TOKEN_SEPARATOR_APOSTROPHE;
            token->name[ 0u ] = '\'';
            tmp_pos += ((off_t) (1u));

            tokenizer_mode = TOKENIZER_MODE_CHAR;
          } else if (c == '(') {
            token->type       = TOKEN_SEPARATOR_BRACKET_ROUND_OPEN;
            token->name[ 0u ] = '(';
            tmp_pos += ((off_t) (1u));

            tokenizer_mode = TOKENIZER_MODE_LONGEST_MATCH;
          } else if (c == ')') {
            token->type       = TOKEN_SEPARATOR_BRACKET_ROUND_CLOSED;
            token->name[ 0u ] = ')';
            tmp_pos += ((off_t) (1u));

            tokenizer_mode = TOKENIZER_MODE_LONGEST_MATCH;
          } else if (c == '*') {
            if (strncmp(((char*) (buffer)), "*=", ((size_t) (2u))) == 0) {
              token->type       = TOKEN_OPERATOR_ASSIGNMENT_MULTIPLICATION;
              token->name[ 0u ] = '*';
              token->name[ 1u ] = '=';
              tmp_pos += ((off_t) (2u));
            } else {
              token->type       = TOKEN_SEPARATOR_ASTERISK;
              token->name[ 0u ] = '*';
              tmp_pos += ((off_t) (1u));
            }

            tokenizer_mode = TOKENIZER_MODE_LONGEST_MATCH;
          } else if (c == '+') {
            if (strncmp(((char*) (buffer)), "++", ((size_t) (2u))) == 0) {
              token->type       = TOKEN_OPERATOR_INCREMENT;
              token->name[ 0u ] = '+';
              token->name[ 1u ] = '+';
              tmp_pos += ((off_t) (2u));
            } else if (strncmp(((char*) (buffer)), "+=", ((size_t) (2u))) == 0) {
              token->type       = TOKEN_OPERATOR_ASSIGNMENT_ADDITION;
              token->name[ 0u ] = '+';
              token->name[ 1u ] = '=';
              tmp_pos += ((off_t) (2u));
            } else {
              token->type       = TOKEN_SEPARATOR_PLUS;
              token->name[ 0u ] = '+';
              tmp_pos += ((off_t) (1u));
            }
          } else if (c == ',') {
            token->type       = TOKEN_SEPARATOR_COMMA;
            token->name[ 0u ] = ',';
            tmp_pos += ((off_t) (1u));

            tokenizer_mode = TOKENIZER_MODE_LONGEST_MATCH;
          } else if (c == '-') {
            if (strncmp(((char*) (buffer)), "--", ((size_t) (2u))) == 0) {
              token->type       = TOKEN_OPERATOR_DECREMENT;
              token->name[ 0u ] = '-';
              token->name[ 1u ] = '-';
              tmp_pos += ((off_t) (2u));
            } else if (strncmp(((char*) (buffer)), "-=", ((size_t) (2u))) == 0) {
              token->type       = TOKEN_OPERATOR_ASSIGNMENT_SUBTRACTION;
              token->name[ 0u ] = '-';
              token->name[ 1u ] = '=';
              tmp_pos += ((off_t) (2u));
            } else if (strncmp(((char*) (buffer)), "->", ((size_t) (2u))) == 0) {
              token->type       = TOKEN_OPERATOR_ACCESS_FIELD_VIA_POINTER;
              token->name[ 0u ] = '-';
              token->name[ 1u ] = '>';
              tmp_pos += ((off_t) (2u));
            } else {
              token->type       = TOKEN_SEPARATOR_MINUS;
              token->name[ 0u ] = '-';
              tmp_pos += ((off_t) (1u));
            }
          } else if (c == '.') {
            if (strncmp(((char*) (buffer)), "...", ((size_t) (3u))) == 0) {
              token->type       = TOKEN_PARAMETER_VARIADIC_ARGS;
              token->name[ 0u ] = '.';
              token->name[ 1u ] = '.';
              token->name[ 2u ] = '.';
              tmp_pos += ((off_t) (3u));
            } else {
              token->type       = TOKEN_SEPARATOR_PERIOD;
              token->name[ 0u ] = '.';
              tmp_pos += ((off_t) (1u));
            }
          } else if (c == '/') {
            if (strncmp(((char*) (buffer)), "/=", ((size_t) (2u))) == 0) {
              token->type       = TOKEN_OPERATOR_ASSIGNMENT_DIVISION;
              token->name[ 0u ] = '/';
              token->name[ 1u ] = '=';
              tmp_pos += ((off_t) (2u));
            } else {
              token->type       = TOKEN_OPERATOR_ARITHMETIC_DIVISION;
              token->name[ 0u ] = '/';
              tmp_pos += ((off_t) (1u));
            }

            tokenizer_mode = TOKENIZER_MODE_LONGEST_MATCH;
          } else if (c == ':') {
            if (strncmp(((char*) (buffer)), "::", ((size_t) (2u))) == 0) {
              token->type       = TOKEN_ATTRIBUTE_SCOPE;
              token->name[ 0u ] = ':';
              token->name[ 1u ] = ':';
              tmp_pos += ((off_t) (2u));
            } else {
              token->type       = TOKEN_SEPARATOR_COLON;
              token->name[ 0u ] = ':';
              tmp_pos += ((off_t) (1u));
            }

            tokenizer_mode = TOKENIZER_MODE_LONGEST_MATCH;
          } else if (c == ';') {
            token->type       = TOKEN_SEPARATOR_SEMICOLON;
            token->name[ 0u ] = ';';
            tmp_pos += ((off_t) (1u));

            tokenizer_mode = TOKENIZER_MODE_LONGEST_MATCH;
          } else if (c == '\\') {
            if (strncmp(((char*) (buffer)), "\\a", ((size_t) (2u))) == 0) {
              token->type       = TOKEN_ESCAPE_a;
              token->name[ 0u ] = '\\';
              token->name[ 1u ] = 'a';
              tmp_pos += ((off_t) (2u));
            } else if (strncmp(((char*) (buffer)), "\\b", ((size_t) (2u))) == 0) {
              token->type       = TOKEN_ESCAPE_b;
              token->name[ 0u ] = '\\';
              token->name[ 1u ] = 'b';
              tmp_pos += ((off_t) (2u));
            } else if (strncmp(((char*) (buffer)), "\\f", ((size_t) (2u))) == 0) {
              token->type       = TOKEN_ESCAPE_f;
              token->name[ 0u ] = '\\';
              token->name[ 1u ] = 'f';
              tmp_pos += ((off_t) (2u));
            } else if (strncmp(((char*) (buffer)), "\\n", ((size_t) (2u))) == 0) {
              token->type       = TOKEN_ESCAPE_n;
              token->name[ 0u ] = '\\';
              token->name[ 1u ] = 'n';
              tmp_pos += ((off_t) (2u));
            } else if (strncmp(((char*) (buffer)), "\\r", ((size_t) (2u))) == 0) {
              token->type       = TOKEN_ESCAPE_r;
              token->name[ 0u ] = '\\';
              token->name[ 1u ] = 'r';
              tmp_pos += ((off_t) (2u));
            } else if (strncmp(((char*) (buffer)), "\\t", ((size_t) (2u))) == 0) {
              token->type       = TOKEN_ESCAPE_t;
              token->name[ 0u ] = '\\';
              token->name[ 1u ] = 't';
              tmp_pos += ((off_t) (2u));
            } else if (strncmp(((char*) (buffer)), "\\v", ((size_t) (2u))) == 0) {
              token->type       = TOKEN_ESCAPE_v;
              token->name[ 0u ] = '\\';
              token->name[ 1u ] = 'v';
              tmp_pos += ((off_t) (2u));
            } else if (strncmp(((char*) (buffer)), "\\x", ((size_t) (2u))) == 0) {
              token->type       = TOKEN_ESCAPE_x;
              token->name[ 0u ] = '\\';
              token->name[ 1u ] = 'x';
              tmp_pos += ((off_t) (2u));
            } else if (strncmp(((char*) (buffer)), "\\\"", ((size_t) (2u))) == 0) {
              token->type       = TOKEN_ESCAPE_QUOTE;
              token->name[ 0u ] = '\\';
              token->name[ 1u ] = '"';
              tmp_pos += ((off_t) (2u));
            } else if (strncmp(((char*) (buffer)), "\\\'", ((size_t) (2u))) == 0) {
              token->type       = TOKEN_ESCAPE_APOSTROPHE;
              token->name[ 0u ] = '\\';
              token->name[ 1u ] = '\'';
              tmp_pos += ((off_t) (2u));
            } else if (strncmp(((char*) (buffer)), "\\\\", ((size_t) (2u))) == 0) {
              token->type       = TOKEN_ESCAPE_BACKSLASH;
              token->name[ 0u ] = '\\';
              token->name[ 1u ] = '\\';
              tmp_pos += ((off_t) (2u));
            } else if (strncmp(((char*) (buffer)), "\\?", ((size_t) (2u))) == 0) {
              token->type       = TOKEN_ESCAPE_QUESTION_MARK;
              token->name[ 0u ] = '\\';
              token->name[ 1u ] = '?';
              tmp_pos += ((off_t) (2u));
            } else {
              token->type       = TOKEN_SEPARATOR_BACKSLASH;
              token->name[ 0u ] = '\\';
              tmp_pos += ((off_t) (1u));
            }
          } else if (c == '<') {
            if (strncmp(((char*) (buffer)), "<<=", ((size_t) (3u))) == 0) {
              token->type       = TOKEN_OPERATOR_ASSIGNMENT_BITWISE_SHIFT_LEFT;
              token->name[ 0u ] = '<';
              token->name[ 1u ] = '<';
              token->name[ 2u ] = '=';
              tmp_pos += ((off_t) (3u));
            } else if (strncmp(((char*) (buffer)), "<<", ((size_t) (2u))) == 0) {
              token->type       = TOKEN_OPERATOR_ARITHMETIC_BITWISE_SHIFT_LEFT;
              token->name[ 0u ] = '<';
              token->name[ 1u ] = '<';
              tmp_pos += ((off_t) (2u));
            } else if (strncmp(((char*) (buffer)), "<=", ((size_t) (2u))) == 0) {
              token->type       = TOKEN_OPERATOR_COMPARISON_LESS_THAN_OR_EQUAL_TO;
              token->name[ 0u ] = '<';
              token->name[ 1u ] = '=';
              tmp_pos += ((off_t) (2u));
            } else {
              token->type       = TOKEN_OPERATOR_COMPARISON_LESS_THAN;
              token->name[ 0u ] = '<';
              tmp_pos += ((off_t) (1u));
            }

            tokenizer_mode = TOKENIZER_MODE_LONGEST_MATCH;
          } else if (c == '=') {
            if (strncmp(((char*) (buffer)), "==", ((size_t) (2u))) == 0) {
              token->type       = TOKEN_OPERATOR_COMPARISON_EQUAL_TO;
              token->name[ 0u ] = '=';
              token->name[ 1u ] = '=';
              tmp_pos += ((off_t) (2u));
            } else {
              token->type       = TOKEN_OPERATOR_ASSIGNMENT_BASIC;
              token->name[ 0u ] = '=';
              tmp_pos += ((off_t) (1u));
            }

            tokenizer_mode = TOKENIZER_MODE_LONGEST_MATCH;
          } else if (c == '>') {
            if (strncmp(((char*) (buffer)), ">>=", ((size_t) (3u))) == 0) {
              token->type       = TOKEN_OPERATOR_ASSIGNMENT_BITWISE_SHIFT_RIGHT;
              token->name[ 0u ] = '>';
              token->name[ 1u ] = '>';
              token->name[ 2u ] = '=';
              tmp_pos += ((off_t) (3u));
            } else if (strncmp(((char*) (buffer)), ">=", ((size_t) (2u))) == 0) {
              token->type       = TOKEN_OPERATOR_COMPARISON_GREATER_THAN_OR_EQUAL_TO;
              token->name[ 0u ] = '>';
              token->name[ 1u ] = '=';
              tmp_pos += ((off_t) (2u));
            } else if (strncmp(((char*) (buffer)), ">>", ((size_t) (2u))) == 0) {
              token->type       = TOKEN_OPERATOR_ARITHMETIC_BITWISE_SHIFT_RIGHT;
              token->name[ 0u ] = '>';
              token->name[ 1u ] = '>';
              tmp_pos += ((off_t) (2u));
            } else {
              token->type       = TOKEN_OPERATOR_COMPARISON_GREATER_THAN;
              token->name[ 0u ] = '>';
              tmp_pos += ((off_t) (1u));
            }

            tokenizer_mode = TOKENIZER_MODE_LONGEST_MATCH;
          } else if (c == '?') {
            token->type       = TOKEN_OPERATOR_CONDITIONAL_PART_ONE;
            token->name[ 0u ] = '?';
            tmp_pos += ((off_t) (1u));

            tokenizer_mode = TOKENIZER_MODE_LONGEST_MATCH;
          } else if (c == '[') {
            if (strncmp(((char*) (buffer)), "[[", ((size_t) (2u))) == 0) {
              token->type       = TOKEN_ATTRIBUTE_DELIMITER_BEGIN;
              token->name[ 0u ] = '[';
              token->name[ 1u ] = '[';
              tmp_pos += ((off_t) (2u));
            } else {
              token->type       = TOKEN_SEPARATOR_BRACKET_SQUARE_OPEN;
              token->name[ 0u ] = '[';
              tmp_pos += ((off_t) (1u));
            }

            tokenizer_mode = TOKENIZER_MODE_LONGEST_MATCH;
          } else if (c == ']') {
            if (strncmp(((char*) (buffer)), "]]", ((size_t) (2u))) == 0) {
              token->type       = TOKEN_ATTRIBUTE_DELIMITER_END;
              token->name[ 0u ] = ']';
              token->name[ 1u ] = ']';
              tmp_pos += ((off_t) (2u));
            } else {
              token->type       = TOKEN_SEPARATOR_BRACKET_SQUARE_CLOSED;
              token->name[ 0u ] = ']';
              tmp_pos += ((off_t) (1u));
            }

            tokenizer_mode = TOKENIZER_MODE_LONGEST_MATCH;
          } else if (c == '^') {
            if (strncmp(((char*) (buffer)), "^=", ((size_t) (2u))) == 0) {
              token->type       = TOKEN_OPERATOR_ASSIGNMENT_BITWISE_XOR;
              token->name[ 0u ] = '^';
              token->name[ 1u ] = '=';
              tmp_pos += ((off_t) (2u));
            } else {
              token->type       = TOKEN_OPERATOR_ARITHMETIC_BITWISE_XOR;
              token->name[ 0u ] = '^';
              tmp_pos += ((off_t) (1u));
            }

            tokenizer_mode = TOKENIZER_MODE_LONGEST_MATCH;
          } else if (c == '{') {
            token->type       = TOKEN_SEPARATOR_BRACKET_CURLY_OPEN;
            token->name[ 0u ] = '{';
            tmp_pos += ((off_t) (1u));

            tokenizer_mode = TOKENIZER_MODE_LONGEST_MATCH;
          } else if (c == '|') {
            if (strncmp(((char*) (buffer)), "|=", ((size_t) (2u))) == 0) {
              token->type       = TOKEN_OPERATOR_ASSIGNMENT_BITWISE_OR;
              token->name[ 0u ] = '|';
              token->name[ 1u ] = '=';
              tmp_pos += ((off_t) (2u));
            } else if (strncmp(((char*) (buffer)), "||", ((size_t) (2u))) == 0) {
              token->type       = TOKEN_OPERATOR_LOGICAL_OR;
              token->name[ 0u ] = '|';
              token->name[ 1u ] = '|';
              tmp_pos += ((off_t) (2u));
            } else {
              token->type       = TOKEN_OPERATOR_ARITHMETIC_BITWISE_OR;
              token->name[ 0u ] = '|';
              tmp_pos += ((off_t) (1u));
            }

            tokenizer_mode = TOKENIZER_MODE_LONGEST_MATCH;
          } else if (c == '}') {
            token->type       = TOKEN_SEPARATOR_BRACKET_CURLY_CLOSED;
            token->name[ 0u ] = '}';
            tmp_pos += ((off_t) (1u));

            tokenizer_mode = TOKENIZER_MODE_LONGEST_MATCH;
          } else if (c == '~') {
            token->type       = TOKEN_OPERATOR_ARITHMETIC_BITWISE_NOT;
            token->name[ 0u ] = '~';
            tmp_pos += ((off_t) (1u));

            tokenizer_mode = TOKENIZER_MODE_LONGEST_MATCH;
          } else {
          }

          goto return_token_fast;
        }
      }

return_token:
      if (token->type == TOKEN_IDENTIFIER) {
        unsigned int i = 0u;

        for (; keywords[ i ].name != NULL; i++) {
          if (strcmp(((char*) (&token->name[ 0u ])), keywords[ i ].name) == 0) {
            token->type = keywords[ i ].type;
            break;
          }
        }
        if (keywords[ i ].name == NULL) {
          for (i = 0u; i < token_identifier_typedefs.no_identifiers; i++) {
            if (strcmp(((char*) (&token->name[ 0u ])), ((char*) (&token_identifier_typedefs.identifiers[ i ][ 0u ]))) == 0) {
              token->type = TOKEN_IDENTIFIER_TYPEDEF;
              break;
            }
          }
        }
      }
      if ((token->type == TOKEN_KEYWORD_CHAR)   ||
          (token->type == TOKEN_KEYWORD_DOUBLE) ||
          (token->type == TOKEN_KEYWORD_FLOAT)  ||
          (token->type == TOKEN_KEYWORD_INT)    ||
          (token->type == TOKEN_KEYWORD_LONG)   ||
          (token->type == TOKEN_KEYWORD_SHORT)  ||
          (token->type == TOKEN_KEYWORD_SIGNED) ||
          (token->type == TOKEN_KEYWORD_UNSIGNED)) {
        unsigned char* buffer = read_ahead(src_code, token->pos, max_pos);

        for (unsigned int i = 0u; basic_types[ i ].name != NULL; i++) {
          size_t sz = strlen(basic_types[ i ].name);

          if (strncmp(((char*) (buffer)), basic_types[ i ].name, sz) == 0) {
            token->type = basic_types[ i ].type;
            strcpy(((char*) (&token->name[ 0u ])), basic_types[ i ].alias);

            for (size_t j = ((size_t) (0u)); j < sz; j++) {
              if (basic_types[ i ].name[ j ] == ' ') {
                token->no_burn_tokens++;
              }
            }
            break;
          }
        }
      }

return_token_fast:
      *pos = tmp_pos;
      if ((get_flags & GET_TOKEN_FLAGS_FPRINTF) && (token->type != TOKEN_INVALID)) {
        fprintf(stdout,
                "token [ %3u :: %32s ] [ %8lld ] [ %2u ] :: %32s\n",
                ((unsigned int) (token->type)),
                token_type_name[ token->type ],
                ((signed long long)(token->pos)),
                token->no_burn_tokens,
                &token->name[ 0u ]);
      }
      return token;
    }
  }

  return NULL;
}

void release_token(const token_t* const token) {
  if (token != NULL) {
    memset(((void*) (token)), 0xAA, sizeof(token_t));
    free(((void*) (token)));
  }
}
