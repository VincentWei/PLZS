#!/bin/python3

def area_of_square(a):
    return a ** 2

def area_of_triangle(a, h):
    return a * h / 2

s = area_of_triangle(5, 10) + area_of_square(10)
print(s)
