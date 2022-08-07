import sys
from collections import defaultdict

crabs = [int(i) for i in sys.stdin.readline().strip().split(',')]
hist = defaultdict(int)

def cost_move_to_pos(pos):
    total_cost = 0

    for c in crabs:
        total_cost += abs(c - pos)

    return total_cost

for c in crabs:
    hist[c] += 1

n = 0
s = 0

for k, v in hist.items():
    s += k * v
    n += v

mean = s // n
mode = max(hist, key = lambda x: hist[x])

low, high = (mean, mode) if mean < mode else (mode, mean)

min_c = 1 << 63 - 1
for nr in range(low, high + 1):
    new_c = cost_move_to_pos(nr)
    min_c = min(min_c, new_c)
print(min_c)
