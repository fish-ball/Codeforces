# Sorting strings and compare.
import sys

a = sys.stdin.readline().strip()
b = sys.stdin.readline().strip()
c = sys.stdin.readline().strip()

# Sorting the string characters.
d = ''.join((lambda x:(x.sort(),x)[1])(list(a+b)))
c = ''.join((lambda x:(x.sort(),x)[1])(list(c)))

if d == c:
   print('YES')
else:
   print('NO')