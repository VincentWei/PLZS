#include <cmath>
#include <cfloat>

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
}

