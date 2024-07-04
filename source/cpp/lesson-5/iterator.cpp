#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

int main()
{
    array<int, 4> primes_10 { 2, 3, 5, 7 };

    for (auto it = begin(primes_10); it != end(primes_10); ++it) {
        cout << *it << endl;
    }

    vector<int> primes { 2, 3, 5, 7, 11 };

    primes.push_back(13);
    primes.push_back(17);
    primes.push_back(19);

    for (auto it = begin(primes); it != end(primes); ++it) {
        cout << *it << endl;
    }

    string hexchars("0123456789ABCDEF");
    for (auto it = begin(hexchars); it != end(hexchars); ++it) {
        cout << *it << endl;
    }
}
