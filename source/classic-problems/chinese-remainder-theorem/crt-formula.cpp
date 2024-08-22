/*
 * The formula version for Chinese Remainder Theroem.
 *
 * Author: Vincent Wei
 *  - <https://github.com/VincentWei>
 *  - <https://gitee.com/vincentwei7>
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * License: GPLv3
 */
#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <cassert>

using namespace std;

unsigned gcd_l(unsigned a, unsigned b)
{
    while (b != 0) {
        unsigned tmp = a;
        a = b;
        b = tmp % b;
    }

    return a;
}

intmax_t ex_gcd(intmax_t a, intmax_t b, intmax_t& x, intmax_t& y)
{
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    intmax_t gcd = ex_gcd(b, a % b, x, y);
    intmax_t temp = x;
    x = y;
    y = temp - a / b * y;
    return gcd;
}

// 注意：该函数返回的最小解有可能为负值。
intmax_t resolve_crt_formula(unsigned nr_equations,
        const unsigned *moduli, const unsigned *remainders, intmax_t &m)
{
    m = 1;
    for (unsigned i = 0; i < nr_equations; i++) {
        m *= moduli[i];
    }

    intmax_t sum_ac = 0;
    for (unsigned i = 0; i < nr_equations; i++) {
        intmax_t n = m / moduli[i];

        // x 是 n 在 moduli[i] 意义下的乘法逆元，有可能为负值。
        intmax_t x, y;
        ex_gcd(n, (intmax_t)moduli[i], x, y);
        sum_ac += n * x * remainders[i];
    }

    return sum_ac % m;
}

int main()
{
    unsigned nr_equations;
    cin >> nr_equations;

    // 检查输入合法性
    if (nr_equations == 0) {
        clog << "Bad number of equations: " << nr_equations << endl;
        return 1;
    }

    unsigned moduli[nr_equations];
    unsigned remainders[nr_equations];
    for (unsigned i = 0; i < nr_equations; i++) {
        cin >> moduli[i] >> remainders[i];
        if (moduli[i] == 0) {
                clog << "Bad modulus: " << moduli[i] << endl;
            return 1;
        }
    }

    // 确认模数两两互质
    for (unsigned i = 0; i < nr_equations; i++) {
        for (unsigned j = i + 1; j < nr_equations; j++) {
            unsigned gcd = gcd_l(moduli[i], moduli[j]);
            if (gcd != 1) {
                clog << "Not coprime moduli: "
                     << moduli[i] << " " << moduli[j] << endl;
                return 1;
            }
        }
    }

    intmax_t lcm, min_ans;
    min_ans = resolve_crt_formula(nr_equations, moduli, remainders, lcm);

    int i = 0, real_ans = 0;
    while (real_ans < 10) {
        intmax_t ans = min_ans + lcm * (i++);
        if (ans > 0) {
            cout << ans << endl;
            real_ans++;
        }
    }
}

