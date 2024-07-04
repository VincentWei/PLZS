#include <iostream>   // std::cout
#include <string>     // std::string, std::stoull

using namespace std;

int main()
{
    string str = "8246821 0xffff 020 -1";
    string::size_type sz = 0;   // alias of size_t

    cout.flags(ios::hex | ios::showbase);
    while (!str.empty()) {
        unsigned long long ull = stoull(str, &sz, 0);
        cout << str.substr(0, sz) << " interpreted as " << ull << '\n';
        str = str.substr(sz);
    }
}
