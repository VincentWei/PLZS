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
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

bool D(const vector<int> &v, int n) {
  for (int i = 1; i < n; ++i) {
    if (v[i] == v[i - 1]) {
      return false;
    }
  }
  return true;
}

bool O(const vector<int> &v, int n) {
  return all_of(v.begin(), v.begin() + n, [](int x) { return x % 2 == 1; });
}

void dump(const vector<int> &v, int n) {
  for (int i = 0; i < n; i++) {
    cout << v[i] << ' ';
  }
  cout << '\n';
}

void SD(int n, unsigned int *dn) {
  vector<int> buffer(n + 1, 0);

  int k = 1;
  buffer[1] = n;

  while (k != 0) {
    int x = buffer[k - 1] + 1;
    int y = buffer[k] - 1;
    k--;
    while (x <= y) {
      buffer[k] = x;
      y -= x;
      k++;
    }
    buffer[k] = x + y;

    if (D(buffer, k + 1)) {
      dump(buffer, k + 1);
      (*dn)++;
    }
  }
}

void SO(int n, unsigned int *on) {
  vector<int> buffer(n + 1, 0);

  int k = 1;
  buffer[1] = n;

  while (k != 0) {
    int x = buffer[k - 1] + 1;
    int y = buffer[k] - 1;
    k--;
    while (x <= y) {
      buffer[k] = x;
      y -= x;
      k++;
    }
    buffer[k] = x + y;
    if (O(buffer, k + 1)) {
      dump(buffer, k + 1);
      (*on)++;
    }
  }
}

int main() {
  int n = 0;
  cin >> n;

  cout << "D(" << n << ")" << endl;
  unsigned dn = 0;
  SD(n, &dn);

  cout << "---" << endl;

  clog << "O(" << n << ")" << endl;
  unsigned on = 0;
  SO(n, &on);

  assert(dn == on);

  cout << endl;

  return 0;
}
