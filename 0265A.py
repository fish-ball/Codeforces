from sys import stdin, stdout

s = stdin.readline().strip()
t = stdin.readline().strip()

p = 0
for c in t:
    if s[p] == c:
        p += 1

print(p + 1)
