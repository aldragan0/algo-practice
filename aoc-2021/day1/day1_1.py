import sys

prev = None
counter = 0

for line in sys.stdin:
    number = int(line.rstrip('\n'))
    if(prev is not None and number >= prev):
        counter += 1
    prev = number

print(counter)
