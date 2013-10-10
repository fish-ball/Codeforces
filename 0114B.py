(n, m) = map(int, input().split())

names = []
mp = {}
for i in range(n):
    name = input()
    mp[name] = i
    names.append(name)

mask = [0] * n
    
for i in range(m):
    (a, b) = map(mp.get, input().split())
    mask[a] |= (1<<b)
    mask[b] |= (1<<a)

ans = 0
result = 0

def bcnt(x):
    return 0 if x == 0 else bcnt(x>>1)+(x&1)

for val in range(1<<n):
    if bcnt(val) <= ans: continue
    valid = True
    for i in range(n):
        if ((1<<i)&val) and (val&mask[i]):
            valid = False
            break
    if valid:
        ans = bcnt(val)
        result = val
        
print(ans)
out = []
for i in range(n):
    if (1<<i)&result:
        out.append(names[i])

for s in sorted(out):
    print(s)
