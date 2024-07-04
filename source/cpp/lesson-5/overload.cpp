#include <cmath>
#include <string>
#include <iostream>

using namespace std;

long int& operator<< (long int& l, string &str)
{
    l = lround(stod(str));
    return l;
}

int main()
{
    long int a = (long int)5.6;
    long int b;
    string s ("5.6");

    b << s;

    cout << a << endl;      // 5
    cout << b << endl;      // 6
}
