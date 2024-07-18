#include <iostream>

using namespace std;

void matrix()
{
    // 定义一个 4 行、5 列的矩阵（二维数组）
    double matrix[4][5] = {
        {1., 2., 3., 4., 5.},
        {2., 3., 4., 5., 1.},
        {3., 4., 5., 1., 2.},
        {4., 5., 1., 2., 3.},
    };

    // 使用双重循环遍历二维数组中的每个单元
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] *= 100.0;
        }
    }

    // 获取行指针并按照一维数组访问行内每个单元
    for (int i = 0; i < 4; i++) {
        double *row = matrix[i];
        for (int j = 0; j < 5; j++) {
            row[j] *= 100.0;
        }
    }

    // 获取首个单元的指针并按照一维数组访问二维数组中的每个单元
    double *unit = &matrix[0][0];
    for (int i = 0; i < 4; i++) {
        double *row = unit + i * 5;
        for (int j = 0; j < 5; j++) {
            row[j] *= 100.0;
        }
    }
}

int main()
{
    const char *names[] = {
        "Julia",
        "Lisa",
        "Tom",
    };

    for (size_t i = 0; i < sizeof(names)/sizeof(names[0]); i++) {
        for (int j = 0; true; j++) {
            if (names[i][j] == '\0')
                break;

            char c = (char)toupper(names[i][j]);
            cout << c;
        }

        cout << endl;
    }
}
