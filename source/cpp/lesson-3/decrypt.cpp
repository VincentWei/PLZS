#include <iostream>
#include <cctype>
#include <cassert>

using namespace std;

int main()
{
    string ciphertext, decrypted;
    cin >> ciphertext;

    // use C++ STL string.
    for (size_t i = 0; i < ciphertext.size(); i++) {
        char c = ciphertext[i];

        // decrypt here.
        if (islower(c)) {
            c = (c + 26 - 7);
            if (c > 'z') {
                c = 'a' + c - 'z' - 1;
            }
        }
        else if (isupper(c)) {
            c = c - 'A';
            c += 26 - 7;
            c %= 26;
            c += 'A';
        }
        else if (c == '&') {
            c = ' ';
        }

        decrypted.push_back(c);
    }
    cout << decrypted << endl;
}
