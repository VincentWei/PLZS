# 准备开发环境

1. 课程内容介绍
1. 背景知识
1. 虚拟机的概念
1. 在虚拟机上安装 Ubuntu Linux
1. 参考链接
1. 要点回顾
1. 作业

		
## 课程内容介绍

### 欢迎迈进改变世界的大门！

俺们的口号

- 给父母惊喜
- 使同学尖叫
- 让老师刮目

	
### 课程规划

- 课程体系
   1) 零基础普及班：针对零基础学生的入门课程，内容包括虚拟机的安装、Linux 桌面系统的安装和使用、常用 Linux 命令、Vim 编辑器、Python 编程入门、Git 使用及 Markdown。
   2) Python 实战班：针对已入门学生开设，课程讲述 Python 编程语言和 Linux 环境编程，最终实现学生的第一个益智游戏类软件作品。
   3) 信奥筑基班：本课程针对计划参加 NOI（全国青少年信息学奥林匹克竞赛）的学生准备，要求已掌握 Python 实战班的课程内容。课程内容涉及 C++ 编程语言和 Linux 环境编程，通过本课程的学习，学生将掌握高精度整数算术的 C++ 实现。

	
- 课程体系（续）
   4) 信奥初级班：本课程针对计划参加 NOI JSP-J 比赛的学生准备，要求已掌握信奥筑基班的课程内容。课程内容围绕四则运算表达式、JSON 解析器等大作业进行，通过将 NOI 大纲（初级）中所列知识点融入解析器的开发加深学生对相关知识的理解和掌握。
   5) 信奥提高班：本课程针对计划参加 NOI JSP-S 比赛的学生准备，要求已掌握信奥初级班的课程内容。课程内容围绕正则表达式以及一个简单脚本语言的解释器开展，通过将 NOI 大纲（提高级）中所列知识点融入脚本语言的解释器加深学生对相关知识的理解和掌握。通过本课程的学习，学生将掌握 NOI 大纲（提高级）中提及的各种算法和数据结构，并使用 C++ 编程语言完成一个脚本语言的解释器。

	
- 对学生的要求
  1. 对编程有强烈的兴趣且学有余力。
  1. 做好“听课一小时，实践三小时”的投入准备。
  1. 要大胆探索尝试；计算机不会爆炸，顶多重装系统。
  1. 不要依赖家长，要学会利用互联网，多请教老师和同学。

	
- 学习周期
  1. 四年级或五年级开始学习，建议学习周期两年。
  1. 六年级开始学习，建议学习周期一年。
  1. 若需入群、答疑、作业辅导等课后服务，请联系客服。

	
### 如何听课

1. 推荐使用短视频应用的电脑版观看课程视频。
1. 在虚拟机上运行的 Ubuntu Linux 环境虚拟机中，使用浏览器打开课件，并对照演示视频进行实操练习。

		
## 背景知识

- UNIX 和 C 语言的故事。
- Linus 和 Linux 的故事。

	
### 演示视频

