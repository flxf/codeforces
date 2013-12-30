import sys

n = int(sys.stdin.readline())
ids = [ int(x) for x in sys.stdin.readline().split() ]

mp = {}
for d in ids:
  if d > 0:
    if d in mp:
      mp[d] += 1
    else:
      mp[d] = 1

soln = 0
for k in mp.keys():
  if mp[k] == 2:
    soln += 1
  elif mp[k] > 2:
    print -1
    sys.exit(0)

print soln
