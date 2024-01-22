import sys
import math
from collections import deque, Counter
from typing import Callable, Tuple, Deque, List

lcm = 0

def getOp(operation: str) -> Callable[[int, int], int]:
    if operation == '*':
        return lambda a, b: a * b
    elif operation == '+':
        return lambda a, b: a + b


class Monkey:

    def __init__(self, items: Deque[int], operation: str, operand: str, test: int, trueMonkey: int, falseMonkey: int):
        self.items = items
        self.operation = getOp(operation)
        self.operand = operand
        self.test = test
        self.trueMonkey = trueMonkey
        self.falseMonkey = falseMonkey

    
    def addItem(self, item: int):
        self.items.append(item)

    
    def throwItems(self) -> List[Tuple[int, int]]:
        items = list()
        
        while len(self.items) != 0:
            items.append(self.throwItem())

        return items


    def throwItem(self) -> Tuple[int, int]:
        item = self.items.popleft()
        other = item if self.operand == 'old' else int(self.operand)
        item = self.operation(item % lcm, other % lcm)
        item %= lcm
        # item //= 3
        return (self.trueMonkey, item) if item % self.test == 0 else (self.falseMonkey, item)


    def __repr__(self) -> str:
        return '\n'.join([
            f"items: {self.items}",
            f"operation: {self.operand}",
            f"operand: {self.operand}",
            f"test: {self.test}",
            f"true: {self.trueMonkey}",
            f"false: {self.falseMonkey}"
        ])


def solve(filename: str):
    global lcm
    lines = None
    with open(filename, 'r') as file:
        lines = [l.strip() for l in file.readlines()]

    lines = list(filter(lambda x: len(x) != 0, lines))
    monkeys: List[Monkey] = list()

    for i in range(0, len(lines), 6):
        items = deque([int(x.strip()) for x in lines[i + 1].split(':')[1].split(',')])
        operation, operand = lines[i + 2].split(' ')[4:]
        test = int(lines[i + 3].split(' ')[-1])
        trueMonkey = int(lines[i + 4].split(' ')[-1])
        falseMonkey = int(lines[i + 5].split(' ')[-1])

        monkey = Monkey(items, operation, operand, test, trueMonkey, falseMonkey)
        monkeys.append(monkey)

    lcm = math.prod([m.test for m in monkeys])

    rounds = 10000
    inspections = Counter()

    for r in range(rounds):
        for (i, monkey) in enumerate(monkeys):
            items = monkey.throwItems()
            inspections.update({i: len(items)})
            
            for (receiver, item) in items:
                monkeys[receiver].addItem(item)


    print(math.prod([x[1] for x in inspections.most_common(2)]))

if __name__ == '__main__':
    solve(sys.argv[1])
