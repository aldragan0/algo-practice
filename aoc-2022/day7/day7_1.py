import sys
from collections import deque


class Node:
    def __init__(self, name, path, size, parent):
        self.name = name
        self.path = path
        self.parent = parent
        self.type = 'd' if size == 0 else 'f'
        self.size = size
        self.children = []

    def __repr__(self):
        return f'({self.name}, {self.size}, {self.path}, {self.children})'


def create_filesystem(lines):
    idx = 1
    parent = Node('/', '', 0, None)

    while idx < len(lines):
        line = lines[idx]

        if line.startswith('$ cd'):
            dest = line.split(' ')[2]
            if dest == '..':
                parent = parent.parent
            else:
                child = next(filter(lambda x: x.name == dest, parent.children))
                parent = child

        elif line.startswith('dir'):
            dirname = line.split(' ')[1]
            curr = Node(dirname, '/'.join([parent.path, dirname]), 0, parent)
            parent.children.append(curr)

        elif not line.startswith('$ ls'):
            (size, name) = line.split(' ')
            curr = Node(name, '/'.join([parent.path, name]), int(size), parent)
            parent.children.append(curr)

        idx += 1

    while parent.parent != None:
        parent = parent.parent

    return parent


def solve(filename: str):
    lines = None
    with open(filename, 'r') as file:
        lines = [l.strip() for l in file.readlines()]

    root = create_filesystem(lines)

    q = deque([root])
    visited = set()
    dirs = dict()

    while len(q) != 0:
        curr = q.popleft()

        if curr.size != 0:
            if curr.type == 'd':
                dirs[curr.path] = curr.size
            if curr.parent != None:
                curr.parent.size += curr.size

        if curr.path not in visited:
            if curr.type == 'd':
                q.appendleft(curr)
            visited.add(curr.path)
        else:
            continue

        for ch in curr.children:
            if ch.path in visited:
                continue
            q.appendleft(ch)

    print(sum(filter(lambda x: x <= 100000, dirs.values())))
    print()

    ## part 2 ##
    total_space = 70000000
    required_space = 30000000

    free_space = total_space - dirs['']
    to_delete = required_space - free_space
    print(min(filter(lambda x: x >= to_delete, dirs.values())))

if __name__ == '__main__':
    solve(sys.argv[1])
