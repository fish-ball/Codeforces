# Just greedy take minimum.
import sys

(n, k, l, c, d, p, nl, np) = [int(x) for x in sys.stdin.readline().split()]

print(min(k*l//nl, c*d, p//np)//n)