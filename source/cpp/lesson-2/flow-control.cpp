#include <iostream>
#include <string>
#include <cassert>
#include <cstdint>

using namespace std;

bool is_even_or_odd_0(int n)
{
    if (n % 2 == 0)
        return true;
    else {
        if (n % 2 == 1) {
            return false;
        }
    }

    return false;
}

bool is_even_or_odd_1(int n)
{
    if (n % 2 == 0)
        return true;
    else if (n % 2 == 1)
        return false;

    return false;
}

bool is_even_or_odd_2(int n)
{
    if (n % 2 == 0)
        return true;
    else
        return false;
}

bool is_even_or_odd_3(int n)
{
    if (n % 2 == 0)
        return true;

    return false;
}

bool is_even_or_odd_4(int n)
{
    if (n % 2)
        return false;

    return true;
}

bool is_even_or_odd_best(int n)
{
    return (n & 0x01) == 0;
}

bool can_make_a_triangle(unsigned d1, unsigned d2, unsigned d3)
{
    if (d1 <= 0 or d2 <= 0 or d3 <= 0) {
        return false;
    }
    else if (((d1 + d2) > d3) and ((d1 + d3) > d2) and ((d2 + d3) > d1)) {
        return true;
    }

    return false;
}

string day_of_week(int weekday)
{
    switch (weekday) {
        case 0:
            return "Sunday";
        case 1:
            return "Monday";
        case 2:
            return "Tuesday";
        case 3:
            return "Wednesday";
        case 4:
            return "Thursday";
        case 5:
            return "Friday";
        case 6:
            return "Saturday";
        default:
            return "<Wrong Weekday Value>";
    }

    return "<NeverGetHere>";
}

bool is_prime_less_than_10(unsigned n)
{
    if (n < 2 || n > 10)
        return false;

    switch (n) {
        case 2:
        case 3:
        case 5:
        case 7:
            return true;
    }

    return false;
}

void list_even_numbers_less_than_v0(unsigned n)
{
    unsigned a = 0;
    while (a < n) {
        if ((a % 2) == 0)
            cout << a << " ";
        a = a + 1;
    }

    cout << endl;
}

void list_even_numbers_less_than_v1(unsigned n)
{
    unsigned a = 0;
    bool flag = true;
    while (true) {
        if (a >= n)
            break;

        if (flag)
            cout << a << " ";

        a = a + 1;
        flag = !flag;
    }

    cout << endl;
}

void list_even_numbers_less_than_v2(unsigned n)
{
    unsigned a = 0;
    do {
        if ((a & 0x01) == 0)
            cout << a << " ";
    } while (++a < n);

    cout << endl;
}

void list_even_numbers_less_than_v3(unsigned n)
{
    for (unsigned i = 0; i < n; i += 2) {
        cout << i << " ";
    }

    cout << endl;
}

void list_even_numbers_less_than_v4(unsigned n)
{
    n /= 2;
    for (unsigned i = 0; i < n; i++) {
        cout << i * 2 << " ";
    }

    cout << endl;
}

void list_even_numbers_less_than_v5(unsigned n)
{
    n >>= 1;
    for (unsigned i = 0; i < n; i++) {
        cout << (i << 1) << " ";
    }

    cout << endl;
}

int main()
{
    assert(!is_even_or_odd_0(15));
    assert(!is_even_or_odd_1(15));
    assert(!is_even_or_odd_2(15));
    assert(!is_even_or_odd_3(15));
    assert(!is_even_or_odd_4(15));
    assert(!is_even_or_odd_best(15));

    assert(is_even_or_odd_0(16));
    assert(is_even_or_odd_1(16));
    assert(is_even_or_odd_2(16));
    assert(is_even_or_odd_3(16));
    assert(is_even_or_odd_4(16));
    assert(is_even_or_odd_best(16));

    assert(!can_make_a_triangle(1, 2, 3));
    assert(can_make_a_triangle(3, 4, 5));

    assert(day_of_week(0) == "Sunday");
    assert(is_prime_less_than_10(7));

    list_even_numbers_less_than_v0(10);
    list_even_numbers_less_than_v1(10);
    list_even_numbers_less_than_v2(10);
    list_even_numbers_less_than_v3(10);
    list_even_numbers_less_than_v4(10);
    list_even_numbers_less_than_v5(10);
}

