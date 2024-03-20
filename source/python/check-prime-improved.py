#!/usr/bin/python3

def check_prime(n):
    if n == 2:
        return True, 1

    factor = 1
    for i in range(2, max(n // 2, 3)):
        if n % i == 0:
            factor = i
            break

    if factor > 1:
        return False, factor

    return True, 1

# 单元测试
prime, factor = check_prime(2)
assert(prime is True)
prime, factor = check_prime(3)
assert(prime is True)
prime, factor = check_prime(4)
assert(prime is False)
prime, factor = check_prime(5)
assert(prime is True)
prime, factor = check_prime(9)
assert(prime is False)
prime, factor = check_prime(1973)
assert(prime is True)
prime, factor = check_prime(2024)
assert(prime is False)

n = 1
while n <= 1:
    n = int(input('Please input an integer larger than 1: '))

prime, factor = check_prime(n)
if prime:
    print(f'{n} is a prime!')
else:
    print(f'{n} has a factor neither itself nor one: {factor}; it is not a prime.')

