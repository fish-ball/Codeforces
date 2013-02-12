# Simply greedy strategy.
import sys

x = int(sys.stdin.readline())
a = [int(p) for p in sys.stdin.readline().split()]
a.sort(reverse=True)

n = 0
for i in range(0, 12):
   if x <= 0:
       break
   else:
       n += 1
       x -= a[i]
if x > 0:
   n = -1

print(n)