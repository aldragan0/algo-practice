import sys

numbers = list(map(lambda x: x.strip(), sys.stdin.readlines()))

freq = [0] * len(numbers[0])

for i in range(len(numbers[0])):
    for nr in numbers:
        if (nr[i] == '1'):
            freq[i] += 1

gamma = 0
epsilon = 0

for i in range(len(freq) - 1, -1, -1):
    if (freq[i] > len(numbers) - freq[i]):
        gamma += 2 ** (len(freq) - i - 1)
    else:
        epsilon += 2 ** (len(freq) - i - 1)

print(epsilon * gamma)

