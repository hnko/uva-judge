t = int(input())
for i in range(t):
	a, b = [int(i) for i in input().split(' ')]
	if a < b: print('<')
	elif a > b: print('>')
	else: print('=')
		