# Simply counting the rows have at least 2 one(s).


import sys

n = int(sys.stdin.readline().strip())

cnt= 0

for i in range(0, n):
   (x, y, z) = [int(x) for x in sys.stdin.readline().strip().split()]
   if x + y + z >= 2:
       cnt += 1

print(cnt)