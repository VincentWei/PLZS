#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<int, 6> primes { 2, 3, 5, 7, 11, 13 };

    for (size_t i = 0; i < primes.size(); i++) {
        cout << primes[i] << endl;
    }

    for (auto it = begin(primes); it != end(primes); ++it) {
        cout << *it << endl;
    }
}
