import sys

lines = [map(str.strip, line.strip().split('|')) for line in sys.stdin.readlines()]

len_to_digit = { 2: 1, 3: 7, 4: 4, 5: (2, 3, 5), 6: (0, 6, 9), 7: 8 }

s = 0
for _, out_digits in lines:
    for digit in out_digits.split():
        if len_to_digit[len(digit)] in [1, 4, 7, 8]:
            s += 1
print(s)


