#!/usr/bin/python3

lines = [
    'line 1\n',
    'line 2\n',
    'line 3\n',
]

with open('sample.txt', 'w') as f:
    f.writelines(lines)
assert(f.closed)

with open('sample.txt', 'r') as f:
    for line in f:
        print(line, end='')
    f.seek(0)
    lines = f.readlines()
    for line in lines:
        print(line, end='')
assert(f.closed)
