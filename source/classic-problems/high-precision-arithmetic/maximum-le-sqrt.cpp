/*
 * This program calculates the summary of factorials.
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

/*
 * 33 / 2 = 16
 * 33 * 5 = 165 / 10 = 16
 */
string nap_half(const string& n)
{
    string result = nap_mul_vert(n, "5");
    result.pop_back();
    if (result.size() == 0)
        result = "0";
    return result;
}

string nap_average(const string& a, const string& b)
{
    string ave = a;
    ave = nap_add(a, b);
    return nap_half(ave);
}

bool nap_less(const string& a, const string& b)
{
    size_t len_a = a.length();
    size_t len_b = b.length();
    if (len_a < len_b)
        return true;
    else if (len_a > len_b)
        return false;

    for (size_t i = 0; i < len_a; i++) {
        if (a[i] < b[i])
            return true;
        else if (a[i] > b[i])
            return false;
    }

    // equal
    return false;
}

bool nap_less_equal(const string& a, const string& b)
{
    size_t len_a = a.length();
    size_t len_b = b.length();
    if (len_a < len_b)
        return true;
    else if (len_a > len_b)
        return false;

    for (size_t i = 0; i < len_a; i++) {
        if (a[i] < b[i])
            return true;
        else if (a[i] > b[i])
            return false;
    }

    // equal
    return true;
}

bool nap_larger(const string& a, const string& b)
{
    size_t len_a = a.length();
    size_t len_b = b.length();
    if (len_a > len_b)
        return true;
    else if (len_a < len_b)
        return false;

    for (size_t i = 0; i < len_a; i++) {
        if (a[i] > b[i])
            return true;
        else if (a[i] < b[i])
            return false;
    }

    // equal
    return false;
}

bool nap_larger_equal(const string& a, const string& b)
{
    size_t len_a = a.length();
    size_t len_b = b.length();
    if (len_a > len_b)
        return true;
    else if (len_a < len_b)
        return false;

    for (size_t i = 0; i < len_a; i++) {
        if (a[i] > b[i])
            return true;
        else if (a[i] < b[i])
            return false;
    }

    // equal
    return true;
}

int check(const string& mid, const string& n)
{
    string square_mid = nap_mul_vert(mid, mid);
    if (square_mid == n)
        return 0;

    if (nap_less(square_mid, n)) {
        string tmp = square_mid;
        nap_add_to(square_mid, nap_mul_vert(mid, "2"));
        nap_add_to(square_mid, "1");
        if (nap_larger(square_mid, n)) {
            return 0;
        }

        return -1;
    }

    return 1;
}

string maximum_le_sqrt(const string& n)
{
    if (nap_less(n, "2"))
        return string(n);

    string start = "0";
    string end = n;
    string mid = "0";

    while (nap_less_equal(start, end)) {
        mid = nap_average(start, end);
        if (mid == "0")
            break;

        int r = check(mid, n);
        if (r == 0) {
            break;
        }
        else if (r > 0) {
            end = mid;
        }
        else {
            start = mid;
        }
    }

    return mid;
}

int main()
{
    assert(nap_half("0") == "0");
    assert(nap_half("1") == "0");
    assert(nap_half("8") == "4");
    assert(nap_half("123") == "61");

    assert(nap_average("0", "1") == "0");
    assert(nap_average("1", "1") == "1");
    assert(nap_average("8", "7") == "7");
    assert(nap_average("123", "100") == "111");

    assert(nap_less("0", "1") == true);
    assert(nap_less("1", "1") == false);
    assert(nap_less("8", "7") == false);
    assert(nap_less("23", "100") == true);

    assert(nap_less_equal("0", "1") == true);
    assert(nap_less_equal("1", "1") == true);
    assert(nap_less_equal("8", "8") == true);
    assert(nap_less_equal("23", "100") == true);

    assert(nap_larger("0", "1") == false);
    assert(nap_larger("1", "1") == false);
    assert(nap_larger("8", "7") == true);
    assert(nap_larger("23", "100") == false);

    assert(nap_larger_equal("0", "1") == false);
    assert(nap_larger_equal("1", "1") == true);
    assert(nap_larger_equal("8", "8") == true);
    assert(nap_larger_equal("23", "100") == false);

    assert(check("2", "4") == 0);
    assert(check("2", "5") == 0);
    assert(check("2", "7") == 0);
    assert(check("2", "9") == -1);
    assert(check("4", "9") == 1);

    assert(maximum_le_sqrt("0") == "0");
    assert(maximum_le_sqrt("1") == "1");
    assert(maximum_le_sqrt("2") == "1");
    assert(maximum_le_sqrt("9") == "3");
    assert(maximum_le_sqrt("100") == "10");
    assert(maximum_le_sqrt("123456789") == "11111");
    assert(maximum_le_sqrt("1234567890") == "35136");
    assert(maximum_le_sqrt("123456789098765432101234567890123456789") == "11111111064999999904");

    string n;
    cin >> n;
    string ans = maximum_le_sqrt(n);
    cout << ans << endl;
    return 0;
}

