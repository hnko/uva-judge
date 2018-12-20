# AC - multiply and divide
import sys

t = int(sys.stdin.readline())

for _ in range(t):
	a, b = [int(i) for i in sys.stdin.readline().split()]

	ans = int(a//3) * int(b//3)
	print(ans)