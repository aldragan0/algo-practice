import sys

lines = [line.strip().split('|') for line in sys.stdin.readlines()]

len_to_digits = { 2: 1, 3: 7, 4: 4, 5: (2, 3, 5), 6: (0, 6, 9), 7: 8 }
digit_to_set = dict()

s = 0
for in_digits, out_digits in lines:
    six_segment = list()
    others = list()

    for digit in in_digits.strip().split():
        match = len_to_digits[len(digit)]
        if type(match) is not tuple:
            digit_to_set[match] = set(digit)
        elif len(digit) == 6: # (0, 6, 9)
            six_segment.append(set(digit))
        else:
            others.append(set(digit))

    for digit in six_segment:
        if len(digit_to_set[4].intersection(digit)) == 4:
            digit_to_set[9] = digit
        elif len(digit_to_set[1].intersection(digit)) == 2:
            digit_to_set[0] = digit
        else:
            digit_to_set[6] = digit

    for digit in others:
        if len(digit_to_set[6].intersection(digit)) == 5:
            digit_to_set[5] = digit
        elif len(digit_to_set[1].intersection(digit)) == 2:
            digit_to_set[3] = digit
        else:
            digit_to_set[2] = digit

    value = 0
    for idx, digit in enumerate(out_digits.strip().split()):
        match = len_to_digits[len(digit)]
        digit_set = set(digit)

        if type(match) is not tuple:
            result = match
        else:
            for k, v in map(lambda x: (x, digit_to_set[x]), match):
                if v == digit_set:
                    result = k
                    break

        value += result * 10 ** (4 - (idx + 1))
    s += value

print(s)

