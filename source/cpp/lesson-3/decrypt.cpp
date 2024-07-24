/*
 * The answer key for Problem 4 of CPP Lesson 3:
 * https://courses.fmsoft.cn/plzs/cpp-data-types.html#/6/3
 *
 * Author: Vincent Wei
 *  - <https://github.com/VincentWei>
 *  - <https://gitee.com/vincentwei7>
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * License: GPLv3
 */
#include <iostream>     // for cin and cout
#include <string>       // for string
#include <cctype>       // for islower() and isuppper()
#include <cassert>      // for assert()

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
