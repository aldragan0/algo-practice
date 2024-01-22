import sys
from collections import namedtuple

Point = namedtuple('Point', 'x y')
dirs = {
    'U': Point(0, 1),
    'D': Point(0, -1),
    'L': Point(-1, 0),
    'R': Point(1, 0)
}


def dist(a: Point, b: Point) -> int:
    return max(abs(b.x - a.x), abs(b.y - a.y))


def add(a: Point, b: Point) -> Point:
    return Point(a.x + b.x, a.y + b.y)


def sub(a: Point, b: Point) -> Point:
    return Point(a.x - b.x, a.y - b.y)


def solve(filename: str):
    lines = None

    with open(filename, 'r') as file:
        lines = [l.strip() for l in file.readlines()]

    t = Point(0, 0)
    h = Point(0, 0)
    oldH = None
    tdirs = set([Point(0, 0)])

    for line in lines:
        (d, l) = line.split(' ')

        for _ in range(int(l)):

            oldH = h
            h = add(h, dirs[d])
            delta = dist(t, h)

            if delta > 1:
                dht = sub(oldH, t)
                t = add(t, dht)
                tdirs.add(t)

    print(len(tdirs))


if __name__ == '__main__':
    solve(sys.argv[1])
