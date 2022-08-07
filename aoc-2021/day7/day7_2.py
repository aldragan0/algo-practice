import sys
from collections import defaultdict

crabs = [int(i) for i in sys.stdin.readline().strip().split(',')]

min_cost = 1 << 63 - 1
min_pos = min(crabs)
max_pos = max(crabs)

for pos in range(min_pos, max_pos + 1):
    total_cost = 0

    for c in crabs:
        n = abs(c - pos)
        total_cost += (n * (n + 1)) // 2

    min_cost = min(min_cost, total_cost)
print(min_cost)

