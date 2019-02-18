# AC - count freq letters

import re
from collections import Counter

t = int(input())
for _ in range(t):
	line = input()
	r = ''.join(re.findall(r'[A-Za-z]+', line.lower()))
	c = Counter(r).most_common()

	prev = c[0][1]
	ans = [c[0][0]]
	
	for counter in c[1:]:
		if counter[1] == prev:
			ans.append(counter[0])
	for elem in sorted(ans):
		print(elem, end='')
	print()

