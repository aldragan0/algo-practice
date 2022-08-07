import sys
from collections import namedtuple
from queue import LifoQueue

Fish = namedtuple('Fish', ['timer', 'creation_time'])

no_days = 256
initial = [Fish(int(i) + 1, no_days) for i in sys.stdin.readline().strip().split(',')]

cache = dict()

def get_num_children(node):
    if node in cache:
        return cache[node]

    remaining = node.creation_time - node.timer
    s = 1

    if remaining >= 0:
        for time in range(remaining, -1, -7):
            child = Fish(9, time)

            if child not in cache:
                no_child = get_num_children(child)
                cache[child] = no_child
            else:
                no_child = cache[child]

            s += no_child

    cache[node] = s
    return s
        
total = 0
for f in initial:
    total += get_num_children(f)
print(total)

