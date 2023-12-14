#ifndef _TOKENIZER_H_
#define _TOKENIZER_H_

#include <stddef.h>

#include <sys/types.h>

#define TOKEN_NAME_MAX_LENGTH (128)

#define GET_TOKEN_FLAGS_FPRINTF (1u << 0u)

typedef enum {
  TOKEN_INVALID,
  //
  TOKEN_NON_DIGIT_a,
  TOKEN_NON_DIGIT_b,
  TOKEN_NON_DIGIT_c,
  TOKEN_NON_DIGIT_d,
  TOKEN_NON_DIGIT_e,
  TOKEN_NON_DIGIT_f,
  TOKEN_NON_DIGIT_g,
  TOKEN_NON_DIGIT_h,
  TOKEN_NON_DIGIT_i,
  TOKEN_NON_DIGIT_j,
  TOKEN_NON_DIGIT_k,
  TOKEN_NON_DIGIT_l,
  TOKEN_NON_DIGIT_m,
  TOKEN_NON_DIGIT_n,
  TOKEN_NON_DIGIT_o,
  TOKEN_NON_DIGIT_p,
  TOKEN_NON_DIGIT_q,
  TOKEN_NON_DIGIT_r,
  TOKEN_NON_DIGIT_s,
  TOKEN_NON_DIGIT_t,
  TOKEN_NON_DIGIT_u,
  TOKEN_NON_DIGIT_v,
  TOKEN_NON_DIGIT_w,
  TOKEN_NON_DIGIT_x,
  TOKEN_NON_DIGIT_y,
  TOKEN_NON_DIGIT_z,
  TOKEN_NON_DIGIT_A,
  TOKEN_NON_DIGIT_B,
  TOKEN_NON_DIGIT_C,
  TOKEN_NON_DIGIT_D,
  TOKEN_NON_DIGIT_E,
  TOKEN_NON_DIGIT_F,
  TOKEN_NON_DIGIT_G,
  TOKEN_NON_DIGIT_H,
  TOKEN_NON_DIGIT_I,
  TOKEN_NON_DIGIT_J,
  TOKEN_NON_DIGIT_K,
  TOKEN_NON_DIGIT_L,
  TOKEN_NON_DIGIT_M,
  TOKEN_NON_DIGIT_N,
  TOKEN_NON_DIGIT_O,
  TOKEN_NON_DIGIT_P,
  TOKEN_NON_DIGIT_Q,
  TOKEN_NON_DIGIT_R,
  TOKEN_NON_DIGIT_S,
  TOKEN_NON_DIGIT_T,
  TOKEN_NON_DIGIT_U,
  TOKEN_NON_DIGIT_V,
  TOKEN_NON_DIGIT_W,
  TOKEN_NON_DIGIT_X,
  TOKEN_NON_DIGIT_Y,
  TOKEN_NON_DIGIT_Z,
  TOKEN_DIGIT_0,
  TOKEN_DIGIT_1,
  TOKEN_DIGIT_2,
  TOKEN_DIGIT_3,
  TOKEN_DIGIT_4,
  TOKEN_DIGIT_5,
  TOKEN_DIGIT_6,
  TOKEN_DIGIT_7,
  TOKEN_DIGIT_8,
  TOKEN_DIGIT_9,
  // Keywords
  TOKEN_IS_KEYWORD_BEGIN,
  TOKEN_KEYWORD_ALIGNAS,       // alignas
  TOKEN_KEYWORD_ALIGNOF,       // alignof
  TOKEN_KEYWORD_AUTO,          // auto
  TOKEN_KEYWORD_BOOL,          // bool
  TOKEN_KEYWORD_BREAK,         // break
  TOKEN_KEYWORD_CASE,          // case
  TOKEN_KEYWORD_CHAR,                   // sint8_t      :: char
  TOKEN_KEYWORD_CONST,         // const
  TOKEN_KEYWORD_CONSTEXPR,     // constexpr
  TOKEN_KEYWORD_CONTINUE,      // continue
  TOKEN_KEYWORD_DEFAULT,       // default
  TOKEN_KEYWORD_DO,            // do
  TOKEN_KEYWORD_DOUBLE,                 // double64_t   :: double
  TOKEN_KEYWORD_ELSE,          // else
  TOKEN_KEYWORD_ENUM,          // enum
  TOKEN_KEYWORD_EXTERN,        // extern
  TOKEN_KEYWORD_FALSE,         // false
  TOKEN_KEYWORD_FLOAT,                  // double32_t   :: float
  TOKEN_KEYWORD_FOR,           // for
  TOKEN_KEYWORD_GOTO,          // goto
  TOKEN_KEYWORD_IF,            // if
  TOKEN_KEYWORD_INLINE,        // inline
  TOKEN_KEYWORD_INT,                    // sint32_t     :: int
  TOKEN_KEYWORD_LONG,                   // sint64_t     :: long
  TOKEN_KEYWORD_NULLPTR,       // nullptr
  TOKEN_KEYWORD_REGISTER,      // register
  TOKEN_KEYWORD_RESTRICT,      // restrict
  TOKEN_KEYWORD_RETURN,        // return
  TOKEN_KEYWORD_SHORT,                  // sint16_t     :: short
  TOKEN_KEYWORD_SIGNED,                 // sint32_t     :: signed
  TOKEN_KEYWORD_SIZEOF,        // sizeof
  TOKEN_KEYWORD_STATIC,        // static
  TOKEN_KEYWORD_STATIC_ASSERT, // static_assert
  TOKEN_KEYWORD_STRUCT,        // struct
  TOKEN_KEYWORD_SWITCH,        // switch
  TOKEN_KEYWORD_THREAD_LOCAL,  // thread_local
  TOKEN_KEYWORD_TRUE,          // true
  TOKEN_KEYWORD_TYPEDEF,       // typedef
  TOKEN_KEYWORD_TYPEOF,        // typeof
  TOKEN_KEYWORD_TYPEOF_UNQUAL, // typeof_unqual
  TOKEN_KEYWORD_UNION,         // union
  TOKEN_KEYWORD_UNSIGNED,               // uint32_t     :: unsigned
  TOKEN_KEYWORD_VOID,          // void
  TOKEN_KEYWORD_VOLATILE,      // volatile
  TOKEN_KEYWORD_WHILE,         // while
  TOKEN_KEYWORD__ATOMIC,       // _Atomic
  TOKEN_KEYWORD__BITINT,       // _BitInt
  TOKEN_KEYWORD__COMPLEX,      // _Complex
  TOKEN_KEYWORD__DECIMAL128,   // _Decimal128
  TOKEN_KEYWORD__DECIMAL64,    // _Decimal64
  TOKEN_KEYWORD__DECIMAL32,    // _Decimal32
  TOKEN_KEYWORD__GENERIC,      // _Generic
  TOKEN_KEYWORD__IMAGINARY,    // _Imaginary
  TOKEN_KEYWORD__NORETURN,     // _Noreturn
  TOKEN_KEYWORD_SIGNED_CHAR,            // sint8_t      :: signed char
  TOKEN_KEYWORD_SIGNED_SHORT_INT,       // sint16_t     :: short, short int, signed short, signed short int
  TOKEN_KEYWORD_SIGNED_INT,             // sint32_t     :: int, signed, signed int
  TOKEN_KEYWORD_SIGNED_LONG_INT,        // sint64_t     :: long, long int, signed long, signed long int
  TOKEN_KEYWORD_SIGNED_LONG_LONG_INT,   // sint64_t     :: long long, long long int, signed long long, signed long long int
  TOKEN_KEYWORD_UNSIGNED_CHAR,          // uint8_t      :: unsigned char
  TOKEN_KEYWORD_UNSIGNED_SHORT_INT,     // uint16_t     :: unsigned short, unsigned short int
  TOKEN_KEYWORD_UNSIGNED_INT,           // uint32_t     :: unsigned, unsigned int
  TOKEN_KEYWORD_UNSIGNED_LONG_INT,      // uint64_t     :: unsigned long, unsigned long int
  TOKEN_KEYWORD_UNSIGNED_LONG_LONG_INT, // uint64_t     :: unsigned long long, unsigned long long int
  TOKEN_KEYWORD_LONG_DOUBLE,            // double128_t  :: long double
  TOKEN_KEYWORD_SINT8,
  TOKEN_KEYWORD_UINT8,
  TOKEN_KEYWORD_SINT16,
  TOKEN_KEYWORD_UINT16,
  TOKEN_KEYWORD_SINT32,
  TOKEN_KEYWORD_UINT32,
  TOKEN_KEYWORD_SINT64,
  TOKEN_KEYWORD_UINT64,
  TOKEN_KEYWORD_FLOAT32,
  TOKEN_KEYWORD_FLOAT64,
  TOKEN_KEYWORD_FLOAT128,
  TOKEN_IS_KEYWORD_END,
  // Separators
  TOKEN_IS_SEPARATOR_BEGIN,
  TOKEN_SEPARATOR_BRACKET_ROUND_OPEN,    // (
  TOKEN_SEPARATOR_BRACKET_ROUND_CLOSED,  // )
  TOKEN_SEPARATOR_BRACKET_SQUARE_OPEN,   // [
  TOKEN_SEPARATOR_BRACKET_SQUARE_CLOSED, // ]
  TOKEN_SEPARATOR_BRACKET_CURLY_OPEN,    // {
  TOKEN_SEPARATOR_BRACKET_CURLY_CLOSED,  // }
  TOKEN_SEPARATOR_SPACE,                 //
  TOKEN_SEPARATOR_QUOTE,                 // "
  TOKEN_SEPARATOR_AMPERSAND,             // &
  TOKEN_SEPARATOR_APOSTROPHE,            // '
  TOKEN_SEPARATOR_ASTERISK,              // *
  TOKEN_SEPARATOR_PLUS,                  // +
  TOKEN_SEPARATOR_COMMA,                 // ,
  TOKEN_SEPARATOR_MINUS,                 // -
  TOKEN_SEPARATOR_PERIOD,                // .
  TOKEN_SEPARATOR_COLON,                 // :
  TOKEN_SEPARATOR_SEMICOLON,             // ;
  TOKEN_SEPARATOR_BACKSLASH,             //
  TOKEN_IS_SEPARATOR_END,
  // Escape sequences
  TOKEN_ESCAPE_a,
  TOKEN_ESCAPE_b,
  TOKEN_ESCAPE_f,
  TOKEN_ESCAPE_n,
  TOKEN_ESCAPE_r,
  TOKEN_ESCAPE_t,
  TOKEN_ESCAPE_v,
  TOKEN_ESCAPE_x,
  TOKEN_ESCAPE_QUOTE,
  TOKEN_ESCAPE_APOSTROPHE,
  TOKEN_ESCAPE_BACKSLASH,
  TOKEN_ESCAPE_QUESTION_MARK,
  // Operators
  TOKEN_IS_OPERATOR_BEGIN,
  TOKEN_OPERATOR_INCREMENT,                           // ++
  TOKEN_OPERATOR_DECREMENT,                           // --
  TOKEN_OPERATOR_ASSIGNMENT_BASIC,                    // =
  TOKEN_OPERATOR_ASSIGNMENT_ADDITION,                 // +=
  TOKEN_OPERATOR_ASSIGNMENT_SUBTRACTION,              // -=
  TOKEN_OPERATOR_ASSIGNMENT_MULTIPLICATION,           // *=
  TOKEN_OPERATOR_ASSIGNMENT_DIVISION,                 // /=
  TOKEN_OPERATOR_ASSIGNMENT_MODULO,                   // %=
  TOKEN_OPERATOR_ASSIGNMENT_BITWISE_AND,              // &=
  TOKEN_OPERATOR_ASSIGNMENT_BITWISE_OR,               // |=
  TOKEN_OPERATOR_ASSIGNMENT_BITWISE_XOR,              // ^=
  TOKEN_OPERATOR_ASSIGNMENT_BITWISE_SHIFT_LEFT,       // <<=
  TOKEN_OPERATOR_ASSIGNMENT_BITWISE_SHIFT_RIGHT,      // >>=
  TOKEN_OPERATOR_ARITHMETIC_UNARY_PLUS,               // +
  TOKEN_OPERATOR_ARITHMETIC_UNARY_MINUS,              // -
  TOKEN_OPERATOR_ARITHMETIC_ADDITION,                 // +
  TOKEN_OPERATOR_ARITHMETIC_SUBTRACTION,              // -
  TOKEN_OPERATOR_ARITHMETIC_PRODUCT,                  // *
  TOKEN_OPERATOR_ARITHMETIC_DIVISION,                 // /
  TOKEN_OPERATOR_ARITHMETIC_REMAINDER,                // %
  TOKEN_OPERATOR_ARITHMETIC_BITWISE_NOT,              // ~
  TOKEN_OPERATOR_ARITHMETIC_BITWISE_AND,              // &
  TOKEN_OPERATOR_ARITHMETIC_BITWISE_OR,               // |
  TOKEN_OPERATOR_ARITHMETIC_BITWISE_XOR,              // ^
  TOKEN_OPERATOR_ARITHMETIC_BITWISE_SHIFT_LEFT,       // <<
  TOKEN_OPERATOR_ARITHMETIC_BITWISE_SHIFT_RIGHT,      // >>
  TOKEN_OPERATOR_LOGICAL_NOT,                         // !
  TOKEN_OPERATOR_LOGICAL_AND,                         // &&
  TOKEN_OPERATOR_LOGICAL_OR,                          // ||
  TOKEN_OPERATOR_COMPARISON_EQUAL_TO,                 // ==
  TOKEN_OPERATOR_COMPARISON_NOT_EQUAL_TO,             // !=
  TOKEN_OPERATOR_COMPARISON_LESS_THAN,                // <
  TOKEN_OPERATOR_COMPARISON_LESS_THAN_OR_EQUAL_TO,    // <=
  TOKEN_OPERATOR_COMPARISON_GREATER_THAN,             // >
  TOKEN_OPERATOR_COMPARISON_GREATER_THAN_OR_EQUAL_TO, // >=
  TOKEN_OPERATOR_FUNCTION_CALL_BEGIN,                 // (
  TOKEN_OPERATOR_FUNCTION_CALL_END,                   // )
  TOKEN_OPERATOR_ACCESS_ARRAY_SUBSCRIPT_BEGIN,        // [
  TOKEN_OPERATOR_ACCESS_ARRAY_SUBSCRIPT_END,          // ]
  TOKEN_OPERATOR_ACCESS_POINTER_DEREFERENCE,          // *
  TOKEN_OPERATOR_ACCESS_ADDRESS_OF,                   // &
  TOKEN_OPERATOR_ACCESS_FIELD,                        // .
  TOKEN_OPERATOR_ACCESS_FIELD_VIA_POINTER,            // ->
  TOKEN_OPERATOR_COMMA,                               // ,
  TOKEN_OPERATOR_CONDITIONAL_PART_ONE,                // ?
  TOKEN_OPERATOR_CONDITIONAL_PART_TWO,                // :
  TOKEN_IS_OPERATOR_END,
  // Body
  TOKEN_BODY_BEGIN,                                   // {
  TOKEN_BODY_END,                                     // }
  // Compound Literals
  TOKEN_COMPOUND_LITERAL_BEGIN,                       // (
  TOKEN_COMPOUND_LITERAL_END,                         // )
  // Declarators
  TOKEN_DECLARATOR_POINTER,                           // *
  TOKEN_DECLARATOR_BINDER_BEGIN,                      // (
  TOKEN_DECLARATOR_BINDER_END,                        // )
  TOKEN_DECLARATOR_ARRAY_BEGIN,                       // [
  TOKEN_DECLARATOR_ARRAY_END,                         // ]
  TOKEN_DECLARATOR_FUNCTION_BEGIN,                    // (
  TOKEN_DECLARATOR_FUNCTION_END,                      // )
  // Designators
  TOKEN_DESIGNATOR_ARRAY_ELEM_BEGIN,                  // [
  TOKEN_DESIGNATOR_ARRAY_ELEM_END,                    // ]
  TOKEN_DESIGNATOR_STRUCT_OR_UNION_MEMBER,            // .
  // Lists
  TOKEN_LIST_DELIMITER,                               // ,
  // Placeholders
  TOKEN_PLACEHOLDER_VLA,                              // *
  // Parameters
  TOKEN_PARAMETER_VARIADIC_ARGS,                      // ...
  // Labels
  TOKEN_LABEL_DECLARATION,                            // :
  // Bit Fields
  TOKEN_BIT_FIELD_WIDTH_DECLARATION_STRUCT_OR_UNION,  // :
  // Identifiers
  TOKEN_IDENTIFIER,
  TOKEN_IDENTIFIER_TYPEDEF,
  // Attributes
  TOKEN_ATTRIBUTE_DELIMITER_BEGIN,                    // [[
  TOKEN_ATTRIBUTE_DELIMITER_END,                      // ]]
  TOKEN_ATTRIBUTE_SCOPE,                              // ::
  //
  TOKEN_MAX_NO_TOKENS
} token_type_t;

