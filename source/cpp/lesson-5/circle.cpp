#include <iostream>
#include <cmath>

using namespace std;

class Rectangle {
    double width, height;

  public:
    // Rectangle 类的构造器（constructor)
    Rectangle(double w, double h) {
        width = w; height = h;
    }

    // Rectangle 类的 perimeter 方法（method)，用于计算周长。
    double perimeter(void) {
        return (width + height) * 2.0;
    }

    // Rectangle 类的 area 方法，用于计算面积。
    double area(void) {
        return width * height;
    }
};

class Circle {
    double radius;

  public:
    // Circle 类的构造器（constructor)
    Circle(double r) {
        radius = r;
    }

    // Circle 类的 perimeter 方法（method)，用于计算周长。
    double perimeter(void) {
        return 2 * M_PI * radius;
    }

    // Circle 类的 area 方法，用于计算面积。
    double area(void) {
        return M_PI * radius * radius;
    }
};

int main()
{
    Rectangle rc_a {20.0, 20.0};
    Rectangle rc_b {20.0, 10.0};
    cout << rc_a.perimeter() << endl;
    cout << rc_b.area() << endl;

    Circle c_a {20.0};
    Circle c_b {10.0};
    cout << c_a.perimeter() << endl;
    cout << c_b.area() << endl;
}

