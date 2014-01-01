import sys
import bisect

line = sys.stdin.readline().strip()

heavy = []
metal = []

last = -1
while True:
  nxt = line.find("heavy", last + 1)
  if nxt == -1:
    break
  heavy.append(nxt)
  last = nxt

last = -1
while True:
  nxt = line.find("metal", last + 1)
  if nxt == -1:
    break
  metal.append(nxt)
  last = nxt

ans = 0
for h in heavy:
  m = bisect.bisect_left(metal, h)
  ans += len(metal) - m

print ans
