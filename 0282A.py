import sys

n = int(sys.stdin.readline())

ans = 0

for i in range(0, n):
    ans += 1 if sys.stdin.readline()[1] == '+' else -1

print(ans)
