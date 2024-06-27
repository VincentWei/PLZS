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

bool can_make_a_triangle_workaround(double d1, double d2, double d3)
{
    if (d1 > UINT32_MAX or d2 > UINT32_MAX or d3 > UINT32_MAX) {
        return false;
    }

    if (d1 <= 0 or d2 <= 0 or d3 <= 0)
        return false;

    uint64_t ull1 = uint64_t(d1 * UINT32_MAX);
    uint64_t ull2 = uint64_t(d2 * UINT32_MAX);
    uint64_t ull3 = uint64_t(d3 * UINT32_MAX);

    if (((ull1 + ull2) > ull3) and ((ull1 + ull3) > ull2) and
            ((ull2 + ull3) > ull1))
        return true;

    return false;
}

int main()
{
    assert(can_make_a_triangle_bad(0.1, 0.2, 0.3));
    assert(!can_make_a_triangle_workaround(0.1, 0.2, 0.3));
}

