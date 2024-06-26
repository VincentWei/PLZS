#include <iostream>

int main()
{
    int a = 10, b;

    std::cout << "Please input an integer: ";
    std::cin >> b;

    auto sum = a + b;
    std::cout << "Th summary of `" << a << "` and `" << b << "` is `" << sum << "`." << std::endl;
    std::cout << "The size of `" << sum << "` is `" << sizeof(sum) << "`." << std::endl;
}
