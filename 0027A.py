from sys import stdin

n = int(stdin.readline())

a = set(sorted([int(buf) for buf in stdin.readline().strip().split()]))

i = 1
while i in a:
    i += 1
    
print(i)

