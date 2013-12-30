import sys

y = int(sys.stdin.readline())

def distinct(y):
  digits = set()
  for p in range(3, -1, -1):
    digits.add((y % 10 ** (p + 1)) / (10 ** p))

  return len(digits) == 4

while True:
  y += 1
  if (distinct(y)):
      print y
      break
