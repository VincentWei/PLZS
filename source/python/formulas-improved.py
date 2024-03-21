#!/usr/bin/python3

def area_of_square(d):
    return d * d

def prompt_for_square():
    d = 0
    while d <= 0:
        d = float(input("Please input the length of one side of a square: "))

    s = area_of_square(d)
    print(f"The area of the square is {s}")

def area_of_triangle(d, h):
    return d * h / 2

def prompt_for_triangle():
    d = h = 0
    while d <= 0 or h <= 0:
        try:
            d = float(input("Please input the length of one side of a triangle: "))
            h = float(input("Please input the length of the height on the side: "))
        except ValueError:
            d = h = 0

    s = area_of_triangle(d, h)
    print(f"The area of the triangle is {s}")

def area_of_circle(r):
    return 3.14159265 * r * r

def prompt_for_circle():
    r = 0
    while r <= 0:
        try:
            r = float(input("Please input the length of one side of a circle: "))
        except ValueError:
            r = 0

    s = area_of_circle(r)
    print(f"The area of the circle is {s}")

def prompt_for_formula():
    formula = 4
    while formula < 0 or formula > 3:
        print('To calculate the area, please choose a geometrical shape:')
        print('1. Triange')
        print('2. Square')
        print('3. Circle')
        print('0. Exit')
        try:
            formula = int(input('Your choice:'))
        except:
            formula = 0

    return formula

while True:
    match prompt_for_formula():
        case 1:
            prompt_for_triangle()
        case 2:
            prompt_for_square()
        case 3:
            prompt_for_circle()
        case _:
            quit()

