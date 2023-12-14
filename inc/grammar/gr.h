#ifndef _GR_H_
#define _GR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tokenizer.h"
#include "parser.h"

#define GR_DEBUG_LEVEL_INFO    (0u)
#define GR_DEBUG_LEVEL_WARNING (1u)
#define GR_DEBUG_LEVEL_ERROR   (2u)
#ifndef GR_DEBUG_LEVEL
#define GR_DEBUG_LEVEL         (GR_DEBUG_LEVEL_ERROR)
#endif

#define GR_MAX_NO_TOKENS (2u * 1024u)
#define GR_MAX_NO_ELEMS  (GR_MAX_NO_TOKENS)
#define GR_MAX_NO_RULES  (96u)

#define GR_RULE_FLAGS_SKIP_EXPAND       (1u << 0u)
#define GR_RULE_FLAGS_SKIP_NON_MARKED   (1u << 1u)
#define GR_ELEM_FLAGS_LAST_RULE_MATCHED (1u << 0u)
#define GR_STACK_FLAGS_SKIP_PRINT       (1u << 0u)

#define GR_STACK_MAX_ELEM_IDX (512u)

typedef enum {
  GR_ELEM_INVALID,

  // Simple gr_elems that translate directly into one token
  GR_ELEM_SIMPLE,
  GR_ELEM_NON_DIGIT_a = GR_ELEM_SIMPLE,
  GR_ELEM_NON_DIGIT_b,
  GR_ELEM_NON_DIGIT_c,
  GR_ELEM_NON_DIGIT_d,
  GR_ELEM_NON_DIGIT_e,
  GR_ELEM_NON_DIGIT_f,
  GR_ELEM_NON_DIGIT_g,
  GR_ELEM_NON_DIGIT_h,
  GR_ELEM_NON_DIGIT_i,
  GR_ELEM_NON_DIGIT_j,
  GR_ELEM_NON_DIGIT_k,
  GR_ELEM_NON_DIGIT_l,
  GR_ELEM_NON_DIGIT_m,
  GR_ELEM_NON_DIGIT_n,
  GR_ELEM_NON_DIGIT_o,
  GR_ELEM_NON_DIGIT_p,
  GR_ELEM_NON_DIGIT_q,
  GR_ELEM_NON_DIGIT_r,
  GR_ELEM_NON_DIGIT_s,
  GR_ELEM_NON_DIGIT_t,
  GR_ELEM_NON_DIGIT_u,
  GR_ELEM_NON_DIGIT_v,
  GR_ELEM_NON_DIGIT_w,
  GR_ELEM_NON_DIGIT_x,
  GR_ELEM_NON_DIGIT_y,
  GR_ELEM_NON_DIGIT_z,
  GR_ELEM_NON_DIGIT_A,
  GR_ELEM_NON_DIGIT_B,
  GR_ELEM_NON_DIGIT_C,
  GR_ELEM_NON_DIGIT_D,
  GR_ELEM_NON_DIGIT_E,
  GR_ELEM_NON_DIGIT_F,
  GR_ELEM_NON_DIGIT_G,
  GR_ELEM_NON_DIGIT_H,
  GR_ELEM_NON_DIGIT_I,
  GR_ELEM_NON_DIGIT_J,
  GR_ELEM_NON_DIGIT_K,
  GR_ELEM_NON_DIGIT_L,
  GR_ELEM_NON_DIGIT_M,
  GR_ELEM_NON_DIGIT_N,
  GR_ELEM_NON_DIGIT_O,
  GR_ELEM_NON_DIGIT_P,
  GR_ELEM_NON_DIGIT_Q,
  GR_ELEM_NON_DIGIT_R,
  GR_ELEM_NON_DIGIT_S,
  GR_ELEM_NON_DIGIT_T,
  GR_ELEM_NON_DIGIT_U,
  GR_ELEM_NON_DIGIT_V,
  GR_ELEM_NON_DIGIT_W,
  GR_ELEM_NON_DIGIT_X,
  GR_ELEM_NON_DIGIT_Y,
  GR_ELEM_NON_DIGIT_Z,
  GR_ELEM_DIGIT_0,
  GR_ELEM_DIGIT_1,
  GR_ELEM_DIGIT_2,
  GR_ELEM_DIGIT_3,
  GR_ELEM_DIGIT_4,
  GR_ELEM_DIGIT_5,
  GR_ELEM_DIGIT_6,
  GR_ELEM_DIGIT_7,
  GR_ELEM_DIGIT_8,
  GR_ELEM_DIGIT_9,
  // Keywords
  GR_ELEM_KEYWORD_ALIGNAS,
  GR_ELEM_KEYWORD_ALIGNOF,
  GR_ELEM_KEYWORD_AUTO,
  GR_ELEM_KEYWORD_BREAK,
  GR_ELEM_KEYWORD_BOOL,
  GR_ELEM_KEYWORD_CASE,
  GR_ELEM_KEYWORD_CHAR,
  GR_ELEM_KEYWORD_CONST,
  GR_ELEM_KEYWORD_CONSTEXPR,
  GR_ELEM_KEYWORD_CONTINUE,
  GR_ELEM_KEYWORD_DEFAULT,
  GR_ELEM_KEYWORD_DO,
  GR_ELEM_KEYWORD_DOUBLE,
  GR_ELEM_KEYWORD_ELSE,
  GR_ELEM_KEYWORD_ENUM,
  GR_ELEM_KEYWORD_EXTERN,
  GR_ELEM_KEYWORD_FALSE,
  GR_ELEM_KEYWORD_FLOAT,
  GR_ELEM_KEYWORD_FOR,
  GR_ELEM_KEYWORD_GOTO,
  GR_ELEM_KEYWORD_IF,
  GR_ELEM_KEYWORD_INLINE,
  GR_ELEM_KEYWORD_INT,
  GR_ELEM_KEYWORD_LONG,
  GR_ELEM_KEYWORD_NULLPTR,
  GR_ELEM_KEYWORD_REGISTER,
  GR_ELEM_KEYWORD_RESTRICT,
  GR_ELEM_KEYWORD_RETURN,
  GR_ELEM_KEYWORD_SHORT,
  GR_ELEM_KEYWORD_SIGNED,
  GR_ELEM_KEYWORD_SIZEOF,
  GR_ELEM_KEYWORD_STATIC,
  GR_ELEM_KEYWORD_STATIC_ASSERT,
  GR_ELEM_KEYWORD_STRUCT,
  GR_ELEM_KEYWORD_SWITCH,
  GR_ELEM_KEYWORD_THREAD_LOCAL,
  GR_ELEM_KEYWORD_TRUE,
  GR_ELEM_KEYWORD_TYPEDEF,
  GR_ELEM_KEYWORD_TYPEOF,
  GR_ELEM_KEYWORD_TYPEOF_UNQUAL,
  GR_ELEM_KEYWORD_UNION,
  GR_ELEM_KEYWORD_UNSIGNED,
  GR_ELEM_KEYWORD_VOID,
  GR_ELEM_KEYWORD_VOLATILE,
  GR_ELEM_KEYWORD_WHILE,
  GR_ELEM_KEYWORD__ATOMIC,
  GR_ELEM_KEYWORD__BITINT,
  GR_ELEM_KEYWORD__COMPLEX,
  GR_ELEM_KEYWORD__DECIMAL128,
  GR_ELEM_KEYWORD__DECIMAL64,
  GR_ELEM_KEYWORD__DECIMAL32,
  GR_ELEM_KEYWORD__GENERIC,
  GR_ELEM_KEYWORD__IMAGINARY,
  GR_ELEM_KEYWORD__NORETURN,
  GR_ELEM_KEYWORD_SINT8,
  GR_ELEM_KEYWORD_UINT8,
  GR_ELEM_KEYWORD_SINT16,
  GR_ELEM_KEYWORD_UINT16,
  GR_ELEM_KEYWORD_SINT32,
  GR_ELEM_KEYWORD_UINT32,
  GR_ELEM_KEYWORD_SINT64,
  GR_ELEM_KEYWORD_UINT64,
  GR_ELEM_KEYWORD_FLOAT32,
  GR_ELEM_KEYWORD_FLOAT64,
  GR_ELEM_KEYWORD_FLOAT128,
  // Separators
  GR_ELEM_SEPARATOR_BRACKET_ROUND_OPEN,                 // (
  GR_ELEM_SEPARATOR_BRACKET_ROUND_CLOSED,               // )
  GR_ELEM_SEPARATOR_QUOTE,                              // "
  GR_ELEM_SEPARATOR_APOSTROPHE,                         // '
  GR_ELEM_SEPARATOR_PLUS,                               // +
  GR_ELEM_SEPARATOR_MINUS,                              // -
  GR_ELEM_SEPARATOR_PERIOD,                             // .
  GR_ELEM_SEPARATOR_COLON,                              // :
  GR_ELEM_SEPARATOR_SEMICOLON,                          // ;
  GR_ELEM_SEPARATOR_BACKSLASH,                          //
  // Escape sequences
  GR_ELEM_ESCAPE_a,
  GR_ELEM_ESCAPE_b,
  GR_ELEM_ESCAPE_f,
  GR_ELEM_ESCAPE_n,
  GR_ELEM_ESCAPE_r,
  GR_ELEM_ESCAPE_t,
  GR_ELEM_ESCAPE_v,
  GR_ELEM_ESCAPE_x,
  GR_ELEM_ESCAPE_QUOTE,
  GR_ELEM_ESCAPE_APOSTROPHE,
  GR_ELEM_ESCAPE_BACKSLASH,
  GR_ELEM_ESCAPE_QUESTION_MARK,
  // Operators
  GR_ELEM_OPERATOR_POSTFIX_INCREMENT,                   // ++
  GR_ELEM_OPERATOR_POSTFIX_DECREMENT,                   // --
  GR_ELEM_OPERATOR_PREFIX_INCREMENT,                    // ++
  GR_ELEM_OPERATOR_PREFIX_DECREMENT,                    // --
  GR_ELEM_OPERATOR_ASSIGNMENT_BASIC,                    // =
  GR_ELEM_OPERATOR_ASSIGNMENT_ADDITION,                 // +=
  GR_ELEM_OPERATOR_ASSIGNMENT_SUBTRACTION,              // -=
  GR_ELEM_OPERATOR_ASSIGNMENT_MULTIPLICATION,           // *=
  GR_ELEM_OPERATOR_ASSIGNMENT_DIVISION,                 // /=
  GR_ELEM_OPERATOR_ASSIGNMENT_MODULO,                   // %=
  GR_ELEM_OPERATOR_ASSIGNMENT_BITWISE_AND,              // &=
  GR_ELEM_OPERATOR_ASSIGNMENT_BITWISE_OR,               // |=
  GR_ELEM_OPERATOR_ASSIGNMENT_BITWISE_XOR,              // ^=
  GR_ELEM_OPERATOR_ASSIGNMENT_BITWISE_SHIFT_LEFT,       // <<=
  GR_ELEM_OPERATOR_ASSIGNMENT_BITWISE_SHIFT_RIGHT,      // >>=
  GR_ELEM_OPERATOR_ARITHMETIC_UNARY_PLUS,               // +
  GR_ELEM_OPERATOR_ARITHMETIC_UNARY_MINUS,              // -
  GR_ELEM_OPERATOR_ARITHMETIC_ADDITION,                 // +
  GR_ELEM_OPERATOR_ARITHMETIC_SUBTRACTION,              // -
  GR_ELEM_OPERATOR_ARITHMETIC_PRODUCT,                  // *
  GR_ELEM_OPERATOR_ARITHMETIC_DIVISION,                 // /
  GR_ELEM_OPERATOR_ARITHMETIC_REMAINDER,                // %
  GR_ELEM_OPERATOR_ARITHMETIC_BITWISE_NOT,              // ~
  GR_ELEM_OPERATOR_ARITHMETIC_BITWISE_AND,              // &
  GR_ELEM_OPERATOR_ARITHMETIC_BITWISE_OR,               // |
  GR_ELEM_OPERATOR_ARITHMETIC_BITWISE_XOR,              // ^
  GR_ELEM_OPERATOR_ARITHMETIC_BITWISE_SHIFT_LEFT,       // <<
  GR_ELEM_OPERATOR_ARITHMETIC_BITWISE_SHIFT_RIGHT,      // >>
  GR_ELEM_OPERATOR_LOGICAL_NOT,                         // !
  GR_ELEM_OPERATOR_LOGICAL_AND,                         // &&
  GR_ELEM_OPERATOR_LOGICAL_OR,                          // ||
  GR_ELEM_OPERATOR_COMPARISON_EQUAL_TO,                 // ==
  GR_ELEM_OPERATOR_COMPARISON_NOT_EQUAL_TO,             // !=
  GR_ELEM_OPERATOR_COMPARISON_LESS_THAN,                // <
  GR_ELEM_OPERATOR_COMPARISON_LESS_THAN_OR_EQUAL_TO,    // <=
  GR_ELEM_OPERATOR_COMPARISON_GREATER_THAN,             // >
  GR_ELEM_OPERATOR_COMPARISON_GREATER_THAN_OR_EQUAL_TO, // >=
  GR_ELEM_OPERATOR_FUNCTION_CALL_BEGIN,                 // (
  GR_ELEM_OPERATOR_FUNCTION_CALL_END,                   // )
  GR_ELEM_OPERATOR_ACCESS_ARRAY_SUBSCRIPT_BEGIN,        // [
  GR_ELEM_OPERATOR_ACCESS_ARRAY_SUBSCRIPT_END,          // ]
  GR_ELEM_OPERATOR_ACCESS_POINTER_DEREFERENCE,          // *
  GR_ELEM_OPERATOR_ACCESS_ADDRESS_OF,                   // &
  GR_ELEM_OPERATOR_ACCESS_FIELD,                        // .
  GR_ELEM_OPERATOR_ACCESS_FIELD_VIA_POINTER,            // ->
  GR_ELEM_OPERATOR_COMMA,                               // ,
  GR_ELEM_OPERATOR_CONDITIONAL_PART_ONE,                // ?
  GR_ELEM_OPERATOR_CONDITIONAL_PART_TWO,                // :
  // Body
  GR_ELEM_BODY_BEGIN,                                   // {
  GR_ELEM_BODY_END,                                     // }
  // Compound Literals
  GR_ELEM_COMPOUND_LITERAL_BEGIN,                       // (
  GR_ELEM_COMPOUND_LITERAL_END,                         // )
  // Declarators
  GR_ELEM_DECLARATOR_POINTER,                           // *
  GR_ELEM_DECLARATOR_BINDER_BEGIN,                      // (
  GR_ELEM_DECLARATOR_BINDER_END,                        // )
  GR_ELEM_DECLARATOR_ARRAY_BEGIN,                       // [
  GR_ELEM_DECLARATOR_ARRAY_END,                         // ]
  GR_ELEM_DECLARATOR_FUNCTION_BEGIN,                    // (
  GR_ELEM_DECLARATOR_FUNCTION_END,                      // )
  // Designators
  GR_ELEM_DESIGNATOR_ARRAY_ELEM_BEGIN,                  // [
  GR_ELEM_DESIGNATOR_ARRAY_ELEM_END,                    // ]
  GR_ELEM_DESIGNATOR_STRUCT_OR_UNION_MEMBER,            // .
  // Lists
  GR_ELEM_LIST_DELIMITER,                               // ,
  // Placeholders
  GR_ELEM_PLACEHOLDER_VLA,                              // *
  // Parameters
  GR_ELEM_PARAMETER_VARIADIC_ARGS,                      // ...
  // Labels
  GR_ELEM_LABEL_DECLARATION,                            // :
  // Bit Fields
  GR_ELEM_BIT_FIELD_WIDTH_DECLARATION_STRUCT_OR_UNION,  // :
  // Identifiers
  GR_ELEM_IDENTIFIER,
  GR_ELEM_IDENTIFIER_TYPEDEF,
  // Attributes
  GR_ELEM_ATTRIBUTE_DELIMITER_BEGIN,                    // [[
  GR_ELEM_ATTRIBUTE_DELIMITER_END,                      // ]]
  GR_ELEM_ATTRIBUTE_SCOPE,                              // ::

  // Complex gr_elems that do not translate directly into tokens
  GR_ELEM_COMPLEX,
  GR_ELEM_DIGIT = GR_ELEM_COMPLEX,
  GR_ELEM_NON_ZERO_DIGIT,
  GR_ELEM_OCTAL_DIGIT,
  GR_ELEM_HEXADECIMAL_DIGIT,
  GR_ELEM_BINARY_DIGIT,
  GR_ELEM_DIGIT_SEQUENCE,
  GR_ELEM_HEXADECIMAL_DIGIT_SEQUENCE,
  GR_ELEM_C_CHAR,
  GR_ELEM_C_CHAR_SEQUENCE,
  GR_ELEM_ESCAPE_SEQUENCE,
  GR_ELEM_SIMPLE_ESCAPE_SEQUENCE,
  GR_ELEM_OCTAL_ESCAPE_SEQUENCE,
  GR_ELEM_HEXADECIMAL_ESCAPE_SEQUENCE,

  GR_ELEM_CONSTANT,
  GR_ELEM_INTEGER_CONSTANT,
  GR_ELEM_DECIMAL_CONSTANT,
  GR_ELEM_OCTAL_CONSTANT,
  GR_ELEM_HEXADECIMAL_CONSTANT,
  GR_ELEM_BINARY_CONSTANT,
  GR_ELEM_HEXADECIMAL_PREFIX,
  GR_ELEM_BINARY_PREFIX,
  GR_ELEM_INTEGER_SUFFIX,
  GR_ELEM_BIT_PRECISE_INT_SUFFIX,
  GR_ELEM_UNSIGNED_SUFFIX,
  GR_ELEM_LONG_SUFFIX,
  GR_ELEM_LONG_LONG_SUFFIX,
  GR_ELEM_FLOATING_CONSTANT,
  GR_ELEM_DECIMAL_FLOATING_CONSTANT,
  GR_ELEM_HEXADECIMAL_FLOATING_CONSTANT,
  GR_ELEM_FRACTIONAL_CONSTANT,
  GR_ELEM_EXPONENT_PART,
  GR_ELEM_SIGN,
  GR_ELEM_HEXADECIMAL_FRACTIONAL_CONSTANT,
  GR_ELEM_BINARY_EXPONENT_PART,
  GR_ELEM_FLOATING_SUFFIX,
  GR_ELEM_ENUMERATION_CONSTANT,
  GR_ELEM_CHARACTER_CONSTANT,
  GR_ELEM_ENCODING_PREFIX,
  GR_ELEM_PREDEFINED_CONSTANT,
  GR_ELEM_STRING_CONSTANT,

  GR_ELEM_PRIMARY_EXPRESSION,
  GR_ELEM_GENERIC_SELECTION,
  GR_ELEM_GENERIC_ASSOC_LIST,
  GR_ELEM_GENERIC_ASSOC,
  GR_ELEM_POSTFIX_EXPRESSION,
  GR_ELEM_ARGUMENT_EXPRESSION_LIST,
  GR_ELEM_COMPOUND_LITERAL,
  GR_ELEM_STORAGE_CLASS_SPECIFIERS,
  GR_ELEM_UNARY_EXPRESSION,
  GR_ELEM_UNARY_OPERATOR,
  GR_ELEM_CAST_EXPRESSION,
  GR_ELEM_MULTIPLICATIVE_EXPRESSION,
  GR_ELEM_ADDITIVE_EXPRESSION,
  GR_ELEM_SHIFT_EXPRESSION,
  GR_ELEM_RELATIONAL_EXPRESSION,
  GR_ELEM_EQUALITY_EXPRESSION,
  GR_ELEM_AND_EXPRESSION,
  GR_ELEM_XOR_EXPRESSION,
  GR_ELEM_OR_EXPRESSION,
  GR_ELEM_LOGICAL_AND_EXPRESSION,
  GR_ELEM_LOGICAL_OR_EXPRESSION,
  GR_ELEM_CONDITIONAL_EXPRESSION,
  GR_ELEM_ASSIGNMENT_EXPRESSION,
  GR_ELEM_ASSIGNMENT_OPERATOR,
  GR_ELEM_EXPRESSION,
  GR_ELEM_CONSTANT_EXPRESSION,
  GR_ELEM_DECLARATION,
  GR_ELEM_DECLARATION_SPECIFIERS,
  GR_ELEM_DECLARATION_SPECIFIER,
  GR_ELEM_INIT_DECLARATOR_LIST,
  GR_ELEM_INIT_DECLARATOR,
  GR_ELEM_ATTRIBUTE_DECLARATION,
  GR_ELEM_STORAGE_CLASS_SPECIFIER,
  GR_ELEM_TYPE_SPECIFIER,
  GR_ELEM_STRUCT_OR_UNION_SPECIFIER,
  GR_ELEM_STRUCT_OR_UNION,
  GR_ELEM_MEMBER_DECLARATION_LIST,
  GR_ELEM_MEMBER_DECLARATION,
  GR_ELEM_SPECIFIER_QUALIFIER_LIST,
  GR_ELEM_TYPE_SPECIFIER_QUALIFIER,
  GR_ELEM_MEMBER_DECLARATOR_LIST,
  GR_ELEM_MEMBER_DECLARATOR,
  GR_ELEM_ENUM_SPECIFIER,
  GR_ELEM_ENUMERATOR_LIST,
  GR_ELEM_ENUMERATOR,
  GR_ELEM_ENUM_TYPE_SPECIFIER,
  GR_ELEM_ATOMIC_TYPE_SPECIFIER,
  GR_ELEM_TYPEOF_SPECIFIER,
  GR_ELEM_TYPEOF_SPECIFIER_ARGUMENT,
  GR_ELEM_TYPE_QUALIFIER,
  GR_ELEM_FUNCTION_SPECIFIER,
  GR_ELEM_ALIGNMENT_SPECIFIER,
  GR_ELEM_DECLARATOR,
  GR_ELEM_DIRECT_DECLARATOR,
  GR_ELEM_ARRAY_DECLARATOR,
  GR_ELEM_FUNCTION_DECLARATOR,
  GR_ELEM_POINTER,
  GR_ELEM_TYPE_QUALIFIER_LIST,
  GR_ELEM_PARAMETER_TYPE_LIST,
  GR_ELEM_PARAMETER_LIST,
  GR_ELEM_PARAMETER_DECLARATION,
  GR_ELEM_TYPE_NAME,
  GR_ELEM_ABSTRACT_DECLARATOR,
  GR_ELEM_DIRECT_ABSTRACT_DECLARATOR,
  GR_ELEM_ARRAY_ABSTRACT_DECLARATOR,
  GR_ELEM_FUNCTION_ABSTRACT_DECLARATOR,
  GR_ELEM_TYPEDEF_NAME,
  GR_ELEM_BRACED_INITIALIZER,
  GR_ELEM_INITIALIZER,
  GR_ELEM_INITIALIZER_LIST,
  GR_ELEM_DESIGNATION,
  GR_ELEM_DESIGNATOR_LIST,
  GR_ELEM_DESIGNATOR,
  GR_ELEM_STATIC_ASSERT_DECLARATION,
  GR_ELEM_ATTRIBUTE_SPECIFIER_SEQUENCE,
  GR_ELEM_ATTRIBUTE_SPECIFIER,
  GR_ELEM_ATTRIBUTE_LIST,
  GR_ELEM_ATTRIBUTE,
  GR_ELEM_ATTRIBUTE_TOKEN,
  GR_ELEM_STANDARD_ATTRIBUTE,
  GR_ELEM_ATTRIBUTE_PREFIXED_TOKEN,
  GR_ELEM_ATTRIBUTE_PREFIX,
  GR_ELEM_ATTRIBUTE_ARGUMENT_CLAUSE,
  GR_ELEM_BALANCED_TOKEN_SEQUENCE,
  GR_ELEM_BALANCED_TOKEN,

  GR_ELEM_STATEMENT,
  GR_ELEM_UNLABELED_STATEMENT,
  GR_ELEM_PRIMARY_BLOCK,
  GR_ELEM_SECONDARY_BLOCK,
  GR_ELEM_LABEL,
  GR_ELEM_LABELED_STATEMENT,
  GR_ELEM_COMPOUND_STATEMENT,
  GR_ELEM_BLOCK_ITEM_LIST,
  GR_ELEM_BLOCK_ITEM,
  GR_ELEM_EXPRESSION_STATEMENT,
  GR_ELEM_SELECTION_STATEMENT,
  GR_ELEM_ITERATION_STATEMENT,
  GR_ELEM_JUMP_STATEMENT,

  GR_ELEM_TRANSLATION_UNIT,
  GR_ELEM_EXTERNAL_DECLARATION,
  GR_ELEM_FUNCTION_DEFINITION,
  GR_ELEM_FUNCTION_BODY,

  GR_ELEM_START,

  GR_ELEM_MAX_NO_ELEMS
} gr_elem_type_t;

