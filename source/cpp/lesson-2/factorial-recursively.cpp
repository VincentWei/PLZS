#include <iostream>
#include <cassert>

using namespace std;

unsigned factorial(unsigned n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int main()
{
    unsigned n;
    cin >> n;
    cout << factorial(n) << endl;
}

