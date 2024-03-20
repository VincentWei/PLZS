#!/usr/bin/python3

n = 2
while n <= 2:
    n = int(input('Please input an integer larger than 2: '))

for i in range(2, max(n // 2, 3)):
    if n % i == 0:
        print(f'{n} equals to {i} * { int(n / i)}; it is not a prime.')
        break
else:
    print(f'{n} is a prime!')
