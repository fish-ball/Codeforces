#   This a recurrence equation.. 
#   Let d(i) to be the count of path that stops at D after i moves,
# while _d(i) to be the count of path that doesn't.
#   So we can use a chain mulitplying of matrices to achieve the
# result.

import math, sys

def mul(a, b):
    return (
            (
            (a[0][0]*b[0][0]+a[0][1]*b[1][0]) % 1000000007,
            (a[0][0]*b[0][1]+a[0][1]*b[1][1]) % 1000000007
            ),
            (
            (a[1][0]*b[0][0]+a[1][1]*b[1][0]) % 1000000007,
            (a[1][0]*b[0][1]+a[1][1]*b[1][1]) % 1000000007
            )
        )

def pw(k):
    if k == 0:
        return ((1,0),(0,1))
    else:
        a = pw(k>>1)
        a = mul(a, a)
        if k % 2 == 1:
            a = mul(a, ((0,3),(1,2)))
        return a

n = int(sys.stdin.readline().strip())

print(pw(n)[0][0])
