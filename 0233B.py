#   Note that s(x) is always less than 90.
#   So the root of [x^2+s(x)*x-n=0] is greater
# than the root of [x^2+90*x-n=0] not more than 90.
#   So, let the root of [x^2+90*x-n=0] r as a lower-bound,
# (we can use binary search), then brute force 90 times to
# find the exact root.

from sys import stdin

n = int(stdin.readline().strip())

l = 0
r = n

while l + 1 < r:
    m = l + r >> 1
    if m * (m + 90) >= n:
        r = m
    else:
        l = m

ans = -1

for x in range(r, r + 90):
    if x * (x + sum([int(c) for c in str(x)])) == n:
        ans = x
        break

print(ans)
