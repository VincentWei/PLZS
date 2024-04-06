#!/usr/bin/python3

def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n - 1)

n = -1
while n < 0:
    try:
        n = int(input('Please input a positive integer: '))
    except ValueError:
        n = -1

print(f'The factorial of {n} is:', factorial(n))