typedef enum {
  GR_MATCH_CODE_FOUND,
  GR_MATCH_CODE_FOUND_NOT,
  GR_MATCH_CODE_RESTART_FULL,
  GR_MATCH_CODE_RESTART_PARTIAL,
  GR_MATCH_CODE_GRAMMAR_END
} gr_match_code_t;

typedef struct {
  const char*  name;
  unsigned int no_tokens;
  token_type_t tokens[ GR_MAX_NO_TOKENS ];
} gr_elem_info_t;

typedef struct {
  gr_elem_type_t type;
  const token_t* token;
  unsigned int   is_mandatory;
  unsigned int   is_marked;
} gr_rule_elem_t;

typedef struct {
  unsigned int   flags;

  unsigned int   no_elems;
  unsigned int   elem_idx;
  gr_rule_elem_t elems[ GR_MAX_NO_ELEMS ];
  unsigned int   is_expanded;

  //token_type_t   last_token_matched;
  //unsigned int   last_elem_matched;
  unsigned int   no_matched_elems;
} gr_rule_t;

typedef struct gr_t {
  gr_elem_type_t type;

  unsigned int   no_rules;
  unsigned int   rule_idx;
  gr_rule_t      rules[ GR_MAX_NO_RULES ];

  unsigned int   flags;
  struct {
    unsigned int last_rule_matched; // readable when GR_FLAGS_LAST_RULE_MATCHED is set
  }              flag_values;

  unsigned int   no_tokens;
  const token_t* tokens[ GR_MAX_NO_TOKENS ];

  struct gr_t*   parent;
} gr_t;

