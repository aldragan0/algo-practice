import sys
from queue import LifoQueue

score = { ')': 3, ']': 57, '}': 1197, '>': 25137 }
start = { '(', '[', '<', '{' }
matching = { '(': ')', '[': ']', '<': '>', '{': '}' }

total_score = 0
for line in sys.stdin.readlines():
    queue = LifoQueue()
    for c in list(line.strip()):
        if c in start:
            queue.put(c)
        else:
            current = queue.get() # start paranthesis
            if c != matching[current]:
                total_score += score[c]
                break

print(total_score)

