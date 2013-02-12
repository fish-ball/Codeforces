# Because the input is no greater than 1000, so all lucky number is easy to write out.
import sys

x = int(sys.stdin.readline())
a = [4,7,44,47,74,77,444,447,474,477,744,747,774,777]

b = False

for p in a:
   if x % p == 0:
       b = True

if b:    
   print('YES')
else:
   print('NO')