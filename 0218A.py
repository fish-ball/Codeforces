from sys import stdin

(n, k) = [int(buf) for buf in stdin.readline().strip().split()]
r = [int(buf) for buf in stdin.readline().strip().split()]

for i in range(1, n+n, 2):
    if k > 0 and r[i-1] < r[i]-1 > r[i+1]:
        r[i] -= 1
        k -= 1
print(' '.join([str(x) for x in r]))
