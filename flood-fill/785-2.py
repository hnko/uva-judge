from sys import stdin
import sys
global character

def fill(x, y):
	V[x][y] = 1
	grid[x][y] = character
	for d in (0, 1), (0, -1), (1, 0), (-1, 0):
		dx, dy = x+d[0], y+d[1]
		if grid[dx][dy] == ' ' and V[x][y] == 0:
			fill(dx, dy)

def find_delim(x, y):
	if 0<=x<len(grid) and 0<=y<len(grid[x]) and grid[x][y] != ' ':
		print('es: ', grid[x][y])	
		return grid[x][y]
	
	find_delim(x+1, y)
	find_delim(x, y+1)

while True:
	try:
		grid =  []
		while True:
			line = list(input())
			grid.append(line)
			if(len(line)>0 and line[0]=='_'):break
	except EOFError: break
	V = [[0 for _ in range(100)] for i in range(40)]
	flag = False
	delim = find_delim(0, 0)
	print('delim')
	for i in range(len(grid)):
		for j in range(len(grid[i])):
			if grid[i][j] != ' ' and grid[i][j] != delim and V[i][j] == 0: 
				character = grid[i][j]
				
				fill(i, j)
				
				
	for row in grid:
		print(''.join(row))



