#include <iostream>     // std::cout, std::ios

using namespace std;

int main() {
    cout.flags ( ios::right | ios::hex | ios::showbase );
    cout.width(10);
    cout << 255 << endl;
}
