#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>

using namespace std;

string decimal_in_different_base(intmax_t decimal, int base)
{
    static const char *digits = "0123456789abcdefghijklmnopqrstuvwxyz";

    bool sign = false;
    if (decimal < 0) {
        sign = true;
        decimal = -decimal;
    }

    string ans;

    do {
        lldiv_t result;
        result = lldiv(decimal, base);

        char digit;
        if (result.rem >= 0) {
            digit = digits[result.rem];
        }
        else {
            result.quot++;
            result.rem -= base;
            digit = digits[result.rem];
        }

        ans.push_back(digit);

        decimal = result.quot;
    } while (decimal != 0);

    if (sign)
        ans.push_back('-');

#if 1
    reverse(ans.begin(), ans.end());
#else
    size_t len = ans.length();
    for (size_t i = 0; i < len / 2; i++) {
        char tmp = ans[i];
        ans[i] = ans[len - i - 1];
        ans[len - i - 1] = tmp;
    }
#endif

    return ans;
}

int main()
{
    long long decimal;
    int base;
    cin >> decimal >> base;

    // check base
    if (!((base >= 2 && base <= 36) || (base <= -2 && base >= -36)))
        return 1;

    string ans = decimal_in_different_base(decimal, base);
    cout << ans << endl;

    if (base >= 2 && base <= 36) {
        long long ll = strtoll(ans.c_str(), NULL, base);
        assert(ll == decimal);
    }
}

