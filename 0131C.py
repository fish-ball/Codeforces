from sys import stdin

(n, m, t) = [int(x) for x in stdin.readline().strip().split()]

ans = 0

for b in range(4, t):
    g = t - b
    nom = 1
    den = 1
    for i in range(0, b):
        nom *= n - i
        den *= i + 1
    for i in range(0, g):
        nom *= m - i
        den *= i + 1
    ans += nom // den

print(ans)
