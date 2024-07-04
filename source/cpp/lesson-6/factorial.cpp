#include <iostream>
#include <cstdint>
#include <cassert>

using namespace std;

uint64_t factorial(uint64_t n)
{
    if (n > 1) {
        return n * factorial(n - 1);
    }

    return 1;
}

int main()
{
    assert(factorial(3) == 6);

    uint64_t n = 0;
    uint64_t last = 1;
    while (++n) {
        uint64_t r = factorial(n);
        if (r / last != n) {
            cout << n << "! = Overflow" << endl;
            break;
        }

        last = r;
        cout << n << "! = " << last << endl;
    }
}

