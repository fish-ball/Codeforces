#   We do the below to get the result:
#   1. Create a set contains all 1 to n, indexing 1 to n;
#   2. Set the result to be 0
#   3. Iterates the sequence a, for each element a[i], if there is
# still exists elemet(s) in the set smaller a[i], update the result
# to i(1-based). And also remove the a[i] from the list.
#   To implement the set, we can use an indexed-doubly-linked-list.

from sys import stdin

n = int(stdin.readline().strip())

a = [int(x) for x in stdin.readline().strip().split()]

pre = list(range(-1, n+1))
nxt = list(range(1, n+3))

ans = 0

for i in range(0, n):
    if pre[a[i]] != 0:
        ans = i + 1
    pr = pre[a[i]]
    nx = nxt[a[i]]
    pre[a[i]] = -1
    nxt[a[i]] = -1
    nxt[pr] = nx
    pre[nx] = pr

print(ans)
