#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> primes { 2, 3, 5, 7 };

    primes.push_back(11);
    primes.push_back(13);
    primes.push_back(17);
    primes.push_back(19);

    for (size_t i = 0; i < primes.size(); i++) {
        cout << primes[i] << endl;
    }

    for (auto it = begin(primes); it != end(primes); ++it) {
        cout << *it << endl;
    }
}