typedef struct {
  token_type_t  type;
  unsigned char name[ TOKEN_NAME_MAX_LENGTH ];
  unsigned int  flags;
  unsigned int  no_burn_tokens;

  off_t      pos;
} token_t;

typedef struct {
  unsigned int  no_identifiers;
  unsigned char identifiers[ 1024u ][ TOKEN_NAME_MAX_LENGTH ];
} token_identifier_typedef_t;

extern token_identifier_typedef_t token_identifier_typedefs;
extern const char* const          token_type_name[ ];

extern token_t* get_token(const unsigned char* const src_code,
                          off_t* const               pos,
                          const off_t                max_pos,
                          unsigned int               get_flags);
extern void release_token(const token_t* const token);

static inline __attribute__((always_inline)) token_t* peek_token(const unsigned char* const src_code,
                                                                 off_t* const               pos,
                                                                 const off_t                max_pos) {
  token_t* token = get_token(src_code, pos, max_pos, 0u);
  if (token != NULL) {
    *pos = token->pos;
  }
  return token;
}
static inline __attribute__((always_inline)) void burn_token(const unsigned char* const src_code,
                                                             off_t* const               pos,
                                                             const off_t                max_pos) {
  release_token(get_token(src_code, pos, max_pos, 0u));
}

#endif
