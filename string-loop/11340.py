# TLE -> convert to c++
from collections import Counter

t = int(input())
for _ in range(t):
	vals = int(input())
	values = {}
	for v in range(vals):
		letter, val = [i for i in input().split()]
		values[letter] = int(val)
	lines = int(input())
	ans = 0
	for l in range(lines):
		for c, v in Counter(input()).most_common():
			if c in values:
				ans += (v*values[c])
	print("%d.%02d$" % (ans//100, ans%100) )