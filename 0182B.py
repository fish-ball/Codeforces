from sys import stdin

d = int(stdin.readline().strip())
n = int(stdin.readline().strip())
a = [int(x) for x in stdin.readline().strip().split()]

print(sum([d-c for c in a[0:-1]]))
