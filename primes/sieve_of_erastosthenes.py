
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

print(sieve(2001))