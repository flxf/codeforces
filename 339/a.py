import sys

line = sys.stdin.readline().strip()
line = line.split("+")
line = [ int(x) for x in line ]
line.sort()

line = [ str(x) for x in line ]

print "+".join(line)
