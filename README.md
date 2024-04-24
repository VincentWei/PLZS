# 面向十岁及以上学生的编程实战系列课程

本仓库包含由[魏永明](https://github.com/VincentWei)主讲的针对十岁及以上学生的编程实战系列课程所用课件、示例程序等。<br/>
Programming Lessons for Zero-based Students Aged 10+ (**PLZS**), by [Vincent Wei](https://github.com/VincentWei).

## 概述

### 宗旨

**提升综合能力**  
本系列课程基于魏永明三十年的基础软件开发经验以及工程师培训经验，强调通过编程提升孩子们的抽象思维、逻辑思维和发散思维能力，培养孩子们的工程管理思想以及团队协作能力。

**助力升学深造**  
本系列课程强调实战的同时，注重提升孩子们的数学思维能力，通过将计算机科学中的各种算法和数据结构融合到真实案例中，帮助孩子们掌握信息技术奥林匹克竞赛初级及提高阶段的各个知识点，从而助力升学和深造。

### 主讲人

魏永明，青海西宁人，清华大学精仪系机械制造专业毕业，研究生学历，工学硕士学位，飞漫软件创始人，2013 年度“开源软件杰出贡献人物”，2023 年度世界开源贡献榜 Top100 人物。1999 年发布了知名开源软件 MiniGUI 并持续研发至今。二十多年来，该软件广泛应用于各类硬件产品。其主要编（译）著有《MiniGUI 剖析》、《Linux 实用教程》、《Linux 设备驱动程序》（二、三版）、《C 语言最佳实践》等。2018 年 11 月，发起合璧操作系统开源协作项目；2020 年 8 月，提出世界首款可编程标记语言 HVML；2022 年 7 月，开源发布 HVML 解释器及渲染器。2022 年底，HVML 项目获评 CSDN 2022 “年度开源影响力项目”；2023 年，HVML 项目入选国际测试委员会年度世界开源 Top100 榜。

### 课程简介

本系列课程面向对编程有强烈兴趣的大中小学生（年龄在 10 到 22 周岁；小学五年级到大学毕业前）。整个系列课程的内容和产业界热门技术、国际前沿技术接轨，会涉及到 Linux、Git、Python、C++、JavaScript、开源 AI 大模型等开发环境、开发工具、编程语言以及算法和数据结构；下分五门课程：
   - 普及班：针对零基础学生的课程，内容包括虚拟机的安装、Linux 桌面系统的安装和使用、常用 Linux 系统命令、Vim 编辑器、Git 使用及 Python 编程入门。学生最终写出自己的第一个 Python 程序并创建自己的第一个开源代码仓库。
   - 筑基班：针对已入门学生开设，课程内容涉及 Python 编程语言和 Linux 环境编程，最终实现学生的第一个软件作品：一个单机益智游戏。
   - AI实战班：针对已掌握 Python 编程语言的学生开设。课程内容涉及 Python 编程语言、JavaScript 编程语言、网页前后端编程、数据库以及开源 AI 模型等，五人一组协作开发一个联网的具有人工智能元素的网页游戏。
   - 信奥初级班：针对计划在初中阶段参加 NOI（全国青少年信息学奥林匹克竞赛）的学生准备，要求已掌握 Linux 桌面系统的使用以及 Python 编程语言。课程内容围绕 C++ 编程语言和常见解析器进行，通过将 NOI 大纲（初级）中所列知识点融入解析器的开发加深学生对相关知识的理解和掌握。
   - 信奥提高班：针对计划在高中阶段参加 NOI（全国青少年信息学奥林匹克竞赛）的学生准备，要求已掌握信奥初级班的内容。课程内容围绕 C++ 编程语言和一个脚本语言的解释器开展，通过将 NOI 大纲（提高级）中所列知识点融入脚本语言的解释器加深学生对相关知识的理解和掌握。
1. 授课方式：
   - 普及班为录播课，外加作业点评及答疑直播。
   - 筑基班、AI实战班、信奥初级班、信奥提高班均为直播课，外加作业点评及答疑直播。
   - 作业点评和答疑直播每周至少安排两场。
1. 学习周期：
   - 普及班：4讲8课时；周末班2周；暑期班1周。
   - 筑基班：5讲20课时；周末班6周；暑期班3周。
   - AI实战班：10讲40课时；周末班10周；暑期班5周。
   - 信奥初级班：10讲40课时；周末班10周；暑期班5周。
   - 信奥提高班：10讲40课时；周末班10周；暑期班5周。
1. 建议学习路线：
   - 零基础想学习全栈开发技术的学生：普及班 -> 筑基班 -> AI 实战班
   - 零基础想参加信奥竞赛的学生： 普及班 -> 筑基班 -> 信奥初级班 -> AI 实战班 -> 信奥提高班
   - 已学习 Python 的学生：信奥初级班 -> AI 实战班 -> 信奥提高班；另需补充学习普及班课程。
   - 只对信奥竞赛感兴趣的学生：信奥初级班 -> 信奥提高班；另需补充学习普及班课程。

![课程体系](slides/plzs-course-framework.svg)

各课程涉及技术如下表所示：

| 课程          | 编程语言                  | 其他技术                                              |
| --            | --                        | --                                                    |
| 普及班        | Python                    | Linux, Vim, Git, Markdown                             |
| 筑基班        | Python                    | Linux, Vim, Git                                       |
| AI实战班      | Python, JavaScript, Bash  | Linux, HTML, CSS, HTTP, WebSocket, Nginx, MySQL, AI   |
| 信奥初级班    | C++                       | Linux, GCC, CMake, JSON, CSP-J                        |
| 信奥提高班    | C++                       | Linux, GCC, CMake, RegEx, CSP-P                       |

对学生的要求：

1. 小学五年级及以上。
1. 学有余力且对编程有强烈的兴趣。
1. 做好“听课一小时，实践三小时”的投入准备。

家长不用担心自己不懂软件或者编程而无法辅导孩子，只要做好如下几件事情即可：

1. 准备好一台专用于学习和开发的台式电脑或笔记本电脑给孩子使用。
1. 协助年龄较小的孩子在 Gitee 或者 GitHub 平台上注册开发者账号。

## 详情

### 普及班

- 商品名称  
学生编程课普及班
- 简介  
本课程面向零基础但对编程有强烈兴趣的大中小学生（年龄在 10 到 22 周岁；小学五年级到大学毕业前）。

主要学习内容：

1. 虚拟机的安装
1. Linux 桌面系统的安装和使用
1. 常用 Linux 系统命令
1. Vim 编辑器
1. Git 使用
1. Python 编程入门

适宜人群：

- 十岁及以上学生（小学五年级到大学毕业前）。
- 对编程有强烈兴趣的学生。

课程特点：

- 超低成本：两周学习周期，快速发现潜力
- 寓教于乐：趣味历史故事，提高学习兴趣
- 注重实战：独立实操视频，方便对照练习
- 能力培养：强调抽象思维，提升数学思维
- 效果保障：串讲课程内容，直播互动答疑
- 作业点评：开源模式批改，培养协作能力

课程收获：

1. 学会常用的 Linux 命令、代码编辑器 Vim、代码仓库管理工具 Git、Markdown 等技术。
1. 掌握人工智能最流行编程语言 Python 的入门语法。
1. 编写自己的第一个 Python 程序并创建自己的第一个开源代码仓库。
1. 基于开源协作平台的作业批改，培养孩子基于开源平台的协作能力。
1. 主讲老师亲自在线答疑，专业辅导。

课程目录：

1. 准备开发环境
   - 课程内容介绍
   - 背景知识
   - 虚拟机的概念
   - 在虚拟机上安装 Ubuntu Linux
   - 参考链接
   - 要点回顾
   - 课后作业
1. 使用 Linux 桌面系统
   - 初识开发环境：终端和命令行
   - 常用系统命令及工具
   - 有趣的 Shell 命令行
   - 用 Vim 编辑文本文件
   - 要点回顾
   - 课后作业
1. 我的第一个 Python 程序
   - 运行 Python 解释器
   - Python 算术表达式和运算符
   - Python 变量和语句
   - Python 函数
   - 我的第一个程序
   - 要点回顾
   - 课后作业
1. 我的第一个开源仓库
   - 使用 Git 管理源文件
   - Markdown 语法创建格式化文本文件
   - 要点回顾
   - 课后作业

课程须知：

问：主要授课形式如何？  
答：本课程提供录播课程、在线课件及答疑直播。

问：提供哪些课后服务？  
答：请家长或学生及时扫码加班主任的企业微信，班主任会将学生组织到班级微信群中，以方便交流。学生可在班级群中提问，亦可添加主讲老师的微信提问。主讲老师每周提供至少两次共四个小时的答疑直播，学生可按需参加。

问：购买后如何上课?  
答：购课成功后，请按照发货短信中的内容做课前准备并开始学习，如有疑问请及时联系班主任。

问：课程有效期多长?  
答：购买后，课程内容长期有效；建议在两到三周左右完成学习并提交作业给主讲老师，以便尽快进入下个阶段的学习。

问：购买后是否支持退换货?  
答：虚拟商品，购课后不支持退换货，请理解。

问：如何联系客服?  
答：如有其他疑问，在视频号主页点击客服按钮，即可咨询客服。

### 筑基班

- 商品名称  
学生编程课筑基班
- 简介  
本课程针对已入门学生开设，课程内容涉及 Python 编程语言和 Linux 环境编程，最终实现学生的第一个软件作品：一个单机益智游戏。

主要学习内容：

1. Python 流程控制
1. Python 数据类型
1. Python 标准库
1. Python 大作业
1. Python 大作业辅导

适宜人群：

- 十岁及以上学生（小学五年级到大学毕业前），已完成普及班的课程内容。
- 对编程有强烈兴趣的学生。
- 科技特长生。

课程特点：

- 寓教于乐：趣味历史故事，提高学习兴趣
- 注重实战：独立实操视频，方便对照练习
- 能力培养：强调抽象思维，提升数学思维
- 学习效果：直播串讲课程，直播互动答疑
- 作业点评：开源模式批改，培养协作能力

课程优势：

1. 快速掌握 Python 编程语言及标准库的精髓，实现孩子的第一个软件作品。
1. 掌握 Python 语言中生成器、迭代器等抽象工具的概念及用法。
1. 掌握函数、递归调用、面向对象等的编程思想。
1. 掌握程序开发过程中的基本工程管理方法，学习如何解耦代码和数据。
1. 基于开源协作平台的作业批改，培养孩子基于开源平台的协作能力。
1. 主讲老师亲自在线答疑，提供专业辅导。

赠送课程：

直接购买筑基班课程的，同时赠送普及班课程；详情请联系客服或班主任。

课程目录：

1. Python 流程控制
   - 普及班作业回顾
   - 流程控制的来由
   - 布尔运算快速入门
   - Python 的逻辑表达式和逻辑运算符
   - Python 的流程控制语句
   - 要点回顾
   - 作业及要求
1. Python 数据类型
   - 作业回顾
   - 数值
   - 字符串
   - 列表及元组
   - 字典
   - 其他数据类型
   - 编程的中层境界：解耦数据和代码
   - 要点回顾
   - 作业及要求
1. Python 标准库
   - 作业回顾
   - Python 标准库概览
   - Python 函数的参数类型
   - Python 类和对象的基本概念
   - 针对常用数据类型的接口
   - 常用模块及其主要接口
   - 深入理解递归调用
   - 要点回顾
   - 作业
1. Python 大作业及相关知识点
   - 作业回顾
   - 大作业可选项目
   - 时间的获取和转换
   - 终端编程
   - 伪随机数
   - 要点回顾
   - 大作业注意事项
1. Python 大作业辅导
   - Python 程序的模块化管理
   - Python 程序的调试方法
   - 架构设计：如何划分模块
   - 可阅读性：为何要注重编码风格
   - 可测试性：如何测试基本功能
   - 可扩展性：解耦代码和数据
   - 示例代码分析

课程须知：

问：主要授课形式如何？  
答：本课程以教学直播为主，错过直播可观看回放，同时提供实操视频、在线课件及答疑直播。

问：提供哪些课后服务？  
答：请家长或学生及时扫码加班主任的企业微信，班主任会将学生组织到班级微信群中，以方便交流。学生可在班级群中提问，亦可添加主讲老师的微信提问。主讲老师每周提供至少两次共四个小时的答疑直播，学生可按需参加。

问：购买后如何上课?  
答：购课成功后，请按照发货短信中的内容做课前准备，并根据课表参与课程直播，如有疑问请及时联系班主任。

问：课程有效期多长?  
答：购买后，课程内容（直播回放、实操视频、在线课件等）三年有效；请按课表学习并及时提交作业给主讲老师，以便可以顺利进入下个阶段的学习。

问：购买后是否支持退换货?  
答：虚拟商品，购课后不支持退换货，请理解。

问：如何联系客服?  
答：如有其他疑问，在视频号主页点击客服按钮，即可咨询客服。

### AI实战班

- 商品名称  
学生编程课AI实战班
- 简介  
本课程针对已掌握 Python 编程语言的学生开设。课程内容涉及 Python 和 JavaScript 编程语言、网页前后端技术、数据库以及开源 AI 模型等。在进入大作业阶段时，将五人一组协作开发一个联网的具有人工智能元素的网页游戏。

主要学习内容：

1. 开源 AI 模型
1. Web 开发的背景知识及相关协议
1. JavaScript 编程语言
1. Web 前端相关技术
1. 用 Python 开发 Web 网关程序
1. 关系数据库基础
1. 用 Python 开发 WebSocket 服务器
1. 复杂软件项目的工程管理及自动运维技术

适宜人群：

- 十岁及以上学生（小学五年级到大学毕业前），已完成筑基班的课程内容。
- 就业前的大学生或初高中阶段的科技特长生。
- 对人工智能等新兴技术有强烈兴趣的学生。

课程特点：

- 全栈实战：学习全栈技术，应对复杂应用
- 人工智能：人工智能技术，面向科技未来
- 能力培养：强调团队协作，提升开发能力
- 学习效果：直播串讲课程，直播互动答疑
- 作业点评：开源模式批改，培养协作能力

课程收获：

1. 快速掌握 JavaScript 编程语言及 Web 编程的精髓，实现孩子们的第一个团队软件作品。
1. 掌握 Web 前端开发中事件处理、更新页面内容、图形绘制等技术。
1. 掌握 Web 后端开发中的数据库操作、服务器网管程序开发等技术。
1. 学习大型软件系统的架构设计方法，掌握基本的接口设计能力。
1. 掌握软件开发过程中基于分布式代码仓库的协作方法。
1. 主讲老师亲自在线答疑，提供专业辅导。

优惠活动：

直接购买本课程的，可优惠购买筑基班课程并获赠普及班课程；详情请联系客服。

课程目录：

1. Web 相关背景知识
   - Web 发展历史
   - HTML 和 CSS
   - HTTP 协议
   - WebSocket 协议
   - 关系数据库和 SQL
   - JSON 数据交换格式
1. 架设 Linux Web 服务器
   - Nginx 服务器的安装和配置
   - MySQL 服务器的安装和配置
   - 常用 Python Web 后端框架
   - Python 实现 WebSocket 服务器及客户端
1. JavaScript 编程语言
   - JavaScript 基础语法
   - JavaScript 的特色
1. Web 前端开发
   - DOM 的概念及接口
   - 在网页中绘制图形
   - 在网页中和用户交互
   - Web 前端数据存储和会话保持
1. 网页前端综合练习及专题辅导
1. 基于 Git 的协作式软件开发
   - Git 仓库的创建、克隆、分支、合并及推送
   - GitHub/Gitee 协作：议题及拉取请求
1. 开源 AI 大模型
   - 流行的开源 AI 大模型
   - 在 Python 中调用 AI 开源大模型
1. 大作业需求分析及架构设计
   - 模块划分及接口、协议设计
   - 后台数据库设计
   - 网页端调用 AI 功能
1. 大作业专题辅导
   - 用户账号管理
   - 数据的散列处理及加解密
   - 文件的上传和下载
   - 前端多媒体处理
   - 通过浏览器扩展访问本地数据
1. 服务的部署和运维
   - Bash 脚本编程
   - GitLab 及 DevOps

课程须知：

问：主要授课形式如何？  
答：本课程以教学直播为主，错过直播可观看回放，同时提供在线课件及答疑直播。

问：提供哪些课后服务？  
答：请家长或学生及时扫码加班主任的企业微信，班主任会将学生组织到班级微信群中，以方便交流。学生可在班级群中提问，亦可添加主讲老师的微信提问。主讲老师每周提供至少两次共四个小时的答疑直播，学生可按需参加。

问：购买后如何上课?  
答：购课成功后，请按照发货短信中的内容做课前准备，并根据课表参与课程直播，如有疑问请及时联系班主任。

问：课程有效期多长?  
答：购买后，课程内容（直播回放、在线课件等）三年有效；请按课表学习并及时提交作业给主讲老师，以便可以顺利进入下个阶段的学习。

问：购买后是否支持退换货?  
答：虚拟商品，购课后不支持退换货，请理解。

问：如何联系客服?  
答：如有其他疑问，在视频号主页点击客服按钮，即可咨询客服。

### 信奥初级班

- 商品名称  
学生编程课信奥初级班
- 简介  
本课程针对计划在初中阶段参加 NOI（全国青少年信息学奥林匹克竞赛）的学生准备，要求已掌握 Linux 桌面系统的使用以及 Python 编程语言。课程内容围绕 C++ 编程语言和四则运算表达式、JSON 解析器和任意精度整数运算几个大作业进行，通过将 NOI 大纲（初级）中所列知识点融入解析器的开发加深学生对相关知识的理解和掌握。

主要学习内容：

1. C++ 编程语言的基本语法
1. GCC 及 CMake 构建生成器
1. CSP-J 重要考点，包括各基础算法和数据结构
1. 通过具有实际意义的大作业加深对所学知识的理解和掌握
1. CSP-J 真题演练及辅导

适宜人群：

- 初中阶段，已完成筑基班的课程内容的学生。
- 计划参加信息学奥林匹克竞赛（初级）的科技特长生。

课程特点：

- 寓教于乐：趣味历史故事，提高学习兴趣
- 能力培养：强化抽象思维，提升编程能力
- 实战结合：应试融合实战，学习不再枯燥
- 学习效果：直播串讲课程，直播互动答疑
- 作业点评：开源模式批改，培养协作能力

课程收获：

1. 快速掌握 C++ 编程语言以及面向对象编程的精髓。
1. 掌握 C++ 编程语言中运算符重载、迭代器等抽象工具的概念及用法。
1. 覆盖 CSP-J 重要考点，结合数学问题讲解，强化训练孩子的抽象思维、逻辑思维和发散思维。
1. 通过具有实际意义的大作业加深的 CSP-J 重要考点的理解。
1. 掌握程序开发过程中的基本工程管理方法，学习如何提高代码的可维护性、可扩展性和可测试性。
1. 基于开源协作平台的作业批改，培养孩子基于开源平台的协作能力。
1. 主讲老师亲自在线答疑，提供专业辅导。

优惠活动：

直接购买本课程的，可优惠购买筑基班课程并获赠普及班课程；详情请联系客服。

课程目录：

1. C++ 编程语言及开发环境
   - C++ 基础语法
   - GCC 及 CMake 构建系统
   - C++ 数据类型
   - C++ 流程控制
   - C++ 类和对象
   - C++ 指针及引用
   - C++ 模板及标准模板库
   - C++ 编程语言作业辅导
1. 基础算法
   - 递归、二分法、倍增法
   - 排序算法
   - 基础算法作业辅导
1. 线性数据结构
   - 队列和栈
   - 单向链表
   - 双向链表
   - 循环链表
   - 线性数据结构作业辅导
1. 树型数据结构
   - 一般树
   - 二叉树
   - 特殊树
   - 树型数据结构作业辅导
1. 中期大作业
   - 四则运算解析器
   - 中期大作业辅导
1. 搜索算法
   - 线性结构中的搜索
   - 子字符串搜索
   - 树型结构中的搜索
   - 搜索算法作业辅导
1. 图及图论算法
   - 图
   - 图论算法
   - 图论算法作业辅导
1. 其他算法和数据结构
   - 动态规划
   - 初等数论
   - 离散与组合数学
1. 结业大作业
   - 无限精度整数运算
   - JSON 解析器
1. CSP-J 真题演练

课程须知：

问：主要授课形式如何？  
答：本课程以教学直播为主，错过直播可观看回放，同时提供在线课件及答疑直播。

问：提供哪些课后服务？  
答：请家长或学生及时扫码加班主任的企业微信，班主任会将学生组织到班级微信群中，以方便交流。学生可在班级群中提问，亦可添加主讲老师的微信提问。主讲老师每周提供至少两次共四个小时的答疑直播，学生可按需参加。

问：购买后如何上课?  
答：购课成功后，请按照发货短信中的内容做课前准备，并根据课表参与课程直播，如有疑问请及时联系班主任。

问：课程有效期多长?  
答：购买后，课程内容（直播回放、在线课件等）三年有效；请按课表学习并及时提交作业给主讲老师，以便可以顺利进入下个阶段的学习。

问：购买后是否支持退换货?  
答：虚拟商品，购课后不支持退换货，请理解。

问：如何联系客服?  
答：如有其他疑问，在视频号主页点击客服按钮，即可咨询客服。

### 信奥提高班

- 商品名称  
学生编程课信奥提高班
- 简介  
本课程针对计划在初中或高中阶段参加 NOI（全国青少年信息学奥林匹克竞赛）提高组的学生准备，要求已掌握信奥初级班的内容。课程内容围绕正则表达式以及一个脚本语言的解释器开展，通过将 NOI 大纲（提高级）中所列知识点融入脚本语言的解释器加深学生对相关知识的理解和掌握。通过本课程的学习，学生将掌握 NOI 大纲（提高级）中提及的各种算法和数据结构，并使用 C++ 编程语言完成一个脚本语言的解释器。

主要学习内容：

1. C++ 编程语言的高级用法
1. CSP-P 重要考点，包括各进阶算法和高级数据结构
1. 通过具有实际意义的大作业加深对所学知识的理解和掌握
1. CSP-P 真题演练及辅导

适宜人群：

- 初中阶段或高中阶段，已完成信奥初级班课程内容的学生。
- 计划参加信息学奥林匹克竞赛（提高组）的科技特长生。

课程特点：

- 寓教于乐：趣味历史故事，提高学习兴趣
- 能力培养：强化抽象思维，提升编程能力
- 实战结合：应试融合实战，学习不再枯燥
- 学习效果：直播串讲课程，直播互动答疑
- 作业点评：开源模式批改，培养协作能力

课程收获：

1. 快速掌握现代 C++ 编程语言的高级功能。
1. 覆盖 CSP-P 重要考点，结合数学问题讲解，强化训练孩子的抽象思维、逻辑思维和发散思维。
1. 通过具有实际意义的大作业加深的 CSP-P 重要考点的理解。
1. 掌握程序开发过程中的基本工程管理方法，学习如何提高代码的可维护性、可扩展性和可测试性。
1. 基于开源协作平台的作业批改，培养孩子基于开源平台的协作能力。
1. 主讲老师亲自在线答疑，提供专业辅导。

课程目录：

1. 现代 C++ 编程语言的高级功能
   - 类的继承
   - 虚函数和多态
   - STL 高级接口
1. 字符串相关算法
   - 哈希算法
   - 字符串匹配算法
   - 正则表达式
1. 通用操作系统的内存管理
   - 虚拟内存机制
   - 常见的堆管理算法
   - 堆管理算法的优化
1. 树型数据结构
   - 最佳平衡二叉树
   - 红黑树及其应用
   - 最小生成树及树上操作
   - 树链剖分
   - 动态树 LCT
1. 中期大作业
   - 正则表达式的解析及匹配
   - 中期大作业辅导
1. 搜索算法
   - 搜索算法的优化
   - 最短路径
1. 动态规划
   - 树型动态规划
   - 状态压缩动态规划
   - 动态规划的优化
1. 其他理论知识
   - 初等数论
   - 线性代数
   - 离散及组合数学
1. 结业大作业
   - Lua 或简化的 Python 解释器
1. CSP-P 真题演练

课程须知：

问：主要授课形式如何？  
答：本课程以教学直播为主，错过直播可观看回放，同时提供在线课件及答疑直播。

问：提供哪些课后服务？  
答：请家长或学生及时扫码加班主任的企业微信，班主任会将学生组织到班级微信群中，以方便交流。学生可在班级群中提问，亦可添加主讲老师的微信提问。主讲老师每周提供至少两次共四个小时的答疑直播，学生可按需参加。

问：购买后如何上课?  
答：购课成功后，请按照发货短信中的内容做课前准备，并根据课表参与课程直播，如有疑问请及时联系班主任。

问：课程有效期多长?  
答：购买后，课程内容（直播回放、在线课件等）三年有效；请按课表学习并及时提交作业给主讲老师，以便可以顺利进入下个阶段的学习。

问：购买后是否支持退换货?  
答：虚拟商品，购课后不支持退换货，请理解。

问：如何联系客服?  
答：如有其他疑问，在视频号主页点击客服按钮，即可咨询客服。

## 直播平台及报名

课程的直播通过微信视频号进行，可扫码关注视频号“考鼎学堂”：

![考鼎学堂](https://courses.fmsoft.cn/plzs/assets/qrcode-wechat-channel-weiym.png)

报名可联系视频号客服或者直接添加企业微信工作人员：

![小李的企业微信](https://courses.fmsoft.cn/plzs/assets/qrcode-wechat-enterprise-lee.png)

## 课程资料

各课程的课件幻灯片入口：

- 普及班：
   1. [准备开发环境](https://courses.fmsoft.cn/plzs/preparing-ubuntu-linux.html)
   1. [使用 Linux 桌面系统](https://courses.fmsoft.cn/plzs/using-linux-desktop-system.html)
   1. [我的第一个 Python 程序](https://courses.fmsoft.cn/plzs/my-first-python-program.html)
   1. [我的第一个开源仓库](https://courses.fmsoft.cn/plzs/my-first-open-source-repository.html)
- 筑基班：
   1. [Python 流程控制](https://courses.fmsoft.cn/plzs/python-flow-control.html)
   1. [Python 数据类型](https://courses.fmsoft.cn/plzs/python-data-types.html)
   1. [Python 标准库](https://courses.fmsoft.cn/plzs/python-standard-library.html)
   1. [Python 大作业及相关知识点](https://courses.fmsoft.cn/plzs/python-comprehensive-exercise.html)
   1. [Python 大作业辅导](https://courses.fmsoft.cn/plzs/python-project-coaching.html)
- AI 实战班：
   1. 搭建网页服务器
   1. JavaScript 及网页编程
   1. 更新网页内容
   1. 在网页中绘制图形
   1. 在网页中和用户交互
   1. JavaScript 综合练习
   1. 基于 Git 的协作式软件开发
   1. [Bash Shell 编程](https://courses.fmsoft.cn/plzs/bash-shell-programming.html)
   1. 大作业需求分析及架构设计
   1. Linux 服务器的安装和配置
   1. Web 服务器网关程序
   1. 用户账号管理及登录界面
   1. WebSocket 服务器及客户端
   1. 从网页中连接到 WebSocket 服务器
   1. 架设开源 AI 大模型
   1. 网页端利用 AI 功能
   1. 部署服务器端软件
- 信奥初级班：
   1. 我的第一个 C++ 程序
   1. C++ 工具链及项目构建
   1. C++ 标准模板库
   1. JSON 解析器的架构
   1. 字符串基本操作及其算法
   1. 基础数据结构
   1. 基础算法
   1. 经典例题一
   1. 高级数据结构
   1. 进阶算法
   1. 经典例题二
- 信奥提高班：
   1. C++ 和其他编程语言的互操作性
   1. [Bash Shell 编程](https://courses.fmsoft.cn/plzs/bash-shell-programming.html)
   1. 脚本解释器的架构
   1. 高阶数据结构
   1. 高阶算法
   1. 经典例题一
   1. 高级数据结构
   1. 进阶算法
   1. 经典例题二
- 番外
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