typedef struct {
  unsigned int elem_idx;
  gr_t*        elems[ GR_STACK_MAX_ELEM_IDX ];

  unsigned int elem_idx_max;
  unsigned int flags;
} gr_stack_t;

extern gr_elem_info_t gr_elem_info[ GR_ELEM_MAX_NO_ELEMS ];
extern unsigned char  gr_elem_token_graph[ GR_ELEM_MAX_NO_ELEMS ][ GR_MAX_NO_RULES ][ TOKEN_MAX_NO_TOKENS ];

// gr.c
extern gr_match_code_t gr_match(const token_t* const token);
extern void            gr_deliver(void);
extern void            gr_reg_callback_declarator(parser_callback_fn_t const parser_callback_fn);
extern void            gr_reg_callback_init_declarator(parser_callback_fn_t const parser_callback_fn);
extern void            gr_reg_callback_declaration(parser_callback_fn_t const parser_callback_fn);
extern void            gr_reg_callback_function_body(parser_callback_fn_t const parser_callback_fn);
extern void            gr_reg_callback_translation_unit(parser_callback_fn_t const parser_callback_fn);
// gr_stack.c
extern void            gr_stack_clear(gr_stack_t* const gr_stack);
// gr_elem_info.c
extern gr_t*           gr_elem_get(const gr_elem_type_t elem_type);
// gr_graph.c
extern void            gr_graph_generate(void);
// gr_error.c
extern void            gr_error_report(gr_stack_t* const gr_stack);
extern void            gr_error_print_style(const gr_rule_t* const rule);
// gr_print.c
extern void            gr_rule_print(const gr_rule_t* const rule);
extern void            gr_print(const gr_t* const gr);
extern void            gr_stack_print(const gr_stack_t* const gr_stack);

