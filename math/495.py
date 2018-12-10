# AC - UVA - BigInteger
fib = [0, 1]
for i in range(2, 5002):
	fib.append(fib[i-1]+fib[i-2])

while(True):
	try:
		number = int(input())
		print('The Fibonacci number for', number, 'is',  fib[number])
	except EOFError:
		break	