import sys

x = 0
y = 0

for line in sys.stdin:
    direction, n = line.strip().split()
    n = int(n)

    if direction == "forward":
        x += n
    elif direction == "down":
        y += n
    else:
        y -= n

print(x * y)

