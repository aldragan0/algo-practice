import sys

def get_priority(item: str):
    if ord(item) >= ord('a'):
        return ord(item) - ord('a') + 1
    else:
        return ord(item) - ord('A') + 27

def solve(filename: str):
    with open(filename, 'r') as file:
        lines = [l.strip() for l in file.readlines()]

        total = 0
        for line in lines:
            first, second = line[:len(line) // 2], line[len(line) // 2:]
            first = set(first)
            second = set(second)

            for char in first & second:
                total += get_priority(char)

        print(total)


if __name__ == '__main__':
    solve(sys.argv[1])
