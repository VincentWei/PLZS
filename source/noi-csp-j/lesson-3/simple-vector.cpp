/*
 * One example for NOI CSP-J Lesson 3:
 * <https://courses.fmsoft.cn/plzs/noijunior-linear-data-structures.html>
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

#define NR_EXTRA_SLOTS      4

template <class T>
class simple_vector {
    T* _back_array;
    size_t _sz_alloc;
    size_t _sz_actual;

    void expand() {
        T* space = new T[_sz_alloc + NR_EXTRA_SLOTS];
        for (size_t i = 0; i < _sz_actual; i++) {
            space[i] = std::move(_back_array[i]);
        }

        delete[] _back_array;
        _back_array = space;
        _sz_alloc += NR_EXTRA_SLOTS;
    }

public:
    simple_vector() {
        _back_array = nullptr;
        _sz_alloc = 0;
        _sz_actual = 0;
    }

    ~simple_vector() {
        if (_back_array != nullptr) {
            delete[] _back_array;
        }
    }

    size_t size() const {
        return _sz_actual;
    }

    T& operator[] (size_t pos) {
        if (pos < _sz_actual) {
            return _back_array[pos];
        }

        throw std::out_of_range("Out of range!");
    }

    const T& operator[] (size_t pos) const {
        if (pos < _sz_actual) {
            return _back_array[pos];
        }

        throw std::out_of_range("Out of range!");
    }

    void push_back(const T& elem) {
        if (_sz_actual == _sz_alloc) {
            expand();
        }

        _back_array[_sz_actual] = elem;
        _sz_actual++;
    }

    void pop_back() {
        if (_sz_actual > 0) {
            _sz_actual--;
        }
    }

    void insert(const T& elem, size_t pos) {
        if (_sz_actual == _sz_alloc) {
            expand();
        }

        if (pos < _sz_actual) {
            for (size_t i = _sz_actual; i > pos; i--) {
                _back_array[i] = _back_array[i - 1];
            }

            _back_array[pos] = elem;
            _sz_actual++;
        }
        else {
            throw std::out_of_range("Out of range!");
        }
    }

    void erase(size_t pos) {
        if (pos < _sz_actual) {
            for (size_t i = pos + 1; i < _sz_actual; i++) {
                _back_array[i - 1] = _back_array[i];
            }
            _sz_actual--;
        }
        else {
            throw std::out_of_range("Out of range!");
        }
    }

    void clear() {
        if (_back_array == nullptr) {
            delete[] _back_array;
        }

        _back_array = nullptr;
        _sz_alloc = 0;
        _sz_actual = 0;
    }
};

using namespace std;

int main()
{
    string buf;
    getline(cin, buf, '\n');

    simple_vector<double> v;
    while (!buf.empty()) {
        size_t sz;
        double d;
        try {
            d = stod(buf, &sz);
        }
        catch (std::exception& e) {
            d = 0;
            sz = 1;
        }
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

