#include <iostream>
#include <cmath>

using namespace std;

double square_area(double a)
{
    return a * a;
}

double circle_area(double r)
{
    return M_PI * r * r;
}

double triangle_area(double a, double b, double c)
{
    double p = (a + b + c) / 2;
    return sqrt(p * (p -a) * (p - b) * (p - c));
}

int main()
{
    double a;

    cout << "To calculate the area of a square, please input the length of one side: ";
    cin >> a;
    cout << "area_of_square(" << a << "): " << square_area(a) << endl;

    cout << "To calculate the area of a circle, please input the length of the radius: ";
    cin >> a;
    cout << "area_of_circle(" << a << "): " << circle_area(a) << endl;

    double b, c;
    cout << "To calculate the area of a triangle, please input the lengthes of three sides (separated with space): ";
    cin >> a >> b >> c;
    cout << "area_of_triangle(" << a << ", " << b << ", " << c << "): " << triangle_area(a, b, c) << endl;
}
