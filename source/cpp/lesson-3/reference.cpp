#include <iostream>

using namespace std;

int addition(const int &a, const int &b)
{
    return a + b;
}

int &addition(int &r, const int &a, const int &b)
{
    r = a + b;
    return r;
}

int main()
{
    int a;
    int &b = a;

    b = 5;
    cout << a << endl;

    b = addition(a, b);
    cout << a << endl;

    int c = addition(b, a, b);
    cout << a << endl;
    cout << c << endl;
}

