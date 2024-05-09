# 使用 Linux 桌面系统

1. 初识开发环境：终端和命令行
1. 常用系统命令及工具
1. 有趣的 Shell 命令行
1. 用 Vim 编辑文本文件
1. 使用 Gtypist 练习键盘打字
1. 要点回顾
1. 作业

		
## 初识开发环境：终端和命令行

	
### 演示视频

[0-2-1：初识 Ubuntu Linux 桌面环境](https://www.douyin.com/video/7355037996367744296)

1. 通过程序坞（Dock）启动应用。
1. 启动浏览器（FireFox）；访问 PLZS 仓库以及在线课件；设置书签。
1. 使用启动台（luncher），查找设置程序（settings）；启动设置程序，展示各系统设置选项。
1. 使用启动台（luncher），查找终端程序（terminal）；启动终端程序；了解外壳程序（shell）及命令提示字符串。
1. 在终端中使用 `pwd` 打印当前目录并使用 `ls` 展示当前目录中的文件。
1. 将终端、设置程序添加到程序坞中。
1. 启动文件管理器，对比终端中的目录项；了解 Linux 文件系统和 Windows 文件系统的区别。
1. 运行 `sudo apt` 命令更新或升级系统。
1. 在命令行按上下键翻看命令行历史。

	
### 知识点：演示视频涉及的术语

- 终端（terminal）：该术语来自早期的计算机操作控制台，操作员通过一个可显示固定大小字符的显示器和一个键盘操控计算机。在图形显示器上的终端程序，是用软件模拟字符显示器运行的，也叫伪（pseudo）终端。
- 外壳（shell）：操作系统为字符终端上的用户提供的最基本程序，用于输入（input）命令（command）并获得命令的执行结果。在这里，由于命令包括外壳程序的内部命令和外部程序（program）两种形式，故而使用命令这一术语。
- 提示字符串（prompt string，PS）：外壳（或类似程序）展示在行首的提示文本，用于向用户表明可以输入一个新的命令了。在文档或者书籍当中，针对普通用户的命令，提示字符串通常使用 `$` 结尾；针对超级用户的命令，提示字符串通常使用 `#` 结尾。

	
### 知识点：演示视频涉及的术语

- 命令行（command line）：输入给计算机外壳程序一串文本，用于描述计算机需要完成的工作。通常由程序的名字和一组选项组成，如 `python3 -i devel/python/my-first-program.py`。
- 命令行界面（command line interface，CLI）：通过字符终端提供菜单、输入文本等功能的界面。由于硬件能力所限，无法展示图形、图像、视频等内容。
- 图形用户界面（graphics user interface，GUI）：通过图形显示器提供菜单、窗口、对话框等交互功能的界面。可展示丰富的图形、图像和视频等内容。
- 交互（interaction）：指用户（人）和计算机之间的互动。用户提供的数据叫输入（input），计算机提供的数据叫输出（output）。

	
### 知识点：演示视频涉及的系统命令

- `sudo`：以超级（`s`uper）用户（`u`ser）身份干活（`do`）。
- `apt`：Ubuntu 使用的软件包管理工具：
   - `apt install`：安装（`install`）某个软件包。
   - `apt remove`：移除（`remove`）某个软件包。
   - `apt update`：检查是否有需要更新（`update`）的软件包。
   - `apt upgrade`：升级（`upgrade`）软件包到最新版本。
- `pwd`：打印（`p`rint）当前（current）或工作（`w`orking）目录（`d`irectory）。
- `cd`：改变（`c`hange）目录（`d`irectory）。
- `ls` 或 `ll`：列出（`l`i`s`t）当前目录中的文件和子目录。

	
### 知识点：一些常识

1) Linux 或类 UNIX 系统中的文件系统没有盘符的概念。
2) Linux 或类 UNIX 系统中文件的路径（path）使用斜杆（slash，`/`）符号分隔目录，而 Windows 使用盘符和反斜杠（backslash，`\`）。
3) 大部分情况下可用 `Ctrl+C`（`^C`） 终止一个正在运行的命令；如果是全屏运行的程序，大部分情况下可以按 `q` 键退出。
4) Linux 命令是区分大小写的，通常使用小写字母。键入时要注意字符的全角（fullwidth）和半角（halfwidth）的区别。
5) 命令行中的参数（argument）通常用来表示命令要操作的目标对象，比如文件名、主机名等；选项（option）用来表示执行该命令时的动作开关或标志。
6) 当参数中包含空白字符时，可使用单引号或者双引号包围该参数。

	
### 知识点：一些常识（续）

7) 大部分情况下可用 `--help` 选项来显示一个命令的简易使用说明。
8) 命令使用说明文档中的一些约定或习惯写法：
   - 命令的选项和参数通常使用大写单词表示。
   - `[]` 包围起来表示可选的部分，不使用 `[]` 包围的表示一定要出现。
   - `...` 表示某个部分可以多次重复出现。
9) 命令行中的选项通常使用 `-` 或者 `--` 打头，前者只用一个字母区别不同的选项；后者用单词或者用 `-` 连接的短语区别不同的选项。

	

举个例子

```console
$ mkdir --help
Usage: mkdir [OPTION]... DIRECTORY...
Create the DIRECTORY(ies), if they do not already exist.

