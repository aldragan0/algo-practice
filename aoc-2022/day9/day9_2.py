import sys
from typing import List
from collections import namedtuple

Point = namedtuple('Point', 'x y')
dirs = {
    'U': Point(0, 1),
    'D': Point(0, -1),
    'L': Point(-1, 0),
    'R': Point(1, 0)
}

diags = {
    'UL': Point(-1, 1),
    'UR': Point(1, 1),
    'DL': Point(-1, -1),
    'DR': Point(1, -1)
}


def dist(a: Point, b: Point) -> int:
    return max(abs(b.x - a.x), abs(b.y - a.y))


def add(a: Point, b: Point) -> Point:
    return Point(a.x + b.x, a.y + b.y)


def sub(a: Point, b: Point) -> Point:
    return Point(a.x - b.x, a.y - b.y)


def getX(a: Point, b: Point) -> str:
    dx = ''
    if b.x > a.x:
        dx = 'L'
    elif b.x < a.x:
        dx = 'R'
    return dx


def getY(a: Point, b: Point) -> str:
    dy = ''
    if b.y > a.y:
        dy = 'D'
    elif b.y < a.y:
        dy = 'U'
    return dy


def printMatrix(points: List[Point], size: int=10):
    matrix = [['.' for _ in range(size)] for _ in range(size)]
    
    for (i, e) in enumerate(reversed(points)):
        matrix[e.y][e.x] = f'{len(points) - i - 1}'

    print('\n'.join([''.join(row) for row in reversed(matrix)]))
    print()


def solve(filename: str):
    lines = None

    with open(filename, 'r') as file:
        lines = [l.strip() for l in file.readlines()]

    points = [Point(0, 0) for _ in range(10)]
    tdirs = set([Point(0, 0)])

    # printMatrix(points, size=6)

    for line in lines:
        (d, l) = line.split(' ')

        for _ in range(int(l)):
            # make step for head
            points[0] = add(points[0], dirs[d])

            for i in range(1, 10):
                prev, curr = points[i - 1], points[i]
                delta = dist(curr, prev)
                if delta > 1:
                    dd = getY(prev, curr) + getX(prev, curr)
                    # make diag move if diag move else make normal move
                    move = diags[dd] if dd in diags else dirs[dd]
                    points[i] = add(curr, move)
                    
                    if i == 9:
                        tdirs.add(points[i])

            # printMatrix(points, size=6)

    print(len(tdirs))


if __name__ == '__main__':
    solve(sys.argv[1])
