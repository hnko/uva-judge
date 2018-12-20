# AC - set and check palindromes
def palindrome(arr):
	return arr == arr[::-1]

while True:
	try:
		line = input()
		
		checked = set()

		#all subsets
		ans = 0
		for i in range(len(line)):
			for j in range(i, len(line)):
				if line[i:j+1] not in checked and palindrome(line[i:j+1]):
					ans += 1
					checked.add(line[i:j+1])

		print("The string '%s' contains %d palindromes." % (line, ans) )
	except:
		break
