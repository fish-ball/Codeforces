# Simple xor for binary strings.
import sys

a = sys.stdin.readline()
b = sys.stdin.readline()
c = ''

for i in range(0, len(a)):
   if a[i] == '\n':
       break
   elif a[i] == b[i]:
       c += '0'
   else:
       c += '1'

print(c)