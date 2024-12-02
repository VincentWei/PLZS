# 信息学启蒙<br/>`考鼎码规范`

1. 定义及约定
1. 考鼎码程序结构
1. 考鼎码名称及书写规范
1. 考鼎码关键词
1. 考鼎码内置函数
1. 考鼎码外部函数库
1. 考鼎码运算符
1. 考鼎码考鼎码单字节字符
1. 考鼎码考鼎码统一字符
1. 考鼎码考鼎码序列及操作
1. 考鼎码考鼎码字符串及操作
1. 考鼎码考鼎码映射及操作
1. 考鼎码解释器实现要求

		
## 定义及约定

- 考鼎码是一种主要用于青少年信息学启蒙的编程语言，主要特征有：
   - 解释型脚本语言
   - 支持函数和递归调用
   - 弱类型；主要支持整数（任意精度）、系统整数（系统位宽一致的整数）、浮点数、单字节字符、统一字符、字符串、序列和映射
- 考鼎码的英文名为 Coding Code，简称 C2

		
## 考鼎码程序结构

	
### Hello, world!

```mathematica
算始 世界你好
    输出 ("Hello, world!")
算终
```

- `算始/算终` 定义的代码为单个考鼎码程序的唯一入口。

	
### 典型示例

<div class="long-code">

```mathematica
算始 数数游戏必胜
    # 实际调用的是 `输入()` 函数，要添加括号；
    # `整数()` 函数用于将输入字符串转成整数。
    x := 整数(输入())

    若始 (x % 7 == 0)
        # 实际调用的是 `执行()` 函数，功能名称（"拍手"）作为参数传入。
        执行("拍手")
        终止()    # 调用 `终止()` 函数终止算法的执行。
    若否
        y := x
        当始 (y != 0)
            y := y // 10
            r := y % 10
            若始 (r == 7)
                执行("拍手")
                终止()
            若终
        当终

        # 要给 `执行()` 函数传递两个参数。
        # 第一个参数是需要调用的系统功能名称（"说出"），
        # 第二个参数是执行说出功能需要的参数。
        执行("说出", x)
    若终
算终
```

</div>

		
## 名称及书写规范

- 函数名、算法名、变量名只能以拉丁字母、下划线、汉字开头，可包含拉丁字母、数字、下划线和汉字。
- 不可和保留的关键词冲突。
- 大小写敏感； 括号、逗号、运算符等使用半角字符。
- 词元分隔符：半角空格、制表符以及括号（`()`）、逗号（`,`）等。
- 汉字指 UniHan 定义的汉字，不含标点符号以及全角字母等。

		
## 考鼎码关键词

| 关键词      |  解释                   | 示例用法                      |
| ---         |  ---                    | ---                           |
| `算始/算终` |  定义一个算法的开始/终止|                               |
| `函始/函终` |  定义一个函数的开始/终止|                               |
| `若始/若终` |  定义一个判断的开始/结束| `若始 (x > 0)`                |
| `又若`      |  定义一个判断的其他条件 | `又若 (x == 0)`               |
| `若否`      |  定义一个判断的否则条件 |                               |
| `当始/当终` |  定义一个循环的开始/结束| `当始 (x > 0)`                |
| `返回`      |  返回一项数据           | `返回 0`                      |
| `真/假`     |  逻辑真/假值            | `返回 真`                     |
| `非`        |  逻辑非                 | `若始 (非 x > 1)`             |
| `且`        |  逻辑且                 | `若始 (x > 1 且 y > 0)`       |
| `或`        |  逻辑或                 | `若始 (x > 1 或 x < -1)`      |
| `未定义`    |  未定义                 | `返回 未定义`                 |
| `空`        |  空数据                 | `返回 空`                     |
| `导入`      |  导入指定函数库         | `导入 数学库`                 |
| `声明`      |  声明外部函数或全局变量 | `声明 sqrt(x)`                |

		
## 考鼎码内置函数

