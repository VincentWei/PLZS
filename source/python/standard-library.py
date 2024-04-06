#!/usr/bin/python3

import sys

result = 10
print("The result is: ", result, sep='')

def my_print(*t):
    for x in t:
        s = str(x)
        for c in s:
            sys.stdout.write(c)

    sys.stdout.write('\n')

my_print("The result is: ", result)

d1 = dict(name='Vincent', weight=68, age=50)

def my_dict(**kws):
    '''return kws'''

    d = {}
    for k in kws:
        d[k] = kws[k]
    return d

d2 = dict(name='Vincent', weight=68, age=50)
assert(d1 == d2)
