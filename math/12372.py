# AC - compare

import sys

t = int(sys.stdin.readline())
for _ in range(t):
	a, b, c = [int(i) for i in sys.stdin.readline().split()]

	if a > 20 or b > 20 or c > 20:
		print('Case %d: bad' % (_+1))
	else:
		print('Case %d: good' % (_+1))