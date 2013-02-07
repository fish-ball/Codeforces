import math, sys

(n, R, r) = [int(x) for x in sys.stdin.readline().strip().split()]

if R>=r+r and math.asin(1.0*r/(R-r))*n < 3.1415927:
    print('YES')
elif n == 1 and r <= R:
    print('YES')
else:
    print('NO')
