from sys import stdin

(n, a, b, c) = [int(x) for x in stdin.readline().strip().split()]

dp = [0] + [-1] * n

for i in range(0, n):
    if dp[i] > -1:
        for d in (a, b, c):
            if i + d <= n:
                dp[i+d] = max(dp[i+d], dp[i]+1)

print(dp[-1])
