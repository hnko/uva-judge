import re

text = 'abcdefgABCDEFGBCAcba 123445 1231234 343321244113'
pattern = re.compile(r'\d')

matches = pattern.finditer(text)

for match in matches:
	print(match)
# necesitan \ : . () + * [] ? {} $ ^ \
# avoid case sensitive (?i)
# . any character except the \n
# \d for number
# \D not number
# \w for word(a-z..0-9)
# \w for not word
# \s spaces, newlines, tab
# \S not \s




"""
.       - Any Character Except New Line
\d      - Digit (0-9)
\D      - Not a Digit (0-9)
\w      - Word Character (a-z, A-Z, 0-9, _)
\W      - Not a Word Character
\s      - Whitespace (space, tab, newline)
\S      - Not Whitespace (space, tab, newline)

\b      - Word Boundary - for check more than one word use it instead of ^
\B      - Not a Word Boundary
^       - Beginning of a String
$       - End of a String

[]      - Matches Characters in brackets
[^ ]    - Matches Characters NOT in brackets
|       - Either Or
( )     - Group

Quantifiers:
*       - 0 or More
+       - 1 or More
?       - 0 or One
{3}     - Exact Number
{3,4}   - Range of Numbers (Minimum, Maximum)


re.finditer(pattern, string)
	match.group()
re.match(pattern, string)
re.search(pattern, string)
	match.start()
	match.end()
re.compile(pattern)
re.sub(pattern, change, string)
re.findall(pattern, string)

start with 'a' or 'e':  re.findall(r'\b[ae]\w+', string)

#### Sample Regexs ####

[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+
"""