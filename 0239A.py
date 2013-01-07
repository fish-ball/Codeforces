import sys

(y, k, n) = [int(buf) for buf in sys.stdin.readline().split()]

ans = []

for xy in range(k, n+1, k):
    if xy > y:
        ans.append(xy - y);

if len(ans) == 0:
    print(-1)
else:
    print(' '.join([str(buf) for buf in ans]))
