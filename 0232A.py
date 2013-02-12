#   The point is: not to construct the graph by some combine of complete sub-graphs.
# But only to adding edges in order, and accumulating the increasing cycles.
#   Calculate increasing edges effected by an added edge requires O(n)-times, then 
# there are O(n^2) edges to be add-in, so O(n^3) in total. 


import sys

n = int(sys.stdin.readline())
m = 0

arr = [['0' for i in range(0, 100)] for j in range(0, 100)]

for i in range(1, 100):
   m = i + 1
   for j in range(0, i):
       cnt = 0
       for k in range(0, m):
           if arr[i][k] == '1' and arr[j][k] == '1':
               cnt += 1
       if cnt <= n:
           n -= cnt
           arr[i][j] = arr[j][i] = '1'
       if n == 0:
           break
   if n == 0:
       break

print(m)

for i in range(0, m):
   print(''.join(arr[i][0:m]))