import sys

n, m, k = [ int(x) for x in sys.stdin.readline().split() ]
arr = [ int(x) for x in sys.stdin.readline().split() ]

clean = 0

for a in arr:
  if (a == 1):
    if (m == 0):
      clean += 1
    else:
      m -= 1
  else:
    if (k > 0):
      k -= 1
    elif (m > 0):
      m -= 1
    else:
      clean += 1

print clean
