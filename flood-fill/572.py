# flood fill - AC

import sys

def flood_fill(x, y):
	def save(x, y):
		return 0<=x<row and 0<=y<column and A[x][y] == '@'
	A[x][y] = '*'
	for d in (0, 1), (0, -1), (1, 0), (-1, 0), (1, 1), (-1, -1), (1, -1), (-1, 1):
		dx, dy = x+d[0], y+d[1]
		if save(dx, dy):
			flood_fill(dx, dy)

while True:
	try:
		global row, column, A
		row, column = [int(i) for i in sys.stdin.readline().split()]
		if row == 0 and column == 0: break
	except: break
	A = [[' ' for _ in range(column)] for i in range(row)]

	for i in range(row):
		A[i] = list(sys.stdin.readline())

	ans = 0
	for i in range(row):
		for j in range(column):
			if A[i][j] == '@':
				ans += 1
				flood_fill(i, j)
	print(ans)

