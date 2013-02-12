import sys


#fin = open('input.txt', 'r')


#(n, m) = [int(x) for x in fin.readline().strip().split()]
(n, m) = [int(x) for x in sys.stdin.readline().strip().split()]


g = [[] for i in range(0, n)]


for i in range(0, m):
    (v, w) = [int(x)-1 for x in sys.stdin.readline().strip().split()]
#    (v, w) = [int(x)-1 for x in fin.readline().strip().split()]
    g[v].append(w)
    g[w].append(v)


seq = []
idx = [-1 for i in range(0, n)]
pre = [-1 for i in range(0, n)]
low = [-1 for i in range(0, n)]


def dfs(v):
    idx[v] = len(seq)
    seq.append(v)
    low[v] = v
    for w in g[v]:
        if idx[w] == -1:
            pre[w] = v
            dfs(w)
            if idx[low[w]] < idx[low[v]]:
                low[v] = low[w]
        elif w != pre[v] and idx[w] < idx[low[v]]:
            low[v] = w


dfs(0)


# calculate the compressed height of a natural vertex.
hgh = [-1 for i in range(0, n)]
hgh[0] = 0


def height(v):
    if hgh[v] != -1:
        return hgh[v]
    elif low[v] == v:
        hgh[v] = height(pre[v]) + 1
        return hgh[v]
    else:
        hgh[v] = height(low[v])
        return hgh[v]


# figure out if a compressed vertex is a ring.
nsz = [0 for i in range(0, n)]
for i in range(0, n):
    nsz[low[i]] += 1


# calculate the rings from v to the root.
wgt = [-1 for i in range(0, n)]
wgt[0] = 1 if nsz[0] > 1 else 0


def weight(v):
    if wgt[v] != -1:
        return wgt[v]
    elif low[v] == v:
        wgt[v] = weight(pre[v]) + (1 if nsz[v] > 1 else 0)
        return wgt[v]
    else:
        wgt[v] = weight(low[v])
        return wgt[v]


# pre-process the LCA array.
lca = [[pre[low[i]] for i in range(0, n)]]


k = 0
while (1<<k) <= n:
    lca.append([(-1 if x == -1 else lca[k][low[x]]) for x in lca[k]])
    k += 1






q = int(sys.stdin.readline().strip())
#q = int(fin.readline().strip())


for i in range(0, q):
    (a, b) = [int(x)-1 for x in sys.stdin.readline().strip().split()]
#    (a, b) = [int(x)-1 for x in fin.readline().strip().split()]


    if height(a) > height(b):
        (a, b) = (b, a)
    (aa, bb) = (a, b)
    for j in range(0, k+1):
        if height(b) - (1<<(k-j)) >= height(a):
            b = lca[k-j][b]
    for j in range(0, k):
        if height(b) - 1<<(k-j) > 0 and low[lca[k-j][a]] != low[lca[k-j][b]]:
            a = lca[k-j][a]
            b = lca[k-j][b]
    while low[a] != low[b]:
        a = lca[0][a]
        b = lca[0][b]


    loops = 0
    loops += weight(aa) + weight(bb) - weight(a) - weight(b)
    if nsz[low[a]] > 1:
        loops += 1


    ans = 1
    for i in range(0, loops):
        ans *= 2
        ans %= 1000000007


    print(ans)