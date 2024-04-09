#!/usr/bin/python3

def make_indent(n):
    s = ''
    for x in range(n):
        s += ' '
    return s

def my_pow(f, n, i = 0):
    indent = make_indent(i)
    print('{3}Call #{0}: my_power({1}, {2})'.format(i, f, n, indent))
    if n == 0:
        r = 1
    else:
        r = f * my_pow(f, n - 1, i + 1)

    print('{2}Return {1} for Call #{0}'.format(i, r, indent))
    return r

print('The value of 2 raised to the power of 8 is', my_pow(2, 8))
