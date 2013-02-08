# We can reduce the formula that:
# r2 = sqrt( (B*x*x*y) / (B*y+A*z) )
# So, we take the maximum x, minimum z, and traverse all y to get the optimal.

from sys import stdin

x = [int(buf) for buf in stdin.readline().strip().split()][1:]
y = [int(buf) for buf in stdin.readline().strip().split()][1:]
z = [int(buf) for buf in stdin.readline().strip().split()][1:]
(A, B) = [int(buf) for buf in stdin.readline().strip().split()]

x = max(x)
z = min(z)

ans = 0
for c in y:
    ans = max(ans, 1.0*B*x*x*c/(B*c+A*z))

print(ans**0.5)
