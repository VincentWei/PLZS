#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>

using namespace std;

long long mypower(long long base, unsigned exp)
{
    int r = 1;

    while (exp--) {
        r *= base;
    }

    return r;
}

long long mystrtoll(const char *str, int base)
{
    const char *start = str;

    while (*str) {
        str++;
    }

    long long ans = 0;
    unsigned exp = 0;

    str--;
    while (str >= start) {
        long long v = 0;
        char ch = *str;
        if (isdigit(ch)) {
            v = ch - '0';
        }
        else if (islower(ch)) {
            v = ch - 'a' + 10;
        }
        else if (isupper(ch)) {
            v = ch - 'A' + 10;
        }

        ans += v * mypower(base, exp);
        exp++;
        str--;
    }

    return ans;
}

int main()
{
    assert(strtoll("1100", NULL, 2) == mystrtoll("1100", 2));
    assert(strtoll("12ABCD", NULL, 16) == mystrtoll("12ABCD", 16));

    string digits;
    int base;
    cin >> digits >> base;

    long long ans = mystrtoll(digits.c_str(), base);
    cout << ans << endl;
}

