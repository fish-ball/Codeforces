from sys import stdin, stdout

(n, t) = [int(x) for x in stdin.readline().strip().split()]

s = list(stdin.readline().strip())

for i in range(0, t):
    y = True
    for j in range(1, n):
        if y and s[-j] == 'G' and s[-1-j] == 'B':
            (s[-j-1], s[-j]) = (s[-j], s[-1-j])
            y = False
        elif y == False:
            y = True

print(''.join(s))
