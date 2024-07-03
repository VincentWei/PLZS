#include <iostream>
#include <cstdint>

using namespace std;

void test_array()
{
    uint64_t fibonacci[100] = { 1, 1, 2, 3, 5, 8 };

    int i = 0;
    while (fibonacci[i] > 0) {
        cout << fibonacci[i] << endl;
        i++;
    }

    for (size_t i = 0; i < sizeof(fibonacci)/sizeof(uint64_t); i++) {
        if (fibonacci[i] == 0) {
            fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
        }
        cout << fibonacci[i] << endl;
    }
}

void test_pointer()
{
    int a;
    int *p = &a;

    cout << p << endl;
    cout << p + 1 << endl;

    *p = 3;
    cout << sizeof(p) << endl;
    cout << a << endl;
}

void test_pointer_2()
{
    int fibonacci[] = { 1, 1, 2, 3, 5, 8 };
    int *p = fibonacci;

    for (size_t i = 0; i < sizeof(fibonacci)/sizeof(int); i++) {
        cout << p[i] << endl;
    }

    for (size_t i = 0; i < sizeof(fibonacci)/sizeof(int); i++) {
        cout << *p << endl;
        p++;
    }
}

#include <cstdint>

int main()
{
    uint64_t fibonacci[90] = { 1, 1, 2, 3, 5, 8 };

    uint64_t *p = fibonacci;
    for (size_t i = 0; i < sizeof(fibonacci)/sizeof(fibonacci[0]); i++) {
        if (p[i] == 0) {
            p[i] = p[i - 1] + p[i - 2];
        }

        cout << p[i] << endl;
    }

    const uint64_t *cp = fibonacci;
    for (size_t i = 0; i < sizeof(fibonacci)/sizeof(fibonacci[0]); i++) {
        cout << *cp << endl;
        cp++;
    }
}
