#include <iostream>
using namespace std;

int addition(int a, int b)
{
    int r;
    r = a + b;
    return r;
}

double addition(double a, double b)
{
    return a + b;
}

int main()
{
    int rz;
    rz = addition(5, 3);
    cout << "The result is " << rz << endl;

    double rf = addition(5.0, (double)3);
    cout << "The result is " << rf << endl;
}
