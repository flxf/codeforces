import sys

n = int(sys.stdin.readline())

if (n >= 0):
  print n
else:
  n = abs(n)
  last = n % 10
  other = (n % 100) / 10

  best = min((n / 100) * 10 + last, (n / 100) * 10 + other)
  if (best == 0):
    print 0
  else:
    print "-%d" % best
