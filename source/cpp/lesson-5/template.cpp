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

template <class T>
class Triple {
    T values[3];

  public:
    Triple(T first, T second, T third)  {
      values[0] = first; values[1] = second; values[2]=third;
    }

    T max();
    T min();
    T average();
};

template <class T>
T Triple<T>::max()
{
    T retval;
    retval = values[0] > values[1] ? values[0] : values[1];
    retval = retval > values[2] ? retval : values[2];
    return retval;
}

template <class T>
T Triple<T>::min()
{
    T retval;
    retval = values[0] > values[1] ? values[1] : values[0];
    retval = retval > values[2] ? values[2] : retval;
    return retval;
}

template <class T>
T Triple<T>::average()
{
    T sum = 0;
    for (int i = 0; i < 3; i++)
        sum += values[i];

    return sum / 3;
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

    Triple<double> coord_3d(100.0, 75.0, 10.0);
    cout << coord_3d.average() << endl;
}

