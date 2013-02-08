from sys import stdin, stdout

p = stdin.readline().strip()

d = dict()

for i in range(10):
    d[stdin.readline().strip()] = i

ans = ''

for i in range(8):
    ans += str(d[p[10*i:10*(i+1)]])
   
print(ans)
