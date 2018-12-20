# AC - find min and max in an array

import sys
t = int(sys.stdin.readline())
for _ in range(t):
	sys.stdin.readline()
	arr = [int(i) for i in sys.stdin.readline().split()]
	print(2*(max(arr)-min(arr)))