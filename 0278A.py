import sys

n = int(sys.stdin.readline().strip());

d = [int(x) for x in sys.stdin.readline().strip().split()]

(s, t) = [int(x) for x in sys.stdin.readline().strip().split()]

if s > t:
    (s, t) = (t, s)

tot = sum(d)

dis = sum(d[s-1:t-1])

print(min(dis, tot-dis))
