# Simply count the even bags and odd bags.
import sys

n = int(sys.stdin.readline().strip())

a = [int(x) for x in sys.stdin.readline().strip().split()]

m = 0

for x in a:
   if x % 2 == 1:
       m += 1

if m % 2 == 1:
   print(m)
else:
   print(n - m)