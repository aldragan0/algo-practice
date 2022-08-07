import sys

x = 0
y = 0
aim = 0

for line in sys.stdin:
    direction, n = line.strip().split()
    n = int(n)

    if direction == "forward":
        x += n
        y += n * aim
    elif direction == "down":
        aim += n
    else:
        aim -= n

print(x * y)