static inline __attribute__((always_inline)) gr_t* gr_alloc(void) {
  gr_t* const gr = (gr_t*) malloc(sizeof(gr_t));

  if (gr != NULL) {
    memset(((void*) (gr)), 0x00, sizeof(gr_t));
  } else {
    if (GR_DEBUG_LEVEL_ERROR >= GR_DEBUG_LEVEL) {
      fprintf(stdout,
              "error[at line %6u in %s] :: %s",
              ((unsigned int) (__LINE__)),
              __PRETTY_FUNCTION__,
              "Can't allocate memory\n");
    }
  }
  return gr;
}

static inline __attribute__((always_inline)) void gr_free(gr_t* const gr) {
  if (gr != NULL) {
    //for (unsigned int i = 0u; i < gr->no_tokens; i++) {
    //  release_token(gr->tokens[ i ]);
    //}

    memset(((void*) (gr)), 0xAA, sizeof(gr_t));
    free(((void*) (gr)));
  } else {
    if (GR_DEBUG_LEVEL_ERROR >= GR_DEBUG_LEVEL) {
      fprintf(stdout,
              "error[at line %6u in %s] :: %s",
              ((unsigned int) (__LINE__)),
              __PRETTY_FUNCTION__,
              "Can't free null pointer\n");
    }
  }
}

