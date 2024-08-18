#include <iostream>
#include <cassert>

bool is_narcissus(unsigned candidant, int n)
{
    unsigned int t = candidant;
    unsigned int sum = 0;

    do {
        unsigned int d = t % 10;
        unsigned power = d;

        int j = 1;
        while (j < n) {
            power *= d;
            j++;
        }

        sum += power;
        t /= 10;
    } while (t > 0);

    if (sum == candidant) {
        return true;
    }

    return false;
}

using namespace std;

int main()
{
    assert(is_narcissus(153, 3));

    unsigned nr_digits;
    cin >> nr_digits;

    unsigned start_number = 1;
    for (unsigned i = 1; i < nr_digits; i++) {
        start_number *= 10;
    }

    for (unsigned n = start_number; n < start_number * 10; n++) {
        if (is_narcissus(n, nr_digits)) {
            cout << n << endl;
        }
    }
}

