def solve(coins, amount):
	import math
	dp = [math.inf] * (amount+1)
	dp[0] = 0
	used = [-1] * (amount+1)

	for coin in coins:
	    for i in range(coin, amount+1):
	        dp[i] = min(dp[i], dp[i-coin]+1)
	        if dp[i - coin] + 1 == dp[i]:
	        	used[i] = coin
	total = amount
	ans = []
	
	while total > 0:
		s = used[total]
		ans.append(s)
		
		total -= s



	return (dp[amount], ans) if dp[amount] != math.inf else -1

print(solve([16, 17, 23, 24, 39, 40], 100))
