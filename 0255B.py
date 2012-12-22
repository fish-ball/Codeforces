# Note that the order of x's and y's does not matters.

from sys import stdin, stdout

x = 0

for c in stdin.readline().strip():
    x += 1 if c == 'x' else -1

print('x' * x if x > 0 else 'y' * -x)
