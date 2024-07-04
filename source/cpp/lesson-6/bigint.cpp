/*
 * This program implements arbitrary arithmetic for integer numbers.
 *
 * Author: Vincent Wei
 *  - <https://github.com/VincentWei>
 *  - <https://gitee.com/vincentwei7>
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * License: GPLv3
 */
#include <vector>
#include <string>
#include <cstdint>

using namespace std;

class BigInt {
    bool _sign;
    vector<int8_t> _bytes;

  public:
    BigInt() {
        _sign = false;
        _bytes.push_back(0);
    }

    BigInt(intmax_t ll);
    BigInt(const std::string& str);
    BigInt(const BigInt &other);            // copy constructor

    bool sign() const { return _sign; }
    const vector<int8_t>& bytes() const { return _bytes; }

    BigInt& operator+ (const BigInt& other) const;
    BigInt& operator- (const BigInt& other) const;
    BigInt& operator- () const;             // -bi

    BigInt& operator++ ();                  // ++bi
    BigInt& operator++ (int);               // bi++

    BigInt& operator-- ();                  // --bi
    BigInt& operator-- (int);               // bi--

    BigInt& operator* (const BigInt& other) const;
    BigInt& operator*= (const BigInt& other);

    BigInt& operator/ (const BigInt& other) const;
    BigInt& operator/= (const BigInt& other);

    BigInt& operator= (const BigInt& other) const;
    BigInt& operator+= (const BigInt& other);
    BigInt& operator-= (const BigInt& other);

    bool operator== (const BigInt& other) const;
    bool operator!= (const BigInt& other) const;
    bool operator> (const BigInt& other) const;
    bool operator>= (const BigInt& other) const;
    bool operator< (const BigInt& other) const;
    bool operator<= (const BigInt& other) const;
};

BigInt::BigInt(intmax_t ll)
{
    if (ll < 0) {
        _sign = true;
        ll = -ll;
    }
    else
        _sign = false;

    for (size_t i = 0; i < sizeof(intmax_t); i++) {
        if (ll == 0)
            break;

        int8_t r = ll % 100;
        _bytes.push_back(r);
        ll /= 100;
    }
}

BigInt::BigInt(const string& str)
{
    size_t len = str.length();
    if (len == 0) {
        _sign = false;
        _bytes.push_back(0);
        return;
    }

    if (str[0] == '-')
        _sign = true;
    else
        _sign = false;

    size_t left = _sign ? len - 1 : len;
    while (left > 0) {
        string digits;
        size_t pos = len - left;
        if (left > 1) {
            digits = str.substr(pos, 2);
            left -= 2;
        }
        else {
            digits = str.substr(pos, 1);
            left -= 1;
        }

        int r = stoi(digits);
        _bytes.push_back(r);
    }
}

BigInt::BigInt(const BigInt &other)
{
    _sign = other.sign();
    _bytes = other.bytes();
}

#include <iostream>

ostream& operator<< (ostream& os, const BigInt& bi) {
    if (bi.sign()) {
        os << "-";
    }

    auto bytes = bi.bytes();
    for (auto it = end(bytes); ; --it) {
        if (it == end(bytes))
            continue;

        os << (int)*it;
        if (it == begin(bytes))
            break;
    }

    return os;
}

#include <cassert>

int main()
{
    BigInt a(1234567890);
    cout << a << endl;

    BigInt b(-1234567890);
    cout << b << endl;

    BigInt c("123456789");
    cout << c << endl;

    BigInt d("-123456789");
    cout << d << endl;

    BigInt e("0");
    cout << e << endl;

    BigInt f("10");
    cout << f << endl;

    BigInt g("");
    cout << g << endl;
}

