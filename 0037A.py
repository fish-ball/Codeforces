# Simply implemetation..
import sys

n = int(sys.stdin.readline().strip())
a = [int(x) for x in sys.stdin.readline().strip().split()]
a.sort()

w = 0
c = 0
h = 0
mxh = 0

for x in a:
   if x != w:
       w = x
       c += 1
       h = 1
   else:
       h += 1
   mxh = max(mxh, h)

sys.stdout.writelines(str(mxh)+' '+str(c))