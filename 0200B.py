# Simply outputs the average of the numbers.
import sys

n = int(sys.stdin.readline().strip())

vals = [float(x) for x in sys.stdin.readline().strip().split()]

print(sum(vals) / n)