# Essentially a logarithm calculation.
import sys
import math

n = int(sys.stdin.readline().strip())
m = int(sys.stdin.readline().strip())

k = int(round(math.log(m, n)))

if n ** k == m:
   print('YES')
   print(int(k) - 1)
else:
   print('NO')