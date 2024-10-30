# 中期综合练习

1. 三种算术运算表达式
1. 将中缀表达式解析为求值二叉树
1. 综合练习
1. 实用技巧及工具

		
## 算术运算表达式

`Arithmetic operation expression`

	
### 三种算术运算表达式

- 如果不将负号视作取反运算符的话，则算术运算符均为双目运算符。
- 前缀表达式（prefix expression）：运算符（operator）位于操作数（operand）之前（波兰式）
   - 简单形式：`+ 3 5`
   - 复杂形式：`+ 3 * 5 8 `
- 中缀表达式（infix expression）：运算符位于操作数之间
   - 简单形式：`3 + 5`
   - 复杂形式：`3 + 5 * 8`
- 后缀表达式（postfix expression）：运算符位于操作数之后（逆波兰式）
   - 简单形式：`3 5 +`
   - 复杂形式：`5 8 * 3 +`
- 前缀表达式和后缀表达式的解析和求值，只需要栈即可完成。
- 中缀表达式可转换为前缀表达式或后缀表达式再行求值；亦可解析为求值二叉树再后序遍历求值。

	
#### 前缀表达式的求值

- 算法描述：
  1. 创建一个空的操作数栈 `operands`。
  1. 从右至左扫描表达式，分解出词元（token）。
  1. 若词元为数值，则将数值压入 `operands`；若词元为运算符，则从 `operands` 弹出两个数值，用当前运算符对它们做相应的计算（`先弹出的数值作为运算符左操作数，后弹出的数值作为运算符右操作数`），然后将结果压入 `operands`。
  1. 重复上述过程直到表达式中的词元全部处理完成；`operands` 栈顶的数值即为该表达式的求值结果。
- 例如：`- × + 3 4 5 6`
  1. 从右至左扫描，依次将 `6`、`5`、`4`、`3` 压入 `operands`。
  1. 其后是 `+` 运算符，从 `operands` 中依次弹出 `3` 和 `4`，计算 `3 + 4`，得 `7`，再将 `7` 压入 `operands`。
  1. 其后是 `×` 运算符，从 `operands` 中依次弹出 `7` 和 `5`，计算 `7 × 5`，得 `35`，将 `35` 压入 `operands`。
  1. 其后是 `-` 运算符，从 `operands` 中依次弹出 `35` 和 `6`，计算 `35 - 6`，得 `29`，将 `29` 压入 `operands`。
  1. 表达式扫描完成，取出栈顶数值 `29`，得出表达式的求值结果为 `29`。

	
#### 参考实现

```cpp
#include <iostream>     // for std::cin and std::cout
#include <string>       // for std::string
#include <deque>        // for std::deque
#include <cstdlib>      // for strtod()
#include <cctype>       // for isdigit()
#include <cassert>      // for assert()

using namespace std;

double evaluate_prefix_expression(string exp)
{
    deque<double> operands;

    while (!exp.empty()) {
        const char* last_token;

        size_t found = exp.rfind(' ');
        if (found != string::npos) {
            last_token = exp.c_str() + found + 1;
        }
        else {
            found = 0;
            last_token = exp.c_str();
        }

        if (strlen(last_token) == 1 && !isdigit(*last_token)) {
            if (operands.size() < 2) {
                throw std::invalid_argument("Bad expression");
            }

            double left = operands.back();
            operands.pop_back();
            double right = operands.back();
            operands.pop_back();
            double result;

            switch (*last_token) {
            case '+':
                result = left + right;
                break;

            case '-':
                result = left - right;
                break;

            case '*':
                result = left * right;
                break;

            case '/':
                result = left / right;
                break;

            default:
                throw std::invalid_argument("Unknown operator");
                break;
            }

            operands.push_back(result);
        }
        else {
            char* end;
            double operand = strtod(last_token, &end);
            if (end == last_token) {
                throw std::invalid_argument("Bad operand");
            }

            operands.push_back(operand);
        }

        exp.erase(found);
    }

    if (operands.size() > 0) {
        return operands.back();
    }

    throw std::invalid_argument("Bad expression");
    return 0;
}

    assert(evaluate_prefix_expression("+ 1 2") == 3);
    assert(evaluate_prefix_expression("- 10 20") == -10);
    assert(evaluate_prefix_expression("* 3 2") == 6);
    assert(evaluate_prefix_expression("/ 6 2") == 3);
    assert(evaluate_prefix_expression("- * + 3 4 5 6") == 29);
```

	
#### 后缀表达式的求值

