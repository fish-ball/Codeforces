from sys import stdin, stdout

n = int(stdin.readline().strip())

s = stdin.readline().strip()

print(sum([1 if s[i] == s[i-1] else 0 for i in range(1, n)]))
