# AC - for loop
import sys

t = int(sys.stdin.readline())

for _ in range(t):
	n = int(sys.stdin.readline())
	arr = [int(i) for i in sys.stdin.readline().split()]
	down = up = 0
	prev = arr[0]
	
	for i in arr[1:]:
		if i> prev: up += 1
		elif i < prev: down += 1
		prev = i

	print('Case %d: %d %d' %(_+1, up, down))