#include <iostream>
#include <cassert>

using namespace std;

double power(double f, unsigned n)
{
    double r;

    if (n == 0)
        r = 1.0;
    else
        r = f * power(f, n - 1);

    return r;
}

int main()
{
    assert(power(3, 2) == 9);
}

