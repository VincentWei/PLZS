#include <iostream>
#include <cassert>

using namespace std;

unsigned fibonacci(unsigned n)
{
    if (n < 2)
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    unsigned max;
    cin >> max;

    cout << "1, 1";
    unsigned n = 2;
    while (true) {
        unsigned c = fibonacci(n);
        if (c >= max)
            break;

        cout << ", " << c;
        n++;
    }

    cout << "." << endl;
}