Mandatory arguments to long options are mandatory for short options too.
  -m, --mode=MODE   set file mode (as in chmod), not a=rwx - umask
  -p, --parents     no error if existing, make parent directories as needed
  -v, --verbose     print a message for each created directory
  -Z                   set SELinux security context of each created directory
                         to the default type
      --context[=CTX]  like -Z, or if CTX is specified then set the SELinux
                         or SMACK security context to CTX
      --help     display this help and exit
      --version  output version information and exit

GNU coreutils online help: <https://www.gnu.org/software/coreutils/>
Full documentation <https://www.gnu.org/software/coreutils/mkdir>
or available locally via: info '(coreutils) mkdir invocation'
```

		
## 常用系统命令及工具

- 大部分常用的系统命令由自由软件基金会的 GNU 项目开发。
- `GNU`：`G`NU's `N`ot `U`nix；递归命名。
- 自由软件基金会创始人 Richard Stallman 的故事。

	
### 有关文件系统的一些常识

- Linux 系统中的文件系统被组成成单个层次结构（hierarchy），根目录表示为 `/`。
- 一个目录项（directory entry）指目录中的某个子（child）目录或者文件。
- 在文件系统中定位一个目录项时，使用 `/` 分隔目录层次关系，从而构成指向这个目录项的路径（path）。
- Linux 系统中的绝对（absolute）路径始终使用 `/` 打头；不以 `/` 打头的路径视作相对（relative）路径，指相对于当前目录的路径。
- `.` 和 `..` 是两个特殊的目录项，分别表示当前目录和父（parent）目录。

	
### 通配符

- 通配符（wildcard）是一种利用特殊字符指代多个字符或者单个字符的简单方法。比如 `A*B` 表示 `A` 开头 `B` 结尾的一个字符串，中间可包含任意数量的任意字符。
- 在 Shell 命令行中使用时，可使用通配符指代匹配（match）对应模式（pattern）的一组文件。
- Shell 通常常用如下几种通配符：
   1. `*`：匹配 0 或多个字符。
   1. `?`：匹配任意单个字符。
   1. `[list]`：匹配 `list` 中的任意单个字符。
   1. `[c1-c2]`：匹配 `c1` 到 `c2` 的任意字符，如 `[0-9]`、`[a-z]`。

	
### 通配符（续）

- Shell 处理命令行参数中的通配符并使用匹配（match）通配符的文件名列表置换通配符参数传入命令；命令行参数被引号包围时不做此处理。

```console
# 查找当前目录下所有名称以 `.md` 结尾的文件；若当前目录下只有一个 `README.md` 文件，
# 则下面的命令行实际等价于 `find . -name README.md`。
$ find . -name *.md
./README.md


