from sys import stdin, stdout

n = int(stdin.readline().strip())
a = [int(x) for x in stdin.readline().strip().split()]

cnt = [[0, 'chest'], [0, 'biceps'], [0, 'back']]

for i in range(0, n):
    cnt[i % 3][0] += a[i]

print(sorted(cnt)[-1][1])
