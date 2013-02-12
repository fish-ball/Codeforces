# Just using greedy strategy, find left longest and right longest count of any pos.


import sys

n = int(sys.stdin.readline().strip())
v = [int(x) for x in sys.stdin.readline().strip().split()]

l = [0 for i in range(0, n)]
r = [0 for i in range(0, n)]

for i in range(1, n):
   if v[i] >= v[i-1]:
       l[i] = l[i-1] + 1
   if v[n-1-i] >= v[n-i]:
       r[n-1-i] = r[n-i] + 1

ans = 0
for i in range(0, n):
   ans = max(ans, 1+l[i]+r[i])

print(ans)