# 若使用下面的命令行，则 `*.md` 将被 `find` 处理，从而可以找到当前目录下所有
# 后缀名为 `md` 的文件。
$ find . -name "*.md"
./slides/my-first-python-program.md
./slides/my-first-open-source-repository.md
./slides/python-data-types.md
./slides/preparing-ubuntu-linux.md
./slides/python-flow-control.md
./slides/python-standard-library.md
./slides/bash-shell-programming.md
./slides/using-linux-desktop-system.md
./README.md
```

	
### 正则表达式

- 正则表达式（regular expression, 简称 `regex`）就是用一个“字符串”来描述一个特征，然后去验证另一个“字符串”是否符合这个特征。
- 类似通配符，使用正则表达式描述的字符串特征称为模式，验证的过程就是判断一个字符串是否匹配这个模式。
- 比如模式 `lo[o]?ng` 描述的特征是“`lo` 外加一个可能的 `o`，再加 `ng`”，那么 `long` 和 `loong` 都匹配这个模式。
- 正则表达式是一种比通配符更加强大的字符串特征描述方法，在 Linux 文本处理工具、编程语言以及各种程序中广泛使用：
   - 匹配满足特定模式的行或者文本。
   - 检查用户输入的手机号码、邮件地址等是否正确。
- 大部分编程语言规定的变量名之命名规范符合如下正则表达式：`^[a-zA-Z_][a-zA-Z0-9_]*$`。

	
### Linux Shell 命令行

1. UNIX 设计哲学：
   - 一切皆文件。
   - 功能单一的程序或模块合作完成复杂任务。
1. 标准输入（`stdin/0`）、标准输出（`stdout/1`）和标准错误（`stderr/2`）的概念。
1. 重定向的概念。
1. 管道的概念。

	
### 演示视频

1. [0-2-2-1：常用系统命令及工具（上）](https://www.douyin.com/video/7355039401547795764)
   - 获取帮助
   - 环境变量
   - 常用命令
1. [0-2-2-2：常用系统命令及工具（中）](https://www.douyin.com/video/7355102308025240872)
   - 文件及文件系统工具
   - 网络管理工具
   - 压缩或归档工具
1. [0-2-2-3：常用系统命令及工具（下）](https://www.douyin.com/video/7355105221888052520)
   - 文本文件工具
   - 流编辑器
   - 系统管理工具

	
### 获取帮助

- `man`：显示指定命令的手册页（`man`ual page）内容，也就是随机文档（document）。
- `info`：显示 GNU 项目开发的各种工具的完整信息（`info`rmation）。
- `whatis`：显示随机手册页的描述信息；通常用于展示某个命令的简短描述。

	
### 环境变量

使用 `$` 可在命令行直接引用环境（environment）变量：

- `SHELL`：当前使用的外壳程序。
- `PWD`：当前工作路径。
- `OLDPWD`：老的工作路径；`$ cd -` 命令依赖此环境变量工作。
- `LOGNAME` 或 `USER`：登录用户名。
- `PATH`：定义可执行程序的搜索路径，以 `:` 分隔多个路径。
- `LC_TIME`：用来定义时间和日期格式的区域（`l`ocale）类别（`c`ategory）。
- `env`：显示当前环境变量（`env`ironment）或者在给定环境变量下运行指定的程序。

	
### 常用命令

- `cd`：改变（`c`hange）工作目录（`d`irectory）。
- `history`：显示命令行历史；使用 `!<history number>` 可执行对应的历史命令。
- `pwd`：打印（`p`rint）当前（current）/工作（`w`orking）目录（`d`irectory）。
- `alias`：定义或显示命令的别名（`alias`）。
- `export`：定义或修改环境变量。
- `which`：可显示给定命令对应的程序路径。
- `file`：可分析并显示给定文件的类型。
- `date`：显示当前时间（墙钟，wall clock）。
- `sleep`：睡眠（暂定当前脚本的执行）指定的秒数。

	
### 文件工具

- `ls`：列出（list）指定目录（或当前目录）中的文件和子目录。
- `ll`：通常被定义为 `ls -alF` 的别名。
- `chmod`：改变（`ch`ange）文件的许可模式（permission `mode`）。
- `touch`：改变指定文件的时间戳为当前时间；若指定文件不存在则新建一个空文件。
- `cp`：复制（`c`o`p`y）文件。
- `mv`：移动（`m`o`v`e）文件；亦可用于重命名文件。
- `rm`：删除（`r`emo`v`e）文件；亦可用于删除一个目录树（使用 `-r` 递归选项）。

	
### 文件系统工具

- `mkdir`：创建（`m`a`k`e）目录（`dir`ectory）。
- `rmdir`：移除（`r`e`m`ove）指定的目录（目录须为空）。
- `find`：在指定目录树中按照名称、大小、创建日期等条件搜索文件。
- `tree`：以树状（`tree`）形式展示目录以及文件的层次结构。
- `du`：显示目录树的磁盘使用情况（`d`isk `u`sage）。
- `df`：文件系统的磁盘使用情况。

	
### 压缩或归档工具

- `tar`：归档工具；将指定目录树打包为单个文件。
- `zip/unzip`：压缩解压工具（使用 Phil Katz 的 ZIP 算法）。使用该工具压缩的文件通常使用 `.zip` 后缀名。
- `gzip/gunzip`：压缩解压工具（使用 Lempel-Ziv 编码，LZ77）。使用该工具压缩的文件通常使用 `.gz` 后缀名。
- `bzip2/bunzip2`：压缩解压工具（使用 Burrows-Wheeler 块排序文本压缩算法和 Huffman 编码）。使用该工具压缩的文件通常使用 `.bz2` 后缀名。

	
### 文本文件工具

- `echo`：打印一行文本到标准输出。
- `cat`：拼接（concatenate）多个文件并打印到标准输出。
- `cut`：从文件的每一行移除指定的字段（field）。
- `grep`：打印匹配指定模式（pattern）的行。
- `sort`：对文本文件按行进行排序。
- `diff`：查看两个文件的差异。
- `wc`：统计并打印文件中的新行符、单词和字节数量（`w`ords `c`ount）。
- `nano`：文本编辑器（`N`ano's `ANO`ther editor）。
- `ed`：面向行的编辑器；主要方便在 Shell 脚本中编辑文本文件。
- `more/less`：方便在终端上查看大文件，通常用在管道的末尾。
- `head/tail`：打印文件头部/尾部的内容。

	
### 流编辑器

- `sed`：用于过滤和转换文本的流编辑器（`s`tream `ed`itor）。
- `tr`：转换（`tr`anslate）或删除标准输出上的字符，并打印到标准输出上。

	
### 系统管理工具

- `ps`：打印系统中正在运行的进程。
- `kill`：杀掉指定的进程。
- `top`：全屏查看进程信息，以资源占用情况排序。
- `free`：查看系统内存使用情况。
- `sudo`：以超级用户身份执行命令。
- `passwd`：修改当前用户的登录密码。
- `uptime`：查看系统运行时间。
- `shutdown`：暂停、关机或者重启机器。
- `halt/poweroff/reboot`：分别用于暂停、关机或者重启机器。

	
### 系统管理工具（续）

- `uname`：打印系统信息。
- `hostname`：显示主机名。
- `whoami`：打印当前有效用户标识符。
- `id`：打印真实及有效用户标识符、组标识符等。
- `groups`：打印指定用户（默认为当前有效用户）所在的组。

	
### 网络管理工具

- `ping`：向指定的主机发送网络回声请求；通常用来判断网络是否可达指定的主机。
- `ifconfig`：配置网络接口（network `i`nter`f`ace）。
- `dig`：DNS 查找工具。
- `nslookup`：交互式查询互联网名称服务器。
- `wget`：非交互式网络下载器；主要用于网页资源（页面、图片、CSS、JS）的下载。

		
## 有趣的 Shell 命令行

	
### 演示视频

[0-2-3：有趣的 Shell 命令行](https://www.douyin.com/video/7355355329766395187)

1. 重定向标准输出、标准错误的方法：
   - `[1]>FILE`：将标准输出重定向到文件 `FILE`。
   - `2>FILE`：将标准错误重定向到文件 `FILE`。
   - `[1]>>FILE`：将标准错误重定向并追加到文件 `FILE`。
1. 通过管道重定向标准输入。
1. 在单条命令行组合多个命令的方法。
1. 若干命令行示例。

	
### 组合多个命令的方法

1. 一条命令行中可以包含多个顺序执行的命令，中间用分号（semicolon，`;`）。
1. 若使用 `&&` 分隔两个命令，则仅当第一个命令执行成功时才会执行第二个命令。
1. 若使用 `||` 分隔两个命令，则仅当第一个命令执行失败时才会执行第二个命令。
1. 若双引号包围的参数中含有 `$` 打头的环境变量或 `$(...)` 表达式，将首先对其求值并置换；单引号包围时忽略。
1. 使用反引号（backtick，`` ` ``）包围一个命令，可将该命令的标准输出作为整条命令行的一部分。
1. `xargs`：从标准输入中构造命令行参数并执行指定的命令。
1. 管道：将管道（pipe，`|`）左侧的命令之标准输出作为管道右侧命令的标准输入。

	
### 命令行示例

