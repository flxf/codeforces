import sys

n = int(sys.stdin.readline())
line = sys.stdin.readline().strip()
trains = [ int(x) for x in line.split(" ") ]
total = sum(trains)

line = sys.stdin.readline().strip().split(" ")
start = int(line[0])
end = int(line[1])

start -= 1
end -= 1


if (start == end):
  print 0
else:
  best = 0
  for i in range(min(start, end), max(start, end)):
    best += trains[i]

  best = min(best, total - best)
  print best
