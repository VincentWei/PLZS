/*
 * This program implements arbitrary precision arithmetic for integer numbers.
 *
 * This program is a part of PLZS (the Programming Lessons for
 * Zero-based Students Aged 10+) project.
 * For more information about PLZS, please visit:
 *
 *  - <https://github.com/VincentWei/PLZS>
 *  - <https://gitee.com/vincentwei7/PLZS>
 *
 * Author: Vincent Wei
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * License: GPLv3
 */
#include <array>
#include <vector>
#include <string>
#include <algorithm>
#include <exception>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <cassert>
#include <cinttypes>

/* Choose one of the following macros */
// #define USE_INT8_AS_SLICE   1
// #define USE_INT16_AS_SLICE  1
#define USE_INT32_AS_SLICE  1

class bigint {
  public:
#if defined(USE_INT32_AS_SLICE)
    using slice_t = int32_t;
    using twin_t  = int64_t;
    using slice_v = std::vector<bigint::slice_t>;
    static const int slice_width_k = 8;             //    9999 9999
    static const int max_slice_nint_k = 99999999;   // 21 4748 3647 (int32max)
    static const int slice_base_k = (max_slice_nint_k + 1); // 1 00000000
    static const int max_nint_slices_k = 2;    // 922 33720368 54775807
    static const int max_group_slices_k = 1;
    static const int group_base_k = 100000000;
        // slice_base_k ^ max_group_slices_k
#elif defined(USE_INT16_AS_SLICE)
    using slice_t = int16_t;
    using twin_t  = int32_t;
    using slice_v = std::vector<bigint::slice_t>;
    static const int slice_width_k = 4;             //   9999
    static const int max_slice_nint_k = 9999;       // 3 2767 (int16max)
    static const int slice_base_k = (max_slice_nint_k + 1); // 1 0000
    static const int max_nint_slices_k = 4;    // 922 3372 0368 5477 5807
    static const int max_group_slices_k = 2;
    static const int group_base_k = 100000000;
        // slice_base_k ^ max_group_slices_k */
#elif defined(USE_INT8_AS_SLICE)
    using slice_t = int8_t;
    using twin_t  = int16_t;
    using slice_v = std::vector<bigint::slice_t>;
    static const int slice_width_k = 2;             //   99
    static const int max_slice_nint_k = 99;         // 1 27 (int8max)
    static const int slice_base_k = (max_slice_nint_k + 1); // 1 00
    static const int max_nint_slices_k = 9;    // 922 33 72 03 68 54 77 58 07
    static const int max_group_slices_k = 4;
    static const int group_base_k = 1000000000;
        // slice_base_k ^ max_group_slices_k
#endif

  private:
    class slice_a {
       size_t  _size;
       slice_t _slices[max_nint_slices_k];

    public:
       slice_a(): _size(0) { }

       slice_a(slice_t slice) {
           _size = 1;
           _slices[0] = slice;
       }

       size_t size() const { return _size; };

       void clear() { _size = 0; }

       void push_back(slice_t val) {
           assert(_size < max_nint_slices_k);
           _slices[_size] = val;
           _size++;
       }

       slice_t operator[](size_t i) const {
           assert(i < _size);
           return _slices[i];
       }

       slice_t front() const {
           return _slices[0];
       }

       slice_t back() const {
            if (_size > 0)
                return _slices[_size - 1];
            return 0;
       }
    };

  public:
    bigint(): _sign(false) { }

    bigint(intmax_t nint);
    bigint(const std::string& str);
    bigint(const bigint& other);            // copy constructor
    bigint(bigint&& other);                 // move constructor

    // some getters
    bool sign() const { return _sign; }
    const slice_v& slices() const { return _slices; }
    slice_t last_slice() const {
        if (_slices.size() == 0)
            return 0;
        return _slices.back();
    }

    // getter or setter for max number of slices for native integer
    static int max_nint_slices();

    // some setters
    void sign(bool sign) { _sign = sign; }
    void reverse() { _sign = !_sign; }

    // overloaded operators
    bigint& operator= (const bigint& other);        // copy assignment operator
    bigint& operator= (bigint&& other) noexcept;    // move assignment operator
    bigint& operator= (intmax_t other);

