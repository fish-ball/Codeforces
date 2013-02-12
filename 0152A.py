# Simple O(n^2) implementation.
import sys

(n, l) = [int(x) for x in sys.stdin.readline().strip().split()]
b = [False for i in range(0, n)]
a = []

for i in range(0, n):
   a.append(sys.stdin.readline().strip())

for j in range(0, l):
   mx = '0'
   for i in range(0, n):
       if mx < a[i][j]:
           mx = a[i][j]
   for i in range(0, n):
       if mx == a[i][j]:
           b[i] = True

cnt = 0
for i in range(0, n):
   if b[i]:
       cnt += 1

print(cnt)