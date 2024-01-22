import sys
from collections import Counter

def get_priority(item: str):
    if ord(item) >= ord('a'):
        return ord(item) - ord('a') + 1
    else:
        return ord(item) - ord('A') + 27


def solve(filename: str):
    with open(filename, 'r') as file:
        lines = [l.strip() for l in file.readlines()]

        total = 0
        for i in range(0, len(lines), 3):
            counter = Counter()

            for line in lines[i:i+3]:
                counter.update(set(line))

            pair = counter.most_common(1)
            total += get_priority(pair[0][0])

        print(total)


if __name__ == '__main__':
    solve(sys.argv[1])
