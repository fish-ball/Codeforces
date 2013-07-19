s = input() + '?'
p = input()

cnt = 0

d = [0] * 26

for c in p: d[ord(c)-97] += 1

for c in s[0:len(p)]:
    if c != '?':
        d[ord(c)-97] -= 1

for k in range(len(p), len(s)):
    if min(d) >= 0:
        cnt += 1
    if s[k] != '?':
        d[ord(s[k])-97] -= 1
    if s[k-len(p)] != '?':
        d[ord(s[k-len(p)])-97] += 1

print(cnt)
