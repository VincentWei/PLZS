/*
 * One example for NOI CSP-J Lesson 2:
 * <https://courses.fmsoft.cn/plzs/noijunior-sort-algorithms.html>
 *
 * Author: Vincent Wei
 *  - <https://github.com/VincentWei>
 *  - <https://gitee.com/vincentwei7>
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * License: GPLv3
 */
#include <iostream>     // for cin and cout

using namespace std;

class Rectangle {
    // 该静态成员变量可用于统计 Rectangle 实例的个数。
    // 注意：
    // 下面这条语句只是声明了该静态成员变量，
    // 在使用前，还必须在 C++ 源文件中显式定义这一静态成员变量。
    static unsigned _nr_rectangles;

    double width, height;

  public:
    // Rectangle 类的构造器（constructor)
    Rectangle(double width, double height) {
        _nr_rectangles++;

        this->width = width;
        this->height = height;
    }

    // Rectangle 类的析构函数（denstructor)
    ~Rectangle() {
        _nr_rectangles--;
    }

    /* 我们可以认为 C++ 编译器为非静态成员函数传入了调用该成员函数时
       对应的那个类对象的指针，而该指针作为一个隐式的形参存在，
       其名称为 `this`：

        double area(Rectangle *this) {
            return this->width * this->height;
        }
     */
    // Rectangle 类的 area 方法，用于计算面积。
    double area() {
        return this->width * this->height;
    }

    /* 为方便书写，在不引起歧义的情形下，在成员函数中无需使用 this
       来引用当前类的成员函数或者成员变量。
     */
    // Rectangle 类的 perimeter 方法（method)，用于计算周长。
    double perimeter() {
        return (width + height) * 2.0;
    }

    // 在静态成员函数中，只能访问静态成员变量，不能使用 this 指针。
    static unsigned quantity() {
        return _nr_rectangles;
    }
};

// 必须在 C++ 源文件中显式定义类的静态成员变量
unsigned Rectangle::_nr_rectangles;

int main()
{
    // 使用 new/delete 创建/销毁一个类对象
    Rectangle *rc = new Rectangle { 20.0, 20.0 };

    // 调用静态成员函数时，不需要通过某个特定的类对象
    cout << Rectangle::quantity() << endl;

    cout << rc->area() << endl;

    delete rc;

    cout << Rectangle::quantity() << endl;
}

