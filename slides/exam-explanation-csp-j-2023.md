# CSP-J 2023 真题

		
## 单项选择题

	
### 第 1 题

- 在 C++ 中，下面哪个关键字用于声明一个变量，其值不能被修改？（  ）

   - A. `unsigned`
   - B. `const`
   - C. `static`
   - D. `mutable`

	
### 第 2 题

- 八进制数 <code>(12345670)<sub>8</sub></code> 和 <code>(07654321)<sub>8</sub></code> 的和为（  ）。

   - А. <code>(22222221)<sub>8</sub></code>
   - B. <code>(21111111)<sub>8</sub></code>
   - C. <code>(22111111)<sub>8</sub></code>
   - D. <code>(22222211)<sub>8</sub></code>

	
### 第 3 题

- 阅读下述代码，请问修改 `data` 的 `value` 成员以存储 `3.14`，正确的方式是（  ）。

```cpp
union Data {
    int num;
    float value;
    char symbol;
};
union Data data;
```

   - A. `data.value = 3.14;`
   - B. `value.data = 3.14;`
   - C. `data->value = 3.14;`
   - D. `value->data = 3.14;`


	
### 第 4 题

- 假设有一个链表节点的定义后附代码片段所示。现在有一个指向链表头部的指针：`Node* head`。如果想要在链表中插入一个新节点，其成员 `data` 的值 `42`，并使新节点成链表的第一个节点，下面哪个操作是正确的？（ ）

   - A. `Node* newNode = new Node; newNode->data = 42; newNode->next = head; head = newNode;`
   - B. `Node* newNode = new Node; head->data = 42; newNode->next = head; head = newNode;`
   - C. `Node* newNode = new Node; newNode->data = 42; head->next = newNode;`
   - D. `Node* newNode = new Node; newNode->data = 42; newNode->next = head;`

```cpp
struct Node {
    int data;
    Node* next;
};
```
	
### 第 5 题

- 根节点的高度为 `1`，一根拥有 `2023` 个节点的三叉树高度至少 （  ）。

   - A. `6`
   - B. `7`
   - C. `8`
   - D. `9`

	
### 第 6 题

- 小明在某一天中依次有七个空闲时间段，他想要选出至少一个空闲时间段来练习唱歌，但他希望任意两个练习的时间段之间都有至少两个空闲的时间段让他休息，则小明一共有（  ）种选择时间段的方案。

   - A. `31`
   - B. `18`
   - C. `21`
   - D. `33`

	
### 第 7 题

- 以下关于高精度运算的说法错误的是（  ）。

   - A. 高精度计算主要是用来处理大整数或需要保留多位小数的运算。
   - B. 大整数除以小整数的处理的步骤可以是，将被除数和除数对齐，从左到右逐位尝试将除数乘以某个数，通过减法得到新的被除数，并累加商。
   - C. 高精度乘法的运算时间只与参与运算的两个整数中长度较长者的位数有关。
   - D. 高精度加法运算的关键在于逐位相加并处理进位。

	
### 第 8 题

- 后缀表达式 `6 2 3 + - 3 8 2 / + * 2 ^ 3 +` 对应的中缀表达式是（  ）。

   - A. `((6 - (2 + 3)) * (3 + 8 / 2)) ^ 2 + 3`
   - B. `6 - 2 + 3 * 3 + 8 / 2 ^ 2 + 3`
   - C. `(6 - (2 + 3)) + ((3 + 8 / 2) ^ 2) + 3`
   - D. `6 - ((2 + 3) * (3 + 8 / 2)) ^ 2 + 3`

	
### 第 9 题

- 数 <code>(101010)<sub>2</sub></code> 和 <code>(166)<sub>8</sub></code> 的和为（  ）。

   - А. <code>(10110000)<sub>2</sub></code>
   - В. <code>(236)<sub>8</sub></code>
   - C. <code>(158)<sub>10</sub></code>
   - D. <code>(AO)<sub>16</sub></code>

	
### 第 10 题

- 假设有一组字符 `{a, b, c, d, e, f}`，对应的频率分别为 `5%, 9%, 12%, 13%, 16%, 45%`。请问以下哪个选项是字符 `a, b, c, d, e, f` 分别对应的一组哈夫曼编码？（ ）

   - A. `1111, 1110, 101, 100, 110, 0`
   - В. `1010, 1001, 1000, 011, 010, 00`
   - С. `000, 001, 010, 011, 10, 11`
   - D. `1010, 1011, 110, 111, 00, 01`

	
