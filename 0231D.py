# For each axis, the value decided one face to see.
# For example:
#   if x < 0, face-5 is visible while face-6 is invisible;
#   else if x > x1, face-5 is invisible while face-6 is visible;
#   else, e.g. 0 <= x <= x1, neither face-5 nor face-6 is visible;


import sys

(x, y, z) = [int(str) for str in sys.stdin.readline().strip().split()]
(x1, y1, z1) = [int(str) for str in sys.stdin.readline().strip().split()]
a = [int(str) for str in sys.stdin.readline().strip().split()]

kx = 0
ky = 0
kz = 0
if x < 0:
   kx = 0
elif x > x1:
   kx = 2
else:
   kx = 1

if y < 0:
   ky = 0
elif y > y1:
   ky = 2
else:
   ky = 1

if z < 0:
   kz = 0
elif z > z1:
   kz = 2
else:
   kz = 1

valx = [a[4], 0, a[5]]
valy = [a[0], 0, a[1]]
valz = [a[2], 0, a[3]]

print(valx[kx]+valy[ky]+valz[kz])