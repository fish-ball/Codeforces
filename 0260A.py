from sys import stdin

(a, b, n) = [int(buf) for buf in stdin.readline().strip().split()]

ans = str(a)

for i in range(n):
    d = (b - a * 10 % b) % b
    if d > 9:
        ans = '-1'
        break
    else:
        ans += str(d)
        a = 0

print(ans)
