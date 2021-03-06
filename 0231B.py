﻿# We should find out that T-primes stand for square of primes.


import sys

(n, d, l) = [int(x) for x in sys.stdin.readline().strip().split()]

v = [[d, d]]

ans = []

for i in range (1, n):
   v.append([1-v[i-1][1], l-v[i-1][0]])

exist = True

if v[n-1][0] > l or v[n-1][1] < 1:
   exist = False
else:
   k = min(v[n-1][1], l)
   ans.append(k)
   for i in range (1, n):
       (a, b) = v[n-i-1]
       _k = min(l - k, b)
       ans.append(_k + k)
       k = _k

if exist:
   for i in range(0, n):
       if i > 0:
           sys.stdout.write(' ')
       sys.stdout.write(str(ans[n - i - 1]))
   print('')
else:
   print(-1)