#include <iostream>

using namespace std;

union natural {
    unsigned int    natural;
    unsigned short  half[2];
    unsigned char   bytes[4];
};

int main()
{
    cout << sizeof(union natural) << endl;

    union natural n;

    n.natural = 0x12345678;

    cout.setf ( ios::hex, ios::basefield );
    cout.setf ( ios::showbase );
    cout << n.half[0] << ", " << n.half[1] << endl;
    cout << (int)n.bytes[0] << ", " << (int)n.bytes[1] << ", " << (int)n.bytes[2] << ", " << (int)n.bytes[3] << endl;
}
