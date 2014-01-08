import sys

s = sys.stdin.readline().strip()

seen = {}

ans = 1
cnt = 0

rem = 10
for i in range(0, len(s)):
  if (s[i] >= '0' and s[i] <= '9'):
    continue
  elif (s[i] >= 'A' and s[i] <= 'Z' and not s[i] in seen):
    if i == 0:
      ans *= 9
    else:
      ans *= rem
    rem -= 1
    seen[s[i]] = True
  elif (s[i] == '?'):
    if i == 0:
      ans *= 9
    else:
      cnt += 1

print str(ans) + "0" * cnt
