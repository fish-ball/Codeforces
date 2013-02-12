# For a calculate b and validate.
import sys

(n, m) = [int(x) for x in sys.stdin.readline().strip().split()]

cnt = 0

a = 0
while a * a <= n:
   b = n - a * a
   if a + b * b == m:
       cnt += 1
   a += 1

print(cnt)