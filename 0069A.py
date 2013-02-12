# Too simple, just summing and check.
import sys

n = int(sys.stdin.readline())
(x, y, z) = (0, 0, 0)

for i in range(0, n):
   (a, b, c) = sys.stdin.readline().split()
   (x, y, z) = (x+int(a), y+int(b), z+int(c))

if x==0 and y==0 and z==0:
   print('YES')
else:
   print('NO')