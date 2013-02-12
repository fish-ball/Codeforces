import sys


buf = sys.stdin.readline().split(' ')
m = int(buf[0])
l = int(buf[1])
r = int(buf[2])
k = int(buf[3])


def mat2mul(a, b):
    return [(a[0]*b[0]+a[1]*b[2])%m, (a[0]*b[1]+a[1]*b[3])%m
            , (a[2]*b[0]+a[3]*b[2])%m, (a[2]*b[1]+a[3]*b[3])%m]


def mat2pow(a, n):
    if n == 0:
        return [1, 0, 0, 1]
    b = mat2pow(a, n>>1)
    b = mat2mul(b, b)
    if n % 2 == 1:
        return mat2mul(b, a)
    else:
        return b


def fib(n):
    a = mat2pow([0, 1, 1, 1], n - 1)
    return (a[0] + a[2]) % m


w = int(r**0.5)


print(w)


q = 1
p = r//q


while q < w and r//p - (l-1)//p < k:
    q += 1
    p = r//q


while p > 0 and r//p - (l-1)//p < k:
    p -= 1


print(fib(p))