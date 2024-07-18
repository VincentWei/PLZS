#include <iostream>

using namespace std;

enum rainbow_color {
    red = 1,        // 第一个枚举值默认取 0，亦可赋值改变其初始值。
    orange,         // 其后的依次确定其值。
    yellow,
    green,
    cyan,
    blue,
    purple,
};

// typedef enum rainbow_color rainbow_color_k;
using rainbow_color_k = enum rainbow_color;

const char *rainbow_color_name(rainbow_color_k c)
{
    const char *name = nullptr;

    /* 警告：green 未被 switch 语句处理。 */
    switch (c) {
    case red:
        name = "red";
        break;
    case orange:
        name = "orange";
        break;
    case yellow:
        name = "yellow";
        break;
    case cyan:
        name = "cyan";
        break;
    case blue:
        name = "blue";
        break;
    case purple:
        name = "purple";
        break;
    case 10:    /* 警告：10 不是 rainbow_color 的有效取值。 */
        break;
    }

    return name;
}

int main()
{
    rainbow_color_k rc = red;
    cout << rainbow_color_name(rc) << endl;
}

