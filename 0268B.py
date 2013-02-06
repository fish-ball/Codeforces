from sys import stdin, stdout

n = int(stdin.readline().strip())

print(n + sum([(n-i)*i for i in range(1, n)]))
