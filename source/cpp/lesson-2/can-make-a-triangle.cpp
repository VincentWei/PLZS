#include <iostream>

using namespace std;

bool can_make_a_triangle(double d1, double d2, double d3)
{
    if (d1 <= 0 or d2 <= 0 or d3 <= 0) {
        return false;
    }
    else if (((d1 + d2) > d3) and ((d1 + d3) > d2) and ((d2 + d3) > d1)) {
        return true;
    }

    return false;
}

int main()
{
    double a, b, c;
    cin >> a >> b >> c;

    cout << (can_make_a_triangle(a, b, c) ? "True" : "False") << endl;

    /* 以上使用 ? 运算符的简化写法相当于如下代码：
    if (can_make_a_triangle(a, b, c)) {
        cout << "True";
    }
    else {
        cout << "False";
    }

    cout << endl; */
}
