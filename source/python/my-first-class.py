#!/usr/bin/python3

class Circle(object):           # `object` 是 Python 基类（base class）或父类（parent class）
    pi = 3.14159265             # pi 是类属性，对所有类的实例只有一个副本

    def __init__(self, r):
        self.r = r              # 实例属性，每个类的实例均有自己的副本

    def perimeter(self):
        return 2. * self.pi * self.r

    def area(self):
        return self.pi * self.r * self.r

    def __str__(self):
        return 'A circle with a radius of ' + str(self.r) + '.'


c = Circle(1.0)     # 解释器会创建一个 Circle 对象并调用 Circle 类的 __init__() 方法。
s = c.area()        # 调用 Circle 对象的 area 方法；此时将使用类属性 pi 的默认值进行计算。
                    # 解释器会将 c 作为第一个参数传入 Circle 类的 `area` 函数。
print(c, "Its area is", s)

import math
Circle.pi = math.pi # 使用 math 模块中的 pi 常量覆盖类属性 pi 的值。
s = c.area()        # 调用 Circle 对象的 area 方法；此时将使用修改后的类属性 pi 的默认值进行计算。
                    # 解释器会将 c 作为第一个参数传入 Circle 类的 `area` 函数。
c1 = Circle(1.0)
s = c1.area()
print(c, "Its area is", s)

