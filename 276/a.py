import sys

n, k = [ int(x) for x in sys.stdin.readline().split() ]

best = 0
f, t  = [ int(x) for x in sys.stdin.readline().split() ]
if (t > k):
  best = f - t + k
elif (t <= k):
  best = f

for i in range(1, n):
  f, t  = [ int(x) for x in sys.stdin.readline().split() ]
  if (t > k and best < (f - t + k)):
    best = f - t + k
  elif (t <= k and best < f):
    best = f

print best
