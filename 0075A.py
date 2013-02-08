from sys import stdin

a = stdin.readline().strip()
b = stdin.readline().strip()
c = int(a) + int(b)

a = int(a.replace('0', ''))
b = int(b.replace('0', ''))
c = int(str(c).replace('0', ''))

print('YES' if a+b==c else 'NO')

