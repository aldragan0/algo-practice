import sys

def solve(filename: str):
    with open(filename, 'r') as file:
        lines = [l.strip() for l in file.readlines()]

        cmax = 0
        gmax = 0
        for l in lines:
            if l.isnumeric():
                cmax += int(l)
            else:
                gmax = max(gmax, cmax)
                cmax = 0
        print(gmax)

if __name__ == '__main__':
    solve(sys.argv[1])
