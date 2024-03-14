#!/usr/bin/python3

def is_even_or_odd_0(n):
    if n % 2 == 0:
        return True
    else:
        if n % 2 == 1:
            return False

def is_even_or_odd_1(n):
    if n % 2 == 0:
        return True
    elif n % 2 == 1:
        return False

def is_even_or_odd_2(n):
    if n % 2 == 0:
        return True
    else:
        return False

def is_even_or_odd_3(n):
    if n % 2 == 0:
        return True

    return False

def is_even_or_odd_4(n):
    if n % 2:
        return False

    return True

def is_even_or_odd_best(n):
    n = int(n)
    return n % 2 == 0

# 直接对比浮点数会得到不正确的结果
def can_make_a_triangle_bad(d1, d2, d3):
    if (d1 <= 0 or d2 <= 0 or d3 <= 0):
        return False
    elif ((d1 + d2) > d3) and ((d1 + d3) > d2) and ((d2 + d3) > d1):
        return True
    else:
        return False

# 折中方案
def can_make_a_triangle_workaround(d1, d2, d3):
    if (d1 > 10000 or d2 > 10000 or d3 > 10000):
        return "<BadValue>"

    if (d1 <= 0 or d2 <= 0 or d3 <= 0):
        return False

    d1 = int(d1 * 10000)
    d2 = int(d2 * 10000)
    d2 = int(d3 * 10000)

    if ((d1 + d2) > d3) and ((d1 + d3) > d2) and ((d2 + d3) > d1):
        return True
    else:
        return False

def day_of_week(weekday):
    match weekday:
        case 0:
            return "Sunday"
        case 1:
            return "Monday"
        case 2:
            return "Tuesday"
        case 3:
            return "Wednesday"
        case 4:
            return "Thursday"
        case 5:
            return "Friday"
        case 6:
            return "Saturday"
        case _:
            return "<Wrong Weekday Value>"

    return "<NeverGetHere>"

def is_prime(n):
    n = int(n)

    if n < 2:
        return "<BadValue>"
    elif n > 10:
        return "<IDontKnow>"

    match n:
        case 3 | 5 | 7:
            return True

    return False

def list_even_numbers_less_than_0(n):
    n = int(n)
    a = 0
    while a < n:
        if a % 2 == 0:
            print(a)
        a = a + 1

def list_even_numbers_less_than_1(n):
    n = int(n)
    a = 0
    flag = True
    while True:
        if a >= n:
            break

        if flag:
            print(a)

        a = a + 1
        flag = not flag

def list_even_numbers_less_than_2(n):
    n = int(n)
    for a in range(0, n, 2):
        print(a)

def list_even_numbers_less_than_3(n):
    n = int(n // 2)
    for a in range(n):
        print(a * 2)

print(is_even_or_odd_4(6))
print(is_even_or_odd_4(5))

list_even_numbers_less_than_3(10)

print(is_even_or_odd_best(5.6))
print(is_even_or_odd_best(1.2))
print(is_even_or_odd_best(1))
print(is_even_or_odd_best(2))

print(can_make_a_triangle_bad(0.2, 0.1, 0.3))
print(can_make_a_triangle_workaround(0.2, 0.1, 0.3))

print(day_of_week(1))
print(is_prime(0))
print(is_prime(5.6))

