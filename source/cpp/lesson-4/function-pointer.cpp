#include <iostream>
#include <iostream>

using namespace std;

bool largerthan(int a, int b)
{
    return a > b;
}

bool lessthan(int a, int b)
{
    return a < b;
}

bool equalto(int a, int b)
{
    return a == b;
}

bool compare(char symbol, int a, int b)
{
    // 声明 op 变量为一个函数指针；该函数有两个整型参数，返回值类型为 bool。
    bool (*op)(int, int);

    // 根据 symbol 选择一个已有的对比函数
    switch (symbol) {
        case '>':
            op = largerthan;
            break;
        case '<':
            op = lessthan;
            break;
        case '=':
            op = equalto;
            break;
        default:
            op = nullptr;
            break;
    }


    // 调用对比函数
    if (op)
        return op(a, b);

    return false;
}

int main()
{
    char symbol;
    int a, b;

    cin >> symbol >> a >> b;

    cout << (compare(symbol, a, b) ? "true" : "false") << endl;
}

