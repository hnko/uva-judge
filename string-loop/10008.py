# AC - re and Counter

import re
from collections import Counter

t = int(input())

words = ''
for _ in range(t): 
	words += input()

r = ''.join(re.findall(r'(?i)[a-z]+', words)).lower()
c = Counter(r)

for elem, freq in sorted(c.most_common(), key=lambda x: (-x[1], ord(x[0]))):
	print(elem.upper(), freq)