#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string digits;
    cin >> digits;

    for (size_t i = 0; i < digits.length(); i++) {
        char c = digits[i];
        if (isdigit(c)) {
#if 0
            // This will print the integer values of characters.
            cout << '0' + '9' - c;
#else
            c = '0' + '9' - c;
            cout << c;
#endif
        }
    }

    cout << endl;
}

