#include "parser.h"

#include <time.h>

#include <sys/stat.h>
#include <sys/mman.h>

#include "tokenizer.h"
#include "gr.h"

typedef struct {
  unsigned int   track;
  unsigned int   no_elems;
  const token_t* elems[ GR_MAX_NO_TOKENS ];
} gr_track_elems_t;

static const unsigned long long PAGE_SIZE = 4096llu;

static off_t this_pos;

static gr_track_elems_t gr_track_init_declarators;

static void parser_callback_declarator(const void* const p);
static void parser_callback_init_declarator(const void* const p);
static void parser_callback_declaration(const void* const p);
static void parser_callback_function_body(const void* const p);
static void parser_callback_translation_unit(const void* const p);

static void* map_source_file(const int fd, const off_t fd_size) {
  if ((fd != -1) && (fd_size > 0)) {
    const unsigned long long fd_mem_size = ((((unsigned long long) (fd_size)) / PAGE_SIZE) + 1llu) * PAGE_SIZE;
    void*                    fd_mem      = mmap(NULL, ((size_t) (fd_mem_size)), PROT_READ, MAP_SHARED, fd, 0);

    if (fd_mem == MAP_FAILED) {
      fd_mem = NULL;
    }

    return fd_mem;
  }

  return NULL;
}

static void umap_source_file(void* const fd_mem, const off_t fd_size) {
  if ((fd_mem != NULL) && (fd_size > 0)) {
    const unsigned long long fd_mem_size = ((((unsigned long long) (fd_size)) / PAGE_SIZE) + 1llu) * PAGE_SIZE;

    (void) munmap(fd_mem, fd_mem_size);
  }
}

static parser_err_t do_parsing(const unsigned char* const src_code,
                               off_t* const               pos,
                               const off_t                max_pos);

extern parser_err_t parse_source_file(const char* const src_file) {
  parser_err_t ret = PARSER_ERR_OK;

	if (src_file != NULL) {
    FILE* const fp = fopen(src_file, "r");

    if (fp != NULL) {
      const int fd        = fileno(fp);
      struct stat fd_stat = { 0 };

      if (fstat(fd, &fd_stat) == 0) {
        if (S_ISREG(fd_stat.st_mode)) {
          const off_t fd_size = fd_stat.st_size;
          void* const fd_mem  = map_source_file(fd, fd_size);

          if (fd_mem != NULL) {
            ret = do_parsing(fd_mem, &this_pos, fd_size);

            umap_source_file(fd_mem, fd_size);
          } else {
            ret = PARSER_ERR_MMAP;
          }
        } else {
          ret = PARSER_ERR_NOT_REGULAR_SRC_FILE;
        }
      } else {
        ret = PARSER_ERR_FSTAT;
      }

      fclose(fp);
    } else {
      return PARSER_ERR_FOPEN;
    }
  } else {
    return PARSER_ERR_NULL_SRC_FILE;
  }

  return ret;
}

static parser_err_t do_parsing(const unsigned char* const src_code,
                               off_t* const               pos,
                               const off_t                max_pos) {
  const token_t* token     = NULL;
  unsigned int   no_tokens = 0u;

  struct timespec a = {};
  struct timespec b = {};

  gr_graph_generate();
  gr_reg_callback_declarator(parser_callback_declarator);
  gr_reg_callback_init_declarator(parser_callback_init_declarator);
  gr_reg_callback_declaration(parser_callback_declaration);
  gr_reg_callback_function_body(parser_callback_function_body);
  gr_reg_callback_translation_unit(parser_callback_translation_unit);

  clock_gettime(CLOCK_MONOTONIC, &a);
  do {
    token = get_token(src_code, pos, max_pos, GET_TOKEN_FLAGS_FPRINTF);
    if (token != NULL) {
      gr_match_code_t ret = GR_MATCH_CODE_FOUND_NOT;

      no_tokens++;
      for (unsigned int i = 0u; i < token->no_burn_tokens; i++) {
        burn_token(src_code, pos, max_pos);
      }

      if (token->type != TOKEN_INVALID) {
        ret = gr_match(token);
        if (ret != GR_MATCH_CODE_FOUND) {
          ret = GR_MATCH_CODE_FOUND_NOT;
        }
      } else {
        ret = GR_MATCH_CODE_FOUND;
      }
      //release_token(token);

      if (ret == GR_MATCH_CODE_FOUND_NOT) {
        fprintf(stdout, "Parsing error at %64s ...\n", &src_code[ *pos ]);
        break;
      }
    } else {
      // error
    }
  } while (token != NULL);
  clock_gettime(CLOCK_MONOTONIC, &b);

  gr_deliver();
  fprintf(stdout,
          "Parser time            = %10llu ms\n",
          (((unsigned long long) (b.tv_sec - a.tv_sec)) * 1000000000llu + ((unsigned long long) (b.tv_nsec - a.tv_nsec))) / 1000000llu);

  fprintf(stdout, "no_tokens              = %10u\n", no_tokens);
  fprintf(stdout, "sizeof(gr_t)           = %10u\n", ((unsigned int) (sizeof(gr_t))));
  fprintf(stdout, "sizeof(gr_rule_t)      = %10u\n", ((unsigned int) (sizeof(gr_rule_t))));
  fprintf(stdout, "sizeof(gr_rule_elem_t) = %10u\n", ((unsigned int) (sizeof(gr_rule_elem_t))));

  return PARSER_ERR_OK;
}

