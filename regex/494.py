# AC use regex

import re

while True:
	try:
		print(len(re.findall(r'[A-Za-z]+', input())))
	except: 
		break