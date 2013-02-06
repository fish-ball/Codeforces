# it require high performance, so the routine cannot pass.
# the algorithm is ok, and was translated to c++, see 0269C.cc

from sys import stdin

(n, m) = [int(x) for x in stdin.readline().strip().split()]

# Be careful that list is mutable so [[]] * n 
g = [[] for i in range(0, n)]
f = [0] * n
mp = {}
ans = [-1] * m

for i in range(0, m):
    (a, b, c) = [int(x) for x in stdin.readline().strip().split()]
    mp[(a-1,b-1)] = i
    f[a-1] += c
    f[b-1] += c
    g[a-1] += [(b-1, c)]
    g[b-1] += [(a-1, c)]

q = [0]
while len(q) > 0:
    v = q.pop()
    for (w, c) in g[v]:
        e = (v, w) if (v, w) in mp else (w, v)
        i = mp[e]
        if ans[i] == -1:
            ans[i] = 1 if e[0] == w else 0
            f[w] -= c + c
            if w != n-1 and f[w] == 0:
                q += [w]

for x in ans:
    print(x)
