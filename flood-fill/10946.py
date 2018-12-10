# flood fill - AC
import sys

global A, V, row, column, letter

def save(x, y):
	return 0<=x<row and 0<=y<column and V[x][y]==-1 and A[x][y] == letter 

def flood_fill(x, y):
	V[x][y] = 1
	ans = 1
	for d in (0, 1), (1, 0), (0, -1), (-1, 0):
		dx, dy = x+d[0], y+d[1]
		if save(dx, dy):
			ans += flood_fill(dx, dy)
	return ans
p = 1
while True:
	try:
		row, column = [int(i) for i in sys.stdin.readline().split()]
		if row == column == 0: break
	except: break

	A = [['' for _ in range(column)] for i in range(row)]

	V = [[-1 for _ in range(column)] for i in range(row)]

	for i in range(row):
		A[i] = list(sys.stdin.readline()[:-1])
	
	solution = []
	for i in range(row):
		for j in range(column):
			if A[i][j] != '.' and V[i][j] == -1 :
				letter = A[i][j]
				solution.append((letter, flood_fill(i, j)))
	solution.sort(key=lambda a: (-a[1], a[0]))
	print('Problem %d:' % p)
	for s in solution:
		print(s[0], s[1])
	p += 1
