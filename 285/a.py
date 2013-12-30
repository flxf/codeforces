import sys

n, k = [ int(x) for x in sys.stdin.readline().split() ]
soln = range(n, n-k, -1) + range(1, n-k+1)

print ' '.join([ str(s) for s in soln ])
