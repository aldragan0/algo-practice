import sys
from collections import defaultdict
from queue import Queue

paths = defaultdict(list)
base2 = dict()

ind = 0

for line in sys.stdin.readlines():
    l, r = line.strip().split('-')

    l, r = (r, l) if r == 'start' or l == 'end' else (l, r)

    if l == 'start' or r == 'end':
        paths[l].append(r)
    else:
        paths[r].append(l)
        paths[l].append(r)

        if l.islower() and l not in base2:
            base2[l] = 2 ** ind
            ind += 1

        if r.islower() and r not in base2:
            base2[r] = 2 ** ind
            ind += 1

q = Queue()
v = Queue()

q.put('start')
v.put(0)

total_paths = 0
VISITED_TWICE = 2 ** ind

while not q.empty():
    curr = q.get()
    cvis = v.get()

    if curr.islower():
        if curr == 'end':
            total_paths += 1
            continue

        elif curr != 'start':
            is_visited = base2[curr] & cvis
            is_twice = VISITED_TWICE & cvis

            if is_visited and is_twice:
                continue

            if is_visited:
                cvis |= VISITED_TWICE

            cvis |= base2[curr]

    for ch in paths[curr]:
        q.put(ch)
        v.put(cvis)

print(total_paths)
