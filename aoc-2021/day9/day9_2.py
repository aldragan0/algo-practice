import sys
from queue import Queue

lows_coords = list()

height_map = [[int(i) for i in list(line.strip())] for line in sys.stdin.readlines()]
n = len(height_map)
m = len(height_map[0])

for i in range(n):
    for j in range(m):
        adjacent = list()
        if i - 1 >= 0:
            adjacent.append(height_map[i - 1][j])
        if i + 1 <= n - 1:
            adjacent.append(height_map[i + 1][j])
        if j - 1 >= 0:
            adjacent.append(height_map[i][j - 1])
        if j + 1 <= m - 1:
            adjacent.append(height_map[i][j + 1])
        point = height_map[i][j]

        if min(adjacent) > point:
            lows_coords.append((i, j))

visited = set()
basins = list()

for min_coord in lows_coords:
    basin = list()
    q = Queue()
    q.put(min_coord)

    while not q.empty():
        current = q.get()
        x, y = current

        if current in visited:
            continue

        point = height_map[x][y]

        if x - 1 >= 0:
            other = height_map[x - 1][y]
            if other > point and other != 9:
                q.put((x - 1, y))

        if x + 1 <= n - 1:
            other = height_map[x + 1][y]
            if other > point and other != 9:
                q.put((x + 1, y))

        if y - 1 >= 0:
            other = height_map[x][y - 1]
            if other > point and other != 9:
                q.put((x, y - 1))

        if y + 1 <= m - 1:
            other = height_map[x][y + 1]
            if other > point and other != 9:
                q.put((x, y + 1))

        visited.add(current)
        basin.append(current)
    basins.append(basin)

basin_lengths = map(len, basins)

first_max = -1
second_max = -1
third_max = -1
for length in basin_lengths:
    if length > first_max:
        third_max = second_max
        second_max = first_max
        first_max = length
    elif length > second_max:
        third_max = second_max
        second_max = length
    elif length > third_max:
        third_max = length

print(first_max * second_max * third_max)
