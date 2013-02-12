# Too simple..
import sys

s = sys.stdin.readline().strip()

cnt = 0

for c in s:
   if c.isupper():
       cnt += 1
   else:
       cnt -= 1

print(s.upper() if cnt > 0 else s.lower())