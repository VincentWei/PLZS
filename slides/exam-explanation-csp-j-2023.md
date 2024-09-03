# CSP-J 2023 真题

		
## 单项选择题

	
### 第 1 题

在 C++ 中，下面哪个关键字用于声明一个变量，其值不能被修改？（  ）<!-- .element: style="text-align:left" -->

   - A. `unsigned`
   - B. `const`
   - C. `static`
   - D. `mutable`

	
### 第 2 题

八进制数 <code>(12345670<sub>8</sub></code> 和 <code>(07654321)<sub>8</sub></code> 的和为（  ）。<!-- .element: style="text-align:left" -->

   - А. <code>(22222221)<sub>8</sub></code>
   - B. <code>(21111111)<sub>8</sub></code>
   - C. <code>(22111111)<sub>8</sub></code>
   - D. <code>(22222211)<sub>8</sub></code>

	
### 第 3 题

阅读下述代码，请问修改 `data` 的 `value` 成员以存储 `3.14`，正确的方式是（  ）。<!-- .element: style="text-align:left" -->

```cpp
union Data {
    int num;
    float value;
    char symbol;
;
union Data data;
```

   - A. `data.value = 3.14;`
   - B. `value.data = 3.14;`
   - C. `data->value = 3.14;`
   - D. `value->data = 3.14;`


		
## CSP-J 2023 真题解析之单项选择题

4) 假设有一个链表的节点定义如下：

```cpp
struct Node {
    int data;
    Node* next;
};
```

现在有一个指向链表头部的指针：`Node* head`。如果想要在链表中插入一个新节点，
其成员 `data` 的值 `42`，并使新节点成链表的第一个节点，下面哪个操作是正确的？（ ）

A. `Node* newNode = new Node; newNode->data = 42; newNode-> next = head; head = newNode;`  
B. `Node* newNode = new Node; head-> data = 42; newNode->next = head; head = newNode;`  
C. `Node* newNode = new Node; newNode->data = 42; head->next = newNode;`  
D. `Node* newNode = new Node; newNode-> data = 42; newNode-> next = head;`
