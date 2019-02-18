# AC longest common subsequence in this case with words not letters

import re
dp = [[None for i in range(1001)] for j in range(1001)]

def lcs(words1, words2):
	for i in range(len(words1)+1):
		for j in range(len(words2)+1):
			if i == 0 or j == 0:
				dp[i][j] = 0
			elif words1[i-1] == words2[j-1]:
				dp[i][j] = dp[i-1][j-1] + 1
			else:
				dp[i][j] = max(dp[i-1][j], dp[i][j-1])
	return dp[len(words1)][len(words2)]

t = 0
while True:
	try:
		t += 1

		words1 = re.findall(r'\w+', input())
		words2 = re.findall(r'\w+', input())
		
		if not words1 or not words2:
			print('%2d. Blank!' % t)
		else:
			print('%2d. Length of longest match: %d' % (t, lcs(words1, words2)) )
		
	except:
		break