static void parser_callback_declarator(const void* const p) {
  gr_t* const gr = ((gr_t* const) (p));

#if 1
  fprintf(stdout, "Declarator      :: ");
  gr->rules[ gr->rule_idx ].flags |= GR_RULE_FLAGS_SKIP_NON_MARKED;
  gr_rule_print(&gr->rules[ gr->rule_idx ]);
  gr->rules[ gr->rule_idx ].flags &= ~GR_RULE_FLAGS_SKIP_NON_MARKED;
#else
  (void) gr;
#endif
}

static void parser_callback_init_declarator(const void* const p) {
  static unsigned int a    = 0u;
  gr_t* const         gr   = ((gr_t* const) (p));
  gr_rule_t* const    rule = &gr->rules[ gr->rule_idx ];

  fprintf(stdout, "Init Declarator :: ");
  gr->rules[ gr->rule_idx ].flags |= GR_RULE_FLAGS_SKIP_NON_MARKED;
  gr_rule_print(&gr->rules[ gr->rule_idx ]);
  gr->rules[ gr->rule_idx ].flags &= ~GR_RULE_FLAGS_SKIP_NON_MARKED;

  if (a == 0u) {
  } else {
    if (gr_track_init_declarators.track == 1u) {
      for (unsigned int i = 0u; i < rule->no_elems; i++) {
        if (rule->elems[ i ].type == GR_ELEM_IDENTIFIER) {
          const unsigned int no_elems = gr_track_init_declarators.no_elems;

          gr_track_init_declarators.no_elems          = no_elems + 1u;
          gr_track_init_declarators.elems[ no_elems ] = rule->elems[ i ].token;
        }
      }
    }
  }
  a = (a + 1u) % 2u;
}

static void parser_callback_declaration(const void* const p) {
  static unsigned int a    = 0u;
  gr_t* const         gr   = ((gr_t* const) (p));
  gr_rule_t* const    rule = &gr->rules[ gr->rule_idx ];

  fprintf(stdout, "Declaration :: ");
  gr->rules[ gr->rule_idx ].flags |= GR_RULE_FLAGS_SKIP_NON_MARKED;
  gr_rule_print(&gr->rules[ gr->rule_idx ]);
  gr->rules[ gr->rule_idx ].flags &= ~GR_RULE_FLAGS_SKIP_NON_MARKED;

  if (a == 0u) {
    gr_track_init_declarators.track = 1u;
  } else {
    // Is this a forward declaration? struct-or-enum
    // ...

    // Is this a typedef construct?
    for (unsigned int i = 0u; i < rule->no_elems; i++) {
      if (rule->elems[ i ].type == GR_ELEM_KEYWORD_TYPEDEF) {
        for (unsigned int j = 0u; j < gr_track_init_declarators.no_elems; j++) {
          const unsigned int no_identifiers = token_identifier_typedefs.no_identifiers;

          token_identifier_typedefs.no_identifiers = no_identifiers + 1u;
          strcpy((char*) &token_identifier_typedefs.identifiers[ no_identifiers ][ 0u ],
                 (char*) &gr_track_init_declarators.elems[ j ]->name[ 0u ]);

          fprintf(stdout, "%3u %32s\n", no_identifiers, (char*) &token_identifier_typedefs.identifiers[ no_identifiers ][ 0u ]);
        }
        fprintf(stdout, "\033[37;1m==================================================\033[0m\n");

        break;
      }
    }

    gr_track_init_declarators.track    = 0u;
    gr_track_init_declarators.no_elems = 0u;
  }
  a = (a + 1u) % 2u;
}

static void parser_callback_function_body(const void* const p) {
  gr_t* const gr = ((gr_t* const) (p));

#if 0
  fprintf(stdout, "Function Body :: ");
  gr_rule_print(&gr->rules[ gr->rule_idx ]);
#else
  (void) gr;
#endif
}

static void parser_callback_translation_unit(const void* const p) {
  gr_t* const gr = ((gr_t* const) (p));

#if 0
  fprintf(stdout, "Translation Unit :: ");
  gr_rule_print(&gr->rules[ gr->rule_idx ]);
#else
  (void) gr;
#endif
}
