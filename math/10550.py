# AC - multiply
import sys

degree = 9

while True:
	a, b, c, d = [int(i) for i in sys.stdin.readline().split()]
	
	if a == b == c == d == 0:
		sys.exit(0)
	
	first = (40-b+a) if a<b else a-b
	second = (40-b+c) if b>c  else c-b
	third = (40-d+c) if c<d else c-d
	
	ans = 1080 + 9*(first + second + third)
	
	print(ans)
	