static inline __attribute__((always_inline)) unsigned int gr_set_next_rule_elem(gr_t* const gr) {
  if (gr != NULL) {
    if (gr->rules[ gr->rule_idx ].elem_idx + 1u < gr->rules[ gr->rule_idx ].no_elems) {
      gr->rules[ gr->rule_idx ].elem_idx++;
      return 1u;
    }
  }
  return 0u;
}

static inline __attribute__((always_inline)) unsigned int gr_set_next_rule(gr_t* const gr) {
  if (gr != NULL) {
    if (gr->rule_idx + 1u < gr->no_rules) {
      gr->rule_idx++;
      return 1u;
    }
  }
  return 0u;
}

static inline __attribute__((always_inline)) unsigned int gr_shift_rules_up(gr_t* const gr) {
  if ((gr != NULL) && (gr->no_rules >= 1u)) {
    if (gr->no_rules + 1u > GR_MAX_NO_RULES) {
      return 0u;
    }

    for (unsigned int i = gr->no_rules - 1u; i >= gr->rule_idx + 1u; i--) {
      memset(&gr->rules[ i + 1u ], 0,               sizeof(gr_rule_t));
      memcpy(&gr->rules[ i + 1u ], &gr->rules[ i ], sizeof(gr_rule_t));
    }
    memset(&gr->rules[ gr->rule_idx + 1u ], 0, sizeof(gr_rule_t));

    gr->no_rules++;

    return 1u;
  }

  return 0u;
}

