# AC - compare strings
import sys
t = 1
while True:

	line = input()
	
	if line == '#':
		sys.exit(0)
	elif line == 'HELLO':
		print('Case %d: ENGLISH' % t)
	elif line == 'HOLA':
		print('Case %d: SPANISH'% t)
	elif line == 'HALLO':
		print('Case %d: GERMAN'% t)
	elif line == 'BONJOUR':
		print('Case %d: FRENCH'% t)
	elif line == 'CIAO':
		print('Case %d: ITALIAN'% t)
	elif line == 'ZDRAVSTVUJTE':
		print('Case %d: RUSSIAN'% t)
	else:
		print('Case %d: UNKNOWN'% t)
	t += 1