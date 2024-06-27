#include <iostream>

using namespace std;

int rounded_addition(int a, int b = 0)
{
    auto r = a + b;
    return r;
}

int rounded_addition(double a, double b = 0)
{
    return (int)(a + 0.5) + (int)(b + 0.5);
}

int main()
{
    auto rz = rounded_addition(5, 3);
    cout << "The result is " << rz << endl;

    auto rf = rounded_addition(5.4, (double)3.6);
    cout << "The result is " << rf << endl;
}
