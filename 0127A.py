# Simple distance calculating.
import sys

(n, k) = [int(x) for x in sys.stdin.readline().strip().split()]

t = 0
x0 = y0 = 0

for i in range(0, n):
   (x, y) = [int(x) for x in sys.stdin.readline().strip().split()]
   if i > 0:
       t += ((x-x0)*(x-x0)+(y-y0)*(y-y0))**0.5
   (x0, y0) = (x, y)

print(t * k / 50)