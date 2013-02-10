from sys import stdin

n = int(stdin.readline().strip())

d = dict()

for i in range(n):
    s = stdin.readline().strip()
    if s not in d:
        print('OK')
        d[s] = 1
    else:
        print('%s%d' % (s, d[s]))
        d[s] += 1
