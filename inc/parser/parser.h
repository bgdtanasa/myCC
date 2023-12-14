#ifndef _PARSER_H_
#define _PARSER_H_

typedef enum {
  PARSER_ERR_OK = 0,
  PARSER_ERR_NULL_SRC_FILE,
  PARSER_ERR_NOT_REGULAR_SRC_FILE,
  PARSER_ERR_FOPEN,
  PARSER_ERR_FSTAT,
  PARSER_ERR_MMAP,
  PARSER_MAX
} parser_err_t;

typedef void (*parser_callback_fn_t)(const void* const);

extern parser_err_t parse_source_file(const char* const src_file);

#endif
