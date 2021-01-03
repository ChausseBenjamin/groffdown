.TL
 Groffdown
.AU
 Benjamin Chausse
.ND
 2019-09-19
Markdown syntax with GNU/Troff-like compilation speeds.
---


.NH 1
What is Groffdown?
.PP
Groffdown aims to take the already existing (and well-known)
markdown syntax and make it compile at speed similar to the
ones of groff. The main compiler for markdown to pdf usually
being 
.CW "pandoc" ","
 it can be quite long to compile a document (up
to four seconds for one page documents
in some cases) unlike Groff which is known
to usually compile very quickly (0.1 second on average for
one page documents). As a proof of concept, this 
.I "README" 
pages can be fully compiled using groffdown to then be used by groff.

.NH 1
Example piping workflow
.PP
Groffdown is a script which when run on a markdown document,
will convert the most typical markdown syntax into groff
(using the 
.CW "ms" " "
macros) to then send it to standard output.
Therefore, it can be piped directly into groff (or
it's related software). Here is an example  of a complete piping
command:

.IP \(bu 2
groffdown <filename>.gd | refer -PS -e "-p$REFERBIB" | groff -me -ms -kejpt -T pdf > <filename>.pdf

.NH 1
Syntax goals
.PP
.IP \(bu 2
Speed
.IP \(bu 2
Markdown Syntax (with yaml preamble)
.IP \(bu 2
LaTeX where markdown lacks


.NH 2
Existing Syntax
.PP

.NH 3
Commands similar to markdown
.PP
.IP \(bu 2
Headers (1-5)
.IP \(bu 2

.I "Italic" 
.IP \(bu 2

.B "Bold" 
.IP \(bu 2

.BI "Bold & Italic" 
.IP \(bu 2
Bullet points
.IP \(bu 2

.CW "Code blocks (in a monospaced font)" 

.NH 3
Commands similar to LaTeX
.PP
.IP \(bu 2
Abstract
.IP \(bu 2
Inline equations
.IP \(bu 2
Centered equations
.IP \(bu 2
Citations

.NH 3
Commands similar to YAML
.PP
.IP \(bu 2
Titles
.IP \(bu 2
Authors
.IP \(bu 2
Dates
.IP \(bu 2
Author's Institution

.NH 1
Current issues
.PP
.IP \(bu 2
All text formatings need to be on the same line (you can't start bold
  on one line and finish on the other) Doing otherwise seems to trigger
  an unescapable recursive loop on the groff side of things.

.NH 1
Needed implementations
.PP
.IP \(bu 2
Numbered lists
.IP \(bu 2
multi-macro compatibility (mom macros for urls)
