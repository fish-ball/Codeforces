#Simple basic implementation.


import sys

n = int(sys.stdin.readline())

def disp(i):
   for j in range(0, n - i):
       sys.stdout.write('  ')
   for j in range(0, i):
       sys.stdout.write(str(j) + ' ')
   sys.stdout.write(str(i))
   for j in range(0, i):
       sys.stdout.write(' ' + str(i-j-1))
   sys.stdout.write('\n')

for i in range(0, n):
   disp(i)

disp(n)

for i in range(0, n):
   disp(n-1-i)