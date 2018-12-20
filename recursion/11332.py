# AC - recursion

def solve(arr):
	if len(arr) == 1:
		return arr
	return solve(str(sum([int(i) for i in arr])))


while True:
	line = input()
	if line == '0':
		break
	print(solve(line))