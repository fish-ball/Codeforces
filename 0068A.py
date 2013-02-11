from sys import stdin

[p1,p2,p3,p4,a,b] = [int(x) for x in stdin.readline().strip().split()]

print(max(min([p1,p2,p3,p4,b+1])-a, 0))
