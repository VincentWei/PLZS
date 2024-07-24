/*
 * The answer key for Problem 1 of CPP Lesson 3:
 * https://courses.fmsoft.cn/plzs/cpp-data-types.html#/6
 *
 * Author: Vincent Wei
 *  - <https://github.com/VincentWei>
 *  - <https://gitee.com/vincentwei7>
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * License: GPLv3
 */
#include <cmath>
#include <cfloat>
#include <cstdint>
#include <cassert>

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

#include <iostream>

using namespace std;

bool can_make_a_triangle_workaround(double d1, double d2, double d3)
{
    if (d1 <= 0 or d2 <= 0 or d3 <= 0)
        return false;

    if (d1 > UINT32_MAX and d2 > UINT32_MAX and d3 > UINT32_MAX) {
        d1 -= UINT32_MAX;
        d2 -= UINT32_MAX;
        d3 -= UINT32_MAX;
    }
    else if (d1 > UINT32_MAX or d2 > UINT32_MAX or d3 > UINT32_MAX) {
        return (((d1 + d2) > d3) and ((d1 + d3) > d2) and
            ((d2 + d3) > d1));
    }

    uint64_t ull1 = uint64_t(d1 * UINT32_MAX);
    uint64_t ull2 = uint64_t(d2 * UINT32_MAX);
    uint64_t ull3 = uint64_t(d3 * UINT32_MAX);

    if (((ull1 + ull2) > ull3) and ((ull1 + ull3) > ull2) and
            ((ull2 + ull3) > ull1))
        return true;

    return false;
}

bool can_make_a_triangle(double d1, double d2, double d3)
{
    if (d1 <= 0 or d2 <= 0 or d3 <= 0) {
        return false;
    }
    else if (
            (!isclose(d1 + d2, d3) && ((d1 + d2) > d3)) and
            (!isclose(d1 + d3, d2) && ((d1 + d3) > d2)) and
            (!isclose(d2 + d3, d1) && ((d2 + d3) > d1))) {
        return true;
    }

    return false;
}

int main()
{
    double a, b, c;
    cin >> a >> b >> c;

    if (can_make_a_triangle(a, b, c)) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }

    assert(can_make_a_triangle_workaround(a, b, c) == can_make_a_triangle(a, b, c));
}

