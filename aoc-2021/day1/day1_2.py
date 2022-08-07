import sys

prev = None
counter = 0

def slidingWindow(values, windowLen):
    for i in range(len(values) - windowLen + 1):
        yield tuple(values[i:i + windowLen])

numbers = [int(line.rstrip('\n')) for line in sys.stdin]

for window in slidingWindow(numbers, 3):
    current_sum = sum(window)
    if prev is not None and current_sum > prev:
        counter += 1

    prev = current_sum

print(counter)
