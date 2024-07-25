/*
 * The answer key for Problem 1 of CPP Lesson 5:
 * <https://courses.fmsoft.cn/plzs/cpp-class-template-and-stl.html#/8>
 *
 * Author: Vincent Wei
 *  - <https://github.com/VincentWei>
 *  - <https://gitee.com/vincentwei7>
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * License: GPLv3
 */
#include <iostream>
#include <cmath>
#include <cfloat>

using namespace std;

bool isclose(double a, double b)
{
    double max_val = fabs(a) > fabs(b) ? fabs(a) : fabs(b);
    return (fabs(a - b) <= max_val * DBL_EPSILON);
}

bool isclosef(float a, float b)
{
    float max_val = fabsf(a) > fabsf(b) ? fabsf(a) : fabsf(b);
    return (fabs(a - b) <= max_val * FLT_EPSILON);
}

bool isclosel(long double a, long double b)
{
    long double max_val = fabsl(a) > fabsl(b) ? fabsl(a) : fabsl(b);
    return (fabsl(a - b) <= max_val * LDBL_EPSILON);
}

bool can_make_a_triangle(double d1, double d2, double d3)
{
    if (d1 < 0 or d2 < 0 or d3 < 0) {
        return false;
    }
    else if (
            (!isclose(d1 + d2, d3) && ((d1 + d2) > d3)) and
            (!isclose(d1 + d3, d2) && ((d1 + d3) > d2)) and
            (!isclose(d2 + d3, d1) && ((d2 + d3) > d1))) {
        return true;
    }

    return false;
}

class Basic2DShape {
  public:
    virtual const char *name() const = 0;
    virtual const char *prompt() const = 0;
    virtual double perimeter() const = 0;
    virtual double area() const = 0;
    virtual void write(ostream &os) const = 0;
    virtual void read(istream &is) = 0;
};

class Rectangle: public Basic2DShape {
    double _w, _h;

  public:
    Rectangle() {
        _w = 0; _h = 0;
    }

    Rectangle(double w, double h) {
        _w = (w > 0) ? w : 0;
        _h = (h > 0) ? h : 0;
    }

    void setWidth(double w) {
        _w = (w > 0) ? w : 0;
    }

    void setHeight(double h) {
        _h = (h > 0) ? h : 0;
    }

    double width() const {
        return _w;
    }

    double height() const {
        return _h;
    }

    virtual const char *name() const {
        return "Rectangle";
    }

    virtual const char *prompt() const {
        return "Please input the lengths of width and height of a rectangle:";
    }

    virtual double perimeter(void) const {
        return (_w + _h) * 2.0;
    }

    virtual double area(void) const {
        return _w * _h;
    }

    virtual void write(ostream &os) const {
        os << "Rectangle (" << _w << " x " << _h << ")";
    }

    virtual void read(istream &is) {
        double w, h;
        is >> w >> h;
        _w = (w > 0) ? w : 0;
        _h = (h > 0) ? h : 0;
    }
};

class Circle: public Basic2DShape {
    double _r;

  public:
    Circle() {
        _r = 0;
    }

    Circle(double r) {
        _r = (r > 0) ? r : 0;
    }

    void setRadius(double r) {
        _r = (r > 0) ? r : 0;
    }

    double radius() const {
        return _r;
    }

    virtual const char *name() const {
        return "Circle";
    }

    virtual const char *prompt() const {
        return "Please input the radius of a circle:";
    }

    virtual double perimeter(void) const {
        return 2.0 * M_PI * _r;
    }

    virtual double area(void) const {
        return M_PI * _r * _r;
    }

    virtual void write(ostream &os) const {
        os << "Circle (" << _r << ")";
    }

    virtual void read(istream &is) {
        double r;
        is >> r;
        _r = (r > 0) ? r : 0;
    }
};

class Square: public Basic2DShape {
    double _a;

  public:
    Square() {
        _a = 0;
    }

    Square(double a) {
        _a = (a > 0) ? a : 0;
    }

    void setSide(double a) {
        _a = (a > 0) ? a : 0;
    }

    double side() const {
        return _a;
    }

    virtual const char *name() const {
        return "Square";
    }

    virtual const char *prompt() const {
        return "Please input the length of the side of a square:";
    }

    virtual double perimeter(void) const {
        return _a * 4;
    }

    virtual double area(void) const {
        return _a * _a;
    }

    virtual void write(ostream &os) const {
        os << "Square (" << _a << ")";
    }

    virtual void read(istream &is) {
        double a;
        is >> a;
        _a = (a > 0) ? a : 0;
    }
};

class Triangle: public Basic2DShape {
    double _a, _b, _c;

  public:
    Triangle() {
        _a = 0; _b = 0; _c = 0;
    }

    Triangle(double a, double b, double c) {
        setSides(a, b, c);
    }

    void setSides(double a, double b, double c) {
        if (can_make_a_triangle(a, b, c)) {
            _a = a; _b = b; _c = c;
        }
        else {
            _a = _b = _c = 0;
        }
    }

    void sides(double &a, double &b, double &c) const {
        a = _a; b = _b; c = _c;
    }

    virtual const char *name() const {
        return "Triangle";
    }

    virtual const char *prompt() const {
        return "Please input the lengths for three sides of a triangle:";
    }

    virtual double perimeter(void) const {
        return (_a + _b + _c);
    }

    virtual double area(void) const {
        double p = (_a + _b + _c) * 0.5;
        return sqrt(p * (p - _a) * (p - _b) * (p - _c));
    }

    virtual void write(ostream &os) const {
        os << "Triangle (" << _a << ", " << _b << ", " << _c << ")";
    }

    virtual void read(istream &is) {
        double a, b, c;
        is >> a >> b >> c;
        setSides(a, b, c);
    }
};

ostream &operator<< (ostream &os, Basic2DShape &rc)
{
    rc.write(os);
    return os;
}

istream &operator>> (istream &is, Basic2DShape &rc)
{
    rc.read(is);
    return is;
}

int main()
{
    Triangle    triangle;
    Circle      circle;
    Square      square;
    Rectangle   rectangle;
    Basic2DShape *shapes[] = { &triangle, &circle, &square, &rectangle };

    size_t nr_shapes = sizeof(shapes)/sizeof(shapes[0]);

    unsigned selected;
    while (true) {
        // 显示菜单
        cout << "To calculate the area, please choose a geometrical shape:" << endl;
        for (size_t i = 0; i < nr_shapes; i++) {
            cout << (i + 1) << ". " << shapes[i]->name() << endl;
        }
        cout << "0. Exit" << endl;

        cin >> selected;

        if (selected == 0) {
            break;
        } else if (selected > nr_shapes) {
            continue;
        }

        selected--;

        Basic2DShape *shape = shapes[selected];
        cout << shapes[selected]->prompt();
        cin >> *shape;
        cout << "The area of your " << shapes[selected]->name() << " is: " << shape->area() << endl;
    }
}

