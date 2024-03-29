#!/usr/bin/python3

def my_range(start, stop = None, step = None):
    if not isinstance(start, int):
        raise(ValueError)

    if stop is None:
        stop = start
        start = 0
    elif not isinstance(stop, int):
        raise(ValueError)

    if step is None:
        if stop > start:
            step = 1
        else:
            step = -1
    elif not isinstance(step, int) or step == 0:
        raise(ValueError)

    if stop > start and step < 0:
        raise(ValueError)
    elif stop < start and step > 0:
        raise(ValueError)

    i = start
    if step > 0:
        while i < stop:
            yield i
            i += step
        else:
            pass
    else:
        while i > stop:
            yield i
            i += step
        else:
            pass

positive_cases = [
    { 'args': (0, None, None), 'result': [] },
    { 'args': (5, None, None), 'result': [0, 1, 2, 3, 4] },
    { 'args': (-5, None, None), 'result': [0, -1, -2, -3, -4] },
    { 'args': (2, 2, None), 'result': [] },
    { 'args': (2, 10, None), 'result': [2, 3, 4, 5, 6, 7, 8, 9] },
    { 'args': (2, 10, 1), 'result': [2, 3, 4, 5, 6, 7, 8, 9] },
    { 'args': (2, 10, 2), 'result': [2, 4, 6, 8] },
    { 'args': (0, -10, -2), 'result': [0, -2, -4, -6, -8] },
]

i = 0
for case in positive_cases:
    print(f'case {i}: ', end = '')
    l = list(my_range(case['args'][0], case['args'][1], case['args'][2]))
    assert(l == case['result'])
    print('passed.')
    i += 1

for x in my_range(7):
    print(x)

f = my_range(0, 10, 2)
print(f)
for x in f:
    print(x)

