#include <iostream>

using namespace std;

class Rectangle {
    double _w, _h;

  public:
    Rectangle(): _w(0), _h(0) {
        std::cout << "The default constructor called" << endl;
    }

    Rectangle(double w, double h) {
        _w = w; _h = h;
    }

    ~Rectangle() {
        std::cout << "The destructor called" << endl;
    }

    void setWidth(double w) {
        _w = w;
    }

    void setHeight(double h) {
        _h = h;
    }

    double width() const {
        return _w;
    }

    double height() const {
        return _h;
    }

    double perimeter(void) {
        return (_w + _h) * 2.0;
    }

    double area(void) {
        return _w * _h;
    }
};

ostream &operator<< (ostream &os, Rectangle &rc)
{
    os << "Rectangle (" << rc.width() << " x " << rc.height() << ")";
    return os;
}

istream &operator>> (istream &is, Rectangle &rc)
{
    double w, h;

    is >> w >> h;

    rc.setWidth(w);
    rc.setHeight(h);
    return is;
}

Rectangle global_rc;

int foo()
{
    Rectangle rc;

    {
        Rectangle rc;
    }

    return 0;
}

int main()
{
    foo();

    Rectangle rc {20.0, 30.0};
    cout << "Perimter: " << rc.perimeter() << endl;
    cout << "Area: " << rc.area() << endl;

    Rectangle rc_b;
    double w, h;
    cin >> w >> h;
    rc_b.setWidth(w);
    rc_b.setHeight(h);

    cout << "Perimter of " << rc_b << ": " << rc_b.perimeter() << endl;
    cout << "Area of " << rc_b << ": " << rc_b.area() << endl;

    Rectangle rc_c;
    cin >> rc_c;
    cout << "Perimter of " << rc_c << ": " << rc_c.perimeter() << endl;
    cout << "Area of " << rc_c << ": " << rc_c.area() << endl;

    std::cout << "The program is exiting..." << endl;
    return 0;
}

