import sys

n, m = [ int(x) for x in sys.stdin.readline().split() ]
arr = [ int(x) for x in sys.stdin.readline().split() ]
brr = [ int(x) for x in sys.stdin.readline().split() ]

mina = min(arr)
maxa = max(arr)
minb = min(brr)

soln = -1

for i in range(maxa, minb):
  if (mina * 2 <= i):
    soln = i
    break

print soln
