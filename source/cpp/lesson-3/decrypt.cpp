#include <iostream>
#include <cctype>
#include <cassert>

using namespace std;

int main()
{
    string ciphertext, decrypted;
    cin >> ciphertext;

    // Method 1: use C++ STL string.
    for (size_t i = 0; i < ciphertext.size(); i++) {
        char c = ciphertext[i];

        // decrpt here.
        // ...

        decrypted.push_back(c);
    }
    cout << decrypted << endl;

    decrypted.clear();

    // Method 1: use C string.
    const char* p = ciphertext.c_str();
    while (*p) {
        char c = *p;

        // decrpt here.
        // ...

        decrypted.push_back(c);
        p++;
    }

    cout << decrypted << endl;
}