## 我的第一个 Shell 程序

1. Bash Shell 概述
1. 初识 Bash 程序
1. Bash 表达式求值
1. Bash 流程控制
1. Bash 字符串操作
1. Bash 中的用户交互
1. Bash 脚本程序示例

		
## Bash Shell 概述

1. Bash：GNU `B`ourne-`A`gain `SH`ell。
1. Bash 是几乎所有 Linux 发行版的默认 Shell 程序。
1. Bash 支持编程；通过编写一些小的 Bash 脚本程序，可以完成一些复杂的系统管理和维护工作。
1. Bash 编程非常简单易学； Linux 系统大量使用 Bash 脚本程序来管理系统功能和服务。
1. Bash 脚本程序通过调用内置命令以及已有的系统外部程序完成工作，主要用于系统管理或自动化维护，不适合科学计算、复杂交互和图形用户界面等程序的开发。

		
## 初识 Bash 程序

### 演示视频

[0-5：初识 Bash 程序](#)

1. Linux 系统中已有的 Bash 脚本程序。
1. 最简单的例子；指定解释器、注释以及引用环境变量。
1. 自定义变量和特殊变量。
1. 执行 Bash 程序的方法。

	
### 知识点：Bash 保留变量

- `$0`, `$1`, `$2`等：表示系统传给脚本程序或脚本程序传给函数的第零个（即脚本程序的名称或函数名）、第一个、第二个等参数。
- `$#`：表示脚本程序的命令参数个数或函数的参数个数。
- `$$`：表示该脚本程序的进程号，常用于生成文件名唯一的临时文件。
- `$?`：表示脚本程序或函数的返回状态值，正常为 0，否则为非零的错误号。
- `$*` 或 `$@`：表示所有的脚本参数或函数参数。
- `$RANDOM`：这个变量用于生成一个从 0 到 65535 的随机数。

		
## Bash 表达式求值

### 演示视频

[0-6：在 Bash 程序中进行表达式求值](#)

1. UNIX 设计哲学。
1. Bash 只支持两种数据类型：整数和字符串。
1. `let` 指令和 `expr` 程序：四则运算表达式的求值。

	
### 知识点：针对整数的运算符

1. `+`：加。
1. `-`：减。
1. `*`：乘。
1. `/`：除。
1. `%`：模（余数）。

```bash
#!/bin/bash

x=2024
let "x = $x + 1"
echo $x
x="The next year is"$x
echo $x
```

		
## Bash 流程控制

### 讲解及演示视频

[0-7：流程控制的由来](#)

[0-8：Bash 的流程控制](#)

1. `if` 指令及逻辑判断：`test` 程序和 `[` 程序。
1. `for` 指令。
1. `while` 指令。
1. `case` 指令。

	
### 知识点：`[` 程序支持的对比操作

| 操作          | 整数  | 字符串    |
| --            | --    | --        |
| 相同          | -eq   |  =        |
| 不同          | -ne   |  !=       |
| 大于          | -gt   |  >        |
| 小于          | -lt   |  <        |
| 大于或等于    | -ge   |  >=       |
| 小于或等于    | -le   |  <=       |
| 为空          |       | -z        |
| 不为空        |       | -n        |

	
### 知识点：`[` 程序判断文件许可

- `-e FILE` 文件 FILE 已经存在（`e`xisted）
- `-f FILE` 文件 FILE 是普通文件（regular `f`ile）
- `-s FILE` 文件 FILE 存在且大小不为零（`s`ize larger than zero）
- `-d FILE` 文件 FILE 存在且是一个目录（`d`irectory）
- `-r FILE` 文件 FILE 存在且对当前用户可以读取（`r`eadable）
- `-w FILE` 文件 FILE 存在且对当前用户可以写入（`w`ritable）
- `-x FILE` 文件 FILE 存在且对当前用户可以执行（e`x`ecutable）
- `-O FILE` 文件 FILE 存在且是属于当前用户的（`O`wner）
- `FILE1 -nt FILE2` 文件 FILE1 比 FILE2 更新（`n`ewer `t`han）
- `FILE1 -ot FILE2` 文件 FILE1 比 FILE2 更老（`o`lder `t`han）

	
### 知识点：条件判断

```bash
#!/bin/bash

if [ $1 -gt 90 ]
then
    echo "Good, $1"
elif [ $1 -gt 70 ]
    then
        echo "OK, $1"
    else
        echo "Bad, $1"
fi

exit 0
```

	
### 知识点：`for` 循环

使用通配符列出当前目录下匹配的文件：

```bash
#!/bin/bash

for file in *.sh
do
    echo $file
done

exit 0
```

	
### 知识点：`while` 循环

	
### 知识点：`until` 循环

	
### 知识点：`case` 分支

```bash
#!/bin/bash

echo "Hit a key, then hit return."
read Keypress

case "$Keypress" in
  [a-z] ) echo "Lowercase letter";;
  [A-Z] ) echo "Uppercase letter";;
  [0-9] ) echo "Digit";;
  * ) echo "Punctuation, whitespace, or other";;
esac

exit 0
```

		
## Bash 函数

### 讲解及演示视频

[0-9：函数的由来](#)

[0-10：Bash 函数和局部变量](#)

1. Bash 函数的写法。
1. Bash 函数的调用。
1. Bash 函数中的局部变量。

	
### 知识点

```bash
#!/bin/bash

area_of_square() {
    let "res = $1 * $1"
    return $res
}

area_of_square $1
result=$?
echo $result

exit 0
```

		
## Bash 字符串操作

### 演示视频

[0-11：Bash 字符串操作](#)

	
### 知识点

- `${var:pos}`：表示变量 `$var` 仅保留从 `pos` 开始的剩余字符。
- `${var:pos:len}`：表示变量 `$var` 中仅保留从 `pos` 开始的前 `len` 个字符。
- `${var/pattern/replacement}`：表示将变量 `$var` 中第一个出现的 `pattern` 模式替换为 `replacement` 字符串。
- `${var//pattern/replacement}`：表示将变量 `$var` 中出现的所有 `pattern` 模式全部都替换为 `replacment` 字符串。

		
## Bash 中的用户交互

### 演示视频

[0-12：Bash 中的用户交互](#)

1. 使用 `select` 指令。
1. 使用 `read` 指令。

	
### 知识点

```baseh
#!/bin/bash

OPTIONS="Hello Quit"
select opt in $OPTIONS; do
  if [ "$opt" = "Quit" ]; then
    echo done
    exit
  elif [ "$opt" = "Hello" ]; then
      echo Hello World
    else
      clear
      echo bad option
  fi
done

exit 0
```

```bash
#!/bin/bash

echo Please enter your name
read NAME
echo "Hi! $NAME !"

exit 0
```

		
## Bash 示例脚本程序

```base
#!/bin/bash

area_of_square() {
    let "area = $1 * $1"
    return $area
}

area_of_circle() {
    let "area = 3 * $1 * $1"
    return $area
}

clear
OPTIONS="Square Circle Quit"
echo "To calculate the area of a surface, please select one shape:"
select opt in $OPTIONS; do
    if [ "$opt" = "Quit" ]; then
        echo done
        exit 0
    elif [ "$opt" = "Square" ]; then
        echo Please input the lenght of a side of the square:
        read D
        area_of_square $D
        S=$?
        echo "area of the suare($D): "$S
        echo `date` ": $USER call area_of_square($D): $S" >> formulas.log
    elif [ "$opt" = "Circle" ]; then
        echo Please input the lenght of the radius of the circle:
        read R
        area_of_circle $R
        S=$?
        echo "area of the circle($R): "$S
        echo `date` ": $USER call area_of_circle($R): $S" >> formulas.log
    else
        echo Bad option
    fi
done

exit 0
```

		
## 作业

1. 增强本讲给出的“Bash 示例脚本程序”，增加至少一个计算面积的函数。运行效果如下：

```console
$ ./my-first-bash-program.sh
To calculate the area of a surface, please select one shape:
1) Square
2) Circle
3) Quit
#? 1
Please input the lenght of a side of the square:
10
area of the suare(10): 100
#?
```

