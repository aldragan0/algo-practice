import sys
from collections import deque

def makeList(value: str) -> list:
    st = list()

    for (i, c) in enumerate(value):
        if value[i].isnumeric():
            start = end = i
            while value[end].isnumeric():
                end += 1
            item = int(value[start:end])
            st.append(item)
        elif value[i] == ',':
            continue
        elif value[i] == '[':
            st.append(value[i])
        elif value[i] == ']':
            sl = deque()
            while st[-1] != '[':
                sl.appendleft(st.pop())
            st.pop()
            st.append(list(sl))

    return st.pop()


def rightOrder(first: list, second: list) -> bool:
    l = min(len(first), len(second))

    for i in range(l):
        if isinstance(first[i], list):
            if isinstance(second[i], list):
                order = rightOrder(first[i], second[i])
                if order is None:
                    continue
                return order
            if isinstance(second[i], int):
                order = rightOrder(first[i], [second[i]])
                if order is None:
                    continue
                return order
        if isinstance(first[i], int):
            if isinstance(second[i], list):
                order = rightOrder([first[i]], second[i])
                if order is None:
                    continue
                return order
            if isinstance(second[i], int):
                if second[i] == first[i]:
                    continue
                return second[i] > first[i]

    return None if len(first) == len(second) else len(second) > len(first)


def solve(filename: str):
    lines = None
    with open(filename, 'r') as file:
        lines = [l.strip() for l in file.readlines()]

    s = 0

    first = [[2]]
    second = [[6]]

    g = [first, second]
    for (idx, i) in enumerate(range(0, len(lines), 3), 1):
        g.append(makeList(lines[i]))
        g.append(makeList(lines[i + 1]))

    for i in range(len(g) - 1):
        for j in range(i, len(g)):
            if not rightOrder(g[i], g[j]):
                g[i], g[j] = g[j], g[i]

    f1 = g.index(first) + 1
    f2 = g.index(second) + 1

    print(f1 * f2)


if __name__ == '__main__':
    solve(sys.argv[1])
