#include <iostream>

using namespace std;

int rounded_addition(int a, int b = 0)
{
    int r;
    r = a + b;
    return r;
}

int rounded_addition(double a, double b = 0)
{
    return (int)(a + 0.5) + (int)(b + 0.5);
}

int main()
{
    int a, b;
    cout << "Please input two integers: ";
    cin >> a >> b;

    auto rz = rounded_addition(a, b);
    cout << "The result is " << rz << endl;

    double c, d;
    cout << "Please input two floats: ";
    cin >> c >> d;
    auto rf = rounded_addition(c, d);
    cout << "The result is " << rf << endl;
}
