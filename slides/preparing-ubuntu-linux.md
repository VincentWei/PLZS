## 准备开发环境

1. 课程内容介绍
1. 背景知识
1. 虚拟机的概念
1. 在虚拟机上安装 Ubuntu Linux
1. 参考链接
1. 作业

		
## 课程内容介绍

### 欢迎迈进改变世界的大门！

俺们的口号

- 给父母惊喜
- 使同学尖叫
- 让老师刮目

	
### 课程规划

1) 课程体系
    - 零基础普及班：针对零基础学生的课程，内容包括虚拟机的安装、Linux 桌面系统的安装和使用、常用 Linux 命令、Vim 编辑器、Python 编程入门、Git 使用及 Markdown。
    - 筑基班：针对已入门学生开设，课程内容涉及 Python 和 JavaScript 编程语言，最终实现一个单机游戏的两个版本：终端版本和网页版本。
    - AI实战班：针对已掌握 Python 和 JavaScript 编程的学生开设。课程内容涉及开源 AI 模型以及网页编程，五人一组协作开发一个联网的网页游戏。
    - AI信奥班：针对已掌握 Python 和 JavaScript 编程的学生开设。课程内容涉及开源 AI 模型以及 C++ 编程语言，课程内容围绕一个联网的桌面游戏进行。

	
<img class="r-frame" style="height:auto;width:100%;" src="assets/plzs-course-framework.svg" />

	
2) 对学生的要求
   - 对编程有强烈的兴趣且学有余力。
   - 做好“听课一小时，实践八小时”的投入准备。
   - 要大胆探索尝试；计算机不会爆炸，顶多重装系统。
   - 不要依赖家长，要学会利用互联网，多请教老师和同学。
3) 课后服务
   - 每周五、周六、周日晚 19:30（或20:30）三个时段主讲老师会安排作业点评和答疑直播。该直播是公开直播，会生成回放，以方便同学们回看。
   - 北京地区的同学可以利用周六、周日非课程直播时段，到线下场地和老师面对面交流。不在北京的同学，如果需要类似的服务，可通过视频通话等方式提供。

	
4) 筑基班大作业
   - 选择一个简单的益智小游戏。
   - 游戏要完成两个版本：在终端中直接运行的版本以及在浏览器中运行的版本。
5) AI实战班大作业
   - 每组选择一个包含人工智能元素的小型联网游戏；小组成员协作完成。
   - 游戏由服务器端（Python）、网页端（JavaScript）程序组成，涉及 HTTP、WebSocket 等网络协议。
   - 参加信息技术比赛。
6) AI信奥班大作业
   - 用 Python 及 C++ 开发一个联网的包含人工智能元素的桌面游戏。
   - 参加信息技术比赛。

	
### 如何听课

1. 用智能手机或平板电脑横屏观看课程串讲视频、课程直播或者课程直播回放。
1. 观看直播时点击屏幕可隐藏评论区信息，亦可用手势放大画面。
1. 观看直播时应积极参与老师发起的互动或按要求操作电脑。
1. 用智能手机或者平板电脑有选择地观看课程串讲视频或直播回放，并同时在电脑（宿主操作系统）上打开课件。点击课件页面中演示视频的链接，可在电脑上观看演示视频。此时，可在虚拟机上运行的 Ubuntu Linux 环境中对照演示视频进行实操练习。
1. 观看课程串讲视频或直播回放时，可选择章节播放自己感兴趣的内容。

		
## 背景知识

### 演示视频

[0-1-1：有关 Ubuntu Linux 和虚拟机的背景知识](#)

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

[0-1-2：在 Windows 10/11 上安装 VirtualBox 和 Ubuntu Linux 22.04](https://www.douyin.com/video/7347307828081642803)

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

		
## 作业

1. 在自己的宿主操作系统上安装虚拟机管理程序，并在其上安装 Ubuntu Linux 22.04 LTS。
1. 使用 Ubuntu Linux，熟悉其中预装的应用，将课程资料仓库设置为浏览器书签：
    - <https://github.com/VincentWei/PLZS>，或
    - <https://gitee.com/vincentwei7/PLZS>

