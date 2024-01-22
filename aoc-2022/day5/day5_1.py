import sys
from collections import deque

def solve(filename: str):
    with open(filename, 'r') as file:
        lines = [l.strip('\n') for l in file.readlines()]

        # split by crates and commands
        sidx = lines.index('')

        # find the number of the last stack
        stack_count = int(lines[sidx - 1].strip()[-1])

        # build the staclistks
        stacks = [deque() for _ in range(stack_count)]

        for line in lines[:sidx-1]:
            for i in range(1, len(line), 4):
                value = line[i]
                if value != ' ':
                    stacks[(i - 1) // 4].append(value)
        print(stacks)

        # iterate through all the commands
        for line in lines[sidx + 1:]:
            (move_cnt, src, dest) = [int(i) for i in line.split(' ')[1::2]]
            # print(move_cnt, src, dest)
        
            # execute each command
            for _ in range(move_cnt):
                stacks[dest - 1].appendleft(stacks[src - 1].popleft())

        #print(stacks)

        result = []
        for stack in stacks:
            result.append(stack.popleft())

        print(''.join(result))

if __name__ == '__main__':
    solve(sys.argv[1])
