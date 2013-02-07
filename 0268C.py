import math, sys

k = min([int(x) for x in sys.stdin.readline().strip().split()]) + 1

print(k)

for i in range(0, k):
    print('%d %d' % (i, i))
