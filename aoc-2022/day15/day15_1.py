import sys
from typing import Tuple
from collections import namedtuple
import re


Point = namedtuple('Point', ['x', 'y', 'd'])


def intersect(a: Tuple[int, int], b: Tuple[int, int]) -> bool:
    return max(a[0], b[0]) <= min(a[1], b[1])


def add(a: Tuple[int, int], b: Tuple[int, int]) -> Tuple[int, int]:
    return min(a[0], b[0]), max(a[1], b[1])


def diff(e: Point, pos: int) -> int:
    return e.d - abs(pos - e.y)


def dist(ax: int, ay: int, bx: int, by: int) -> int:
    return abs(bx - ax) + abs(by - ay)


def solve(filename: str):
    lines = None
    with open(filename, 'r') as file:
        lines = [l.strip() for l in file.readlines()]

    s = set()
    b = set()

    for line in lines:
        sx, sy, bx, by = [int(x) for x in re.findall(r'(-?\d+)', line)]

        s.add(Point(sx, sy, dist(sx, sy, bx, by)))
        b.add(Point(bx, by, 0))

    pos = 2000000

    ss = [(e.x - diff(e, pos), e.x + diff(e, pos)) for e in s if diff(e, pos) >= 0]

    i = 0
    while i < len(ss) - 1:
        j = i + 1
        while j < len(ss):
            if intersect(ss[i], ss[j]):
                ss.insert(i, add(ss[i], ss[j]))
                ss.pop(i + 1)
                ss.pop(j)
                j = i
                i = 0
            j += 1
        i += 1

    reaching = sum([e[1] - e[0] + 1 for e in ss])
    beacons = len(set(map(lambda e: e.x, filter(lambda e: e.y == pos, b))))
    print(reaching - beacons)

if __name__ == '__main__':
    solve(sys.argv[1])
