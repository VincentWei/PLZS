#include <iostream>
#include <cassert>

using namespace std;

bool check_prime(unsigned n)
{
    if (n < 2)
        return false;

    for (unsigned i = 2; i < n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

int main()
{
    assert(check_prime(0) == false);
    assert(check_prime(1) == false);
    assert(check_prime(2) == true);
    assert(check_prime(3) == true);
    assert(check_prime(5) == true);
    assert(check_prime(6) == false);

    unsigned n;
    cin >> n;

    if (check_prime(n)) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }
    // cout << (check_prime(n) ? "True" : "False") << endl;
}

