import sys
from itertools import repeat
from collections import defaultdict

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __eq__(self, other):
        if isinstance(other, Point):
            return self.x == other.x and self.y == other.y
        return False

    def __hash__(self):
        return self.x * 1000000 + self.y

    def __str__(self):
        return "({}, {})".format(self.x, self.y)

class Segment:
    @classmethod
    def from_string(cls, data):
        start, end = [Point(*[int(el) for el in it.split(',')]) for it in data.strip().split(' -> ')]

        if start.y > end.y or (start.y == end.y and start.x > end.x):
            start, end = end, start

        return cls(start, end)

    def __init__(self, start: Point, end: Point):
        self.start = start
        self.end = end
        self.d = Segment.get_direction(start, end)

    def __str__(self):
        return "st: {}, end: {}, d: {}".format(self.start, self.end, self.d)

    @staticmethod
    def get_direction(start, end):
        if start.x == end.x:
            return 'v'
        elif start.y == end.y:
            return 'h'
        elif start.x < end.x and start.y < end.y:
            return 'pd'
        return 'sd'

segments = [Segment.from_string(x) for x in sys.stdin.readlines()]

points = defaultdict(int)

for segment in segments:
        range_x = range(segment.start.x, segment.end.x + 1)
        range_y = range(segment.start.y, segment.end.y + 1)

        if segment.d == 'h':
            range_x = range(segment.start.x, segment.end.x + 1)
            range_y = repeat(segment.start.y, segment.end.x - segment.start.x + 1)
        elif segment.d == 'v':
            range_x = repeat(segment.start.x, segment.end.y - segment.start.y + 1)
            range_y = range(segment.start.y, segment.end.y + 1)
        elif segment.d == 'sd':
            range_x = range(segment.start.x, segment.end.x - 1, -1)
            range_y = range(segment.start.y, segment.end.y + 1)

        for x, y in zip(range_x, range_y):
            p = Point(x, y)
            points[p] += 1

other = [k for k, v in points.items() if v > 1]
print(len(other))