| 内置函数      |  解释                         | 示例用法                          |
| ---           |  ---                          | ---                               |
| `输入()`      |  提示并读取用户输入           | `x := 输入 ("姓名")`        |
| `整数()`      |  将指定数据转换为整数         | `x := 整数(输入("任意正整数"))`   |
| `系统整数()`  |  将指定数据转换为系统整数     | `x := 系统整数(输入("任意正整数"))`   |
| `字符()`      |  将指定数据转换为统一字符     | `x := 统一字符(输入("任意中文"))`   |
| `单字节字符()`|  将指定数据转换为单字节字符   | `x := 单字节字符(输入("任意字母"))`   |
| `浮点数()`    |  将指定数据转换为浮点数       | `x := 浮点数(输入("任意正整数"))` |
| `输出()`      |  输出变量或者数据             | `输出 (x)`                        |
| `终止()`      |  终止算法执行                 | `终止()`                          |
| `执行()`      |  执行一个系统动作             | `执行 ("拍手")`                   |
| `长度()`      |  返回给定数据的长度           | `长度 (s)`                        |

		
## 考鼎码外部函数库

- 数学库：对 C 语言数学库函数的简单封装

```mathematica
导入 数学库
算始 任意底的对数
    # 真数
    p := 浮点数(输入("真数"))
    # 底数
    b := 浮点数(输入("底数"))

    # 利用换底公式计算 p 对 b 的对数
    x := log2(p) / log2(b)
    输出(x)
算终
```

		
## 考鼎码运算符

### 基本算术运算符

| 名称        | 运算符  | 示例        | 结果  |
| ---         | ---     | ---         | ---   |
| 加法        | `+`     | `3 + 5`     | `8`   |
| 减法        | `-`     | `5 - 3`     | `2`   |
| 乘法        | `*`     | `5 * 3`     | `15`  |
| 除法        | `/`     | `5 / 2`     | `2.5` |
| 整除        | `//`    | `5 // 2`    | `2`   |
| 取模        | `%`     | `5 % 2`     | `1`   |

	
### 赋值运算符

| 名称        | 运算符  | 示例        | 结果            |
| ---         | ---     | ---         | ---             |
| 赋值        | `:=`    | `x := 3`    | `x` 的值为 3    |

	
### 基本逻辑判断运算符

| 名称        | 运算符  | 示例        | 结果    |
| ---         | ---     | ---         | ---     |
| 等于        | `==`    | `3 == 5`    | `假`    |
| 大于        | `>`     | `5 > 3`     | `真`    |
| 小于        | `<`     | `5 < 3`     | `假`    |
| 大于等于    | `>=`    | `5 >= 3`    | `真`    |
| 小于等于    | `<=`    | `5 <= 3`    | `假`    |
| 不等于      | `!=`    | `5 != 3`    | `真`    |

		
## 考鼎码整数

1. 任意整数：默认
1. 系统整数：使用和系统位宽一致的有符号整数类型（等同于 C 语言 `intmax_t` 类型）。
1. 使用 `i` 后缀定义系统整数字面量。

| 操作              | 运算符        | 示例                          | 结果                          |
| ---               | ---           | ---                           | ---                           |
| 定义任意整数      | `:=`          | `i := 1234`                   | `i` 是任意整数                |
| 定义系统整数      | `:=`          | `i := 1234i`                  | `i` 是系统整数                |
| 转任意整数        | `整数()`      | `i := 整数("12367890")`       | `i` 是任意整数                |
| 转系统整数        | `系统整数()`  | `i := 系统整数("12367890")`   | `i` 是任意整数                |

		
## 考鼎码单字节字符

1. 单字节字符：同 C 语言 `unsigned char` 类型；使用单引号定义字面量。
1. 考鼎码中单字节字符的基本操作

| 操作              | 运算符        | 示例                          | 结果                          |
| ---               | ---           | ---                           | ---                           |
| 定义单字节字符    | `:=`          | `c := 'A'`                    | `c` 的值为 0x41               |
| 定义单字节字符    | `:=`          | `c := '\xA1'`                 | `c` 的值为 0x41               |
| 转单字节字符      | `单字节字符()`| `c := 单字节字符 ("ABCD")`    | `c` 的值为 0x41               |

		
## 考鼎码统一字符

