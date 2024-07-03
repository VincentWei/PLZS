#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

string make_indent(unsigned n)
{
    string indent;
    for (unsigned i = 0; i < n; i++) {
        indent += ' ';
    }

    return indent;
}

double my_power(double f, unsigned n, unsigned i = 0)
{
    string indent = make_indent(i);
    cout << indent << "Call #" << i << " my_power(" << f << ", " << n << ")" << endl;

    double r;
    if (n == 0)
        r = 1;
    else
        r = f * my_power(f, n - 1, i + 1);

    cout << indent << "Return " << r << " for Call #" << i << "." << endl;
    return r;
}

int main ()
{
    double r = my_power(2.0, 8);
    cout << "The value of 2 raised to the power of 8 is " << r << endl;
}
