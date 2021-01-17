typedef struct singleNode {
  char pattern; // Character to match
  int pos;      // Position of char to match relative to it's parent node.
  int event; // What happens when this treeNode is the last to be matched
    // 0:  Invalid match: Match pattern is most likely incomplete (or escaped)
    // 1:  italics delimiter
    // 2:  bold delimiter
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
    // 15: bold&italics delimiter with a -1 offset
    // 16: bold&italics delimiter with a -2 offset
    // 17: asterisk escape sequence
    // 18: underscore escape sequence
    // 19: backtick escape sequence
  int childsize;
  struct singleNode *child[]; // Pointer array to other child nodes
} node ;

// 8 depth {{{
node n_dfaaaaaa = {
  ':',	1,	11,	0,
  {}
};
// }}}

// 7 depth {{{
node n_dfaaaaa = {
  'r',	1,	0,	1,
  {&n_dfaaaaaa}
};

node n_dfcaaaa = {
  ':',	1,	10,	0,
  {}
};
// }}}

// 6 depth {{{
node n_dfaaaa = {
  'o',	1,	0,	1,
  {&n_dfaaaaa}
};

node n_dfbaaa = {
  ':',	1,	13,	0,
  {}
};

node n_dfbaab = {
  '\n',	1,	12,	0,
  {}
};

node n_dfcaaa = {
  'e',	1,	0,	1,
  {&n_dfcaaaa}
};
// }}}

// 5 depth {{{
node n_dfaaa = {
  'h',	2,	0,	1,
  {&n_dfaaaa}
};

node n_dfbaa = {
  'e',	2,	0,	2,
  {&n_dfbaaa, &n_dfbaab}
};

node n_dfcaa = {
  'l',	2,	0,	1,
  {&n_dfcaaa}
};
// }}}

// 4 depth {{{
node n_dfca = {
  'i',	1,	0,	1,
  {&n_dfcaa}
};

node n_cbaa = {
  '\n',	-3,	5,	0,
  {}
};

node n_deaa = {
  '-',	-1,	9,	0,
  {}
};

node n_dfaa = {
  'u',	1,	0,	1,
  {&n_dfaaa}
};

node n_dfba = {
  'a',	1,	0,	1,
  {&n_dfbaa}
};
// }}}

// 3 depth {{{
node n_dfc = {
  't',	-2,	0,	1,
  {&n_dfca}
};

node n_aba = {
  '_',	-2,	15,	0,
  {}
};

node n_abb = {
  '*',	1,	3,	0,
  {}
};

node n_abc = {
  '_',	1,	3,	0,
  {}
};

node n_aca = {
  '_',	-1,	16,	0,
  {}
};

node n_ada = {
  '_',	1,	3,	0,
  {}
};

node n_bba = {
  '_',	1,	3,	0,
  {}
};

node n_cba = {
  '`',	1,	0,	1,
  {&n_cbaa}
};

node n_dea = {
  '-',	-1,	0,	1,
  {&n_deaa}
};

node n_dfa = {
  'a',	-2,	0,	1,
  {&n_dfaa}
};

node n_dfb = {
  'd',	-2,	0,	1,
  {&n_dfba}
};
// }}}

// 2 depth {{{
node n_df = {
  't',	3,	0,	3,
  {&n_dfa, &n_dfb, &n_dfc}
};

node n_aa = {
  '\\',	-1,	17,	0,
  {}
};

node n_ab = {
  '*',	1,	2,	3,
  {&n_aba, &n_abb, &n_abc}
};

node n_ac = {
  '_',	-1,	0,	1,
  {&n_aca}
};

node n_ad = {
  '_',	1,	0,	1,
  {&n_ada}
};

node n_ba = {
  '\\',	-1,	18,	0,
  {}
};

node n_bb = {
  '_',	1,	0,	1,
  {&n_bba}
};

node n_ca = {
  '\\',	-1,	19,	0,
  {}
};

node n_cb = {
  '`',	1,	0,	1,
  {&n_cba}
};

node n_da = {
  '#',	1,	8,	0,
  {}
};

node n_db = {
  '=',	1,	6,	0,
  {}
};

node n_dc = {
  '-',	1,	7,	0,
  {}
};

node n_dd = {
  '>',	1,	14,	0,
  {}
};

node n_de = {
  '-',	-1,	0,	1,
  {&n_dea}
};
// }}}

// 1 depth {{{
node n_a = {
  '*',	0,	1,	4,
  {&n_aa, &n_ab, &n_ac, &n_ad}
};

node n_b = {
  '_',	0,	1,	2,
  {&n_ba, &n_bb}
};

node n_c = {
  '`',	0,	4,	2,
  {&n_ca, &n_cb}
};

node n_d = {
  '\n',	0,	0,	6,
  {&n_da, &n_db, &n_dc, &n_dd, &n_de, &n_df, }
};
// }}}

node main_root = {
  '@', 0, 0, 4,
  {&n_a, &n_b, &n_c, &n_d}
};

