# CSP-J 2023 真题

		
## 单项选择题

	
### 第 1 题

1) 在 C++ 中，下面哪个关键字用于声明一个变量，其值不能被修改？（  ）
   - A. `unsigned`
   - B. `const`
   - C. `static`
   - D. `mutable`

	
### 第 2 题

2) 八进制数 `$ (12345670)_8 $` 和 `$ (07654321)_8 $` 的和为（  ）。
   - А. `$ (22222221)_8 $`
   - B. `$ (21111111)_8 $`
   - C. `$ (22111111)_8 $`
   - D. `$ (22222211)_8 $`

	
### 第 3 题

3) 阅读下述代码，请问修改 `data` 的 `value` 成员以存储 `3.14`，正确的方式是（  ）。

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
