# AC - sum
import sys

t = int(sys.stdin.readline())
account = 0

for _ in range(t):
	line = [i for i in sys.stdin.readline().split()]

	if len(line) > 1:
		account += int(line[1])
	else:
		print(account)