"""

  In the full comparision case, each index has n-1 comparisions.

  If we define the score to be 1 for each win, and -1 for each lose,
the odd/even property of result score for each index should be the
same with n-1, meaning the total comaprisions.

  So because there is a single pair missing, there will be exactly
two index with wrong odd/even property, take them out, and the one
has greater current score should be output false.

"""

n = int(input())

a = [0] * n

for c in range(n*(n-1)//2-1):
    (x, y) = map(int, input().split())
    a[x-1] += 1
    a[y-1] -= 1

r = []
for i in range(n):
    if (a[i] & 1) != (n-1) & 1:
        r += [(a[i], i+1)]

r.sort()
    
print(r[1][1], r[0][1])
