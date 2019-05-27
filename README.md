# Groffdown
Markdown syntax with GNU/Troff-like compilation speeds.

## What is Groffdown?
Groffdown aims to take the already existing (and well-known)
markdown syntax and make it compile at speed similar to the
ones of groff. The main compiler for markdown to pdf usually
being `pandoc`, it can be quite long to compile a document (up
to four seconds for one page documents
in some cases) unlike Groff which is known
to usually compile very quickly (0.1 second on average for
one page documents).

Groffdown is a script that when ran on a markdown document,
will convert the most typical markdown syntax into groff
(using the `ms` macros) to then output it to a `.ms` file.

At a later stage, the goal will be to output groffdown
as standard output (sdout). Since I am not aware if the
`refer` groff pre-processor can accept standard input
(sdin), I prefer to keep it at that for the moment.

## Syntax goals

1. Speed
2. Markdown Syntax (with yaml preamble)
3. LaTeX where markdown lacks


## Existing Syntax

| Description          | Command                             | `.md` | `.tex` | `YAML-like` |
|----------------------|-------------------------------------|-------|--------|-------------|
| Headers (1-5)        | `#`-`#####`                         | X     |        |             |
| Italic               | `*text*`                            | X     |        |             |
| Bold                 | `**text**`                          | X     |        |             |
| Bold & Italic        | `***text***`                        | X     |        |             |
| Bullet points        | `- text`                            | X     |        |             |
| Title                | `title: `(in preamble)              |       |        | X           |
| Author               | `author: `(in preamble)             |       |        | X           |
| Date                 | `date: `(in preamble)               |       |        | X           |
| Author's Institution | `institution: `(in preamble)        |       |        | X           |
| Abstract             | `\begin{abstract}`-`\end{abstract}` |       | X      |             |
| Inline equations     | `$x+1$`                             |       | X      |             |
| Centered equations   | `\begin{equation}`-`\end{equation}` |       | X      |             |
| Citations            | `\cite{reference}`                  |       | X      |             |

## Current issues
- Indented bulletted list (sublists) don't work
- All text formatings need to be on the same line (you can't start bold
  on one line and finish on the other)

## Needed implementations
- Numbered lists
- Tables
- multi-macro compatibility (mom macros for urls)
- Optional output to `sdout`
