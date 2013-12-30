import sys

n, m = [ int(x) for x in sys.stdin.readline().split() ]
f = [ int(x) for x in sys.stdin.readline().split() ]
f.sort()

print min((f[i+n-1] - f[i] for i in range(0, len(f) - n + 1)))
