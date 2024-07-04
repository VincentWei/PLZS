#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char my_tolower(char c)
{
    return tolower(c);
}

int main()
{
    string hexchars("0123456789ABCDEF");

    transform(hexchars.begin(), hexchars.end(), hexchars.begin(), my_tolower);

    cout << hexchars << endl;
}
