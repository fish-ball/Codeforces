# Simple counting when the maximum or minimum extends.
import sys

n = int(sys.stdin.readline())
a = [int(x) for x in sys.stdin.readline().split()]

mx = mn = a[0]
cnt = 0
for i in range(1, n):
   if a[i] > mx:
       cnt += 1
       mx = a[i]
   if a[i] < mn:
       cnt += 1
       mn = a[i]

print(cnt)