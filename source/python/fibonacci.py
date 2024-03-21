#!/usr/bin/python3

n = 0
while n <= 0:
    try:
        n = int(input('Please input a positive integer: '))
    except ValueError:
        n = 0

a, b = 0, 1
while a <= n:
    if a == n or b > n:
        print(a, end = '.\n')
    else:
        print(a, end = ', ')
    a, b = b, a + b
