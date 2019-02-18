# AC - iterate through an array

code = [2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9]

while True:
	try:
		line = input()
		for char in line:
			if char.isalpha():
				print(code[ord(char)-ord('A')], end='')
			else:
				print(char, end='')
		print()
	except:
		break