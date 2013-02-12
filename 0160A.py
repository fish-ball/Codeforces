# Sort the array and use greedy strategy, take the biggest elements.


import sys

n = int(sys.stdin.readline())
vals = sys.stdin.readline().split(' ')

total = 0
arr = []
for x in vals:
   arr.append(int(x))
   total += int(x)

arr.sort()

sum = 0
for x in arr:
   if sum + sum + x + x < total:
       n -= 1
       sum += x
   else:
       break

print n