    bigint  operator+  (const bigint& other) const;
    bigint& operator+= (const bigint& other);
    bigint  operator+  (intmax_t other) const;
    bigint& operator+= (intmax_t other);

    bigint  operator-  () const;             // -bi

    bigint  operator-  (const bigint& other) const;
    bigint& operator-= (const bigint& other);
    bigint  operator-  (intmax_t other) const;
    bigint& operator-= (intmax_t other);

    bigint& operator++ ();                  // ++bi
    bigint  operator++ (int);               // bi++

    bigint& operator-- ();                  // --bi
    bigint  operator-- (int);               // bi--

    bool operator== (const bigint& other) const;
    bool operator!= (const bigint& other) const;
    bool operator>  (const bigint& other) const;
    bool operator>= (const bigint& other) const;
    bool operator<  (const bigint& other) const;
    bool operator<= (const bigint& other) const;

    bool operator== (intmax_t other) const;
    bool operator!= (intmax_t other) const;
    bool operator>  (intmax_t other) const;
    bool operator>= (intmax_t other) const;
    bool operator<  (intmax_t other) const;
    bool operator<= (intmax_t other) const;

    bigint  operator*  (const bigint& other) const;
    bigint& operator*= (const bigint& other);
    bigint  operator*  (intmax_t other) const;
    bigint& operator*= (intmax_t other);

    bigint  operator/  (const bigint& other) const;
    bigint& operator/= (const bigint& other);
    bigint  operator/  (intmax_t other) const;
    bigint& operator/= (intmax_t other);

    bigint  operator%  (const bigint& other) const;
    bigint& operator%= (const bigint& other);
    bigint  operator%  (intmax_t other) const;
    bigint& operator%= (intmax_t other);

    static bool divmod(const bigint& dividend, const bigint& divisor,
            bigint& quotient, bigint& remainder);
    static bool divmod(const bigint& dividend, intmax_t divisor,
            bigint& quotient, bigint& remainder);

    bigint abs() const;
    int abscmp(const bigint& other) const;

  private:
    static int _max_nint_slices;

    template <class T>
    static void initfrom(intmax_t nint, T& slices);

    bool _sign;
    slice_v _slices;

    void initfrom(intmax_t nint);
    void normalize();
    bool iszero() const {
        if (_slices.size() == 0 ||
                (_slices.size() == 1 and _slices[0] == 0))
            return true;
        return false;
    }

    bool isone() const {
        if (_slices.size() == 1 and _slices[0] == 0)
            return true;
        return false;
    }

    template <class T>
    static intmax_t makenint(const T& slices, size_t off = 0,
            size_t len = max_group_slices_k);

    template <class Ta, class Tb>
    static void absadd(const Ta& one, const Tb& other, bigint& result);
    template <class Ta, class Tb>
    static int  abscmp(const Ta& one, const Tb& other);
    template <class Ta, class Tb>
    static void abssub(const Ta& one, const Tb& other, bigint& result);
    template <class Ta, class Tb>
    static void absmul(const Ta& one, const Tb& other, bigint& result);
    template <class T>
    static void absdiv_slice(const T& dividend, slice_t divisor,
            bigint& quotient, bigint& remainder);
    template <class T>
    static void absdiv_nint(const T& dividend, intmax_t divisor,
            bigint& quotient, bigint& remainder);
    template <class Ta, class Tb>
    static bool absdiv_fast(const Ta& dividend, const Tb& divisor,
            bigint& quotient, bigint& remainder);

    static void absdiv_slow(const bigint& dividend, const bigint& divisor,
            bigint& quotient, bigint& remainder);

    template <class T>
    static void absmod_slice(const T& dividend, slice_t divisor,
            bigint& remainder);
    template <class T>
    static void absmod_nint(const T& dividend, intmax_t divisor,
            bigint& remainder);

    template <class T>
    void abssubfrom(const T& other);
    template <class T>
    void absaddto(const T& other);

    static slice_t quick_modulo(slice_t factor, slice_t base, uintmax_t exp,
            slice_t modulus, slice_t rem_pre = 0);
    static intmax_t quick_modulo_128(intmax_t factor, intmax_t base,
            uintmax_t exp, intmax_t modulus, intmax_t rem_pre = 0);
};

#include <iostream>

std::ostream& operator<< (std::ostream& os, const bigint& bi);

