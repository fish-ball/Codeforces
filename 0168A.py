# Simply round and output.
import sys

(n, x, y) = [int(x) for x in sys.stdin.readline().strip().split()]

print(max((n*y-1)//100+1-x, 0))