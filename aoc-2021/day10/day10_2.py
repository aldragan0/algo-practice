import sys
from queue import LifoQueue

score = { ')': 1, ']': 2, '}': 3, '>': 4 }
start = { '(', '[', '<', '{' }
matching = { '(': ')', '[': ']', '<': '>', '{': '}' }

scores = list()

for line in sys.stdin.readlines():
    queue = LifoQueue()
    error = False

    for c in list(line.strip()):
        if c in start:
            queue.put(c)
        else:
            current = queue.get() # start paranthesis

            if c != matching[current]:
                error = True
                break

    if not error:
        line_score = 0
        while not queue.empty():
            current = matching[queue.get()]
            line_score = line_score * 5 + score[current]
        scores.append(line_score)

scores.sort()
print(scores[len(scores) // 2])

