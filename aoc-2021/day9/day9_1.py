import sys

lows = list()
height_map = [[int(i) for i in list(line.strip())] for line in sys.stdin.readlines()]
n = len(height_map)
m = len(height_map[0])
print(n, m)

for i in range(n):
    for j in range(m):
        points = list()
        if i - 1 >= 0:
            points.append(height_map[i - 1][j])
        if i + 1 <= n - 1:
            points.append(height_map[i + 1][j])
        if j - 1 >= 0:
            points.append(height_map[i][j - 1])
        if j + 1 <= m - 1:
            points.append(height_map[i][j + 1])
        point = height_map[i][j]

        if min(points) > point:
            lows.append(point)

print(sum(lows) + len(lows))
