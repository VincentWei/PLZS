/*
 * This program implements arbitrary arithmetic for natural numbers:
 * addition, subtraction (decrement), and multiplication.
 *
 * Author: Vincent Wei
 *  - <https://github.com/VincentWei>
 *  - <https://gitee.com/vincentwei7>
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * License: GPLv3
 */
#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

void nap_add(string &result, const string &a, const string &b)
{
    size_t len_a = a.length();
    size_t len_b = b.length();
    size_t len_max = (len_a > len_b) ? len_a : len_b;

    result.clear();
    int c = 0;
    for (size_t i = 0; i < len_max; i++) {
        int n_a = ((i < len_a) ? a[len_a - i - 1] : '0') - '0';
        int n_b = ((i < len_b) ? b[len_b - i - 1] : '0') - '0';

        int r = n_a + n_b + c;
        if (r >= 10) {
            c = 1;
            r -= 10;
        }
        else
            c = 0;

        result.insert(0, 1, '0' + r);
    }

    if (c > 0) {
        result.insert(0, 1, '1');
    }
}

string nap_add(const string &a, const string &b)
{
    string result;
    size_t len_a = a.length();
    size_t len_b = b.length();
    size_t len_max = (len_a > len_b) ? len_a : len_b;

    int c = 0;
    for (size_t i = 0; i < len_max; i++) {
        int n_a = ((i < len_a) ? a[len_a - i - 1] : '0') - '0';
        int n_b = ((i < len_b) ? b[len_b - i - 1] : '0') - '0';

        int r = n_a + n_b + c;
        if (r >= 10) {
            c = 1;
            r -= 10;
        }
        else
            c = 0;

        result.insert(0, 1, '0' + r);
    }

    if (c > 0) {
        result.insert(0, 1, '1');
    }

    return result;
}

void nap_add_to(string &r, const string &a)
{
    size_t len_r = r.length();
    size_t len_a = a.length();
    size_t len_max = (len_r > len_a) ? len_r : len_a;

    int carry = 0;
    for (size_t i = 0; i < len_max; i++) {
        int value_r = ((i < len_r) ? r[len_r - i - 1] : '0') - '0';
        int value_a = ((i < len_a) ? a[len_a - i - 1] : '0') - '0';

        value_r += value_a + carry;
        if (value_r >= 10) {
            carry = 1;
            value_r -= 10;
        }
        else
            carry = 0;

        if (i >= len_r)
            r.insert(0, 1, '0' + value_r);
        else
            r[len_r - i - 1] = '0' + value_r;
    }

    if (carry > 0) {
        r.insert(0, 1, '1');
    }
}

bool nap_not_zero(const string &n)
{
    size_t len = n.length();
    for (size_t i = 0; i < len; i++) {
        if (n[i] != '0')
            return true;
    }

    return false;
}

void nap_mul(string &result, const string &a, const string &b)
{
    string times = "0";

    result = "0";
    while (b != times) {
        string tmp;
        nap_add(tmp, result, a);
        result = tmp;

        nap_add(tmp, times, "1");
        times = tmp;
    }
}

string nap_mul(const string &a, const string &b)
{
    string result = "0";
    string times = "0";

    while (b != times) {
        result = nap_add(result, a);
        times = nap_add(times, "1");
    }

    return result;
}

string nap_mul_op(const string &a, const string &b)
{
    string times("0");
    string result("0");
    while (b != times) {
        nap_add_to(result, a);
        nap_add_to(times, "1");
    }

    return result;
}

/* Use vertical multiplication method */
string nap_mul_alt(const string &a, const string &b)
{
    string r;

    size_t len_a = a.length();
    size_t len_b = b.length();
    size_t len_r = 0;

    for (size_t i = 0; i < len_a; i++) {
        int value_a = a[len_a - i - 1] - '0';

        int carry = 0;
        for (size_t j = 0; j < len_b; j++) {
            int value_b = b[len_b - j - 1]  - '0';

            int p = value_a * value_b + carry;
            if (p >= 10) {
                carry = p / 10;
                p %= 10;
            }
            else {
                carry = 0;
            }

            size_t k = j + i;
            if (k >= len_r) {
                r.insert(0, 1, '0' + p);
                len_r++;
            }
            else {
                int value_r = r[len_r - k - 1]  - '0';
                value_r += p;
                if (value_r >= 10) {
                    carry++;
                    value_r -= 10;
                }

                r[len_r - k - 1] = '0' + value_r;
            }
        }

        if (carry > 0) {
            r.insert(0, 1, '0' + carry);
            len_r++;
            carry = 0;
        }

        assert(len_r == r.length());
    }

    return r;
}

void nap_dec(string &n)
{
    assert(n != "0" && n != "");

    size_t nr_digits = n.length();

    int digit0 = n[nr_digits - 1] - '0';
    int r = digit0 - 1;
    int borrow = 0;
    if (r < 0) {
        borrow = 1;
        r += 10;
    }
    n[nr_digits - 1] = '0' + r;

    size_t i = 1;
    while (borrow > 0) {
        int digit = n[nr_digits - i - 1] - '0';
        int r = digit - borrow;

        if (r < 0) {
            borrow = 1;
            r += 10;
        }
        else
            borrow = 0;

        n[nr_digits - i - 1] = '0' + r;
        i++;
    }

    if (n[0] == '0' && nr_digits > 1)
        n.erase(0, 1);
}

#ifndef NTEST
int main()
{
    string r;

    // test nap_add()
    nap_add(r, "0", "1");
    assert(r == "1");
    nap_add(r, "1", "9");
    assert(r == "10");
    nap_add(r, "91", "10");
    assert(r == "101");
    nap_add(r, "101", "99");
    assert(r == "200");
    clog << "test for nap_add() passed\n";

    // test nap_add_alt()
    r = nap_add("0", "1");
    assert(r == "1");
    r = nap_add("1", "9");
    assert(r == "10");
    r = nap_add("91", "10");
    assert(r == "101");
    r = nap_add("101", "99");
    assert(r == "200");
    clog << "test for nap_add_alt() passed\n";

    // test nap_add_to()
    r = "0";
    nap_add_to(r, "1");
    assert(r == "1");
    nap_add_to(r, "9");
    assert(r == "10");
    nap_add_to(r, "91");
    assert(r == "101");
    nap_add_to(r, "99");
    assert(r == "200");
    clog << "test for nap_add_to() passed\n";

    // test nap_dec()
    r = "1";
    nap_dec(r);
    assert(r == "0");

    r = "10";
    nap_dec(r);
    assert(r == "9");
    clog << "test for nap_dec() passed\n";

    // test nap_mul_op()
    r = nap_mul_op("2", "2");
    assert(r == "4");
    r = nap_mul_op("2", "10");
    assert(r == "20");
    r = nap_mul_op("20", "20");
    assert(r == "400");
    r= nap_mul_op("11", "11");
    assert(r == "121");
    cout << "test for nap_mul_op() passed\n";

    // test nap_mul_alt()
    r = nap_mul_alt("33", "77");
    assert(r == "2541");
    r = nap_mul_alt("2", "2");
    assert(r == "4");
    r = nap_mul_alt("2", "10");
    assert(r == "20");
    r = nap_mul_alt("20", "20");
    assert(r == "400");
    r = nap_mul_alt("11", "11");
    assert(r == "121");
    cout << "test for nap_mul_alt() passed\n";

}

#endif /* not defined NTEST */
