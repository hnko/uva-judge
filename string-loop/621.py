# AC - compare things
import sys

t = int(sys.stdin.readline())
for _ in range(t):
	line = input()
	if line[-2:] =='35':
		print('-')
	elif line == '1' or line == '4' or line == '78':
		print('+')
	elif line[0] == '9' and line[-1] == '4':
		print('*')
	else:
		print('?')