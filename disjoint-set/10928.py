# AC - take min value
t = int(input())
 
while t:
	t -= 1
	nodes = int(input())
	arr = [0] * (nodes+1)
	for neighbor in range(nodes):
		arr[neighbor+1] = len(input().split())
		
	
	min_ = min(arr[1:])
	ans = [str(i) for i in range(len(arr)) if arr[i] == min_]
	
	print(' '.join(ans))
	
	if t: input()
