(r, c) = (int(x) for x in input().split())

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

e = ()
s = ()

g = [[-1] * c for x in range(0, r)]
mp = []

for i in range(0, r):
    buf = input()
    mp.append(buf)
    k = buf.find('E')
    if k > -1: e = (i, k)
    k = buf.find('S')
    if k > -1: s = (i, k)

q = [e]
g[e[0]][e[1]] = 0

while len(q) > 0:
    (x, y) = q.pop(0)
    v = g[x][y]
    for d in range(0, 4):
        x += dx[d]
        y += dy[d]
        if 0 <= x < r and 0 <= y < c and mp[x][y] != 'T' and g[x][y] == -1:
            g[x][y] = v + 1
            q.append((x, y))
        x -= dx[d]
        y -= dy[d]

t = g[s[0]][s[1]]
ans = 0

nums = {str(x) for x in range(1,10)}

for i in range(0, r):
    for j in range(0, c):
        if 0 <= g[i][j] <= t and mp[i][j] in nums:
            ans += int(mp[i][j])

print(ans)
            
