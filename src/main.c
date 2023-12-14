#include "parser.h"

#include <stdio.h>

int main(int argc, char* argv[ ]) {
  for (int i = 0; i < argc; i++) {
    fprintf(stdout, "argv[ %2d ] = %s\n", i, argv[ i ]);
  }

  parse_source_file(argv[ 1 ]);
  return 0;
}