static inline __attribute__((always_inline)) unsigned int gr_shift_rules_down(gr_t* const gr) {
  if ((gr != NULL) && (gr->no_rules >= 1u)) {
    for (unsigned int i = gr->rule_idx; i < gr->no_rules - 1u; i++) {
      memset(&gr->rules[ i ], 0,                    sizeof(gr_rule_t));
      memcpy(&gr->rules[ i ], &gr->rules[ i + 1u ], sizeof(gr_rule_t));
    }
    memset(&gr->rules[ gr->no_rules ], 0, sizeof(gr_rule_t));

    gr->no_rules--;
    if (gr->rule_idx == gr->no_rules) {
      gr->no_rules++;

      gr->rules[ gr->rule_idx ].no_elems                 = 1u;
      gr->rules[ gr->rule_idx ].elems[ 0u ].type         = GR_ELEM_INVALID;
      gr->rules[ gr->rule_idx ].elems[ 0u ].is_mandatory = 1u;
      gr->rules[ gr->rule_idx ].elems[ 0u ].is_marked    = 0u;
      //gr->rules[ gr->rule_idx ].last_token_matched       = TOKEN_INVALID;
      //gr->rules[ gr->rule_idx ].last_elem_matched        = 0u;
      gr->rules[ gr->rule_idx ].no_matched_elems         = 0u;
    }

    gr->flags                         &= ~GR_ELEM_FLAGS_LAST_RULE_MATCHED;
    gr->flag_values.last_rule_matched  = 0u;

    return 1u;
  }

  return 0u;
}

