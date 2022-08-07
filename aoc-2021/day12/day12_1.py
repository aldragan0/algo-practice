import sys
from collections import defaultdict
from queue import Queue
from copy import deepcopy

paths = defaultdict(list)

for line in sys.stdin.readlines():
    l, r = line.strip().split('-')

    l, r = (r, l) if r == 'start' or l == 'end' else (l, r)

    if l == 'start' or r == 'end':
        paths[l].append(r)
    else:
        paths[r].append(l)
        paths[l].append(r)

q = Queue()
v = Queue()

q.put('start')
v.put(list())

total_paths = 0

while not q.empty():
    curr = q.get()
    cvis = v.get()

    if curr in cvis:
        continue

    if curr.islower():
        if curr == 'end':
            total_paths += 1
            continue
        elif curr != 'start':
            cvis.append(curr)

    for ch in paths[curr]:
        q.put(ch)
        v.put(deepcopy(cvis))

print(total_paths)
