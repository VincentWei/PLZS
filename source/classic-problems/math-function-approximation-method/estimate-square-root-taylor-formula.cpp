/*
 * This program estimates the square root of a given number
 * by using the Taylor's formula.
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
#include <iostream>     // for cin and cout
#include <cmath>        // for NAN and fabs()
#include <cfloat>       // for XXX_EPSILON
#include <cassert>      // for assert()

using namespace std;

bool isclose(double a, double b)
{
    double max_val = fabs(a) > fabs(b) ? fabs(a) : fabs(b);
    return (fabs(a - b) <= max_val * DBL_EPSILON);
}

bool isclosef(float a, float b)
{
    float max_val = fabsf(a) > fabsf(b) ? fabsf(a) : fabsf(b);
    return (fabs(a - b) <= max_val * FLT_EPSILON);
}

bool isclosel(long double a, long double b)
{
    long double max_val = fabsl(a) > fabsl(b) ? fabsl(a) : fabsl(b);
    return (fabsl(a - b) <= max_val * LDBL_EPSILON);
}

unsigned determine_number_of_round(long double x, long double tolerance)
{
    long double factorial = 1.0;
    unsigned n = 1;

    while (n < 20) {
        long double r = 1.0 / factorial;

        long double numerator = 1.0, denominator = 2.0;
        for (unsigned i = 1; i < n; i++) {
            numerator *= 2.0 * i - 1;
            denominator *= 2.0;
        }

        cout << n << ": " << numerator << "/" << denominator << endl;

        r *= numerator / denominator * fabs(x - 1.0);
        cout << n << ": " << r << endl;
        if (r < tolerance)
            break;
        factorial *= ++n;
        cout << n << ": " << factorial << endl;
    }

    return n;
}

long double sqrt_by_taylor_formula(long double x, long double a, long double sqrt_a)
{
    long double ret = sqrt_a;
    long double factorial = 1.0;
    long double factor = 0.5;
    long double power_delta = x - a;
    long double power_x = x;

    for (unsigned i = 1; i < 5; i++) {
        factorial *= i;

        if (i >= 2) {
            factor *= (0.5 - (i - 1));
            power_delta *= (x - a);
            power_x *= x;
        }

        ret += (1.0/factorial) * factor * sqrt_a * (1.0/power_x) * power_delta;
    }

    return ret;
}

int check(uint64_t mid, uint64_t n)
{
    if (mid > UINT32_MAX)
        return 1;

    uint64_t square_mid = mid * mid;
    if (square_mid == n)
        return 0;

    if (square_mid < n) {
        square_mid += mid << 1;
        square_mid += 1;
        if (square_mid > n) {
            return 0;
        }

        return -1;
    }

    return 1;
}

uint64_t maximum_le_sqrt(uint64_t n)
{
    if (n < 2)
        return n;

    uint64_t start = 0;
    uint64_t end = n;
    uint64_t mid = n / 2;

    while (start <= end) {
        mid = (start >> 1) + (end >> 1);
        if (mid == 0)
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

long double estimate_square_root(uint64_t x, unsigned scale)
{
    if (x < 2)
        return x;

    uint64_t tmp = maximum_le_sqrt(x);
    long double sqrt_a = (long double)maximum_le_sqrt(tmp);
    long double a = sqrt_a * sqrt_a;

    long double tolerance = 1;
    while (scale != 0) {
        tolerance *= 0.1;
        scale--;
    }

    long double ans = sqrt_a;
    unsigned i = 0;
    while (true) {
        ans = sqrt_by_taylor_formula(x, a, sqrt_a);

        long double errors = x - ans * ans;
        cout << "Iteration #" << i << ":\ta = " << a << "; x = " << ans << "; errors: " << errors << endl;
        if (fabs(errors) < tolerance or isclose(fabs(errors), tolerance)) {
            break;
        }

        if (++i > 100) {
            break;
        }

        sqrt_a = ans;
        a = ans * ans;
    }

    return ans;
}

int main()
{
    unsigned a;
    unsigned scale;
    cin >> a >> scale;

    cout.precision(scale);
    cout.setf(ios::fixed, ios::floatfield);
    cout << estimate_square_root((long double)a, scale) 
        << " while sqrt() gives: " << sqrt(a) << endl;
}
