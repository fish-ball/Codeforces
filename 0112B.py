# it can be done only if the selected square doesn't intersect with the center point.

from sys import stdin, stdout

(n2, x, y) = [int(x) for x in stdin.readline().strip().split()]

print('YES' if x != n2//2 and x != n2//2+1 or y != n2//2 and y != n2//2+1 else 'NO' )
