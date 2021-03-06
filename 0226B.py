﻿# Make a full tree of at most k-children, layer by layer, order by weight.
# Make the height of the root 0, then each node is used by height-times.
# In this way, the total cost is the smallest.
# So, sort the array descending, for the height h from 1 to log(k, n), adding the weight of all the elements higher than h, then finally we get the result. 


import sys

n = int(sys.stdin.readline())
vals = sys.stdin.readline().split(' ')
nodes = []

for x in vals:
   nodes.append(int(x))

nodes.sort(reverse = True)

for i in range(1, len(nodes)):
   nodes[i] += nodes[i-1]

calc = []

for k in range(1, len(nodes)):
   step = k
   index = 0
   total = 0
   while index < len(nodes):
       total += nodes[-1] - nodes[index]
       index += step
       step *= k
   calc.append(total)

q = int(sys.stdin.readline())
vals = sys.stdin.readline().split(' ')

for x in vals:
   if n > 1:
       y = 0
       if int(x) >= len(calc):
           y = calc[-1]
       else:
           y = calc[int(x) - 1]
       print y,
   else:
       print 0,