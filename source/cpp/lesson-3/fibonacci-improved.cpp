#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    unsigned n;
    cin >> n;

    if (n < 2)
        return 1;

    uint64_t fibonacci[n];
    memset(fibonacci, 0, sizeof(fibonacci));
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
