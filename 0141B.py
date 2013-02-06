from sys import stdin

(a, x, y) = [int(x) for x in stdin.readline().strip().split()]

if y % a == 0:
    print(-1)
elif y < a:
    if -a < x+x < a:
        print(1)
    else:
        print(-1)
elif y // a % 2 == 1:
    if -a < x+x < a:
        print((y//a-1)//2*3+2)
    else:
        print(-1)
else:
    if -a < x < 0:
        print(y//a//2*3)
    elif 0 < x < a:
        print(y//a//2*3+1)
    else:
        print(-1)
