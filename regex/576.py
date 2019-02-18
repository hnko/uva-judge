# AC - (?i) for case insensitive - [aeiouy]+ get all syllables - so just get the len od the regex
import re

while True:
	line = input()
	if line == 'e/o/i':
		break
	
	line = line.split('/')

	r1 = re.findall(r'(?i)([aeiouy]+)', line[0])
	r2 = re.findall(r'(?i)([aeiouy]+)', line[1])
	r3 = re.findall(r'(?i)([aeiouy]+)', line[2])
	
	if len(r1) != 5:
		print('1')
	elif len(r2) != 7:
		print('2')
	elif len(r3) != 5:
		print('3')
	else:
		print('Y')