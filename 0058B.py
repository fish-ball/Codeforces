from sys import stdin

n = int(stdin.readline().strip())

a = [n]

i = 2

while n > 1:
    while n % i == 0:
        n //= i
        a.append(n)
    i += 1

print(' '.join([str(x) for x in a]))
