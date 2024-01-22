import sys

def solve(filename: str):
    with open(filename, 'r') as file:
        lines = [l.strip() for l in file.readlines()]

        cmax = 0
        gmax1 = 0
        gmax2 = 0
        gmax3 = 0
        for l in lines:
            if l.isnumeric():
                cmax += int(l)
            else:
                if cmax > gmax1:
                    cmax, gmax1 = gmax1, cmax
                if cmax > gmax2: 
                    cmax, gmax2 = gmax2, cmax
                if cmax > gmax3:
                    gmax3 = cmax
                cmax = 0

        if cmax > gmax1:
            cmax, gmax1 = gmax1, cmax
        if cmax > gmax2: 
            cmax, gmax2 = gmax2, cmax
        if cmax > gmax3:
            gmax3 = cmax
                
        print(gmax1 + gmax2 + gmax3)

if __name__ == '__main__':
    solve(sys.argv[1])
