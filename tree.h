typedef struct treeNode {
  char pattern; // Character to match
  int pos;      // Position (index) relative to the first treeNode to match
  int identity; // What happens when this treeNode is the last to be matched
    // 0:  Invalid match: Match pattern is most likely incomplete (or escaped)
    // 1:  bold delimiter
    // 2:  italics delimiter
    // 3:  bold&italics delimiter
    // 4:  inline code delimiter
    // 5:  code block delimiter
    // 6:  header 1 (h1) delimiter
    // 7:  header 2 (h2) delimiter
    // 8:  header delimiter
    // 9:  yaml intro delimiter
    // 10: title
    // 11: author
    // 12: automatic date (date will be formatted for groff on compile time)
    // 13: manual date
    // 14: indent text
  int childsize;
  struct treeNode *child[]; // Pointer array to other child nodes
} node ;

node root {
  ' ', 0, 0, 4,
  { node  = {
    '*',	0,	2,	4,
    {}
    };
  }
}
