# python code seems not effecient enough to get pass... try the c++ edition.

from sys import stdin

(xa, ya, xb, yb) = [int(buf) for buf in stdin.readline().strip().split()]

(xa, xb) = sorted((xa, xb))
(ya, yb) = sorted((ya, yb))

a = []
a += [(xa, y) for y in range(ya, yb+1)]
a += [(xb, y) for y in range(ya, yb+1)]
a += [(x, ya) for x in range(xa+1, xb)]
a += [(x, yb) for x in range(xa+1, xb)]

n = int(stdin.readline().strip())

for k in range(n):
    (x, y, r) = [int(buf) for buf in stdin.readline().strip().split()]
    j = 0
    for i in range(0, len(a)):
        if (a[i][0]-x)**2 + (a[i][1]-y)**2 > r*r:
            a[j] = a[i]
            j += 1
    a[j:] = []

print(len(a))
