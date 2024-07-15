#include <iostream>
#include <cctype>
#include <cassert>

using namespace std;

int main()
{
    const char *p = "I Love You!";

    string encrypted;

    while (*p) {
        char en;

        if (islower(*p)) {
            en = (*p + 7);
            if (en > 'z') {
                en = 'a' + en - 'z' - 1;
            }
        }
        else if (isupper(*p)) {
            en = *p - 'A';
            en += 7;
            en %= 26;
            en += 'A';
        }
        else {
            en = *p;
        }

        encrypted.push_back(en);
        p++;
    }

    cout << encrypted << endl;
}
