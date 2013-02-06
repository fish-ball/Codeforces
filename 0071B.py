#   Suppose the progress bar has n*k points total, i.e. k points per-square,
# while p points of them are filled.
#   So it's not hard to find out the equation: p / (n * k) >= t / 100 then
# p = floor(t * n * k // 100). Then fill it block by block.

from sys import stdin, stdout

(n, k, t) = [int(x) for x in stdin.readline().strip().split()]

t = t * n * k // 100

a = []

for i in range(0, n):
    a.append(str(min(t, k)))
    t -= min(t, k)

print(' '.join(a))
