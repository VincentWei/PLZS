#include <iostream>
#include <cmath>

using namespace std;

double circle_area(double r)
{
    return M_PI * r * r;
}

int main()
{
    double r;

    cin >> r;
    cout << circle_area(r);
}

