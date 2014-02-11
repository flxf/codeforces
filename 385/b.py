import sys
import string

s = sys.stdin.readline().strip()

bears = []
last = -4
while True:
  last = string.find(s, "bear", last + 4)
  if (last == -1):
    break
  bears.append(last)

cnt = 0
for i in range(0, len(s) - 3):
  least = min([ x for x in bears if x >= i ] or [ -1 ])
  if least == -1:
    continue
  cnt += len([ x for x in range(least + 3, len(s)) ])

#print bears
print cnt
