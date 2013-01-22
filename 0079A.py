from sys import stdin

(x, y) = [int(buf) for buf in stdin.readline().strip().split()]


ans = 0
while y >= 2 and x*100 + y*10 >= 220:
    ans = 1 - ans
    if ans == 1:
        y -= 22 - max(x, 2) * 10
        x -= max(x, 2)
    else:
        x -= 2 - max((y-2)//10, 2)
        y -= 2 + max((y-2)//10, 2) * 10

print('Ciel' if ans == 1 else 'Hanako')
