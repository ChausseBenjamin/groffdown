GNU/Troff macros and macro packages
===================================

man: The traditional man page format (`man groff_man`)
------------------------------------------------------

me: The classical `me` document format (`man groff_me`)
-------------------------------------------------------

mm: The classical `mm` document format (`man groff_mm`)
-------------------------------------------------------

ms: The classical `ms` document format (`man groff_ms`)
-------------------------------------------------------

www: HTML-like macros (`man groff_www`)
---------------------------------------

| Macro | Meaning                       | Subsection                 | Sets | MD Alternative      |
| ----- | ----------------------------- | -------------------------- | ---- | ------------------- |
| .B    | Bold                          | Font style macros          | man, | **Bold**            |
| .BI   | Bold, italic alternating      | Font style macros          | man, | ***Bold & italic*** |
| .BR   | Bold, roman alternating       | Font style macros          | man, | N/A                 |
| .EE   | Example end                   | Document structure macros  | man, | N/A                 |
| .EX   | Example begin                 | Document structure macros  | man, | N/A                 |
| .I    | Italic                        | Font style macros          | man, | *Italic*            |
| .IP   | Indented paragraph            | Paragraph macros           | man, | `    ` Tabs         |
| .IR   | Italic, roman alternating     | Font style macros          | man, |
| .LP   | (Left) paragraph              | Paragraph macros           | man, |
| .ME   | Mail-to end                   | Hyperlink and email macros | man, |
| .MT   | Mail-to start                 | Hyperlink and email macros | man, |
| .OP   | (Command-line) option         | Command synopsis macros    | man, |
| .P    | Paragraph                     | Paragraph macros           | man, |
| .PP   | Paragraph                     | Paragraph macros           | man, |
| .RB   | Roman, bold alternating       | Font style macros          | man, |
| .RE   | Relative-indent end           | Document structure macros  | man, |
| .RI   | Roman, italic alternating     | Font style macros          | man, |
| .RS   | Relative-indent start         | Document structure macros  | man, |
| .SB   | Small bold                    | Font style macros          | man, |
| .SH   | Section heading               | Document structure macros  | man, |
| .SM   | Small                         | Font style macros          | man, |
| .SS   | Subection heading             | Document structure macros  | man, |
| .SY   | Synopsis start                | Command synopsis macros    | man, |
| .TH   | Title heading                 | Document structure macros  | man, |
| .TP   | Tagged paragraph              | Paragraph macros           | man, |
| .TQ   | Tagged paragraph continuation | Paragraph macros           | man, |
| .UE   | URL end                       | Hyperlink and email macros | man, |
| .UR   | URL start                     | Hyperlink and email macros | man, |
| .YS   | Synopsis end                  | Command synopsis macros    | man, |

