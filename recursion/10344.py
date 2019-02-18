solution = ['Impossible', 'Possible']

def solve(res, i, line):
	#print(res)
	if i == len(line):
		if res == 23:
			return True
		else:
			return False
	return solve(res+line[i], i+1, line) or solve(res-line[i], i+1, line) or solve(res*line[i], i+1, line)
			
	return ans

while True:
	line = [int(i) for i in input().split()]
	if sum(line) == 0:
		break

	print(solution[solve(0, 0, line)])