[0-1-1：有关 Ubuntu Linux 和虚拟机的背景知识](https://www.douyin.com/video/7355029937885138176)

- 常见桌面操作系统
   - 微软的 Windows
   - 苹果的 macOS
   - 开源的 Linux 桌面系统
- 流行的 Linux 发行版
   - Debian（开源社区维护，三十岁了）
   - RedHat（红帽公司的商业产品）
   - Ubuntu（基于 Debian 的商业产品）

	
- Ubuntu Linux 发行版的版本号
   - 版本号由首次发布年份及月份组成，如 22.04, 23.10 等。
   - 每年出两个版本，如 22.04、22.10、23.04、23.10 等。
   - 每两年出一个长期支持（LTS）版本，如 20.04 LTS、22.04 LTS、24.04 LTS 等。
   - LTS 版本的维护、支持周期长达 5 年。
   - 除了 LTS 之外的版本是实验性的版本，适用于喜欢尝鲜的用户。

	
### 虚拟机的概念

- 在真实的计算机（物理机）上创建出一个软件模拟出来的虚拟计算机（virtual machine），仿佛这个虚拟机拥有自己的处理器、内存以及硬盘、显示器、键盘、鼠标、网卡等外设，从而在这个虚拟机上运行另一个操作系统。
   - 虚拟机的CPU：从物理机中分配部分处理器核（core）。
   - 虚拟机的内存：从物理机中分配部分内存。
   - 虚拟机的硬盘：把物理机操作系统中的文件当成一个硬盘给虚拟机使用。
   - 虚拟机的显示器：把物理机操作系统中的窗口当成虚拟机的显示器。
   - ...

	
<img class="r-frame" style="height:auto;width:100%;" src="assets/plzs-diagram-virtual-machine.svg" />

	
- 流行的桌面虚拟机管理软件
   - Oracle VirtualBox（开源软件，免费）。
   - VMware Fusion（商业软件，但可申请针对个人的免费许可证）。

		
## 在虚拟机上安装 Ubuntu Linux

1. 下载链接
1. 演示视频

	
### 下载链接

- Windows 10/11
    - [Visual Studio Redistributable X64](https://aka.ms/vs/17/release/vc_redist.x64.exe)
    - [VirtualBox 安装程序](https://download.virtualbox.org/virtualbox/7.0.14/VirtualBox-7.0.14-161095-Win.exe)
    - [Ubuntu Linux 22.04 AMD64 ISO](https://releases.ubuntu.com/22.04/ubuntu-22.04.4-desktop-amd64.iso)
- macOS（Intel 芯片）
    - [VirtualBox 安装程序](https://download.virtualbox.org/virtualbox/7.0.14/VirtualBox-7.0.14-161095-OSX.dmg)
    - [Ubuntu Linux 22.04 AMD64 ISO](https://releases.ubuntu.com/22.04/ubuntu-22.04.4-desktop-amd64.iso)
- macOS（Apple 的 M1/M2 芯片）
    - [VMware Fusion](https://www.vmware.com/products/fusion/fusion-evaluation.html)：需要自行注册账号并获得针对个人的免费许可证
    - [Ubuntu Linux 22.04 ARM64 ISO](https://cdimage.ubuntu.com/jammy/daily-live/current/jammy-desktop-arm64.iso)
- 其他非 Ubuntu Linux PC
    - [VirtualBox 安装包](https://www.virtualbox.org/wiki/Linux_Downloads)：根据自己的 Linux 发行版选择下载对应的安装包
    - [Ubuntu Linux 22.04 AMD64 ISO](https://releases.ubuntu.com/22.04/ubuntu-22.04.4-desktop-amd64.iso)

	
### 演示视频

[0-1-2：在 Windows 10/11 上安装 VirtualBox 和 Ubuntu Linux 22.04](https://www.douyin.com/video/7355032540748500239)

- 安装 VirtualBox。
- 创建一个虚拟机，指定 CPU、内存和虚拟硬盘位置及大小。
- 指定虚拟光驱，使用 Ubuntu Linux 22.04 的光盘映像文件。
- 启动虚拟机并进入 Ubuntu 安装程序。
- 选择简体中文、键盘布局、时区、选择安装类型。
- 指定默认用户信息开始安装。
- 安装结束后按 `<ENTER>` 键弹出光盘并重启系统。
- 进入 Ubuntu 系统。
- 关机。

		
## 参考链接

1. 若在电脑上直接安装 Ubuntu Linux 22.04，请参阅如下文档：
   - [知乎文章：如何安装 Ubuntu 22.04 LTS 桌面版](https://zhuanlan.zhihu.com/p/569347838)。
   - [知乎文章：Ubuntu 22.04.4 安装（双系统）](https://zhuanlan.zhihu.com/p/536994892)。
1. 若使用 macOS，请参照如下文档在系统中安装 Homebrew：
   - [官方文档](https://brew.sh/zh-cn/)。
   - [知乎文章](https://zhuanlan.zhihu.com/p/372576355)。
1. 若使用 Windows，可安装 WSL 或者 VirtualBox 虚拟机，然后再安装 Ubuntu Linux 22.04：
   - [微软文档：如何使用 WSL 在 Windows 上安装 Linux](https://learn.microsoft.com/zh-cn/windows/wsl/install)。
   - [知乎文章：安装 WSL2 并下载配置 Ubuntu](https://zhuanlan.zhihu.com/p/348813745)。
   - [知乎文章：在 VirtualBox 虚拟机上安装 Ubuntu Linux 22.04](https://zhuanlan.zhihu.com/p/600668604)。
1. 若使用 macOS，可安装 VirtualBox 虚拟机或者 VMWare Fusion 虚拟机，然后再安装 Ubuntu Linux 22.04。

		
## 要点回顾

1. 了解 Linux 发行版和桌面系统的发展历史。
1. 了解虚拟机的概念。
1. 掌握在虚拟机上安装 Ubuntu Linux 的方法。

		
## 作业

1. 在自己的宿主操作系统上安装虚拟机管理程序，并在其上安装 Ubuntu Linux 22.04 LTS。
1. 使用 Ubuntu Linux，熟悉其中预装的应用，将课程资料仓库设置为浏览器书签：
    - <https://github.com/VincentWei/PLZS>，或
    - <https://gitee.com/vincentwei7/PLZS>

