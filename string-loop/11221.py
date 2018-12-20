# AC - replace symbols and check if is palindromic
t = int(input())

def solve(arr):
	cleaned_arr = arr.replace(' ', '').replace('!', '').replace('?','').replace('(', '').replace(')', '').replace('.', '').replace(',', '')
	if len(cleaned_arr)**0.5 - int(len(cleaned_arr)**0.5) > 0:
		return False, 0
	return cleaned_arr == cleaned_arr[::-1], int(len(cleaned_arr)**0.5)


for _ in range(t):
	line = input()
	ans = solve(line)
	if ans[0]:
		print('Case #%d:\n%d' % (_+1, ans[1]) )
	else:
		print('Case #%d:\nNo magic :(' % (_+1) )
