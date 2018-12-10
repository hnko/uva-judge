from sys import stdin

def bfs(contorno,i,j):
	no_explorados = [(i,j)]
	for ele in no_explorados:
		row = ele[0]
		col = ele[1]
		if grid[row+1][col] == " ":
			grid[row+1][col] = grid[i][j]
			no_explorados.append((row+1, col))
		if grid[row-1][col] == " ":
			grid[row-1][col] = grid[i][j]
			no_explorados.append((row-1, col))
		if grid[row][col+1] == " ":
			grid[row][col+1] = grid[i][j]
			no_explorados.append((row, col+1))
		if grid[row][col-1] == " ":
			grid[row][col-1] = grid[i][j]
			no_explorados.append((row, col-1))
		no_explorados.pop(no_explorados.index(ele))


def resolver():
	rows = len(grid)
	first = True
	contorno = "_"
	

	for i in range(rows):
		cols = len(grid[i])
		for j in range(cols):
			if first and grid[i][j]!=" ":
				contorno = grid[i][j]
				first = False
			if grid[i][j] != " " and grid [i][j] != contorno:
				bfs(contorno, i, j)
	
	for i in grid:
		print("".join(i))



while True:
	try:
		grid =  []
		while True:
			line = list(stdin.readline()[:-1])
			if(line[0]=='_'):
				break
			grid.append(line)
		resolver()
	except EOFError:
		break