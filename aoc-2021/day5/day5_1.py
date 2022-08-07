import sys
from itertools import repeat
# each line is given as a segment
# x1, y1 -> x2, y2

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

        if start.x > end.x or (start.x == end.x and start.y > end.y):
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

        return 'd'

    def intersection(self, other):
        start = Point(max(self.start.x, other.start.x), max(self.start.y, other.start.y))
        end = Point(min(self.end.x, other.end.x), min(self.end.y, other.end.y))
        return Segment(start, end)

segments = list(filter(lambda it: it.d == 'v' or it.d == 'h', map(Segment.from_string, sys.stdin.readlines())))

#for s in segments:
#    print(s)

points = set()

for i, segment in enumerate(segments):
    for j in range(i):
        intr = segment.intersection(segments[j])
        if(intr.start.x > intr.end.x or\
                intr.start.y > intr.end.y):
            # do not intersect
            continue
        # print(intr)
        
        if intr.d == 'h':
            range_x = range(intr.start.x, intr.end.x + 1)
            range_y = repeat(intr.start.y, intr.end.x - intr.start.x + 1)
        else:
            range_x = repeat(intr.start.x, intr.end.y - intr.start.y + 1)
            range_y = range(intr.start.y, intr.end.y + 1)

        for x, y in zip(range_x, range_y):
            p = Point(x, y)
            points.add(p)
            # print(p)

print(len(points))

