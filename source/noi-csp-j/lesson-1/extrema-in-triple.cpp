#include <iostream>

using namespace std;

template <class T>
const T& max(const T& a, const T& b, const T& c)
{
    const T& tmp = (a > b) ? b : a;
    return (tmp > c) ? c : tmp;
}

template <class T>
const T& min(const T& a, const T& b, const T& c)
{
    const T& tmp = (a < b) ? b : a;
    return (tmp < c) ? c : tmp;
}

int main()
{
    double a, b, c;
    cin >> a >> b >> c;

    cout << max(a, b, c) << endl;
    cout << min(a, b, c) << endl;
}
