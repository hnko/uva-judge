# DP - coin change - AC

coins = [5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000]
solution = [0 for i in range(300001)]
solution[0] = 1
for coin in coins:
	for i in range(coin, 300001):
		solution[i] += solution[i-coin]

while(True):
	n = float(input().strip())
	if n == 0: break
	error = int((n+0.001)*100) # avoid error
	print('%6.2lf%17d' % (n, solution[error]))


