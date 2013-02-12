# Just count the pairs, return the half of the count.
import sys

n = int(sys.stdin.readline().strip())

a = [int(x) for x in sys.stdin.readline().strip().split()]
a.sort()

i = 1
cnt = 0
while i < n:
   if a[i] == a[i-1]:
       cnt += 1
       i += 1
   i += 1

print(cnt // 2)