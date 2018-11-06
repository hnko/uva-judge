# DP - coin change - AC
coins = [1, 5, 10, 25, 50]
solution = [0 for i in range(30001)]
solution[0] = 1
for coin in coins:
	for i in range(coin, 30001):
		solution[i] += solution[i - coin]
while True:
	try:
		n = int(input())
		result = solution[n]
		if result == 1:
			print('There is only 1 way to produce {} cents change.'.format(n))
		else:
			print('There are {} ways to produce {} cents change.'.format(result, n))
	except EOFError:
		break