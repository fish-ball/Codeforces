#   The point is each permutation group should be of length-2, so, construct 
# a sequence which swaps all the i-th and i+1-th element(i mod 2 = 0, 0-based)
# when the sequence has even length. Otherwise output -1.


import sys

n = int(sys.stdin.readline())

if n % 2 == 1:
   print(-1)

else:
   for i in range(0, n//2):
       if i > 0:
           sys.stdout.write(' ')
       sys.stdout.write(str(2*i+2)+' '+str(2*i+1))
   print('')