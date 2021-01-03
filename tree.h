typedef struct treeNode {
  char pattern; // Character to match
  int pos;      // Position (index) relative to the first treeNode to match
  int identity; // What happens when this treeNode is the last to be matched
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
  int childsize;
  struct treeNode *child[]; // Pointer array to other child nodes
} node ;

node n_a = {
  '*',	0,	1,	4,
  {&n_aa, &n_ab, &n_ac, &n_ad}
};

node n_aa = {
  '\\',	-1,	0,	0,
  {}
};

node n_ab = {
  '*',	1,	2,	3,
  {&n_aba, &n_abb, &n_abc}
};

node n_aba = {
  '_',	-1,	3,	0,
  {}
};

node n_abb = {
  '*',	2,	3,	0,
  {}
};

node n_abc = {
  '_',	2,	3,	0,
  {}
};

node n_ac = {
  '_',	-1,	0,	1,
  {&n_aca}
};

node n_aca = {
  '_',	-2,	3,	0,
  {}
};

node n_ad = {
  '_',	1,	0,	1,
  {&n_ada}
};

node n_ada = {
  '_',	2,	3,	0,
  {}
};

node n_b = {
  '_',	0,	1,	2,
  {&n_ba, &n_bb}
};

node n_ba = {
  '\\',	-1,	0,	0,
  {}
};

node n_bb = {
  '_',	1,	0,	1,
  {&n_bba}
};

node n_bba = {
  '_',	2,	3,	0,
  {}
};

node n_c = {
  '`',	0,	4,	2,
  {&n_ca, &n_cb}
};

node n_ca = {
  '\\',	-1,	0,	0,
  {}
};

node n_cb = {
  '`',	1,	0,	1,
  {&n_cba}
};

node n_cba = {
  '`',	2,	0,	1,
  {&n_cbaa}
};

node n_cbaa = {
  '\n',	-1,	5,	0,
  {}
};

node n_d = {
  '\n',	0,	0,	6,
  {&n_da, &n_db, &n_dc, &n_dd, &n_de, &n_df, }
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

node n_dea = {
  '-',	-2,	0,	1,
  {&n_deaa}
};

node n_deaa = {
  '-',	-3,	9,	0,
  {}
};

node n_df = {
  't',	3,	0,	3,
  {&n_dfa, &n_dfb, &n_dfc}
};

node n_dfa = {
  'a',	1,	0,	1,
  {&n_dfaa}
};

node n_dfaa = {
  'u',	2,	0,	1,
  {&n_dfaaa}
};

node n_dfaaa = {
  'h',	4,	0,	1,
  {&n_dfaaaa}
};

node n_dfaaaa = {
  'o',	5,	0,	1,
  {&n_dfaaaaa}
};

node n_dfaaaaa = {
  'r',	6,	0,	1,
  {&n_dfaaaaaa}
};

node &n_dfaaaaaa = {
  ':',	7,	11,	0,
  {}
};

node n_dfb = {
  'd',	1,	0,	1,
  {&n_dfba}
};

node n_dfba = {
  'a',	2,	0,	1,
  {&n_dfbaa}
};

node n_dfbaa = {
  'e',	4,	0,	2,
  {&n_dfbaaa, &n_dfbaab}
};

node n_dfbaaa = {
  ':',	5,	13,	0,
  {}
};

node n_dfbaab = {
  '\n',	5,	12,	0,
  {}
};

node n_dfc = {
  't',	1,	0,	1,
  {&n_dfca}
};

node n_dfca = {
  'i',	2,	0,	1,
  {&n_dfcaa}
};

node n_dfcaa = {
  'l',	4,	0,	1,
  {&n_dfcaaa}
};

node n_dfcaaa = {
  'e',	5,	0,	1,
  {&n_dfcaaaa}
};

node n_dfcaaaa = {
  ':',	6,	10,	0,
  {}
};

