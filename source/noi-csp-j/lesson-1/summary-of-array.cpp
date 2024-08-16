#include <iostream>
#include <cassert>

using namespace std;

template <class T>
T sum(const T* arr, size_t nr)
{
    T sum = 0;
    for (size_t i = 0; i < nr; i++) {
        sum += arr[i];
    }

    return sum;
}

int main()
{
    double a[5];
    cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];

    cout << sum(a, 5) << endl;
}
