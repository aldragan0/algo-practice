import sys
from collections import namedtuple

Point = namedtuple('Point', ['x', 'y'])

points = set()

lines = sys.stdin.readlines()

ind = 0
for i, line in enumerate(lines):
    ind = i
    if not line.strip():
        break

    points.add(Point(*[int(i) for i in line.strip().split(',')]))

ind += 1 # skip the empty line

for i in range(ind, ind + 1):
    condition = lines[i].strip().split()[2]
    d, v = condition.split('=')
    v = int(v)

    if d == 'x':
        greater = {p for p in points if p.x > v}
        updated = {Point(v - (p.x - v), p.y) for p in greater}

        points.difference_update(greater)
        points.update(updated)
    else:
        greater = {p for p in points if p.y > v}
        updated = {Point(p.x, v - (p.y - v)) for p in greater}

        points.difference_update(greater)
        points.update(updated)

print(len(points))
