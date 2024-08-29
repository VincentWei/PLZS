/*
 * The program implementation the high precision division with remainder.
 *
 * This program is a part of PLZS (the Programming Lessons for
 * Zero-based Students Aged 10+) project.
 * For more information about PLZS, please visit:
 *
 *  - <https://github.com/VincentWei/PLZS>
 *  - <https://gitee.com/vincentwei7/PLZS>
 *
 * Author: Vincent Wei
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * License: GPLv3
 */

#define NTEST
#include "nap-arithmetic.cpp"

int nap_cmp(const string &a, const string &b)
{
    size_t len_a = a.length();
    size_t len_b = b.length();

    if (len_a > len_b)
        return a[0];
    else if (len_a < len_b)
        return -b[0];

    // same lengths
    for (size_t i = 0; i < len_a; i++) {
        int cmp = int(a[i]) - int(b[i]);
        if (cmp != 0)
            return cmp;
    }

    return 0;
}

void nap_normalize(string &a)
{
    while (a[0] == '0') {
        a.erase(0, 1);
    }
    a.shrink_to_fit();

    if (a.length() == 0)
        a = "0";
}

/* one must be larger or equal to other. */
string nap_subtract(const string &a, const string &b)
{
    size_t len_a = a.size();
    size_t len_b = b.size();
    size_t len_max = (len_a > len_b) ? len_a : len_b;

    string result;

    int borrow = 0;
    for (size_t i = 0; i < len_max; i++) {
        int n_a = ((i < len_a) ? a[len_a - i - 1] : '0') - '0';
        int n_b = ((i < len_b) ? b[len_b - i - 1] : '0') - '0';

        int r;
        if (n_a - borrow >= n_b) {
            r = n_a - borrow - n_b;
            borrow = 0;
        }
        else {
            r = n_a - borrow + 10 - n_b;
            borrow = 1;
        }

        result.insert(0, 1, '0' + r);
    }

    assert(borrow == 0);
    nap_normalize(result);
    return result;
}

/* one must be larger or equal to other. */
void nap_subtract_from(string &a, const string &b)
{
    size_t len_a = a.size();
    size_t len_b = b.size();
    size_t len_max = (len_a > len_b) ? len_a : len_b;

    int borrow = 0;
    for (size_t i = 0; i < len_max; i++) {
        int n_a = ((i < len_a) ? a[len_a - i - 1] : '0') - '0';
        int n_b = ((i < len_b) ? b[len_b - i - 1] : '0') - '0';

        int r;
        if (n_a - borrow >= n_b) {
            r = n_a - borrow - n_b;
            borrow = 0;
        }
        else {
            r = n_a - borrow + 10 - n_b;
            borrow = 1;
        }

        a[len_a - i - 1] = '0' + r;
    }

    assert(borrow == 0);
    nap_normalize(a);
}

/* returns false if divisor is zero */
bool nap_divmod(const string &dividend, const string &divisor,
        string &quotient, string &remainder)
{
    if (nap_not_zero(divisor)) {
        int cmp = nap_cmp(dividend, divisor);
        if (cmp == 0) {
            quotient = "1";
            remainder = "0";
        }
        else if (cmp < 0) {
            quotient = "0";
            remainder = dividend;
        }
        else {
            quotient = "0";
            remainder = dividend;

            while (nap_cmp(remainder, divisor) >= 0) {
                nap_subtract_from(remainder, divisor);
                nap_add_to(quotient, "1");
            }
        }

        return true;
    }

    return false;
}

int main()
{
    assert(nap_cmp("0", "0") == 0);
    assert(nap_cmp("0", "1") == -1);
    assert(nap_cmp("1", "0") == 1);
    assert(nap_cmp("120", "121") == -1);
    assert(nap_cmp("120", "119") == 1);
    clog << "test for nap_cmp() passed\n";

    string r;
    r = nap_subtract("0", "0");
    assert(r == "0");
    r = nap_subtract("9", "0");
    assert(r == "9");
    r = nap_subtract("10", "0");
    assert(r == "10");
    r = nap_subtract("10", "9");
    assert(r == "1");
    clog << "test for nap_subtract() passed\n";

    r = "20";
    nap_subtract_from(r, "0");
    assert(r == "20");
    nap_subtract_from(r, "9");
    assert(r == "11");
    nap_subtract_from(r, "1");
    assert(r == "10");
    nap_subtract_from(r, "10");
    assert(r == "0");
    clog << "test for nap_subtract_from() passed\n";

    string a, b;
    cin >> a >> b;

    string quot, rem;
    if (nap_divmod(a, b, quot, rem)) {
        cout << quot << " " << rem << endl;
    }
    else {
        cout << "NO SOLUTION" << endl;
    }
}

