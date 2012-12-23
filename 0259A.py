# Just check whether it has to consecutive same cell in a row.

from sys import stdin, stdout

yes = True

for i in range(0, 8):
    s = stdin.readline().strip()
    pre = ' '
    for c in s:
        if c == pre:
            yes = False
        pre = c

print('YES' if yes else 'NO')