from sys import stdin

(n, m) = [int(x) for x in stdin.readline().strip().split()]


if n == 0 and m > 0:
    print('Impossible')
else:
    print('%d %d' % (n+max(m-n, 0), n+m-(1 if m > 0 else 0)))

