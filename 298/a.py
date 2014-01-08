import sys

sys.stdin.readline()
line = sys.stdin.readline().strip()

onlyl = line.find(".L")
if onlyl != -1:
  s = line.find("L.")
  print s + 1, onlyl + 1
  sys.exit(0)

onlyr = line.find("R.")
if onlyr != -1:
  s = line.find(".R") + 1
  print s + 1, onlyr + 2
  sys.exit(0)

s = line.find(".R") + 1
e = line.find("RL")

print s + 1, e + 1
