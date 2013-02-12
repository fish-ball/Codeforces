# Using a dictionary to store the count of each key, multiplying each opps.
import sys

n = int(sys.stdin.readline().strip())

a = [int(x) for x in sys.stdin.readline().strip().split()]

mp = {0: 0}

for x in a:
   if not(x in mp):
       mp[x] = 1
   else:
       mp[x] += 1

cnt = mp[0] * (mp[0] - 1) // 2

for i in mp:
   if i > 0 and -i in mp:
       cnt += mp[-i] * mp[i]

print(cnt)