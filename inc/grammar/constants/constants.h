#ifndef _TOKENS_H_
#define _TOKENS_H_

#include "gr.h"

extern gr_t gr_elem_digit;
extern gr_t gr_elem_non_zero_digit;
extern gr_t gr_elem_octal_digit;
extern gr_t gr_elem_hexadecimal_digit;
extern gr_t gr_elem_binary_digit;
extern gr_t gr_elem_digit_sequence;
extern gr_t gr_elem_hexadecimal_digit_sequence;
extern gr_t gr_elem_c_char;
extern gr_t gr_elem_c_char_sequence;
extern gr_t gr_elem_escape_sequence;
extern gr_t gr_elem_simple_escape_sequence;
extern gr_t gr_elem_octal_escape_sequence;
extern gr_t gr_elem_hexadecimal_escape_sequence;
extern gr_t gr_elem_constant;
extern gr_t gr_elem_integer_constant;
extern gr_t gr_elem_decimal_constant;
extern gr_t gr_elem_octal_constant;
extern gr_t gr_elem_hexadecimal_constant;
extern gr_t gr_elem_binary_constant;
extern gr_t gr_elem_hexadecimal_prefix;
extern gr_t gr_elem_binary_prefix;
extern gr_t gr_elem_integer_suffix;
extern gr_t gr_elem_bit_precise_int_suffix;
extern gr_t gr_elem_unsigned_suffix;
extern gr_t gr_elem_long_suffix;
extern gr_t gr_elem_long_long_suffix;
extern gr_t gr_elem_floating_constant;
extern gr_t gr_elem_decimal_floating_constant;
extern gr_t gr_elem_hexadecimal_floating_constant;
extern gr_t gr_elem_fractional_constant;
extern gr_t gr_elem_exponent_part;
extern gr_t gr_elem_sign;
extern gr_t gr_elem_hexadecimal_fractional_constant;
extern gr_t gr_elem_binary_exponent_part;
extern gr_t gr_elem_floating_suffix;
extern gr_t gr_elem_enumeration_constant;
extern gr_t gr_elem_character_constant;
extern gr_t gr_elem_encoding_prefix;
extern gr_t gr_elem_predefined_constant;
extern gr_t gr_elem_string_constant;

#endif
