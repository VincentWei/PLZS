#include <iostream>
#include <string>
#include <cassert>
#include <cstdint>

using namespace std;

bool can_make_a_triangle_bad(double d1, double d2, double d3)
{
    if (d1 <= 0 or d2 <= 0 or d3 <= 0) {
        return false;
    }
    else if (((d1 + d2) > d3) and ((d1 + d3) > d2) and ((d2 + d3) > d1)) {
        return true;
    }

    return false;
}

int main()
{
    assert(can_make_a_triangle_bad(0.1, 0.2, 0.3));
}

