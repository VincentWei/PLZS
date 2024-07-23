#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    unsigned n;
    cin >> n;

    if (n < 2)
        return 1;

#if 0
    // Only works when using g++
    uint64_t fibonacci[n] = {};
#else
    uint64_t fibonacci[n];
    memset(fibonacci, 0, sizeof(fibonacci));
#endif
    fibonacci[0] = 1;
    fibonacci[1] = 1;

    for (size_t i = 0; i < sizeof(fibonacci)/sizeof(fibonacci[0]); i++) {
        if (fibonacci[i] == 0) {
            fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
        }
    }

    for (size_t i = 1; i < sizeof(fibonacci)/sizeof(fibonacci[0]); i++) {
        double ratio = (double)fibonacci[i - 1] / fibonacci[i];
        cout << fibonacci[i - 1] << " / " << fibonacci[i] << ": " << ratio << endl;
    }
}
