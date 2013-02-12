# Reverse and compare, too simple..
import sys

a = sys.stdin.readline().strip()
b = sys.stdin.readline().strip()

if a == b[::-1]:
   print('YES')
else:
   print('NO')