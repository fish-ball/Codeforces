import sys

s = input()

n = int(input())

acc = [0 for x in s]

for i in range(1, len(s)):
    acc[i] = acc[i-1] + (1 if s[i]==s[i-1] else 0)

for i in range(n):
    (l, r) = [int(x) for x in input().split()]
    print(acc[r-1] - acc[l-1])
