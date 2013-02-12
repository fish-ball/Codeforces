# Construct the answer, pairing the i-th and the (i+n/2)-th student.
# What we should do is to decide whether to swap their position.
# Answer is, only when i-th is R while (i+n/2) is L.


import sys

fin = open('input.txt', 'r')
fout = open('output.txt', 'w')

n = int(fin.readline().strip())
s = fin.readline().strip()

for i in range(0, n//2):
   if s[i] == 'R' and s[i+n//2] == 'L':
       fout.write(str(i+n//2+1)+' '+str(i+1)+'\n')
   else:
       fout.write(str(i+1)+' '+str(i+n//2+1)+'\n')