- 算法描述：
  1. 创建一个空的操作数栈 `operands`。
  1. 从左到右扫描表达式，分解出词元。
  1. 若词元为数值，则将数值压入`operands`；若词元为运算符，则从 `operands` 弹出两个数值，用当前运算符对它们做相应的计算（`先弹出的数值作为运算符右操作数，后弹出的数值作为运算符左操作数`），然后将结果压入`operands`。
  1. 重复上述过程直到表达式全部处理完成；`operands` 栈顶数值即为该表达式的求值结果。
- 例如：`3 4 + 5 × 6 -`
  1. 将数值 `3`、`4` 压入栈。
  1. 其后是 `+` 运算符，从 `operands` 中依次弹出 `3` 和 `4`，计算 `4 + 3`，得 `7`，再将 `7` 压入 `operands`。
  1. 其后是数值 `5`，压入 `operands`。
  1. 其后是 `×` 运算符，从 `operands` 中依次弹出 `5` 和 `7`，计算 `7 × 5`，得 `35`，将 `35` 压入 `operands`。
  1. 其后是数值 `6`，压入 `operands`。
  1. 其后是 `-` 运算符，从 `operands` 中依次弹出 `6` 和 `35`，计算 `35 - 6`，得 `29`，将 `29` 压入 `operands`。
  1. 表达式扫描完成，取出栈顶数值 `29`，得出表达式的求值结果为 `29`。

	
#### 参考实现

```cpp
#include <iostream>     // for std::cin and std::cout
#include <string>       // for std::string
#include <stack>        // for std::stack
#include <cstdlib>      // for strtod()
#include <cctype>       // for isdigit()
#include <cassert>      // for assert()

using namespace std;

double evaluate_postfix_expression(string exp)
{
    stack<double> operands;

    while (!exp.empty()) {
        const char* token = exp.c_str();

        size_t found = exp.find(' ');
        size_t token_len;
        if (found != string::npos) {
            token_len = found;
        }
        else {
            token_len = exp.length();
            found = token_len - 1;
        }

        if (token_len == 1 && !isdigit(*token)) {
            if (operands.size() < 2) {
                throw std::invalid_argument("Bad expression");
            }

            // 注意栈顶操作数应该是右操作数
            double right = operands.top();
            operands.pop();
            double left = operands.top();
            operands.pop();
            double result;

            switch (*token) {
            case '+':
                result = left + right;
                break;

            case '-':
                result = left - right;
                break;

            case '*':
                result = left * right;
                break;

            case '/':
                result = left / right;
                break;

            default:
                throw std::invalid_argument("Unknown operator");
                break;
            }

            operands.push(result);
        }
        else {
            char* end;
            double operand = strtod(token, &end);
            if (end == token) {
                throw std::invalid_argument("Bad operand");
            }

            operands.push(operand);
        }

        exp.erase(0, found + 1);
    }

    if (operands.size() > 0) {
        return operands.top();
    }

    throw std::invalid_argument("Bad expression");
    return 0;
}

    assert(evaluate_postfix_expression("1 2 +") == 3);
    assert(evaluate_postfix_expression("10 20 -") == -10);
    assert(evaluate_postfix_expression("3 2 *") == 6);
    assert(evaluate_postfix_expression("6 2 /") == 3);
    assert(evaluate_postfix_expression("3 4 + 5 * 6 -") == 29);
```

	
#### 中缀表达式转换为前缀表达式

