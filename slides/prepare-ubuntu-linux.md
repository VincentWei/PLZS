## 准备开发环境

1. 背景知识
1. 虚拟机的概念
1. 安装包下载链接
1. 安装实操演示

		
## 背景知识

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

		
## 虚拟机的概念

- 在真实的计算机（物理机）上创建出一个软件模拟出来的虚拟计算机（virtual machine），放佛这个虚拟机拥有自己的处理器、内存以及硬盘、显示器、键盘、鼠标、网卡等外设，从而在这个虚拟机上运行另一个操作系统。
   - 虚拟机的CPU：从物理机中分配部分处理器核（core）。
   - 虚拟机的内存：从物理机中分配部分内存。
   - 虚拟机的硬盘：把物理机操作系统中的文件当成一个硬盘给虚拟机使用。
   - 虚拟机的显示器：把物理机操作系统中的窗口当成虚拟机的显示器。
   - ...

	
<img class="fragment" src="assets/diagram-virtual-machine.svg" height="600" />

	
- 流行的桌面虚拟机管理软件
   - Oracle VirtualBox（开源软件，免费）。
   - VMware Fusion（商业软件，但可申请针对个人的免费许可证）。

		
## 下载链接

- Windows 10/11
    - [Visual Studio Redistributable X64](https://aka.ms/vs/17/release/vc_redist.x64.exe)
    - [VirtualBox 安装程序](https://download.virtualbox.org/virtualbox/7.0.14/VirtualBox-7.0.14-161095-Win.exe)
    - [Ubuntu Linux 22.04 AMD64 ISO](https://releases.ubuntu.com/22.04/ubuntu-22.04.4-desktop-amd64.iso)
- MacOS（Intel 芯片）
    - [VirtualBox安装程序](https://download.virtualbox.org/virtualbox/7.0.14/VirtualBox-7.0.14-161095-Win.exe)
    - [Ubuntu Linux 22.04 AMD64 ISO](https://releases.ubuntu.com/22.04/ubuntu-22.04.4-desktop-amd64.iso)
- MacOS（Apple 的 M1/M2 芯片）
    - [VMware Fusion](https://download.virtualbox.org/virtualbox/7.0.14/VirtualBox-7.0.14-161095-Win.exe)：需要自行注册账号并获得针对个人的免费许可证
    - [Ubuntu Linux 22.04 ARM64 ISO](https://cdimage.ubuntu.com/jammy/daily-live/current/jammy-desktop-arm64.iso)
- 其他非 Ubuntu Linux PC
    - [VirtualBox 安装包](https://www.virtualbox.org/wiki/Linux_Downloads)：根据自己的 Linux 发行版选择下载对应的安装包
    - [Ubuntu Linux 22.04 AMD64 ISO](https://releases.ubuntu.com/22.04/ubuntu-22.04.4-desktop-amd64.iso)

