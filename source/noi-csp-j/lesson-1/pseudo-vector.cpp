/*
 * One example for NOI CSP-J Lesson 1:
 * <https://courses.fmsoft.cn/plzs/noijunior-basic-algorithms.html>
 *
 * Author: Vincent Wei
 *  - <https://github.com/VincentWei>
 *  - <https://gitee.com/vincentwei7>
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * License: GPLv3
 */
#include <iostream>     // for cin and cout
#include <string>       // for stod()
#include <stdexcept>    // for std::out_of_range
#include <cassert>      // for assert()

#define PVSZ_MAX 100

template <class T>
struct pseudo_vector {
    T _buf[PVSZ_MAX];
    size_t _sz;

    pseudo_vector() {
        _sz = 0;
    }

    size_t size() const {
        return _sz;
    }

    T& operator[] (size_t n) {
        if (n < _sz) {
            return _buf[n];
        }

        throw std::out_of_range("Out of range!");
    }

    const T& operator[] (size_t n) const {
        if (n < _sz) {
            return _buf[n];
        }

        throw std::out_of_range("Out of range!");
    }

    void push_back(const T& elem) {
        if (_sz < PVSZ_MAX) {
            _buf[_sz] = elem;
            _sz++;
        }
        else {
            throw std::overflow_error("Reached space limit.");
        }
    }

    void pop_back() {
        if (_sz > 0) {
            _sz--;
        }
    }

    void insert(const T& elem, size_t pos) {
        if (_sz == PVSZ_MAX) {
            throw std::overflow_error("Reached space limit.");
        }

        if (pos < _sz) {
            for (size_t i = _sz; i > pos; i--) {
                _buf[i] = _buf[i - 1];
            }

            _buf[pos] = elem;
            _sz++;
        }
        else {
            throw std::out_of_range("Out of range!");
        }
    }

    void erase(size_t pos) {
        if (pos < _sz) {
            for (size_t i = pos + 1; i < _sz; i++) {
                _buf[i - 1] = _buf[i];
            }
            _sz--;
        }
        else {
            throw std::out_of_range("Out of range!");
        }
    }
};

using namespace std;

int main()
{
    string buf;
    getline(cin, buf, '\n');

    pseudo_vector<double> v;
    size_t n = 0;
    while (!buf.empty() && n < PVSZ_MAX) {
        size_t sz;
        double d = stod(buf, &sz);
        buf = buf.substr(sz);
        v.push_back(d);
    }

    cout << "Origin vector:" << endl;
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    v.push_back(0);

    cout << "Vector after calling push_back(0):" << endl;
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    v.pop_back();
    cout << "Vector after calling pop_back():" << endl;
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    v.insert(0, 0);
    cout << "Vector after calling insert(0, 0):" << endl;
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    v.erase(0);
    cout << "Vector after calling erase(0):" << endl;
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