- 将当前日期和用户名拼接在一起，将输出重定向追加到 `users.log` 文件中：

```console
# 使用反单引号包围命令，则该命令的标准输出将作为命令行的一部分
$ echo `date` ": $USER" >> users.log
$ echo `date` ": $USER" >> users.log
$ echo `date` ": $USER" >> users.log
$ echo "$(date): $USER" >> users.log
$ cat users.log
2024年 03月 27日 星期三 11:30:53 CST : weiym
2024年 03月 27日 星期三 11:30:54 CST : weiym
2024年 03月 27日 星期三 11:30:55 CST : weiym
2024年 03月 27日 星期三 11:30:56 CST : weiym
```

	
### 命令行示例

- 使用 `cat`、`cut` 和 `sort`列出系统中所有的用户账号并排序：

```console
# 使用 `cat` 命令读取 `/etc/passwd` 文件内容并打印到标准输出。
# 使用 `cut` 命令截取 `/etc/passwd` 每行中的第一个字段（即用户账号）到标准输出。
# 使用 `sort` 命令将标准输入的内容排序并打印到标准输出。

$ cat /etc/passwd | cut -d':' -f1 | sort
_apt
avahi
avahi-autoipd
backup
bin
cn-fmsoft-hybridos-hibus
colord
com-example-foo
cups-pk-helper
daemon
dnsmasq
_flatpak
fwupd-refresh
games
gdm
geoclue
gnats
gnome-initial-setup
hplip
irc
kernoops
lightdm
list
lp
lxc-dnsmasq
lxd
mail
man
messagebus
news
nm-openvpn
nobody
proxy
pulse
root
rtkit
saned
speech-dispatcher
sshd
sssd
sync
sys
syslog
systemd-coredump
systemd-network
systemd-oom
systemd-resolve
systemd-timesync
tcpdump
tss
usbmux
uucp
uuidd
weiym
whoopsie
www-data
```

	
### 命令行示例

