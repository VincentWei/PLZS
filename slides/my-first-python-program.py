#!/usr/bin/python3

# 计算正方形面积的函数
def area_of_square(a):
    return a ** 2

# 计算三角形面积的函数
def area_of_triangle(a, h):
    return a * h / 2

# 默认变量（_）在解释器模式中不可用
# area_of_triangle(5, 10) + area_of_square(10)
# print(_)

s = area_of_triangle(5, 10) + area_of_square(10)
print(s)