1. 统一字符：同 C 语言 `uint32_t` 类型；使用一对竖线定义字面量。
1. 考鼎码中统一字符的基本操作：


| 操作              | 运算符        | 示例                    | 结果                                |
| ---               | ---           | ---                     | ---                                 |
| 定义统一字符      | `:=`          | `uc := |中|`            | `uc` 的值为 0x4E2D                  |
| 定义统一字符      | `:=`          | `uc := |\x4E2D|`        | 使用 Unicode 码点；`uc` 的值为 0x4E2D |
| 定义统一字符      | `:=`          | `uc := |\uE4B8AD|`      | 使用 UTF-8 编码；`uc` 的值为 0x4E2D |
| 转统一字符        | `字符()`      | `uc := 字符("中国")`    | `uc` 的值为 0x4E2D                  |

		
## 考鼎码序列及其操作

1. 序列的定义：一组有序的元素构成
1. 超范围访问均返回 `未定义`；设置给定索引的元素为 `未定义` 将移除该元素。
1. 考鼎码中序列的基本操作

| 操作                          | 运算符  | 示例                    | 结果                          |
| ---                           | ---     | ---                     | ---                           |
| 定义空序列                    | `:=`    | `s := []`               | `s` 是一个空序列              |
| 串接两个序列                  | `+`     | `s := [0, 2] + [3, 4]`  | `s` 为 `[0, 2, 3, 4]`         |
| 获取序列中第 `i` 个元素       | `[i]`   | `a := s[0]`             | `a` 的值为 `0`                |
| 设置序列中第 `i` 个元素       | `[i]`   | `s[0] := 1`             | `s` 变为 `[1, 2, 3, 4]`       |
| 将某个元素插入到序列的前面    | `+`     | `s := [0] + s`          | `s` 变为 `[0, 1, 2, 3, 4]`    |
| 将某个元素追加到序列的后面    | `+`     | `s := s + [5]`          | `s` 变为 `[0, 1, 2, 3, 4, 5]` |
| 使用 `未定义` 移除序列中的元素| `:=`    | `s[0] := 未定义`        | `s` 变为 `[1, 2, 3, 4, 5]`    |

		
## 考鼎码字符串及其操作

1. 字符串：内部使用 UTF-8 编码；本质上是单字节字符构成的序列，结尾包含 `\0` 字符。
1. 使用双引号（`""`）定义字符串字面量。
1. 可通过索引访问字符串中的每个字节。
1. 可使用字符串方法 `.分割()` 将一个字符串按字符或者指定的分隔符进行分隔。
1. 可使用字符串方法 `字符()` 将一个字符串按字符或者指定的分隔符进行分隔。

| 操作                          | 运算符/函数   | 示例                    | 结果                                            |
| ---                           | ---           | ---                     | ---                                             |
| 定义字符串                    | `:=`          | `str := "一个字符串"`   | `str` 是一个单字节字符串。                      |
| 获取长度                      | `长度()`      | `len := 长度(str)`      | `len 的值为 15`                                 |
| 获取字符串中第一个统一字符    | `统一字符()`  | `uc := 统一字符(str)`   | `uc 的值为 0x4E00                               |
| 分割                          | `.分割()`     | `chars := str.分割()`   | `chars 为 ["一", "个", "字", "符", "串"]`       |

		
## 考鼎码映射及其操作

- 参照 Python。

		
## 考鼎码解释器实现要求

1. 循环应有最大上限控制，超过此上限的报 `可能的死循环` 错误。
1. 函数的调用栈帧应有最大上限控制，超过此上限的报 `函数调用嵌套过深` 错误。
1. 应统计算法的基础运算次数、函数调用次数等，并在执行结束后输出统计信息。
1. 在 WASM 平台上，`输入()` 函数的实现应通过对话框进行，加上提示信息。
1. 可基于 HVML PurC 解释器提供的变体实现各数据类型。
1. 可基于 C++ `bigint` 类实现对任意精度整数的支持。
