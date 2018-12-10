global D
def ok(i, j):
	dist = (x[i]-x[j])**2 + (y[i]-y[j])**2
	return (((a[i]-a[j])**2 + ()**2)**0.5)<= D
while True:
	try:
		v, m = [int(i) for i in sys.stdin.readline().split()]
		if v==0 and m==0: break
	except:
		break
	
	D = v*m*60
	n = 0
	while True:
		try:
			v, m = [int(i) for i in sys.stdin.readline().split()]
			n += 1
		except:
			break
	for i in range(n):
		a[i][i] = True
		d[i] = 1e6
		for j in range(i, n):
			a[i][j] = a[j][i] = ok(i, j)

