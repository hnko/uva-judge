# AC - use bin and the sum the bin string
import sys

while True:
	 n = int(sys.stdin.readline())
	 if not n:
	 	sys.exit(0)
	 print('The parity of %s is %d (mod 2).' % (bin(n)[2:], sum([int(i) for i in bin(n)[2:]])) )