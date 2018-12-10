# RTE but AC with udebug
import sys
global letter

def save(x, y):
	return 0<=x<len(G) and 0<=y<len(G[x]) and V[x][y] == 0 and G[x][y] == letter

def floodfill(x, y):

	V[x][y] = 1
	ans = 1
	for d in (0, 1), (0, -1), (1, 0), (-1, 0), (1, 1), (-1, -1), (1, -1), (-1, 1):
		dx, dy = x+d[0], y+d[1]
		if save(dx, dy):
			ans += floodfill(dx, dy)
	return ans

t = int(sys.stdin.readline())
for n in range(t):

	G = []
	if n==0: input()

	not_number = True
	while not_number:
		aux = sys.stdin.readline()[:-1]
		#print(aux)
		
		if aux[0] in '123456789':
			x, y = [int(i)-1 for i in aux.split()]
			not_number = False

		else:
		#	print(G)
			G.append(list(aux))

	while True:
		letter = G[x][y]
		V = [[0 for _ in range(len(G[i]))] for i in range(len(G))]

		print(floodfill(x, y))
		try:		
			x, y = [int(i)-1 for i in sys.stdin.readline().split()]
			
		except: 
			break
		
	if n!= t-1: print()


