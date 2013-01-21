from sys import stdin, stdout

def check(a, b, c):
    if a + b > c:
        return 2
    elif a + b == c:
        return 1
    else:
        return 0

(a1, a2, a3, a4) = sorted([int(x) for x in stdin.readline().strip().split()])

ans = max(check(a1,a2,a3), check(a1,a2,a4),check(a1,a3,a4),check(a2,a3,a4))

if ans == 2:
    print('TRIANGLE')
elif ans == 1:
    print('SEGMENT')
else:
    print('IMPOSSIBLE')
