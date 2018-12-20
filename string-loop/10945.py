# AC - palindrome take care of spaces and symbols.

import re

def palindrome(arr):
	clean_arr = ''.join(re.findall(r'[A-Za-z]+', arr.lower()))
	return clean_arr == clean_arr[::-1]

while True:
	line = input()
	if line == 'DONE':
		break

	if palindrome(line):
		print("You won't be eaten!")
	else:
		print('Uh oh..')
