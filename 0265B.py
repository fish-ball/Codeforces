from sys import stdin, stdout

n = int(stdin.readline().strip())

y = 0
ans = n+n-1

for i in range(0, n):
    x = int(stdin.readline().strip())
    ans += abs(x-y)
    y = x

print(ans)

