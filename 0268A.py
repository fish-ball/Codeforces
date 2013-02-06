from sys import stdin, stdout

n = int(stdin.readline().strip())

a = [stdin.readline().strip().split() for i in range(0, n)]

ans = 0

for i in range(0, n):
    for j in range(0, n):
        ans += 1 if a[i][0] == a[j][1] else 0

print(ans)
