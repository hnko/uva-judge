# AC - use regex - Counter - sort
import re
from collections import Counter

while True:
	try:
		r = re.findall(r'[A-Za-z]+', input())
		r = ''.join(r)
		freq = Counter(r).most_common()

		prev = freq[0][1]
		ans = [ freq[0][0] ]

		for f in freq[1:]:
			if f[1] == prev:
				ans.append(f[0])
		ans.sort()
		for i in ans:
			print(i, end='')
		print(' %d' % prev)
	except:
		break