- 在上一条命令行基础上将 `_` 打头的用户名过滤掉：

```console
# 在 `sort` 前使用 `sed` 命令。
# 使用 `sed` 的删除命令 `/^_/d`，其中的正则表达式 `^_` 将匹配所有以 `_` 打头的行。

$ cat /etc/passwd | cut -d':' -f1 | sed '/^_/d' | sort
avahi
avahi-autoipd
backup
bin
cn-fmsoft-hybridos-hibus
colord
com-example-foo
cups-pk-helper
daemon
dnsmasq
fwupd-refresh
games
gdm
geoclue
gnats
gnome-initial-setup
hplip
irc
kernoops
lightdm
list
lp
lxc-dnsmasq
lxd
mail
man
messagebus
news
nm-openvpn
nobody
proxy
pulse
root
rtkit
saned
speech-dispatcher
sshd
sssd
sync
sys
syslog
systemd-coredump
systemd-network
systemd-oom
systemd-resolve
systemd-timesync
tcpdump
tss
usbmux
uucp
uuidd
weiym
whoopsie
www-data
```

	
### 命令行示例

- 查找所有使用 `bash` 的 `.sh` 脚本程序并拼接在一起显示：

```console
# xargs 命令将管道左侧命令的标准输出作为 `cat` 的命令行参数
$ grep bash *.sh -l | xargs cat | less
```

	
### 命令行示例

- 用 Vim 打开所有包含 `SHELL` 的 `.md` 文件：

```console
# 使用反单引号包围命令，则该命令的标准输出将作为命令行的一部分
$ vim `grep SHELL -l *.md`
```
	
### 命令行示例

- 使用流编辑器 `sed` 就地（in-place）编辑包含 `SHELL` 的 `.md` 文件，将每一行中的 `SHELL` 替换为 `Shell`：

