# Bash Shell 编程

1. Bash Shell 概述
1. 初识 Bash 程序
1. Bash 表达式求值
1. Bash 流程控制
1. Bash 字符串操作
1. Bash 中的用户交互
1. 示例脚本程序

		
## Bash Shell 概述

1. Bash：GNU `B`ourne-`A`gain `SH`ell。
1. Bash 是几乎所有 Linux 发行版的默认 Shell 程序。
1. Bash 支持编程；通过编写一些小的 Bash 脚本程序，可以完成一些简单或复杂的系统管理和维护工作。
1. Bash 编程非常简单易学； Linux 系统大量使用 Bash 脚本程序来管理系统功能和服务。
1. Bash 脚本程序通过调用内置命令以及已有的系统外部程序完成工作，主要用于系统管理或自动化维护，不适合科学计算、复杂交互和图形用户界面等程序的开发。

		
## 初识 Bash 脚本

### 演示视频

[1-10-1：初识 Bash 程序](#)

1. 查看 Linux 系统中已有的 Bash 脚本程序。
1. UNIX 设计哲学：每个程序专注于自身的功能，然后通过管道将多个程序串接在一起使用。
1. 最简单的例子；指定解释器、注释以及引用环境变量。
1. 自定义变量和特殊变量。
1. 执行 Bash 程序的方法。

	
### 示例程序：最简单的 Bash 脚本

```bash
#!/bin/bash

# Hello, world!
echo Hello, world!
echo - $USER@$HOSTNAME

FULLNAME='WEI Yongming'
echo - $FULLNAME@$HOSTNAME
```
	
### 知识点：Bash 保留变量

- `$0`, `$1`, `$2`等：表示系统传给脚本程序或脚本程序传给函数的第零个（即脚本程序的名称或函数名）、第一个、第二个等参数。
- `$#`：表示脚本程序的命令参数个数或函数的参数个数。
- `$$`：表示该脚本程序的进程号，常用于生成文件名唯一的临时文件。
- `$?`：表示脚本程序或函数的返回状态值，正常为 0，否则为非零的错误号。
- `$*` 或 `$@`：表示所有的脚本参数或函数参数。
- `$RANDOM`：这个变量用于生成一个从 0 到 65535 的随机数。

		
## Bash 表达式求值

### 演示视频

[1-10-2：在 Bash 程序中进行表达式求值](#)

1. Bash 只支持两种数据类型：整数和字符串。
1. `let` 指令、`((...))` 语法和 `expr` 程序：运算表达式的求值。

	
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
# 等价写法：x=$((x+1))
# 等价写法：((x=x+1))

x="The next year is: "$x
```

		
## Bash 流程控制

### 演示视频

[1-10-3：Bash 流程控制](#)

1. `if` 指令及逻辑判断：`test` 程序和 `[` 程序。
1. Shell 判断一个程序是否成功的条件：程序是否返回 0。
1. `case` 指令。
1. `for` 指令。
1. `while` 和 `until` 指令。

	
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

	
### `if` 分支

- 语法：

```bash
if [CONDITION1]
  [COMMANDS]
then
  [COMMANDS]
elif [CONDITION2]
  then
    [COMMANDS]
  else
    [COMMANDS]
fi
```

	
- 典型用法

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

	
### `case` 分支

- 语法：

```bash
case EXPRESSION in
  Pattern_Case_1)
   STATEMENTS
   ;;
 Pattern_Case_1)
   STATEMENTS
   ;;
 Pattern_Case_N)
   STATEMENTS
   ;;
 *)
   STATEMENTS
   ;;
esac
```

	
- 典型用法

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

	
### `for` 循环

- 语法：

```bash
for item in [LIST]
do
  [COMMANDS]
done
```

	
- 遍历词元（token）：

```bash
for city in Beijing Shanghai Guangzhou Shenzhen
do
  echo "City: $city"
done
```

	
- 遍历数值范围：

```bash
for i in {0..10}
do
  echo "Number: $i"
done

for i in {0..10..2}
do
  echo "Even number: $i"
done
```

	
- 使用通配符列出当前目录下匹配的文件：

```bash
#!/bin/bash

for file in *.sh
do
    echo $file
done

exit 0
```

	
### `while` 循环

- 语法：

```bash
while [CONDITION]
do
  [COMMANDS]
done
```

	
- 累加到指定值：

```bash
i=0
while [ $i -le 2 ]
do
  echo Number: $i
  ((i++))
done
```

	
- 无限循环

```bash
while :
do
  echo "Press <CTRL+C> to exit."
  sleep 1
done
```

	
- 从文件中循环读取一行并进行处理：

```bash
file=/etc/passwd

while read -r line; do
  echo $line
done < "$file"
```

	
### `until` 循环

- 语法：

```bash
until [CONDITION]
do
  [COMMANDS]
done
```

	
- 等待远程 Git 仓库可用：

```bash
#!/bin/bash

until git pull &> /dev/null
do
    echo "Waiting for the git host ..."
    sleep 1
done

echo -e "\nThe git repository is pulled."
```

		
## Bash 函数

### 演示视频

[1-10-4：Bash 函数](#)

1. Bash 函数的写法。
1. Bash 函数的调用。

	
### 典型用法

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

[1-10-5：Bash 字符串操作](#)

	
### 知识点

- `${var:pos}`：表示变量 `$var` 仅保留从 `pos` 开始的剩余字符。
- `${var:pos:len}`：表示变量 `$var` 中仅保留从 `pos` 开始的前 `len` 个字符。
- `${var/pattern/replacement}`：表示将变量 `$var` 中第一个出现的 `pattern` 模式替换为 `replacement` 字符串。
- `${var//pattern/replacement}`：表示将变量 `$var` 中出现的所有 `pattern` 模式全部都替换为 `replacment` 字符串。

	
### 典型用法

		
## Bash 中的用户交互

### 演示视频

[1-10-6：Bash 中的用户交互](#)

1. 使用 `select` 指令。
1. 使用 `read` 指令。

	
### 典型用法

```bash
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

		
## 示例脚本程序

### 定时关机

```bash
#!/bin/bash

while:
do
    hour=`date '+%H'`
    if [ $hour -eq 0 ]
    then
        poweroff
    else
        sleep 1
    fi
done
```

	
### 批量更改后缀名

```bash
#!/bin/bash

if [ $# < 2 ]
then
    echo 'Usage: change-postfix.sh org dst'
fi

for file in *.$1; do
    mv -- "$file" "${file%.$1}.$2"
done
```

	
### 计算面积

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
3) Triangle
4) Quit
#? 1
Please input the lenght of a side of the square:
10
area of the suare(10): 100
#?
```

