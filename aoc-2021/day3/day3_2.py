import sys

numbers = list(map(lambda x: x.strip(), sys.stdin.readlines()))

oxygen_candidates = numbers

for i in range(len(numbers[0])):
    freq = 0
    ones = []
    zeros = []
    for nr in oxygen_candidates:
        if (nr[i] == '1'):
            freq += 1
            ones.append(nr)
        else:
            zeros.append(nr)

    if freq >= len(oxygen_candidates) - freq:
        oxygen_candidates = ones
    else:
        oxygen_candidates = zeros

    if len(oxygen_candidates) == 1:
        break;

co_candidates = numbers

for i in range(len(numbers[0])):
    freq = 0
    ones = []
    zeros = []
    for nr in co_candidates:
        if (nr[i] == '1'):
            freq += 1
            ones.append(nr)
        else:
            zeros.append(nr)

    if freq >= len(co_candidates) - freq:
        co_candidates = zeros
    else:
        co_candidates = ones

    if len(co_candidates) == 1:
        break;

print(int(oxygen_candidates[0], base=2) * int(co_candidates[0], base=2))
