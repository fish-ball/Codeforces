import sys

n = int(sys.stdin.readline().strip()) + 1

while len(set(str(n))) < 4: n += 1

print(n)