static inline __attribute__((always_inline)) void gr_stack_push(gr_stack_t* const gr_stack, gr_t* const gr) {
  if (gr_stack != NULL) {
    if (gr != NULL) {
      if (gr_stack->elem_idx < GR_STACK_MAX_ELEM_IDX) {
        gr_stack->elems[ gr_stack->elem_idx ] = gr;
        gr_stack->elem_idx++;

        gr_stack->elem_idx_max = (gr_stack->elem_idx > gr_stack->elem_idx_max) ? (gr_stack->elem_idx) : (gr_stack->elem_idx_max);
      } else {
        if (GR_DEBUG_LEVEL_WARNING >= GR_DEBUG_LEVEL) {
          fprintf(stdout,
                  "warning[at line %6u in %s] :: %s",
                  ((unsigned int) (__LINE__)),
                  __PRETTY_FUNCTION__,
                  "Full Stack\n");
        }
      }
    }
  }
}

static inline __attribute__((always_inline)) gr_t* gr_stack_pop(gr_stack_t* const gr_stack) {
  gr_t* gr = NULL;

  if (gr_stack != NULL) {
    if (gr_stack->elem_idx >= 1u) {
      gr_stack->elem_idx--;
      gr = gr_stack->elems[ gr_stack->elem_idx ];
      gr_stack->elems[ gr_stack->elem_idx ] = NULL;
    } else {
      if (GR_DEBUG_LEVEL_WARNING >= GR_DEBUG_LEVEL) {
        fprintf(stdout,
                "warning[at line %6u in %s] :: %s",
                ((unsigned int) (__LINE__)),
                __PRETTY_FUNCTION__,
                "Empty Stack\n");
      }
    }
  }
  return gr;
}

static inline __attribute__((always_inline)) gr_t* gr_stack_peek(gr_stack_t* const gr_stack) {
  gr_t* gr = NULL;

  if (gr_stack != NULL) {
    if (gr_stack->elem_idx >= 1u) {
      gr = gr_stack->elems[ gr_stack->elem_idx - 1u ];
    }
  }
  return gr;
}

static inline __attribute__((always_inline)) gr_t* gr_stack_pop_and_peek(gr_stack_t* const gr_stack) {
  gr_free(gr_stack_pop(gr_stack));

  return gr_stack_peek(gr_stack);
}

static inline __attribute__((always_inline)) unsigned int gr_stack_is_empty(const gr_stack_t* const gr_stack) {
  if (gr_stack != NULL) {
    return (gr_stack->elem_idx == 0u) ? (1u) : (0u);
  }
  return 1u;
}

static inline __attribute__((always_inline)) unsigned int gr_stack_is_full(const gr_stack_t* const gr_stack) {
  if (gr_stack != NULL) {
    return (gr_stack->elem_idx >= GR_STACK_MAX_ELEM_IDX) ? (1u) : (0u);
  }
  return 0u;
}

#endif
