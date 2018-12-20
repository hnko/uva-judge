# AC - recursion

def is_palindrome(arr):
	i, j = 0, len(arr)-1
	while i<j:
		if arr[i] != arr[j]:
			return False
		i += 1
		j -= 1
	return True

def solve(cnt, line):
	if is_palindrome(line) and cnt:
		return cnt, line
	return solve(cnt+1, str(int(line) + int(line[::-1])) )

t = int(input())
for _ in range(t):
	line = input()
	cnt, ans = solve(0, line)
	print('%d %s' %(cnt, ans))