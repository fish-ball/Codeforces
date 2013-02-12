# Too simple...


import sys
result = 0
for line in sys.stdin:
   if 'H' in line or 'Q' in line or '9' in line:
       result = 1
if result == 1:
   print 'YES'
else:
   print 'NO'