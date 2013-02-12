# Only the first position of the maximum and the last position of the minimum affects the result.


import sys

n = int(sys.stdin.readline())
vals = sys.stdin.readline().split(' ')

mx = 1
mn = 100
mxp = 0
mnp = 0
pos = 0

for x in vals:
   if mx < int(x):
       mx = int(x)
       mxp = pos
   if mn >= int(x):
       mn = int(x)
       mnp = pos
    pos += 1

result = mxp + n - 1 - mnp
if mxp > mnp:
   result -= 1
   
print result