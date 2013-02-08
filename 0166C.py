# Note that the number we add is always x.

from sys import stdin

(n, x) = [int(y) for y in stdin.readline().strip().split()]

(l, e, g) = (0, 0, 0)

for v in [int(y) for y in stdin.readline().strip().split()]:
    if v == x: e += 1
    elif v < x: l += 1
    elif v > x: g += 1

if l + e >= g and g + e > l:
    print(0)
elif l + e < g:
    print(g-l-e)
else:
    print(l-e-g+1)
