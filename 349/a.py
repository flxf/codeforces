import sys

n = int(sys.stdin.readline())
bills = [ int(x) for x in sys.stdin.readline().split() ]

tw5 = 0
fif = 0

good = True

for b in bills:
  if b == 25:
    tw5 += 1
  elif b == 50:
    if (tw5 > 0):
      tw5 -= 1
      fif += 1
    else:
      good = False
      break
  else:
    if (fif > 0 and tw5 > 0):
      fif -= 1
      tw5 -= 1
    elif (tw5 >= 3):
      tw5 -= 3
    else:
      good = False
      break

if good:
  print "YES"
else:
  print "NO"
