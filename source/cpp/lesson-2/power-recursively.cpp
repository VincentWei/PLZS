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
    // 使用 assert 测试 power() 函数的正确性
    assert(power(3, 0) == 1);
    assert(power(3, 2) == 9);
    assert(power(-3, 3) == -27);

    double d;
    unsigned n;
    cin >> d >> n;

    cout << power(d, n) << endl;
}

