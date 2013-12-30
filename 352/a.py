import sys

n = int(sys.stdin.readline())
digs = [ int(x) for x in sys.stdin.readline().split() ]
five = digs.count(5)
zeros = digs.count(0)

if (zeros == 0):
  print -1
else:
  good = ((five / 9) * 9)
  if good == 0:
    print 0
  else:
    print "5" * good + "0" * zeros
