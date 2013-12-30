import sys

n = int(sys.stdin.readline())
s = sum([ int(x) for x in sys.stdin.readline().split() ])


cnt = 0
for f in range(1, 5+1):
  if ((s + f - 1) % (n + 1) != 0):
    cnt += 1

print cnt
