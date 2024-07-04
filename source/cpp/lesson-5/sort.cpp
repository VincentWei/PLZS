#include <iostream>
#include <string>
#include <algorithm>    // std::shuffle and std::sort
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock

using namespace std;

bool islessthan(char c1, char c2)
{
    return c1 < c2;
}

int main()
{
    string hexchars("0123456789ABCDEF");

    // obtain a time-based seed:
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(hexchars.begin(), hexchars.end(), default_random_engine(seed));
    cout << hexchars << endl;

    sort(hexchars.begin(), hexchars.end(), islessthan);

    cout << hexchars << endl;
}
