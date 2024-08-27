/*
 * The answer key for Problem 1 of CPP Lesson 6:
 *  <https://courses.fmsoft.cn/plzs/cpp-arbitrary-precision-arithmetic.html#/8>
 *
 * Author: Vincent Wei
 *  - <https://github.com/VincentWei>
 *  - <https://gitee.com/vincentwei7>
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * License: GPLv3
 */

#define NTEST

#include "nap-arithmetic.cpp"

static vector<string> cached_factorial(50);

string nap_factorial(const string &n)
{
    string r;
    size_t native_n;
    string times = "1";

    native_n = (size_t)stoul(n);
    if (native_n < cached_factorial.size() &&
            cached_factorial[native_n] != "") {
        r = cached_factorial[native_n];
        goto done;
    }

    if (n.empty() or n == "0") {
        r = "1";
        goto done;
    }

    r = n;
    while (n != times) {
        r = nap_mul_alt(r, times);
        nap_add_to(times, "1");
    }

    // cached the result
    if (native_n < cached_factorial.size()) {
        cached_factorial[native_n] = r;
    }
    else {
        cached_factorial.resize(native_n + 1, "");
        cached_factorial[native_n] = r;
    }

done:
    return r;
}

string nap_factorial_recursive(const string &n)
{
    string r;
    size_t native_n;
    string prev_n = n;

    if (n.empty() or n == "0") {
        r = "1";
        goto done;
    }

    native_n = (size_t)stoul(n);
    if (native_n < cached_factorial.size() &&
            cached_factorial[native_n] != "") {
        r = cached_factorial[native_n];
        goto done;
    }

    nap_dec(prev_n);

    r = nap_factorial_recursive(prev_n);
    r = nap_mul_alt(r, n);

    // cached the result
    if (native_n < cached_factorial.size()) {
        cached_factorial[native_n] = r;
    }
    else {
        cached_factorial.resize(native_n + 1, "");
        cached_factorial[native_n] = r;
    }

done:
    return r;
}

string summary_of_factorials(const string &n)
{
    string result("0");
    string times("0");

    while (true) {
        string factorial = nap_factorial_recursive(times);
        nap_add_to(result, factorial);

        if (n == times)
            break;
        nap_add_to(times, "1");
    }

    return result;
}

int main()
{
    string r;

    // test for nap_factorial()
    r = nap_factorial("0");
    assert(r == "1");
    r = nap_factorial("1");
    assert(r == "1");
    r = nap_factorial("2");
    assert(r == "2");
    r = nap_factorial("3");
    assert(r == "6");
    r = nap_factorial("4");
    assert(r == "24");
    r = nap_factorial("5");
    assert(r == "120");
    clog << "test for nap_factorial() passed\n";

    // test for nap_factorial_recursive()
    r = nap_factorial_recursive("0");
    assert(r == "1");
    r = nap_factorial_recursive("1");
    assert(r == "1");
    r = nap_factorial_recursive("2");
    assert(r == "2");
    r = nap_factorial_recursive("3");
    assert(r == "6");
    r = nap_factorial_recursive("4");
    assert(r == "24");
    r = nap_factorial_recursive("5");
    assert(r == "120");
    clog << "test for nap_factorial_recursive() passed\n";

    string n;
    cin >> n;

    string summary;
    summary = summary_of_factorials(n);
    cout << summary << endl;
    return 0;
}

