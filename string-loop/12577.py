# AC - compare string
t = 1

while True:
	line = input()

	if line =='Hajj':
		print('Case %d: Hajj-e-Akbar' % t)
	elif line == 'Umrah':
		print('Case %d: Hajj-e-Asghar' % t)
	else:
		break
	t += 1