# AC - for loop
import sys
t = int(sys.stdin.readline())

for _ in range(t):
	a = int(sys.stdin.readline())
	b = int(sys.stdin.readline())
	ans = 0
	for i in range(a, b+1):
		if i&1:
			ans += i
	print('Case %d: %d' %(_+1, ans))