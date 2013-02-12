# Simple replacement.
import sys

s = sys.stdin.readline().strip().split('WUB')

ans = ''

for t in s:
   if t != '':
       if ans != '':
           ans += ' '
       ans += t

print(ans)