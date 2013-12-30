import sys

n, m = sys.stdin.readline().split()
n = int(n) - 1
m = int(m)

tasks = sys.stdin.readline().split()
tasks = [ int(t) - 1 for t in tasks ]

dist = 0

curr = 0
for t in tasks:
  if (t == curr):
    continue
  elif (t > curr):
    dist += (t - curr)
    curr = t
  else:
    dist += (n - curr) + 1
    dist += t
    curr = t

print dist
