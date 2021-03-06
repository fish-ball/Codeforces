from sys import stdin, stdout

stdin=open("input.txt","r")
stdout=open("output.txt","w")

n = int(stdin.readline().strip())

days = [0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365]

cnt = [0 for i in range(0, 600)]

for i in range(0, n):
    (m, d, p, t) = [int(x) for x in stdin.readline().strip().split()]
    dd = days[m] + d
    for j in range(1, t+1):
        cnt[dd-j] += p

stdout.write(str(max(cnt)))