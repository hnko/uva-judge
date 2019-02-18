# AC - use regex

import re

pattern = re.compile(r'^[-+]?\d+(\.\d+([eE][-+]?\d+)?|[eE][-+]?\d+)$')
ans = ['is illegal', 'is legal']

while True:
	line =  re.findall(r'\S+', input())[0]
	if line == '*':
		break
	
	print('%s %s.' % (line, ans[bool(pattern.match(line))]) )
	

	