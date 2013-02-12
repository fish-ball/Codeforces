# Just sort the two part and comparing. Simple.


import sys

n = int(sys.stdin.readline().strip())
s = sys.stdin.readline().strip()

s1 = ''.join((lambda x: (x.sort(), x)[1])(list(s[0:n])))
s2 = ''.join((lambda x: (x.sort(), x)[1])(list(s[n:])))

k = 0
for i in range(0, n):
   if s1[i] > s2[i]:
       k += 1
   elif s1[i] < s2[i]:
       k -= 1

if max(k, -k) == n:
   print('YES')
else:
   print('NO')