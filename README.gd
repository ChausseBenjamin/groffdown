---
title: Groffdown
author: Benjamin Chausse
date: 2019-09-19
Markdown syntax with GNU/Troff-like compilation speeds.
---


# What is Groffdown?
Groffdown aims to take the already existing (and well-known)
markdown syntax and make it compile at speed similar to the
ones of groff. The main compiler for markdown to pdf usually
being `pandoc`, it can be quite long to compile a document (up
to four seconds for one page documents
in some cases) unlike Groff which is known
to usually compile very quickly (0.1 second on average for
one page documents). As a proof of concept, this *README*
file can be fully compiled using groffdown to then be used by groff.

# Example piping workflow
Groffdown is a script which when run on a markdown document,
will convert the most typical markdown syntax into groff
(using the `ms` macros) to then send it to standard output.
Therefore, it can be piped directly into groff (or
it's related software). Here is an example  of a complete piping
command:

- groffdown <filename>.gd | refer -PS -e "-p$REFERBIB" | groff -me -ms -kejpt -T pdf > <filename>.pdf

# Syntax goals
- Speed
- Markdown Syntax (with yaml preamble)
- LaTeX where markdown lacks


## Existing Syntax

### Commands similar to markdown
- Headers (1-5)
- *Italic*
- **Bold**
- ***Bold & Italic***
- Bullet points
- `Code blocks (in a monospaced font)`

### Commands similar to LaTeX
- Abstract
- Inline equations
- Centered equations
- Citations

### Commands similar to YAML
- Titles
- Authors
- Dates
- Author's Institution

# Current issues
- All text formatings need to be on the same line (you can't start bold
  on one line and finish on the other) Doing otherwise seems to trigger
  an unescapable recursive loop on the groff side of things.

# Needed implementations
- Numbered lists
- multi-macro compatibility (mom macros for urls)
