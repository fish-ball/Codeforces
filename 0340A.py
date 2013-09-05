import sys

def gcd(m, n): return m if n==0 else gcd(n, m%n)
def lcm(m, n): return m // gcd(m,n) * n


(x, y, a, b) = list(map(int, input().split()))

z = lcm(x, y)

print(b//z-(a-1)//z)
