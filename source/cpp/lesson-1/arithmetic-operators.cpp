#include <iostream>

using namespace std;

int main()
{
    auto i = 0;
    auto u = 0xFFFFFFFFU;
    auto ul = 0UL;

    float f = 0.0;
    f++;

    double d = 50.0 / 0;

    cout << i << ": " << sizeof(i) << endl;
    cout << u << ": " << sizeof(u) << endl;
    cout << ul << ": " << sizeof(ul) << endl;
    cout << f << ": " << sizeof(f) << endl;
    cout << d << ": " << sizeof(d) << endl;
}
