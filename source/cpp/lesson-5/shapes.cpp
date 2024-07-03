#include <iostream>

using namespace std;

class Basic2DShape {
  public:
    virtual double perimeter(void) = 0;
    virtual double area(void) = 0;
    virtual void write(ostream &os) = 0;
    virtual void read(istream &is) = 0;
};

class Rectangle: public Basic2DShape {
    double _w, _h;

  public:
    Rectangle() {
        _w = 0; _h = 0;
    }

    Rectangle(double w, double h) {
        _w = w; _h = h;
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

    virtual double perimeter(void) {
        return (_w + _h) * 2.0;
    }

    virtual double area(void) {
        return _w * _h;
    }

    virtual void write(ostream &os) {
        os << "Rectangle (" << _w << " x " << _h << ")";
    }

    virtual void read(istream &is) {
        is >> _w >> _h;
    }
};

class Circle: public Basic2DShape {
    double _r;

  public:
    Circle() {
        _r = 0;
    }

    Circle(double r) {
        _r = r;
    }

    void setRadius(double r) {
        _r = r;
    }

    double radius() const {
        return _r;
    }

    virtual double perimeter(void) {
        return 2.0 * M_PI * _r;
    }

    virtual double area(void) {
        return M_PI * _r * _r;
    }

    virtual void write(ostream &os) {
        os << "Circle (" << _r << ")";
    }

    virtual void read(istream &is) {
        is >> _r;
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

    Circle circle;
    cin >> circle;
    cout << "Perimter of " << circle << ": " << circle.perimeter() << endl;
    cout << "Area of " << circle << ": " << circle.area() << endl;
}

