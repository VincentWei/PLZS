/*
 * The answer key for Problem 2 of CPP Lesson 5:
 * <https://courses.fmsoft.cn/plzs/cpp-class-template-and-stl.html#/8/1>
 *
 * Author: Vincent Wei
 *  - <https://github.com/VincentWei>
 *  - <https://gitee.com/vincentwei7>
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * License: GPLv3
 */
#include <iostream> // for cout and cin
#include <string>   // for string
#include <vector>   // for vector
#include <cstdio>   // for BUFSIZ
#include <cctype>   // for isalnum() and isspace()

using namespace std;

int main()
{
    char buf[BUFSIZ];
    cin.getline(buf, sizeof(buf));

    string line(buf);

    vector<string> words;

    bool word_start = false;
    size_t start_pos = 0;
    for (size_t i = 0; i < line.length(); i++) {
        char c = line[i];

        if (i == line.length() - 1 || !isalnum(c) || isspace(c)) {
            if (word_start && i > start_pos) {
                // got a new word.
                string word = line.substr(start_pos, i - start_pos);
                words.push_back(word);
                word_start = false;
            }
        }
        else if (isalnum(c) && !word_start) {
            // start of a new word.
            word_start = true;
            start_pos = i;
        }
    }

    // find the longest word
    size_t max_len = 0;
    string *longest_one = nullptr;
    for (size_t i = 0; i < words.size(); i++) {
        if (words[i].length() > max_len) {
            max_len = words[i].length();
            longest_one = &words[i];
        }
    }

    if (longest_one)
        cout << *longest_one << " " << max_len << endl;
}

