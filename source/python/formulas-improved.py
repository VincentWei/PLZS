#!/usr/bin/python3

"""
学到新技能：
1. 块注释。
1. print() 函数中使用格式化字符串。
"""

def perimeter_of_square(d):
    return d * 4

def area_of_square(d):
    return d * d

def prompt_for_square():
    d = float(input("即将计算正方形周长与面积，请输入正方形边长："))
    c = perimeter_of_square(d)
    s = area_of_square(d)
    print(f"正方形周长为 {c}", end = '; ')
    print(f"正方形面积为 {s}", end = '.\n')

prompt_for_square()
prompt_for_square()
