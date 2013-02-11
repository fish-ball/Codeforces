import sys

sys.stdin=open("input.txt","r")
sys.stdout=open("output.txt","w")

(n, k) = [int(x) for x in sys.stdin.readline().strip().split()]

a = [int(x) for x in sys.stdin.readline().strip().split()]

for i in range(n):
    a[i] = [a[i], i+1]

a.sort(reverse=True)

print(str(a[k-1][0]))

print(' '.join([str(x[1]) for x in a[0:k]]))
