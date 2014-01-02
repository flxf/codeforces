import sys

n = int(sys.stdin.readline())
for i in range(0, n):
  line = sys.stdin.readline()[0:-1]
  lala = line[-5:] == "lala."
  miao = line[0:5] == "miao."

  if (miao and lala):
    print "OMG>.< I don't know!"
  elif (miao):
    print "Rainbow's"
  elif (lala):
    print "Freda's"
  else:
    print "OMG>.< I don't know!"
