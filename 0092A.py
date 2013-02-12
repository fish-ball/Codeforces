# Brute force execution.
import sys

(k, n) = [int(x) for x in sys.stdin.readline().strip().split()]

i = 1
while n >= i:
   n -= i
   i = i % k + 1

print(n)