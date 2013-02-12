# Process as a string.


import sys

(i, f) = (sys.stdin.readline().strip().split('.'))

if i[-1] == '9':
   print('GOTO Vasilisa.')
elif f[0] < '5':
   print(i)
else:
   print(int(i)+1)