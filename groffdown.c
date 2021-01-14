/*=============================================================================

  title: groffdown
  author: Benjamin Chausse
  last update: 2020-01-02

  Groffdown is meant as a translation layer between markdown and groff (or
  GNU/Troff if you are so inclined). Most solutions for generating formatted
  documents using groff often rely on software that is heavy on processing
  (such as LaTeX) thus making marking document compilation feel slow and
  innapropriate for live previewing. For more information about the project and
  it's usage please consult the man page. For more information about the
  project's copyright rules, please consult the LICENSE file contained in this
  repository.

  TODO: Write a manual

=============================================================================*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

FILE *fileptr;
char *buffer;
long filelen;

// Node tree used by the algorithm:
#include "tree.h"


node * match(node *n) {
  /* int nomatch = 1; */
  printf("Master node: %c\n", n->pattern );
  for (int i = 0; i < n->childsize-1; i++) {
    printf("Child %d, pattern: %c, identity: %d, position: %d\n",
        i,
        (n->child[i])->pattern,
        (n->child[i])->identity,
        (n->child[i])->pos);
  };
  printf("\n");
  return (n->child[1]) ;
};

int main() {

  node *test = match(&n_a);
  test = match(test);
  /* test = match(&test, '*'); */

  /* // Importing the file into a char[] {{{ */
  /* // TODO: file should be either piped or passed as an argument */
  /* fileptr = fopen("sample.gd", "rb"); */
  /* fseek(fileptr, 0, SEEK_END); // Jump to EOF */
  /* filelen = ftell(fileptr);    // Get byte offset */
  /* rewind(fileptr);             // Jump back to beggining */
  /* buffer = (char *)malloc(filelen * sizeof(char)); // Enough memory for the file */
  /* fread(buffer, filelen, 1, fileptr);              // Read all the file */
  /* fclose(fileptr);                                 // Close file */
  /* // }}} */

  /* // Pattern matching algorithm {{{ */
  /* for (long i = 0; i < filelen; i++) { */
  /*   printf("%s", *fileptr); */
  /*   fileptr++; */
  /* } */
  /* // }}} */

  /* // Node Tree test {{{ */
  /* printf("Pattern: '%c'\n", root.pattern); */
  /* printf("End of test."); */
  /* // }}} */

return 0;
};
