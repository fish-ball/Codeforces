import sys

(n, k) = [int(x) for x in sys.stdin.readline().strip().split()]

a = list(range(k+1))[::-1] + list(range(k+1, n))

print(' '.join([str(x+1) for x in a]))
