from sys import stdin

(n, m) = [int(x) for x in stdin.readline().strip().split()]

a = [-int(x) if int(x) < 0 else 0 for x in stdin.readline().strip().split()]

print(sum(sorted(a, reverse=True)[0:m]))
