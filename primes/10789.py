# AC - sieve for primes and Counter for letter freq

from collections import Counter

# sieve
def sieve(limit):	
	numbers = [True] * (limit+1)
	for i in range(2, int(limit**0.5 + 1) ):
		if numbers[i]:
			for j in range(i*i, (limit+1), i):
				numbers[j] = False
	
	primes = set()
	for i in range(2, (limit+1)):
		if numbers[i]:
			primes.add(i)

	return primes

primes = sieve(2002)

t = int(input())

for _ in range(t):
	line = Counter(input()).most_common()
	
	ans = []
	i = 0
	while i < len(line):
		if line[i][1] in primes:
			ans.append(line[i][0])
		i += 1

	ans.sort()
	if len(ans):
		print('Case %d: %s' % (_+1, ''.join(ans)) )
	else:
		print('Case %d: empty' % (_+1,) )
