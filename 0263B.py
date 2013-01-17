from sys import stdin, stdout
(n, k) = [int(x) for x in stdin.readline().split()]
a = sorted([int(x) for x in stdin.readline().split()], reverse=True)
if k > n or k != n and a[k] == a[k-1]:
    print(-1)
else:
    print('%d 0' % a[k-1])
