#include <iostream>
#include <cassert>

using namespace std;

int main()
{
    unsigned max;
    cin >> max;

    unsigned a = 1, b = 1;

    cout << "1, 1";
    while (true) {
        unsigned c = a + b;
        if ((a + b) >= max)
            break;

        cout << ", " << c;
        a = b;
        b = c;
    }

    cout << "." << endl;
}

