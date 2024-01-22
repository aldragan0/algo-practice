import sys

def solve(filename: str):
    lines = None
    with open(filename, 'r') as file:
        lines = [l.strip() for l in file.readlines()]



if __name__ == '__main__':
    solve(sys.argv[1])
