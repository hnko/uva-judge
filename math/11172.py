# AC - compare numbers
import sys
t = int(sys.stdin.readline())
for _ in range(t):
	a, b = [int(i) for i in sys.stdin.readline().split()]
	if a == b:
		print('=')
	elif a > b:
		print('>')
	else:
		print('<')