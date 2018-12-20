# AC - count inversions
import sys

t = int(sys.stdin.readline())

for _ in range(t):
	n = int(sys.stdin.readline())
	arr = [int(i) for i in sys.stdin.readline().split()]

	cnt = 0
	for i in range(n):
		for j in range(i+1, n):
			if arr[i] > arr[j]: cnt += 1
	print('Optimal train swapping takes %d swaps.' % cnt)