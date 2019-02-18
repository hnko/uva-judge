# AC - count freq and sort

from collections import Counter

first = False
while True:
	try:
		
		c = Counter(input()).most_common()

		if first: print()

		for elem, freq in sorted(c, key=lambda x: (x[1], -ord(x[0]))):
			print(ord(elem), freq)
		
		first = True
		
	except:
		break