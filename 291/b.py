import sys

line = sys.stdin.readline().strip()

last = ""
bracketed = False
wasbracketed = False
for c in line:
  if c == '"':
    bracketed = not bracketed
    wasbracketed = True
  elif c == ' ':
    if bracketed:
      last += " "
    else:
      if last != "" or wasbracketed:
        print "<" + last + ">"
        last = ""
        wasbracketed = False
        
  else:
    last += c

if last != "" or wasbracketed:
  print "<" + last + ">"
