# Best strategy is: kill ceiling(n/2) of army 2 first, 
# then kill floor(n/2) of army 1 twice.
import sys

n = int(sys.stdin.readline().strip())

print(n+n//2)