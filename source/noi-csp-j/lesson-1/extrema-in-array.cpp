#include <iostream>
#include <cassert>

using namespace std;

template <class T>
const T& max(const T* arr, size_t nr)
{
    assert(nr > 0);

    const T* max = arr;
    if (nr > 1) {
        for (size_t i = 1; i < nr; i++) {
            if (arr[i] > *max) {
                max = arr + i;
            }
        }
    }

    return *max;
}

template <class T>
const T& min(const T* arr, size_t nr)
{
    assert(nr > 0);

    const T* min = arr;
    if (nr > 1) {
        for (size_t i = 1; i < nr; i++) {
            if (*min > arr[i]) {
                min = arr + i;
            }
        }
    }

    return *min;
}
int main()
{
    double a[5];
    cin >> a[0] >> a[0] >> a[1] >> a[2] >> a[3];

    cout << max(a, 5) << endl;
    cout << min(a, 5) << endl;
}
