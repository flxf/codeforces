import sys

line = sys.stdin.readline().strip()

first = ' '
if line[0] >= 'a' and line[0] <= 'z':
  first = chr(ord(line[0]) - ord('a') + ord('A'))
else:
  first = line[0]

print first + line[1:]
