# bfs - AC
from math import ceil
import sys

dp = [[0 for column in range(106)] for row in range(106)]
t = 1
while True:	
	try:
		nodes, edges = [int(i) for i in sys.stdin.readline().split()]
	except:
		break
	
	if nodes == 0 and edges == 0: break
		
	for i in range(1, nodes+1):
		for j in range(1, nodes+1):
			dp[i][j] = -1e6
		dp[i][i] = 0

	for _ in range(edges):
		src, dest, weight = [int(i) for i in sys.stdin.readline().split()]
		dp[src][dest] = dp[dest][src] = weight

	src, dest, weight = [int(i) for i in sys.stdin.readline().split()]

	for k in range(1, nodes+1):
		for i in range(1, nodes+1):
			for j in range(1, nodes+1):
				dp[i][j] = dp[j][i] = max(dp[i][j], min(dp[i][k], dp[k][j]))

	result = ceil(weight/(dp[src][dest]-1))
	print('Scenario #%d' % t)
	print('Minimum Number of Trips = %d\n' % result)
	t += 1
