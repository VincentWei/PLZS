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

unsigned determine_number_of_round(double x, double tolerance)
{
    double factorial = 1.0;
    unsigned n = 1;

    while (n < 20) {
        double r = 1.0 / factorial;

        double numerator = 1.0, denominator = 2.0;
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

double sqrt_by_taylor_formula(double x, double a, double sqrt_a)
{
    double ret = sqrt_a;
    double factorial = 1.0;
    double factor = 0.5;
    double power_delta = x - a;
    double power_x = x;

    for (unsigned i = 1; i < 3; i++) {
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

double estimate_square_root(double x, unsigned scale)
{
    if (x < 0)
        return NAN;

    if (isclose(x, 0) || isclose(x, 1.0))
        return x;

    double tolerance = 1;
    while (scale != 0) {
        tolerance *= 0.1;
        scale--;
    }

    double sqrt_a = 1.0;
    double a = sqrt_a * sqrt_a;

    double ans = sqrt_a;
    unsigned i = 0;
    while (true) {
        ans = sqrt_by_taylor_formula(x, a, sqrt_a);

        double errors = ans * ans - x;
        cout << "Iteration #" << i << ":\ta = " << a << "; x = " << ans << "; errors: " << errors << endl;
        if (fabs(errors) < tolerance or isclose(fabs(errors), tolerance)) {
            break;
        }

        if (i++ > 100) {
            break;
        }

        sqrt_a = ans;
        a = ans * ans;
    }

    return ans;
}

int main()
{
    double a;
    unsigned scale;
    cin >> a >> scale;

    cout.precision(scale);
    cout.setf(ios::fixed, ios::floatfield);
    cout << estimate_square_root(a, scale) 
        << " while sqrt() gives: " << sqrt(a) << endl;
}