### 第 11 题

- 给定一棵二叉树，其前序遍历结果为 `ABDECFG`，中序遍历结果为 `DEBACFG`。请问这棵树的正确后序遍历结果是什么？（  ）

   - A. `EDBGFCA`
   - B. `EDBGCFA`
   - C. `DEBGFCA`
   - D. `DBEGFCA`

	
### 第 12 题

- 考虑一个有向无环图，该图包括 4 条有向边：`(1, 2)`，`(1, 3)`，`(2, 4)` 和 `(3, 4)`。以下哪个选项是这个有向无环图的一个有效拓扑排序？（  ）

   - A. `4, 2, 3, 1`
   - B. `1, 2, 3, 4`
   - C. `1, 2, 4, 3`
   - D. `2, 1, 3, 4`

	
### 第 13 题

- 在计算机中，以下哪个选项描述的数据存储容量最小？（  ）

   - A. 字节（byte）
   - B. 比特（bit）
   - C. 字（word）
   - D. 千字节（kilobyte）

	
### 第 14 题

- 一个班级有 10 个男生和 12 个女生。如果要选出一个 3 人的小组，并且小组中必须至少包含 1 个女生，那么有多少种可能的组合？（  ）

   - A. 1420
   - B. 1770
   - C. 1540
   - D. 2200

	
### 第 15 题

- 以下哪个不是操作系统？（  ）

   - A. Linux
   - B. Windows
   - C. Android
   - D. HTML

		
## 阅读程序题

```cpp []
#include<iostream>
#include<cmath>
using namespace std;

double f(double a, double b, double c){
    double s=(a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main(){
    cout.flags(ios::fixed);
    cout.precision(4);
    int a, b,c;
    cin>>a>>b>>c;
    cout<<f(a,b,c)<<endl；
    return 0;
}
```

- 假设输入的所有数都为不超过 `1000` 的正整数，完成下面的判断题和单选题。

	
### 判断

16) 当输入为 `2 2 2` 时，输出为 `1.7321`。
17) 将第 7 行中的 `(s-b)*(s-c)` 改为 `(s-c)*(s-b)` 不会影响程序运行的结果。
18) 程序总是输出四位小数。

	
### 选择

19) 当输入为 `3 4 5` 时，输出为（）  
A. `6.0000`  
В. `12.0000`  
C. `24.0000`  
D. `30.0000`

20) 当输入`5 12 13`时，输出为（）  
A. `24.0000`  
B. `30.0000`  
C. `60.0000`  
D. `120.0000`

		
## 阅读程序题

```cpp []
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int f(string x, string y){
    int m=x.size();
    int n=y.size();
    vector<vector<int>>v(m+1, vector<int>(n+1,0));
    for (int i=1;i<=m;i++){
        for（int j=1;j<=n;j++){
            if(x[i-1]==y[j-1]){
                v[i][j]=v[i-1][j-1]+1;
            } else {
                v[i][j]=max(v[i-1][j], v[i][j-1]);
            }
        }
    }
    return v[m][n];
}

bool g(string x, string y){
    if(x.size() != y.size()){
        return false;
    }
    return f(x+x,y)==y.size();
}

int main(){
    string x,y;
    cin>>х>>у;
    cout<<g(x,y)<<endl;
    return 0;
}
```

	
### 判断

21) `f` 函数的返回值小于等于 `min(n, m)`。
22) `f` 函数的返回值等于两个输入字符串的最长公共子串的长度。
23) 当输入两个完全相同的字符串时，`g` 函数的返回值总是 `true`。

	
### 选择

24) 将第 `19` 行中的 `v[m][n]` 替换为 `v[n][m]`，那么该程序（）  
A. 行为不变  
B. 只会改变输出  
C. 一定非正常退出  
D. 可能非正常退出

25) 当输入为 `csp-j p-jcs` 时，输出为（）  
A. `0`  
С. `1`  
B. `T`  
D. `F`

26) 当输入为 `csppsc spsccp` 时，输出为（）  
A. `T`  
B. `F`  
C. `0`  
D. `1`

