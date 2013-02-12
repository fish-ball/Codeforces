# Sort the points, and using brute-force to find the points.
import sys

n = int(sys.stdin.readline())

a = []

for i in range(0, n):
   a.append([int(p) for p in sys.stdin.readline().split()])

a.sort()

cnt = 0

for i in range(1, n-1):
   if a[i-1][0] != a[i][0] or a[i+1][0] != a[i][0]:
       continue
   b1 = b2 = False
   for j in range(0, i):
       if a[i][1] == a[j][1]:
           b1 = True
   for j in range(i+1, n):
       if a[i][1] == a[j][1]:
           b2 = True
   if b1 and b2:
       cnt += 1

print(cnt)