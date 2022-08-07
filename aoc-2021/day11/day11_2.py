import sys
from queue import Queue

a = [[int(i) for i in list(line.strip())] for line in sys.stdin.readlines()]

d_x = [-1, 0, 1, -1, 1, -1, 0, 1]
d_y = [-1, -1, -1, 0, 0, 1, 1, 1]

n = len(a)

k = 1
while True:
    q = Queue()
    visited = set()

    for i in range(n):
        for j in range(n):
            a[i][j] += 1
            if a[i][j] > 9:
                q.put((i, j))

    while not q.empty():
        current = q.get()

        if current in visited:
            continue

        x1, y1 = current
        a[x1][y1] += 1

        if a[x1][y1] > 9:
            visited.add(current)
            for x, y in zip(d_x, d_y):
                nx = x1 + x
                ny = y1 + y
                if nx >= 0 and nx < n and ny >= 0 and ny < n:
                    q.put((nx, ny))

    invalid = False

    for i in range(n):
        for j in range(n):
            if a[i][j] > 9:
                a[i][j] = 0
            if a[i][j] != 0:
                invalid = True

    if not invalid:
        print(k)
        break

    k += 1
