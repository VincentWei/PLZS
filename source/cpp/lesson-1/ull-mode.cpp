#include <iostream>

#define MY_PRIME    (0x80000000U - 1)

int main()
{
    unsigned long long ull;

    std::cin >> ull;

    std::cout << ull % MY_PRIME << std::endl;
}
