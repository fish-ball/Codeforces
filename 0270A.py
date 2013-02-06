from sys import stdin, stdout

n = int(stdin.readline().strip())

for i in range(0, n):
    x = int(stdin.readline().strip())
    print('YES' if 360 % (180-x) == 0 else 'NO')

