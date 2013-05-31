import sys

n = int(input())

b = n.bit_length()

a = sorted([int(x) for x in input().split()], reverse=True)

ans = 0

for w in range(0, b, 2):
    ans += sum(a[0:(1<<w)])

print(ans)
