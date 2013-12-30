import sys

n = int(sys.stdin.readline())
last = int(sys.stdin.readline())
groups = 1

for i in range(1, n):
  nxt = int(sys.stdin.readline())
  if (nxt == last):
    continue
  else:
    groups += 1
    last = nxt

print groups