```console
# 使用 `sed` 命令的 `-i` 选项，可直接编辑对应的文件。
$ sed -i 's/SHELL/Shell/g` `grep SHELL -l *.md`
```

		
## 用 Vim 编辑文本文件

	
### 演示视频

[0-2-4：用 Vim 编辑文本文件](https://www.douyin.com/video/7355331037934685490)

1. `vi` 和 `vim` 的区别。
1. 安装 `vim`。
1. 常规模式进入插入模式。
1. 退出插入模式。
1. 保存文件。
1. 再次查看问题，插入新行，保存并退出。

	
### 知识点：Vim 快速入门

### 四大工作模式

1. 常规（normal）模式：移动光标/插入符（caret）的位置、删除文本、复制和粘贴文本等。启动时为常规模式；按 `i` 等字符可进入插入模式。
1. 插入（insert）模式：用于键入文本，按 `ESC` 键退出插入模式返回常规模式。
1. 命令（command）模式：在常规模式下按冒号（colon：`:`）进入命令模式，可用于保存文件、搜索文本、替换文本等操作。
1. 可视（visual）模式：在常规模式下按 `v/V/^V` 进入选择字符、行、列的模式，移动光标按字符、行或者列选择字符，然后可针对选定的字符或行执行相应的编辑操作或者命令。

	
### 常用术语

1. 缓冲区（buffer）：指 Vim 用于保存从文件中读入或者用户输入的文本内容的内存区域。
1. 底栏（bottom line）：指屏幕最底下的一行，用于显示当前工作模式、提示信息以及输入命令的区域。
1. 空白字符（whitespace character）：指空格、制表符等字符。

温馨提示：在初学阶段，学会进入插入模式输入自己的程序，然后退出插入模式，再使用命令模式保存文件并退出 Vim 就可以了！

	
### 速查：Vim 常规模式下移动光标

- `j`　光标向下移动一行；亦可用小键盘（keypad）上的向下键。
- `k`　光标向上移动一行；亦可用小键盘（keypad）上的向下键。
- `h`　光标向左移动一个字符；亦可用小键盘（keypad）上的向左键。
- `l`　光标向右移动一个字符；亦可用小键盘（keypad）上的向右键。
- `H`　光标移动到当前屏幕的最上方（`H`igh）那一行的第一个字符位置。
- `M`　光标移动到当前屏幕的中央那一行（`M`iddle）的第一个字符位置。
- `L`　光标移动到当前屏幕的最下方（`L`ow）那一行的第一个字符位置。
- `0`　光标移动到当前行的第一个字符位置。
- `$`　光标移动到当前行的最后一个字符位置。
- `^`　光标移动到当前行的第一个非空白字符位置。

	
### 速查：Vim 常规模式下移动光标（续）
- `w`　在当前行内右移光标，到下一个单词（`w`ord）的开头。
- `e`　在当前行内右移光标，到一个单词的末尾（`e`nd）。
- `b`　在当前行内左移光标，到前一个单词的开头（`b`egin）。
- `^f`　向下翻页（`f`orward）。
- `^b`　向上翻页（`b`ackward）。
- `gg` 或 `1G`　光标移动到文件头。
- `<N>G`　光标移动到第 `N` 行。
- `G`　光标移动到文件尾。

**探索：试试 `HOME`、`END`、`PgUp`、`PgDn` 键**

	
### 速查：Vim 常规模式进入插入模式

- `i`　进入插入（`i`nsert）模式，在光标当前位置开始输入文本。
- `I`　进入插入（`i`nsert）模式，从光标所在行的第一个非空白字符处开始输入文本。
- `a`　进入插入模式，在光标下一个位置开始输入文本。
- `A`　进入插入模式，在光标所在行的末尾开始输入。
- `o`　在当前行的下方插入一个新行，并进入插入模式。
- `O`　在当前行的上方插入一个新行，并进入插入模式。

**探索：试试在命令前加个数字**

	
### 速查：Vim 常规模式下的编辑操作

- `x`　删除当前光标所在位置的字符。
- `X`　删除当前光标左侧位置的字符。
- `r<C>`　用 `C` 替换光标所在位置的字符。
- `db`　删除光标左侧的字符到光标所在位置单词的开头。
- `de`　删除光标右侧的字符到光标所在位置单词的结尾。
- `dw`　删除光标右侧的字符到光标所在位置单词的结果以及其后的空白字符。
- `dd`　剪切当前行。
- `yy`　复制当前行。
- `p`　粘贴剪贴板内容到光标下方。
- `P`　粘贴剪贴板内容到光标上方。
- `u`　撤销（`u`ndo）上一次编辑操作。
- `^r`　重做（`r`epeat）上一次撤销的编辑操作。
- `.`　重复上个编辑操作。

**探索：试试在命令前加个数字**

	
### 速查：Vim 命令模式下的常用命令

- `:`　从常规模式进入命令模式，可在底栏的提示行输入命令。
- `:<N>`　将光标移到当前缓冲区的第 `N` 行。
- `:f`　显示当前文件名称和状态，如文件的行数、光标所在的行号等。
- `:f <FILE>`　指定当前缓冲区的默认保存目标文件名称为 `FILE`。
- `:r <FILE>`　读取（`w`rite） `FILE` 文件的内容，插入当前光标所在行的后面。
- `:e <FILE>`　编辑（`e`dit）新文件，将使用 `FILE` 文件中的内容替代缓冲区内容。
- `:w [FILE]`　将缓冲区中的内容保存到可选的 `FILE` 文件中。
- `<N1,N2>w <FILE>`　将第 `N1` 行至第 `N2` 行的内容写入 `FILE` 文件
- `:q`　退出 Vim 编辑器。
- `:wq`　保存缓冲区内容到当前文件并退出 Vim 编辑器。
- `:q!`　强制退出 Vim 编辑器，不保存当前缓冲区中已做的修改。

	
### 速查：Vim 搜索和替换

- `/WORD`　向下搜索指定的 WORD；在常规模式或者命令模式下输入。
- `?WORD`　向上搜索指定的 WORD；在常规模式或者命令模式下输入。
- `n`　向下重复上个搜索；在常规模式下输入。
- `N`　向上重复上个搜索；在常规模式下输入。
- `:%s/WORD1/WORD2/gc`　命令模式下，全局搜索 WORD1 并使用 WORD2 替换。`gc` 是可选后缀：`g` 表示替换行内所有搜索到的 WORD1，`c` 表示需要用户确认是否替换。

		
## 使用 Gtypist 练习键盘打字

- 科学练习键盘打字的重要性

	
### QWERTY 键盘布局

<img class="r-frame" style="height:auto;width:100%;" src="assets/plzs-keyboard-typing-0.webp" />

	
### 左手食指键位

<img class="r-frame" style="height:auto;width:100%;" src="assets/plzs-keyboard-typing-1.webp" />

	
### 左手中指键位

<img class="r-frame" style="height:auto;width:100%;" src="assets/plzs-keyboard-typing-2.webp" />

	
### 左手无名指键位

<img class="r-frame" style="height:auto;width:100%;" src="assets/plzs-keyboard-typing-3.webp" />

	
### 左手小指键位

<img class="r-frame" style="height:auto;width:100%;" src="assets/plzs-keyboard-typing-4.webp" />

	
### 右手食指键位

<img class="r-frame" style="height:auto;width:100%;" src="assets/plzs-keyboard-typing-5.png" />

	
### 右手中指键位

<img class="r-frame" style="height:auto;width:100%;" src="assets/plzs-keyboard-typing-6.png" />

	
### 右手无名指键位

<img class="r-frame" style="height:auto;width:100%;" src="assets/plzs-keyboard-typing-7.png" />

	
### 右手小指键位

<img class="r-frame" style="height:auto;width:100%;" src="assets/plzs-keyboard-typing-8.png" />

	
### 左右大拇指键位

<img class="r-frame" style="height:auto;width:100%;" src="assets/plzs-keyboard-typing-9.webp" />

	
### 演示视频

[0-2-5：使用 Gtypist 练习键盘打字]()

1. 了解键盘打字的指法规范。
1. 安装 `Gtypist`。
1. `Gtypist` 的基本用法。

		
## 要点回顾

1. 掌握常用的 Linux 系统命令。
1. 掌握通配符的用法。
1. 掌握在 Linux Shell 命令行中组合使用多个命令的基本用法。
1. 了解正则表达式的基本概念。
1. 掌握基本的 Vim 操作。
1. 使用 `gtypist` 练习键盘打字。

		
## 进一步学习资料

1. [知乎文章：115个最常用的Linux命令行大全](https://zhuanlan.zhihu.com/p/420247468)
1. [揭开正则表达式的神秘面纱](http://www.regexlab.com/zh/regref.htm)
1. [Vim 官方文档中文版](https://yianwillis.github.io/vimcdoc/doc/help.html)
1. [Vim 实操教程](https://dofy.gitbook.io/learn-vim/zh-CN)
1. [键盘打字指法规范](https://zhuanlan.zhihu.com/p/536226696)

		
## 作业

1) 搭建好基于 Ubuntu Linux 22.04 的学习环境，将本节所讲内容对照演示视频实操一遍。
