#include <iostream>

using namespace std;

int main()
{
    auto i = 0;
    auto u = 0xFFFFFFFFU;
    auto ul = 0UL;

    auto f1 = 0.0f;
    decltype(f1) f2 = f1++;

    auto d = 50.0 / 0.0;

    cout << i << ": " << sizeof(i) << endl;
    cout << u << ": " << sizeof(u) << endl;
    cout << ul << ": " << sizeof(ul) << endl;
    cout << f1 << ": " << sizeof(f1) << endl;
    cout << f2 << ": " << sizeof(f2) << endl;
    cout << d << ": " << sizeof(d) << endl;
}
