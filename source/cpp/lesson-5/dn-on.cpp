/*
 * The answer key for Problem 5 of CPP Lesson 5:
 * <https://courses.fmsoft.cn/plzs/cpp-class-template-and-stl.html#/8/4>
 *
 * Author: Long Long
 *
 * Revised by Vincent Wei
 *  - <https://github.com/VincentWei>
 *  - <https://gitee.com/vincentwei7>
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * License: GPLv3
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

vector<int> v_;
vector<vector<int>> r_;
static int s_[100];

void S(int n, int m, int i, int k)
{
    if (n == k && n != m)
    {
        i = 0;
        if (!v_.empty())
        {
            r_.push_back(v_);
            v_.clear();
        }
    }
    if (n == 1)
    {
        v_.push_back(1);
        r_.push_back(v_);
        v_.clear();
        return;
    }
    else if (m == 1)
    {
        for (int i = 0; i < n; i++)
        {
            v_.push_back(1);
        }
        r_.push_back(v_);
        v_.clear();
        return;
    }
    if (n < m)
    {
        S(n, n, i, k);
    }
    else if (n == m)
    {
        v_.push_back(n);
        r_.push_back(v_);
        v_.clear();
        for (int j = 0; j < i; j++)
        {
            v_.push_back(s_[j]);
        }
        S(n, m - 1, i, k);
    }
    else
    {
        v_.push_back(m);
        s_[i++] = m;
        S(n - m, m, i, k);
        i--;
        for (int j = 0; j < i; j++)
        {
            v_.push_back(s_[j]);
        }
        S(n, m - 1, i, k);
    }
}

bool D(const vector<int>& v)
{
    vector<int> sorted = v;
    sort(sorted.begin(), sorted.end());
    for (size_t i = 1; i < sorted.size(); ++i) 
    {
        if (sorted[i] == sorted[i - 1])
        {
            return false;
        }
    }
    return true;
}


bool O(const vector<int>& v)
{
    return all_of(v.begin(), v.end(), [](int x) { return x % 2 == 1; });
}

void dump(const vector<int>& v)
{
    for (auto e : v)
    {
        cout << e << " ";
    }
    cout << '\n';
}


int main()
{
    int n = 0;
    cin >> n;

    if (n <= 0 || n > 31) {
        return 1;
    }

    S(n, n, 0, n);

    cout << "D(" << n << ")" << endl;
    unsigned dn = 0;
    for (const auto& i : r_) {
        if (D(i)) {
            dump(i);
            dn++;
        }
    }

    cout << "---" << endl;

    clog << "O(" << n << ")" << endl;
    unsigned on = 0;
    for (const auto& i : r_) {
        if (O(i)) {
            dump(i);
            on++;
        }
    }

    assert(dn == on);

    cout << endl;

    return 0;
}

