#   Pre-process the row sum and col sums, for each row sum s, count how many col sums
# there are greater than s. Summing them to output.


import sys

n = int(sys.stdin.readline().strip())

row = [0 for i in range(0, n)]
col = [0 for i in range(0, n)]

for i in range(0, n):
   vals = [int(x) for x in sys.stdin.readline().strip().split()]
   for j in range(0, n):
       row[i] += vals[j]
       col[j] += vals[j]

row.sort()
col.sort()

i = 0
j = 0

ans = 0

while i < n:
   while j < n and col[j] <= row[i]:
       j += 1
   ans += n - j
   i += 1

print(ans)