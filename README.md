# 面向十岁及以上学生的编程实战系列课程

本仓库包含由[魏永明](https://github.com/VincentWei)主讲的针对十岁及以上学生的编程实战系列课程所用课件、示例程序等。<br/>
Programming Lessons for Zero-based Students Aged 10 to 18 (**PLZS**), by [Vincent Wei](https://github.com/VincentWei).

## 概述

本课程特点：

1. 面向零基础但对编程有强烈兴趣的大中小学生（年龄在 10 到 18 周岁；小学五年级到大学一年级），学过一些编程课程的更好。
1. 整个系列课程的内容和国际前沿接轨，会涉及到 Linux、Git、Python、JavaScript、开源 AI 大模型等开发环境、开发工具、编程语言以及算法和数据结构；下分四个课程：
   - 零基础普及班：针对零基础学生的课程，内容包括虚拟机的安装、Linux 桌面系统的安装和使用、常用 Linux 系统命令、Vim 编辑器、Git 使用及 Python 编程入门。
   - 筑基班：针对已入门学生开设，课程内容涉及 Python、JavaScript 编程语言和 Bash Shell 编程，最终实现一个单机游戏的两个版本：终端版本和网页版本。
   - AI实战班：针对已掌握 Python 和 JavaScript 编程的学生开设。课程内容涉及开源 AI 模型以及网页编程，五人一组协作开发一个联网的网页游戏。
   - AI信奥班：针对计划在初中阶段参加 NOI（全国青少年信息学奥林匹克竞赛）的学生准备，要求已掌握 Linux 桌面系统的使用以及 Python 或 JavaScript 编程语言。课程内容涉及开源 AI 模型以及 C++ 编程语言，课程作业围绕一个联网的桌面游戏进行，其中内嵌有一个脚本编程语言解释器。通过将 NOI 大纲中所列知识点融入游戏程序和脚本语言的解释器加深学生对相关知识的理解和掌握。当然本课程既然面向竞赛，免不了要刷题。

1. 授课方式：
   - 零基础普及班为录播课，外加答疑直播。
   - 筑牢基础班、AI实战班以及AI信奥班均为直播课，外加作业点评及答疑直播。
   - 作业点评和答疑直播每周至少安排两场。
1. 学习周期：
   - 零基础普及班：两周。
   - 筑基班：周末班三个月；暑期班一个月。
   - AI实战班：周末班三个月；暑期班一个月。
   - AI信奥班：周末班三个月；暑期班一个月。

![课程体系](slides/plzs-course-framework.svg)

对学生的要求：

1. 小学五年级及以上。
1. 学有余力且对编程有强烈的兴趣。
1. 做好“听课一小时，实践三小时”的投入准备。

家长不用担心自己不懂软件或者编程而无法辅导孩子，只要做好如下几件事情即可：

1. 准备好一台专用于学习和开发的台式电脑或笔记本电脑给孩子使用。
1. 协助年龄较小的孩子在 Gitee 或者 GitHub 平台上注册开发者账号。

## 主讲介绍

魏永明，青海西宁人，清华大学精仪系机械制造专业毕业，研究生学历，工学硕士学位，飞漫软件创始人，2013 年度“开源软件杰出贡献人物”，2023 年度世界开源贡献榜人物。1999 年发布了知名开源软件 MiniGUI 并持续研发至今。二十多年来，该软件广泛应用于各类硬件产品。其主要编（译）著有《MiniGUI 剖析》、《Linux 实用教程》、《Linux 设备驱动程序》（二、三版）、《C 语言最佳实践》等。2018 年 11 月，发起合璧操作系统开源协作项目；2020 年 8 月，提出世界首款可编程标记语言 HVML；2022 年 7 月，开源发布 HVML 解释器及渲染器。2022 年底，HVML 项目获评 CSDN 2022 “年度开源影响力项目”；2023 年，HVML 项目入选国际测试委员会年度世界开源 Top100 榜。

## 课程计划

本系列课程和一般聚焦于单个特定编程语言的课程不同，课程中会涉及很多开发环境、工具、编程语言、算法和数据结构。本课程的目的不是培养仅仅熟悉单个编程语言以及应试型的竞赛选手，而是能够熟练利用已有的资源，包括各种开发工具、软件包、开源软件，并能灵活运用各种算法和数据结构，从而可以轻松完成特定编程和开发任务的小小全栈软件工程师，进而助力升学及深造。

课程分三个阶段。

入门阶段（零基础普及班）主要针对零基础的学生准备，期间会涉及 Linux 命令行、代码编辑器 Vim、代码仓库管理工具（Git）、Python 编程语言、Markdown 标记语言等内容。学生最终写出自己的第一个 Python 程序并创建自己的第一个开源代码仓库。

夯实基础阶段（筑基班）包含 10 场直播课和相应的视频内容。基础阶段的课程内容主要围绕 Python 和 JavaScript 编程程语言进行。学生最终要完成一个益智类单机游戏的两个版本，一个使用 Python 开发（字符界面），另一个使用 JavaScript 开发（图形界面）。对应的教学目标是，学生面对任何一种常见编程语言编写的程序代码，都能大致读懂其工作流程，借助互联网资源和开源世界中的各种已有软件包和代码，能够实现自己需要的增强功能，最终破除学生对程序和编程语言的神秘感，并激发其好奇心。

实战阶段（AI实战班）包含 10 场直播课和相应的视频内容。五人一组协作，使用 Python 和 JavaScript 完成一个联网的且使用开源 AI 模型的页面游戏。分组的策略是混合编队，就是不同年龄段的学生编到一个组当中，有基础或者大年龄段的学生担任组长，助教扮演项目主管角色。小组通过自建的代码仓库完成分工协作。大作业的任务可以由小组讨论确定（需要经过教学团队确认，以免目标太大无法完成），也可以选择教学团队给定的任务。大作业必须是联网的、包含人工智能元素的多人参与的小型网页游戏。

实战阶段（AI信奥班）包含 10 场直播课和相应的视频内容。该课程的内容针对计划在初中阶段或高中阶段参加 NOI（全国青少年信息学奥林匹克竞赛）的学生准备，要求已掌握 Linux 桌面环境以及Python 或 JavaScript 编程语言。课程内容涉及开源 AI 模型以及 C++ 编程语言，课程内容围绕一个联网的桌面游戏进行，通过将 NOI 大纲中所列知识点融入游戏程序加深学生对相关知识的理解和掌握。在课程学习当中，学生要学习掌握 NOI 大纲中提及的各种算法和数据结构，并使用 Python 和 C++ 编程语言完成一个联网的且使用开源 AI 模型的桌面（Linux/Windows）游戏。

该系列课程的设计以“授人以渔”为目标，通过在教学中模拟当下流行的开源协作软件开发模式，讲述软件工程师日常使用的工具和需要掌握的知识，以大作业为依托，引导学生理解需求、实现需求，通过自身的努力实践，将零基础的学生培养成面向未来的信息技术专家，助力升学及深造。

各课程涉及的编程语言及技术如下表所列：

| 课程          | 编程语言                  | 其他技术                                          |
| --            | --                        | --                                                |
| 零基础普及班  | Python                    | Linux, Vim, Git, Markdown                         |
| 筑基班        | Python, JavaScript, Bash  | Linux, HTML, CSS, HTTP, WebSocket                 |
| AI实战班      | Python, JavaScript, Bash  | Linux, HTML, CSS, HTTP, WebSocket, AI             |
| AI信奥班      | Python, C++, Bash         | Linux, Windows, GCC, CMake, HTTP, WebSocket, AI   |

## 直播平台及报名

课程的直播通过微信视频号进行，可扫码关注视频号“魏永明的编程课”：

![魏永明的编程课](https://courses.fmsoft.cn/plzs/assets/qrcode-wechat-channel-weiym.png)

报名可联系视频号客服或者直接添加企业微信工作人员：

![小李的企业微信](https://courses.fmsoft.cn/plzs/assets/qrcode-wechat-enterprise-lee.png)

## 课程资料

各课程的课件幻灯片入口：

- 零基础普及班：
   1. [准备开发环境](https://courses.fmsoft.cn/plzs/preparing-ubuntu-linux.html)
   1. [使用 Linux 桌面系统](https://courses.fmsoft.cn/plzs/using-linux-desktop-system.html)
   1. [我的第一个 Python 程序](https://courses.fmsoft.cn/plzs/my-first-python-program.html)
   1. [我的第一个开源仓库](https://courses.fmsoft.cn/plzs/my-first-open-source-repository.html)
- 筑基班：
   1. [流程控制（Python）](https://courses.fmsoft.cn/plzs/python-flow-control.html)
   1. [数据类型（Python）](https://courses.fmsoft.cn/plzs/python-data-types.html)
   1. [Python 标准库](https://courses.fmsoft.cn/plzs/python-standard-library.html)
   1. 大作业相关知识点（Python）
   1. HTTP 协议及 HTML/CSS
   1. JavaScript 编程语言
   1. 更新网页内容并和用户交互
   1. 在网页中绘制图形
   1. 大作业相关知识点（JavaScript）
- AI 实战班：
   1. 基于 Git 的协作式软件开发
   1. 大作业需求分析及架构设计
   1. Linux 服务器的安装和配置
   1. Web 服务器网关程序
   1. 用户账号管理及登录界面
   1. WebSocket 服务器及客户端
   1. 从网页中连接到 WebSocket 服务器
   1. 架设开源 AI 大模型
   1. 网页端利用 AI 功能
   1. 部署服务器端软件
- AI 信奥班：
   1. 我的第一个 C++ 程序
   1. C++ 工具链及项目构建
   1. C++ 标准模板库
   1. 字符串基本操作及其算法
   1. 基础数据结构
   1. 基础算法
   1. 经典例题一
   1. 高级数据结构
   1. 进阶算法
   1. 经典例题二
- 番外
   1. [Bash Shell 编程](https://courses.fmsoft.cn/plzs/bash-shell-programming.html)
   1. [其他编程语言长什么样？](https://courses.fmsoft.cn/plzs/other-programming-languages.html)
   1. [为什么选择二进制？](https://courses.fmsoft.cn/plzs/icsm-why-choose-binary.html)
   1. [二进制运算](https://courses.fmsoft.cn/plzs/icsm-binary-arithmetic.html)
   1. [数值：整数和实数](https://courses.fmsoft.cn/plzs/icsm-numbers.html)
   1. [文字：字符集及编码](https://courses.fmsoft.cn/plzs/icsm-text.html)
   1. [多媒体：图像、图形和音视频](https://courses.fmsoft.cn/plzs/icsm-multimedia.html)
   1. [结构化数据](https://courses.fmsoft.cn/plzs/icsm-structured-data.html)

## 学前准备

### 学习用电脑

学习用电脑最好是专用的，以防误操作导致数据丢失。电脑可以是：

1. 支持 Ubuntu Linux 22.04 的台式机或笔记本；请参考如下页面获取认证的设备清单：<https://ubuntu.com/certified>。
1. 2020 年以后生产的运行 macOS 14+ 的苹果 Mac 台式机或者笔记本。
1. 2020 年以后生产的运行 Windows 10/11 的台式机或者笔记本。

电脑的硬件配置要求：

- 主频在 2GHz 以上的 4 核或以上处理器；若安装虚拟机，则应选择 8 核或以上处理器。
- 内存 16GB 或以上；若安装虚拟机，则选择 32GB 或以上处理器。

考虑到基础阶段对电脑配置的要求不高，故如果已经有电脑则可暂时不用购置新的电脑。在进入提高阶段学习时，需要运行开源的人工智能大模型，此时再行考虑购置新的开发用电脑。

### 注册 GitHub 账号

家长需协助孩子在 <https://github.com> 或者 <https://gitee.com> 上注册一个开发者账号。在 GitHub 上注册需要一个电子邮件地址，在 Gitee 上注册需要一个中国大陆地区的手机号码。课程相关的学习资料、文档、示例程序等，通过如下代码仓库发布：

- GitHub: <https://github.com/VincentWei/PLZS>，或
- Gitee: <https://gitee.com/vincentwei7/PLZS>

在注册后，请确保在开发用电脑上使用 Chrome、Edge 浏览器登录 GitHub，并让孩子牢记账号名称和账号密码。

## 版权声明及许可证

本仓库中的文档及示例程序遵循 AGPL 3.0 许可证发布；由北京飞漫软件技术有限公司持有其著作权。

PLZS - Programming Lesson for Zero-based Students Aged 10 ~ 18
Copyright (C) 2024  Beijing FMSoft Technologies Co., Ltd.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as published
by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

## 附言

> Talk is cheap, show me the code.
>
> -- Linus Torvalds

### 各编程语言的 `Hello, world!` 程序

#### Python

```python
print('Hello, world!')
```

#### JavaScript

```javascript
console.log('Hello, world!')
```

#### Bash

```bash
echo 'Hello, world!'
```

#### C

```c
#include <stdio.h>

int main(void)
{
    printf("Hello, world!");
    return 0;
}
```

#### C++

```c++
#include <iostream>
using namespace std;

int main()
{
    cout << 'Hello, world!';
    return 0;
}
```

