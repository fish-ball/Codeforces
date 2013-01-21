from sys import stdin

(na, ma) = [int(buf) for buf in stdin.readline().strip().split()]
a = [int(stdin.readline().strip()[::-1], 2) for i in range(0, na)]

(nb, mb) = [int(buf) for buf in stdin.readline().strip().split()]
b = [int(stdin.readline().strip()[::-1], 2) for i in range(0, nb)]

def count1(x):
    x = (x & 0x55555555555555555555555555555555) + ((x>>0x01) & 0x55555555555555555555555555555555)
    x = (x & 0x33333333333333333333333333333333) + ((x>>0x02) & 0x33333333333333333333333333333333)
    x = (x & 0x0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F) + ((x>>0x04) & 0x0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F)
    x = (x & 0x00FF00FF00FF00FF00FF00FF00FF00FF) + ((x>>0x08) & 0x00FF00FF00FF00FF00FF00FF00FF00FF)
    x = (x & 0x0000FFFF0000FFFF0000FFFF0000FFFF) + ((x>>0x0F) & 0x0000FFFF0000FFFF0000FFFF0000FFFF)
    x = (x & 0x00000000FFFFFFFF00000000FFFFFFFF) + ((x>>0x10) & 0x00000000FFFFFFFF00000000FFFFFFFF)
    x = (x & 0x0000000000000000FFFFFFFFFFFFFFFF) + ((x>>0x20) & 0x0000000000000000FFFFFFFFFFFFFFFF)
    return x

def getval(x, y):
    cnt = 0
    for i in range(0, na):
        if i+x in range(0, nb):
            if y > 0:
                cnt += count1((a[i]<<y) & b[i+x])
            else:
                cnt += count1(a[i] & (b[i+x]<<-y))
    return cnt

(ans, xx, yy) = (0, 0, 0)
for x in range(1-na, nb):
    for y in range(1-ma, mb):
        val = getval(x, y)
        if ans  < val:
            (ans, xx, yy) = (val, x, y)

print('%d %d' % (xx, yy))
                
