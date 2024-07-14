#include <iostream>

#define MY_PRIME    (0x80000000U - 1)

// 亦可使用如下方法定义这个质数
// #define MY_PRIME    ((1U << 31) - 1)

int main()
{
    unsigned long long ull;

    std::cin >> ull;

    std::cout << ull % MY_PRIME << std::endl;
}
