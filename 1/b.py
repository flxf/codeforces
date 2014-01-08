import sys
import re

typea = re.compile("^R\d+C\d+$")

def l2i(col):
  l = [ ord(c) - ord("A") for c in col ]
  for i in range(0, len(l) - 1):
    l[i] += 1

  ans = 0
  pw = 1
  for i in range(0, len(l)):
    ans += l[len(l) - i - 1] * pw
    pw *= 26

  return ans

def i2l(col):
  if (col < 26):
    return chr(ord("A") + col)
  return i2l(col / 26 - 1) + i2l(col % 26)


n = int(sys.stdin.readline())
for i in range(0, n):
  line = sys.stdin.readline().strip()
  if typea.match(line):
    row = int(line[1:line.find("C")])
    col = int(line[line.find("C")+1:])
    print i2l(col - 1) + str(row)
  else:
    intg = (x for x in xrange(len(line)) if line[x] >= '0' and line[x] <= '9').next()
    col = line[0:intg]
    row = line[intg:]
    print "R" + row + "C" + str(l2i(col) + 1)
