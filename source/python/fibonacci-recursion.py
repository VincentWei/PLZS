#!/usr/bin/python3

def fibonacci(n):
   if n <= 1:
       return n
   else:
       return fibonacci(n - 1) + fibonacci(n - 2)

mx = 0
while mx <= 0:
    try:
        mx = int(input('Please input a positive integer: '))
    except ValueError:
        mx = 0

print(f"The Fibonacci numbers less than {mx}:")

for i in range(mx):
    a = fibonacci(i)
    b = fibonacci(i + 1)
    if a >= mx or b >= mx:
        print(a, end = '.\n')
        break
    else:
        print(a, end = ', ')
