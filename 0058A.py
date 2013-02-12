# Using greedy match.
import sys

s = sys.stdin.readline().strip()

b = True
for c in list('hello'):
   p = s.find(c)
   if p == -1:
       b = False
       break
   else:
       s = s[p+1:]
       
if b:
   print('YES')
else:
   print('NO')