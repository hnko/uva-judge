coins = [1, 5, 10, 25, 50]

def make_change(coins):
    results = [0 for _ in range(7490)]
    results[0] = 1
    for coin in coins:
        for i in range(coin, 7490):
            results[i] += results[i - coin]
    return results

out = make_change(coins)
while True:
	try:
		n = int(input())
		print(out[n])
	except EOFError:
		break

