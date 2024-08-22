/*
 * The plain version for Chinese Remainder Theroem.
 *
 * Author: Vincent Wei
 *  - <https://github.com/VincentWei>
 *  - <https://gitee.com/vincentwei7>
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * License: GPLv3
 */
#include <iostream>
#include <climits>      // for UINT_MAX

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

unsigned resolve_crt_plain(unsigned nr_equations,
        const unsigned *moduli, const unsigned *remainders)
{
    // 找到最小的模数，并确定起始值；这是在数组中找最小值的经典代码。
    unsigned min_mod = UINT_MAX, min_ans;
    for (unsigned i = 0; i < nr_equations; i++) {
        if (moduli[i] < min_mod) {
            min_mod = moduli[i];
            min_ans = remainders[i];
        }
    }

    cerr << min_mod << " " << min_ans << endl;

    while (true) {
        unsigned nr_satisfied = 0;

        // 就 min_ans 的当前值测试是否满足各个方程。
        for (unsigned i = 0; i < nr_equations; i++) {
            if ((min_ans % moduli[i]) == remainders[i]) {
                nr_satisfied++;
            }
        }

        // 如果满足方程的数量等于方程的总数，
        // 则 min_ans 的当前值就是该方程组的最小解。
        if (nr_satisfied == nr_equations) {
            break;
        }

        // 判断溢出
        if (min_ans + min_mod < min_ans) {
            return 0;
        }

        min_ans += min_mod;
    }

    return min_ans;
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

    // 最小公倍数
    unsigned lcm = 1;
    for (unsigned i = 0; i < nr_equations; i++) {
        lcm *= moduli[i];
    }

    unsigned min_ans = resolve_crt_plain(nr_equations, moduli, remainders);
    if (min_ans == 0) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    for (unsigned i = 0; i < 10; i++) {
        cout << (min_ans + lcm * i) << endl;
    }
}

