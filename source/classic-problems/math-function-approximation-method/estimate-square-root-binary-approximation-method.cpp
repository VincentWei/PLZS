/*
 * This program estimates the square root of a given number
 * by using the binary approximation method.
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

double estimate_square_root(double a, unsigned scale)
{
    if (a < 0)
        return NAN;

    double tolerance = 1;
    while (scale != 0) {
        tolerance *= 0.1;
        scale--;
    }

    double start, end;
    if (a >= 1.0) {
        start = 1.0;
        end = a;
    }
    else {
        start = 0;
        end = 1.0;
    }

    double mid = NAN;
    unsigned i = 0;
    while (start <= end) {
        mid = start + ((end - start) / 2.0);

        if (isclose(start, end))
            break;

        double errors = mid * mid - a;

        cout << "Iteration #" << i++ << ":\tx = " << mid << "; errors: " << errors << endl;
        if (fabs(errors) <= tolerance) {
            break;
        }
        else if (errors < 0) {
            start = mid;
        }
        else {
            end = mid;
        }
    }

    return mid;
}

int main()
{
    double a;
    unsigned scale;
    cin >> a >> scale;

    cout.precision(scale);
    cout.setf(ios::fixed, ios::floatfield);
    cout << estimate_square_root(a, scale) << endl;
}
