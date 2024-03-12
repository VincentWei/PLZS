#!/usr/bin/python3

def perimeter_of_square(d):
    return d * 4

def area_of_square(d):
    return d ** 2

d = float(input('将计算正方形的周长和面积，请输入正方形的边长：'))
c = perimeter_of_square(d)
print('perimeter_of_square(', d, '): ', c)

a = area_of_square(d)
print('area_of_square(', d, '): ', c)

def area_of_triangle(d, h):
   return d * h /2

d = float(input('将计算三角形的面积，请输入三角形底边的长：'))
h = float(input('再输入这个底边对应的高：'))

a = area_of_triangle(d, h)
print('area_of_triangle(', d, ',', h, '): ', a)

