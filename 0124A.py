# Too simple...
import sys

(a, b, c) = [int(x) for x in sys.stdin.readline().split()]

print(min(a-b, c+1))