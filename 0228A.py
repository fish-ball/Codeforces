# Easy, prints 4 - distinct numbers.
import sys

vals = sys.stdin.readline().split()
vals.sort()

pre = ''
ans = 0
for s in vals:
   if pre != s:
       pre = s
       ans += 1

print(4 - ans)