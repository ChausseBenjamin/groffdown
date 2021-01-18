/*=============================================================================

  title: groffdown
  author: Benjamin Chausse
  last update: 2020-01-18

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

#include "tree.h"
#include "matchlist.h"

FILE *fileptr;
char *buffer;
long filelen;


/*
 * Checks for pattern matches within all the nodes children
 *   returns the the deepest child for which there is a match
 *   returns 0 if no match was found
 *   if node a->move, b->move = -1, 2 (And b is a's child)
 *     b should be changed to 3:
 *       0(the root) -1(node a) + 3(node b) = 2
 *       2 being b's actual moveition relative to root
 */
node * checkChildren(node *n, char *b){
  node *curr;
  for ( int i = 0; i < n->childsize-1; i++ ) {
    curr = n->child[i];
    if ( curr->pattern == b[curr->move] ){
      return checkChildren(curr, b+curr->move);
    };
  };
  return n;
}

int main() {

  char *c = "\\*ello";
  const char *bufstart = c;
  c +=4;
  printf("Index: %d\n", c-bufstart);
  node *current = &main_root;

  /* printf("CS: %d\n", n->childsize); */
  /* printnode(n->child[3]); */

  node *test;
  test = checkChildren(current, c);
  printf("Test: %d", test->event);

  return 0;
};

