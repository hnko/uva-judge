# AC - get the freq of the countries and sort them

t = int(input())
d = {}
for _ in range(t):
	line = input().split()
	if not line[0] in d:
		d[line[0]] = 1
	else:
		d[line[0]] += 1

for country, value in sorted(d.items(), key=lambda x: x[0]):
	print(country, value)