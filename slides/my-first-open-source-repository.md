# 我的第一个开源代码仓库

1. 使用 Git 管理源文件
1. Markdown 语法创建格式化文本文件
1. 要点回顾
1. 作业

		
## 使用 Git 管理源文件

- Git 和 GitHub 的故事

	
### 演示视频

[0-4-1：在 Gitee 上创建代码仓库](https://www.douyin.com/video/7355347061836942618)

1. 访问 Gitee/GitHub 网站并登录。
1. 生成 SSH 密钥対，并将公钥登记到 Gitee/GitHub。
1. 新建公开代码仓库（repository）。
1. 按照页面提示复制相关命令并在本地执行。
1. 复制第一个 Python 程序到仓库中，并将其添加、提交、推送到 Gitee/GitHub 仓库。
1. 修改文件，提交修改并推送到 Gitee/GitHub。
1. 刷新 Gitee/GitHub 页面查看源文件。
1. 分享仓库或者源文件链接给老师或者同学。

	
### 视频中用到的主要命令

```console
# 生成 SSH 密钥对
$ ssh-keygen

# 设置 git 用户信息
$ git config --global user.name "your-username"
$ git config --global user.email "your-email-address"

# 复制文件
cp ~/my-first-python-program.py .

# 复制文件
mv ~/my-first-python-program.py .
```

	
克隆 Github 上的代码仓库到本地

```console
$ git clone git@github.com:<YourAccountName>/plzs-homework.git
$ cd plzs-homework
$ vim README.md
$ git add README.md
$ git commit -m "first commit"
$ git branch -M main
$ git push -u origin main
```

或者，在本地创建 Git 仓库并推送到 GitHub：

```console
$ mkdir plzs-homework
$ cd plzs-homework
$ vim README.md
$ git init
$ git add README.md
$ git commit -m "first commit"
$ git branch -M main
$ git remote add origin git@github.com:<YourAccountName>/plzs-homework.git
$ git push -u origin main
```

		
## Markdown 语法创建格式化文本文件

	
### 演示视频

[0-4-2：Markdown 的由来和基本语法](https://www.douyin.com/video/7355347641347149083)

1. 查看网页内容（HTML 文件）了解 Markdown 的由来。
1. 使用 Markdown 语法定义标题。
1. 使用 Markdown 语法定义段落和强制换行。
1. 使用 Markdown 语法定义超链接。
1. 使用 Markdown 语法定义强调文本。
1. 使用 Markdown 语法定义有序列表。
1. 使用 Markdown 语法定义无序列表。
1. 使用 Markdown 语法引用图片。
1. 使用 Markdown 语法定义代码段落。
1. 使用 Markdown 语法定义引用段落。
1. 使用 Markdown 语法定义表格。

		
## 要点回顾

1. 将自己的 SSH 公钥上传到 GitHub 或者 Gitee 平台。
1. 在 GitHub 或者 Gitee 平台上创建开源代码仓库。
1. 克隆（clone）远程 Git 仓库到本地。
1. 将本地文件纳入本地 Git 仓库管理。
1. 提交改动到本地 Git 仓库。
1. 从远程仓库拉取改动到本地仓库。
1. 将本地仓库的改动推送（push）到远程仓库。
1. 使用 Markdown 语法撰写简单的格式化文本文件。

		
## 进一步学习资料

1. [知乎文章：最常用的19个Git命令](https://zhuanlan.zhihu.com/p/40461007])
1. [Markdown 官方教程之基本语法](https://markdown.com.cn/basic-syntax/)

		
## 作业

1) 在 GitHub 或者 Gitee 上创建一个自己的代码仓库（名为 `plzs-homework`）；提交作业时提供仓库链接即可。
2) 使用 Markdown 语法为上述代码仓库撰写 `README.md` 文件，添加上对自己的一个简单介绍。
3) 将自己在完成本课程作业时编写的程序纳入该仓库管理，要求目录结构以及文件名称如下所示：

```console
.
├── README.md
└── source
    └── python
        └── my-first-python-program.py
```