- 算法描述：
  1. 初始化两个栈：运算符栈 `operators` 和结果的栈 `result`。
  1. 从右至左扫描中缀表达式，分解出词元。
  1. 当词元为操作数时，将其压入 `result`。
  1. 当词元为运算符时，比较其与 `operators` 栈顶运算符的优先级。
     1. 如果 `operators` 为空，或栈顶运算符为右括号 `)`，则直接将此运算符入栈；
     1. 否则，若该运算符的优先级比栈顶运算符`高或相等`，将该运算符压入 `operators`；
     1. 否则，将 `operators` 栈顶的运算符弹出并压入到 `result` 中，并转到步骤 4.1。
  1. 遇到括号时，
     1. 如果是右括号 `)`，则直接压入 `operators`。
     1. 如果是左括号 `(`，则依次弹出 `operators` 栈顶的运算符，并压入 `result`，直到遇到右括号为止，此时将这一对括号丢弃。
  1. 重复步骤2，直到表达式的最左边。
  1. 将 `operators` 中剩余的运算符依次弹出并压入 `result`。
  1. 依次弹出 `result` 中的元素并输出，结果即为中缀表达式对应的前缀表达式。

	
- 举例：将中缀表达式 `a+((b+c)×d)-e` 转换为前缀表达式

| 词元  | `result`                  | `operators`       | 说明                                          |
| ---   | ---                       | ---               | ---                                           |
| e     | e                         | EMPTY             | 数值，压入 `results` 栈                       |
| -     | e                         | -                 | 运算符，`operators` 为空，直接入栈            |
| )     | e                         | ), -              | 右括号，压入 `operators` 栈                   |
| d     | d, e                      | ), -              | 数值，压入 `results` 栈                       |
| ×     | d, e                      | ×, ), -           | `operators` 栈顶是右括号，直接入栈            |
| )     | d, e                      | ), ×, ), -        | 右括号，压入 `operators` 栈                   |
| c     | c, d, e                   | ), ×, ), -        | 数值，压入 `results` 栈                       |
| +     | c, d, e                   | +, ), ×, ), -     | `operators` 栈顶是右括号，直接入栈            |
| b     | b, c, d, e                | ), ×, ), -        | 数值，压入 `results` 栈                       |
| (     | + b, c, d, e              | ×, ), -           | 左括号，弹出运算符直至遇到右括号              |
| (     | ×, + b, c, d, e           | -                 | 左括号，从`operators`弹出运算符并压入`result`直至遇到右括号 |
| +     | ×, + b, c, d, e           | +, -              | 优先级与栈顶的 `-` 相同，直接入栈             |
| a     | a, ×, + b, c, d, e        | +, -              | 数值，压入 `results` 栈                       |
| NONE  | -, +, a, ×, + b, c, d, e  | EMPTY             | 从 `operators` 弹出所有运算符并压入 `result`  |

	
#### 中缀表达式转换为后缀表达式

- 算法描述：
  1. 初始化两个栈：运算符栈 `operators` 和结果栈 `result`。
  1. 从左至右扫描中缀表达式，分解出词元
  1. 当词元为操作数时，将其压入 `result`。
  1. 党词元为运算符时，比较其与 `operators` 栈顶运算符的优先级：
     1. 如果 `operators` 为空，或栈顶运算符为左括号 `(`，则直接将此运算符入栈；
     1. 否则，若该运算符的优先级比栈顶运算符`高`，将该运算符压入 `operators`；
     1. 否则，将 `operators` 栈顶的运算符弹出并压入到 `result` 中，并转到步骤 4.1。
  1. 遇到括号时，
     1. 如果是左括号 `(`，则直接压入 `operators`；
     1. 如果是右括号 `)`，则依次弹出 `operators` 栈顶的运算符，并压入 `result`，直到遇到左括号为止，此时将这一对括号丢弃。
  1. 重复步骤2，直到表达式的最右边；
  1. 将 `operators` 中剩余的运算符依次弹出并压入 `result`；
  1. 依次弹出 `result` 中的元素并输出，其结果的`逆序`即为中缀表达式对应的后缀表达式。

	
- 举例：将中缀表达式 `a+((b+c)×d)-e` 转换为后缀表达式

| 词元  | `result`                  | `operators`    | 说明                                          |
| ---   | ---                       | ---               | ---                                           |
| a     | a                         | EMPTY             | 数值，压入 `results` 栈                       |
| +     | a                         | +                 | 运算符，`operators` 为空，直接入栈            |
| (     | a                         | (, +              | 左括号，压入 `operators` 栈                   |
| (     | a                         | (, (, +           | 左括号，压入 `operators` 栈                   |
| b     | b, a                      | (, (, +           | 数值，压入 `results` 栈                       |
| +     | b, a                      | +, (, (, +        | `operators` 栈顶是左括号，直接入栈            |
| c     | c, b, a                   | +, (, (, +        | 数值，压入 `results` 栈                       |
| )     | +, c, b, a                | (, +              | 右括号，弹出运算符压入`result`直至遇到左括号  |
| ×     | +, c, b, a                | ×, (, +           | `operators` 栈顶是左括号，直接入栈            |
| d     | d, + c, b, a              | ×, ), +           | 数值，压入 `results` 栈                       |
| )     | ×, d, + c, b, a           | +                 | 右括号，弹出运算符压入`result`直至遇到左括号  |
| -     | +, ×, d, + c, b, a        | -                 | 优先级与栈顶的 + 相同，先弹出 + 并压入`result`，再压入 -  |
| e     | e, +, ×, d, + c, b, a     | -                 | 数值，压入 `results` 栈                       |
| NONE  | -, e, +, ×, d, + c, b, a  | EMPTY             | 从 `operators` 弹出所有运算符并压入 `result`  |

		
## 将中缀表达式解析为求值二叉树

- 原理
   1. 单个双目算术运算，可构成一个以操作数为叶子节点，结果为根节点的二叉树。
   1. 有多个运算符参与的混合运算，按优先级或者括号递归处理，然后将这些二叉树铰接在一起；如果某个二叉树的根将作为另一个运算二叉树的操作数，则将其铰接（splice）到那个二叉树上，成为其子节点。此时，括号、前后两个运算符的优先级，将决定如何铰接两个二叉树。
   1. 通过后序遍历求出所有内部节点的值，结束后根节点的值即为表达式的最终求值结果。

	
- 举例
  1. `3 + 5`
  1. `3 + 5 - 6`
  1. `3 + (5 - 6)`
  1. `3 + (5 - 6) × 6`
  1. `(3 + (5 - 6) × 6) ÷ (4 × (3 - 8))`

	
- 课堂思考：中缀表达式的求值二叉树和前后缀表达式之间有何关系？

		
## 综合练习

`Comprehensive Practices`

	
### 第一题：算术表达式解析器

- 编写一个算术表达式解析器（`arithmetic-expression-parser.cpp`）完成中缀表达式的解析和求值。
- 要求支持如下功能：
  1. 读取用户输入的中缀算术表达式；该表达式支持加减乘除四则混合运算，支持负号、括号。
  1. 将中缀表达式转换为前缀表达式进行求值，输出前缀表达式及其求值结果。
  1. 将中缀表达式转换为后缀表达式进行求值，输出后缀表达式及其求值结果。
  1. 将中缀表达式解析为求值二叉树进行求值，按求值二叉树输出其正规中缀表达式（全部使用括号表示运算顺序）及其求值结果。
  1. 若发现表达式有误，输出 `INVALID`。

	
- 运行效果如下：

```console
$ ./arithmetic-expression-parser
<300.5 + 50.6>  // 注意：运算符和操作数之间可能包括任意多的空白字符。
Prefix expression: + 300.5 50.6
    = 351.1
Postfix expression: 50.6 300.5 +
    = 351.1
Normalized infix expression: (300.5 + 50.6)
    = 351.1

$ ./arithmetic-expression-parser
<300.5 + ((5 + 10.6) * 85>
INVALID
```

	
#### 实现时要考虑的问题

- 假定表达式使用十进制表示实数或整数，表达式支持 `+`、`-`、`*`、`/`、`%` 五种运算以及 `()`，且不含非法字符。
- 如何处理负号（`-`）？
  1. 若表达式字符串中，运算符和操作符之间没有任何空白字符，则无法有效区分前缀和后缀表达式中的负号和减号。
  1. 有两种解决办法：可将负号转为减法运算，比如 `-5`，对应 `0 - 5`；或者始终在运算符和操作数之间插入至少一个空白字符，而负号和数字之间不插入任何空白字符。
  1. 中缀表达式中，可通过上下文判断是否为负号，比如 `-3 + -5`，或者 `(-3) + (-5)`。
- 如何判断非法表达式？
  1. 前缀和后缀表达式的处理中，在执行运算时，若操作数栈中只有一个操作数，则对应表达式为非法。
  1. 将中缀表达式转换为前缀或后缀表达式时，若出现括号不匹配的情形，则表达式为非法。
  1. 将中缀表达式解析为求值二叉树时，若出现括号不匹配的情形，或者没有预期的操作数时，则表达式为非法。
- 如何判断表达式中括号的嵌套关系？
  1. 参考中缀表达式转前缀表达式的算法，使用栈来跟踪括号的嵌套关系。

	
### 第二题：使用霍夫曼编码压缩解压文件

- 编写程序 `huffman-encode.cpp`，该程序使用霍夫曼编码压缩作为命令行参数指定的文本文件（若未指定文件名则从标准输入读取；对文件中的非 ASCII 码，全部使用 `?` 替代），并将压缩后的内容保存为二进制文件 `huffman-code.bin`。运行效果如下：

```console
./huffman-encode huffman-encode.cpp
File compressed and saved to huffman-code.bin (11631 -> 3456 bytes).

./huffman-encode
<asdfasdfasdf sadfasf asf asdf asfsafasfasf^D>        # Ctrl+D（^D） 表示输入结束。
File compressed and saved to huffman-code.bin (43 -> 121 bytes).
```

- 编写程序 `huffman-decode.cpp`，该程序读取 `huffman-code.bin` 中的内容并还原为原始文本并输出到标准输出。运行效果如下：

```console
./huffman-decode
asdfasdfasdf sadfasf asf asdf asfsafasfasf
```

	
#### 实现时要考虑的问题

- 如何将霍夫曼树存储到文件且便于再读入？
- 如何处理变长编码？

		
## 实用技巧及工具

`Skills and Utilities`

	
### C++ STL 字符串转换接口（函数）

| 函数      | 用途 |
| ---       | ---  |
| `stoi`    | 字符串转换为整数（int）                           |
| `stol`    | 字符串转换为长整型（long）                        |
| `stoul`   | 字符串转换为无符号整型（unsigned long）           |
| `stoll`   | 字符串转换为长长整型（long long）                 |
| `stoull`  | 字符串转换为无符号长长整型（unsigned long long）  |
| `stof`    | 字符串转换为单精度浮点数（float）                 |
| `stod`    | 字符串转换为双精度浮点数（double）                |
| `stold`   | 字符串转换为长双精度浮点数（long double）         |

	
- 原型及用法（`stol` 为例）

```cpp
#include <string>

long stol(const string& str, size_t* idx = 0, int base = 10);

    std::string str_bad = "xyz";
    std::string str_dec = "1987520";
    std::string str_hex = "2f04e009";
    std::string str_bin = "-11101001100100111010";
    std::string str_auto = "0x7fffff";

    std::string::size_type sz;   // alias of size_t

    long li_bad = std::stol(str_bad, &sz);      // sz = 0; li_bad = 0;
    long li_dec = std::stol(str_dec, &sz);
    long li_hex = std::stol(str_hex, nullptr, 16);
    long li_bin = std::stol(str_bin, nullptr, 2);
    long li_auto = std::stol(str_auto, nullptr, 0);
```

- 参数说明
  1. `str`：用于表达一个数值的字符串对象。
  1. `idx`：如果 `idx` 不是空指针，则该函数会将 `idx` 的值设置为 `str` 中合法数值后的第一个字符的索引。
  1. `base`：决定有效字符及其解释的数字基数（进制）。如果此值为 `0`，则使用的进制由字符串序列的格式决定（如 `0x` 前缀表示 16 进制）。注意此参数的默认值为为 `10`，而不是 `0`。

	
### C 字符串转换接口（函数）

| 函数      | 用途 |
| ---       | ---  |
| `atoi`    | 字符串转换为整数（int）                   |
| `strtol`  | 字符串转换为长整型（long）                |
| `strtoul` | 字符串转换为无符号整型（long long）       |
| `strtoll` | 字符串转换为长长整型（long long）         |
| `strtoull`| 字符串转换为无符号长长整型（unsigned long long）|
| `strtof`  | 字符串转换为单精度浮点数（float）         |
| `strtod`  | 字符串转换为双精度浮点数（double）        |
| `strtold` | 字符串转换为长双精度浮点数（long double） |

	
- 原型及用法示例

```cpp
#include <cstdlib>

int atoi(const char* str);
long int strtol(const char* str, char** endptr, int base);
long double strtold(const char* str, char** endptr);

  char reals[] = "90613.305 365.24";
  char* end;

  long double f1, f2;
  f1 = strtold(reals, &end);
  f2 = strtold(end, NULL);
```

	
### 浮点数取模接口

```cpp
#include <cmath>

float fmodf(float x, float y);
double fmod(double x, double y);
long double fmodl(long double x, long double y);
```

- 对浮点数亦可定义取模运算：设 `fmod(x, y)` 的返回值为 `m`，则有 `x = n * y + m`，其中 `n` 是整数，`m` 和 `x` 有相同的符号，而且 `m` 的绝对值小于 `y` 的绝对值。

	
### 位运算

- C++ 二进制位运算符
   1. 位非：`~`；
   1. 位与：`&`；位与并赋值：`&=`
   1. 位或：`|`；位或并赋值：`|=`
   1. 位亦或：`^`；位亦或并赋值：`^=`
   1. 左移：`<<`；左移并赋值：`<<=`
   1. 右移：`>>`；右移并赋值：`>>=`
- 二进制位的表述规则：
   1. 最高位（most significant bit，MSB），始终在最左侧。
   1. 最低位（least significant bit，LSB），始终在最右侧。

	

```cpp
unsigned char set_bit_in_byte(unsigned char byte, size_t index)
{
    assert(index < 8);
    unsigned char my_byte = 0x01 << index;
    return (byte | my_byte);
}

unsigned char clear_bit_in_byte(unsigned char byte, size_t index)
{
    assert(index < 8);
    unsigned char my_byte = 0x01 << index;
    return (byte & ~my_byte);
}

bool is_bit_set_in_bytes_array(unsigned char* bytes, size_t index_bit)
{
    size_t index_byte = index_bit / 8;
    index_bit %= 8;

    return (bytes[index_byte] & (0x01 << index_bit));
}
```

	
### STL 文件读写流

#### 复习一下基础 STL 文件读写相关类和对象

- [课件：C++ STL（标准模板库）](https://courses.fmsoft.cn/plzs/cpp-class-template-and-stl.html#/6)

	
#### `open()` 方法和文件打开模式

- `void std::fstream::open(const char* filename, ios_base::openmode mode = ios_base::in | ios_base::out);`：打开或创建文件。
- `void std::fstream::open(const string& filename, ios_base::openmode mode = ios_base::in | ios_base::out);`：打开或创建文件。

----

| 打开模式              | 含义                                                           |
| ---                   | ---                                                            |
| `ios_base::in`        | 输入（input）；打开文件用于读取。                              |
| `ios_base::out`       | 输出（output）；打开文件用于写入。                             |
| `ios_base::binary`    | 二进制（binary）；文件上的读写操作以二进制数据进行而不是文本。 |
| `ios_base::ate`       | 尾部（at end）；打开时的读写位置在文件尾部。                   |
| `ios_base::app`       | 追加（append）；所有的输出操作发生在文件尾部。                 |
| `ios_base::trunc`     | 截断（truncate）；打开时，文件中已有的任何内容将被清除/废弃。  |

	
```cpp
#include <fstream>      // std::fstream

int main()
{
    std::fstream fs;
    fs.open("test.txt",
            std::fstream::in | std::fstream::out | std::fstream::app);
    fs << "This is a line\n";
    fs.close();
    return 0;
}
```

	
#### 更基础的字符读写方法及状态判断

- `istream::get()` 读取单个或者多个字符。
- `ostream::put()` 写入单个字符。
- `bool ios::eof()` 可用来判断是否到达文件尾。
- `bool ios::fail()` 可用来判断是否产生文件读写错误。
- `EOF` 表示文件尾（end of file），是一个常量宏，在 `<cstdio>` 中定义其值为 `-1`。

	
```cpp
// 读取单个字符，在无内容可读取的情况下返回 `EOF`
int istream::get();
// 读取单个字符到 c，不返回 `EOF`。
istream& istream::get(char& c);

// 读取到 C 字符串缓冲区
istream& istream::get(char* s, streamsize n);
istream& istream::get(char* s, streamsize n, char delim);

// 写入单个字符。
ostream& ostream::put(char c);

// 判断是否到达文件尾
bool ios::eof() const;

// 判断是否失败
bool ios::fail() const;

    std::fstream fs { "test.txt", std::fstream::in };
    if (fs.fail()) {
        cerr << "Failed to open 'test.txt'\n";
    }
    else {
        int c;
        while ((c = fs.get()) != EOF) {
            cout.put((char)c);
        }
        fs.close();
    }
```

	
#### 输入输出流的缓冲模式

- 缓冲模式
   1. 行缓冲（文本模式）
   1. 块缓冲/完全缓冲（二进制模式）
   1. 无缓冲
- 操作器 `ostream& flush(ostream& os);` 可用于刷新输出缓冲区。
- 操作器 `ostream& endl(ostream& os);` 输出新行符，行缓冲模式下同时刷新输出缓冲区。
- `ostream& std::ostream::flush();` 方法可用于刷新输出缓冲区。
- `void std::fstream::close();` 方法在关闭文件读写流之前，也会刷新输出缓冲区。

	
#### 二进制模式常用读写方法

- 格式化输入输出和无格式化输入输出的区别。
- `istream& std::istream::read(char* dst, streamsize n);` 方法从流中读取指定长度的字节到目标内存。
- `ostream& std::ostream::write(const char* src, streamsize n);` 方法将目标内存中指定长度的字节写入流。
- `istream& std::istream::seekg(streamoff off, ios_base::seekdir way);` 方法修改输入流的读取位置。
- `streamoff std::istream::tellg();` 方法获得输入流的当前读取位置。
- `ostream& std::ostream::seekp(streamoff off, ios_base::seekdir way);` 方法修改输出流的写入位置。
- `streamoff std::ostream::tellp();` 方法获得输出流的当前写入位置。

----

| 定位方式          | 含义                              |
| ---               | ---                               |
| `ios_base::beg`   | 相对于流的起始位置（beginning）   |
| `ios_base::cur`   | 相对于流的当前位置（current）     |
| `ios_base::end`   | 相对于流的结束位置（end）         |

	
#### 二进制读写示例程序

- [完整示例程序](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-4/fstream-binary.cpp)
- 思考：将一般的类对象以二进制形式存入文件后再行读取，是否可行？

```cpp
#include <iostream>     // std::cout and std::cerr
#include <fstream>      // std::ofstream and std::ifstream

using namespace std;

int main()
{
    struct student {
        int id;
        int age;
        float height;
        float weight;
        char  name[16];
    } students[] = {
        { 10001, 10, 159.0f, 55.5f, "Tom" },
        { 10002, 11, 160.0f, 58.5f, "Jerry" },
    };

    ofstream ofs;
    ofs.open("students.bin",
            ofstream::out | ofstream::binary | std::ostream::app);
    for (size_t i = 0; i < sizeof(students)/sizeof(students[0]); i++) {
        ofs.write((const char*)(students + i), sizeof(struct student));
    }
    ofs.close();

    ifstream ifs("students.bin", ofstream::in | ofstream::binary);
    if (ifs) {
        // 调用 seekg() 将读取位置置于文件尾。
        ifs.seekg(0, ifs.end);
        // 然后调用 tellg() 确定文件长度。
        size_t length = ifs.tellg();

        // 确定文件中保存的学生记录数
        size_t nr_students = length/sizeof(struct student);

        // XXX 改变流中的读取位置到文件头
        ifs.seekg(0, ifs.beg);

        // 依次读取学生记录并输出基本信息
        for (size_t i = 0; i < nr_students; i++) {
            struct student student;

            ifs.read((char*)(&student), sizeof(struct student));
            cout << "Got a student: " << student.id
                << " (" << student.name << ")\n";
        }

        ifs.close();
    }
    else {
        cerr << "Failed to open students.bin file\n";
    }
}
```

	
#### 输入/输出流的重定向

- 重定向（redirect）的概念。
- Shell 中重定向标准输出、标准错误的方法：
  1. `$ PROGRAM [1]>FILE`：将标准输出重定向到文件 `FILE`。
  1. `$ PROGRAM 2>FILE`：将标准错误重定向到文件 `FILE`。
  1. `$ PROGRAM [1]>>FILE`：将标准错误重定向并追加到文件 `FILE`。
- Shell 中重定向标准输入的方法：
  1. `$ PROGRAM <FILE`：将标准输入重定向为文件 `FILE`，程序将从 `FILE` 中读取输入内容。
- C++ STL 输入/输出流的 `std::streambuf` 对象：
  1. 每个文件流（`std::ifstream`、`std::ofstream` 或 `std::ofstream`）关联有一个 `std::filebuf` 对象。
  1. 每个字符串流（`std::stringstream`）关联有一个 `std::stringbuf` 对象。
  1. `std::filebuf` 和 `std::stringbuf` 类是 `std:streambuf` 的子类。

	
#### 动态改变 C++ 的流对象的流缓冲区对象

- 使用 STL `std::ios::rdbuf()` 方法，通过设置输入输出流对象的流缓冲区对象，可实现“重定向”。
- [示例程序](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-4/iostream-rdbuf.cpp)

```cpp
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // 备份 cin 和 cout 的默认 filebuf 对象
    streambuf *cin_backup, *cout_backup;
    cin_backup = cin.rdbuf();
    cout_backup = cout.rdbuf();

    // 打开要参与重定向的文件
    fstream in, out;
    in.open("in.txt", ios::in | ios::out | ios::trunc);
    out.open("out.txt", ios::out | ios::app);
    if (in.fail() || out.fail())
        return -1;

    // 向 `in.txt` 文件写入一个整数
    in << 1000 << endl;

    in.seekg(0, in.beg);

    // 将 `in` 的 filebuf 对象设置给 cin 使用
    cin.rdbuf(in.rdbuf());

    // 将 `out` 的 filebuf 对象设置给 cout 使用
    cout.rdbuf(out.rdbuf());

    // 此后在 cin 和 cout 上的读取和写入，
    // 相当于从 in.txt 中读取，向 out.txt 写入。
    int n;
    cin >> n;
    cout << n << endl;

    // 恢复 cin 和 cout 的 filebuf 对象
    cin.rdbuf(cin_backup);
    cout.rdbuf(cout_backup);

    // 关闭 in 和 out 流
    in.close();
    out.close();

    return 0;
}
```

