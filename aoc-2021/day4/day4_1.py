import re
import sys
import math

boards = list()

data = sys.stdin.readlines()

numbers = map(int, data[0].strip().split(','))

num_boards = (len(data) - 1 - (len(data) - 1) // 6) // 5

for i in range(num_boards):
    current_board = dict()
    start = 6 * i + 2

    for j, row in enumerate(range(start, start + 5)):
        for k, num in enumerate(re.sub(r'[ ]{2,}', r' ', data[row].strip()).split()):
            current_board[int(num)] = 5 * j + (k + 1)

    boards.append(current_board)
                
                # row    , col
board_indices = [([0] * 5, [0] * 5) for i in range(num_boards)]

found = False
number = -1
current_board = -1

for nr in numbers:
    for board_id, board in enumerate(boards):
        if nr in board:
            idx = board[nr]
            board[nr] = 0

            col_id = (idx - 1) % 5
            row_id = int(math.ceil(idx / 5)) - 1
            
            indices = board_indices[board_id]
            indices[0][row_id] += 1
            indices[1][col_id] += 1
            

            if indices[0][row_id] == 5 or\
                    indices[1][col_id] == 5:
                
                found = True
                current_board = board_id
                break

    if found:
        number = nr
        break

s = 0
for k, v in boards[current_board].items():
    if v != 0:
        s += k

print(s * number)

