# Because the number is too small, listing them all.
import sys

dic = {2:3,3:5,5:7,7:11,11:13,13:17,17:19,19:23,23:29,29:31,31:37,37:41,41:43,43:47}

(n, m) = [int(x) for x in sys.stdin.readline().split()]

if n in dic and dic[n] == m:
   print('YES')
else:
   print('NO')