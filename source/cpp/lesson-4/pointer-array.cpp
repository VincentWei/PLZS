#include <iostream>

using namespace std;

void matrix()
{
    double matrix[4][5] = {
        {1., 2., 3., 4.},
        {2., 3., 4., 1.},
        {3., 4., 1., 2.},
        {4., 1., 2., 3.},
    };

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] *= 100.0;
        }
    }
}

int main()
{
    const char *names[] = {
        "Julia",
        "Lisa",
        "Tom",
    };

    for (size_t i = 0; i < sizeof(names)/sizeof(names[0]); i++) {
        for (int j = 0; true; j++) {
            if (names[i][j] == '\0')
                break;

            char c = (char)toupper(names[i][j]);
            cout << c;
        }

        cout << endl;
    }
}
