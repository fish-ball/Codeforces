# Read carefully, simple..
import sys

n = int(sys.stdin.readline().strip())

s = sys.stdin.readline().strip()

cnt = 0
yes = True

for i in range(0, n):
   val = int(s[i])
   if val != 4 and val != 7:
       yes = False
       break
   if i < n//2:
       cnt += val
   else:
       cnt -= val
       
print('YES' if yes and cnt == 0 else 'NO')