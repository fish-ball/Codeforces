# First, in order to be divisible by 2 and 5, 0 is required, otherwise, print -1
# Also, if 0 exists, at least 0 is divisible by 3, so answer exists.
# Then count the numbers of each digit, and divide them to following cases:
#   1. The sum residue is 0: keep the initial set then sort and output;
#   2. The residue is 2: remove one 2/5/8 or two 1/4/7(s) then sort and output;
#   3. The residue is 1: remove one 1/4/7 or two 2/5/8(s) then sort and output;
#   4. After remove, If all digits are 0s, because leading-0 is forbidden, output 0;
import sys


n = int(sys.stdin.readline().strip())
a = [int(x) for x in sys.stdin.readline().strip().split()]
c = [0 for i in range(0, 10)]


res = 0


for x in a:
    c[x] += 1
    res = (res + x) % 3


if res == 1:
    k = 1
    for i in [1,4,7]:
        if k > 0 and c[i] > 0:
            c[i] -= 1
            k -= 1
            n -= 1
    if k == 1:
        k = 2
        for i in [2,5,8]:
            while k > 0 and c[i] > 0:
                c[i] -= 1
                k -= 1
                n -= 1
elif res == 2:
    k = 1
    for i in [2,5,8]:
        if k > 0 and c[i] > 0:
            c[i] -= 1
            k -= 1
            n -= 1
    if k == 1:
        k = 2
        for i in [1,4,7]:
            while k > 0 and c[i] > 0:
                c[i] -= 1
                k -= 1
                n -= 1


if c[0] == 0:
    print(-1)
elif c[0] == n:
    print(0)
else:
    for i in range(0, 10):
        sys.stdout.write(str(9-i)*c[9-i])
    print('')