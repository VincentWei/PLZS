#include <iostream>

using namespace std;

template <class T>
T summary(T a, T b)
{
  return a+b;
}

template <class T>
class Pair {
    T values[2];

  public:
    Pair(T first, T second)  {
      values[0] = first; values[1] = second;
    }

    T max();
    T min();
};

template <class T>
T Pair<T>::max()
{
    T retval;
    retval = values[0] > values[1] ? values[0] : values[1];
    return retval;
}

template <class T>
T Pair<T>::min()
{
    T retval;
    retval = values[0] > values[1] ? values[1] : values[0];
    return retval;
}

int main()
{
    auto x = summary<int>(10, 20);
    auto y = summary<double>(10.03, 20.01);
    auto z = summary<long double>(10.00003l, 20.00009l);

    cout << x << endl;
    cout << y << endl;
    cout << z << endl;

    Pair<double> coordinates(100.0, 75.0);
    cout << coordinates.max() << endl;
}

