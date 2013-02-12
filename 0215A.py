# Brute force
import sys

n = int(sys.stdin.readline().strip())
a = [int(x) for x in sys.stdin.readline().strip().split()]
m = int(sys.stdin.readline().strip())
b = [int(x) for x in sys.stdin.readline().strip().split()]

rat = 0
cnt = 0

for x in a:
   for y in b:
       if y % x == 0:
           if y / x == rat:
               cnt += 1
           elif y / x > rat:
               rat = y / x
               cnt = 1

print(cnt)