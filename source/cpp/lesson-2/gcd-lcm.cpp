#include <iostream>
#include <cassert>

using namespace std;

unsigned gcd_r(unsigned a, unsigned b)
{
    if (b == 0)
        return a;
    return gcd_r(b, a % b);
}

unsigned gcd_l(unsigned a, unsigned b)
{
    while (b != 0) {
        unsigned tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}

int main()
{
    assert(gcd_l(1, 0) == 1);
    assert(gcd_l(2, 3) == 1);
    assert(gcd_l(2, 4) == 2);
    assert(gcd_l(24, 36) == 12);

    assert(gcd_r(1, 0) == 1);
    assert(gcd_r(2, 3) == 1);
    assert(gcd_r(2, 4) == 2);
    assert(gcd_r(24, 36) == 12);

    unsigned n1, n2;
    cin >> n1 >> n2;

    unsigned gcd = gcd_l(n1, n2);
    unsigned lcm = n1 * n2 / gcd;

    cout << gcd << " " << lcm << endl;
}

