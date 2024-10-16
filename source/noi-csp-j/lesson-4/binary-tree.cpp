/*
 * One example for NOI CSP-J Lesson 4:
 * <https://courses.fmsoft.cn/plzs/noijunior-tree-data-structures.html>
 *
 * Author: Vincent Wei
 *  - <https://github.com/VincentWei>
 *  - <https://gitee.com/vincentwei7>
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * License: GPLv3
 */
#include <stack>        // for stack
#include <queue>        // for queue

template <typename T>
class bin_tree_node {
  public:
    T payload;                          // 节点负载
    bin_tree_node *left;                // 左子节点
    bin_tree_node *right;               // 右子节点

    // 节点的构造函数
    bin_tree_node(const T& value) {
        payload = value;
        left = nullptr;
        right = nullptr;
    }

    // 节点的析构函数
    ~bin_tree_node() {
        if (left)
            delete left;
        if (right)
            delete right;
    }

    // 深度优先（depth-first）遍历
    template <typename context, typename visitor_func>
    void dfs(context* ctxt, visitor_func visitor) const
    {
        std::stack<const bin_tree_node*> stack;
        stack.push(this);

        while (!stack.empty()) {
            const bin_tree_node* node = stack.top();
            stack.pop();

            // call the visitor for the current node
            visitor(ctxt, node->payload);

            if (node->right)
                stack.push(node->right);
            if (node->left)
                stack.push(node->left);
        }
    }

    // 深度优先（depth-first）前序遍历
    template <typename context, typename visitor_func>
    void dfs_preorder(context* ctxt, visitor_func visitor) const
    {
        // call the visitor for the current node
        visitor(ctxt, payload);

        if (left)
            left->dfs_preorder(ctxt, visitor);
        if (right)
            right->dfs_preorder(ctxt, visitor);
    }

    // 深度优先（depth-first）中序遍历
    template <typename context, typename visitor_func>
    void dfs_inorder(context* ctxt, visitor_func visitor) const
    {
        if (left)
            left->dfs_inorder(ctxt, visitor);

        // call the visitor for the current node
        visitor(ctxt, payload);

        if (right)
            right->dfs_inorder(ctxt, visitor);
    }

    // 深度优先（depth-first）后序遍历
    template <typename context, typename visitor_func>
    void dfs_postorder(context* ctxt, visitor_func visitor) const
    {
        if (left)
            left->dfs_postorder(ctxt, visitor);

        // call the visitor for the current node
        visitor(ctxt, payload);

        if (right)
            right->dfs_postorder(ctxt, visitor);
    }

    // 广度优先（breadth-first）级序遍历
    template <typename context, typename visitor_func>
    void bfs(context* ctxt, visitor_func visitor) const
    {
        std::queue<const bin_tree_node*> queue;
        queue.push(this);

        while (!queue.empty()) {
            const bin_tree_node* node = queue.front();
            queue.pop();

            // call the visitor for the current node
            visitor(ctxt, node->payload);

            if (node->left)
                queue.push(node->left);
            if (node->right)
                queue.push(node->right);
        }
    }

    // 获取左子节点（const 版本）
    const bin_tree_node* left_child() const
    {
        return left;
    }

    // 获取左子节点（非 const 版本）
    bin_tree_node* left_child()
    {
        return left;
    }

    // 设置当前节点的左子节点，返回新节点；已有左子节点时返回 nullptr
    bin_tree_node* left_child(const T& value)
    {
        if (left)
            return nullptr;

        // Create a new node with the given value
        left = new bin_tree_node(value);
        return left;
    }

    // 移除当前节点的左子树
    bool erase_left_subtree()
    {
        if (left == nullptr)
            return false;

        delete left;
        left = nullptr;
        return true;
    }

    // 获取右子节点（const 版本）
    const bin_tree_node* right_child() const
    {
        return right;
    }

    // 获取右子节点（非 const 版本）
    bin_tree_node* right_child()
    {
        return right;
    }

    // 设置当前节点的右子节点，返回新节点；已有右子节点时返回 nullptr
    bin_tree_node* right_child(const T& value)
    {
        if (right)
            return nullptr;

        // Create a new node with the given value
        right = new bin_tree_node(value);
        return right;
    }

    // 移除当前节点的右子树
    bool erase_right_subtree()
    {
        if (right == nullptr)
            return false;

        delete right;
        right = nullptr;
        return true;
    }
};

#include <iostream>     // for cin and cout
#include <sstream>      // for ostringstream
#include <string>       // for stod()
#include <cassert>      // for assert()

using namespace std;

void test_binary_tree_node()
{
    struct context_print {
        ostream& os;
    };

    struct visitor_print {
        void operator() (context_print* ctxt, const int& value) {
            ctxt->os << value << " ";
        }
    };

    ostringstream oss;
    context_print ctxt = { oss };
    using my_bin_tree_node = bin_tree_node<int>;
    my_bin_tree_node *level_0, *level_1, *level_2;

    level_0 = new my_bin_tree_node(0);

    oss.str("");
    level_0->dfs_preorder(&ctxt, visitor_print{});
    assert(oss.str() == "0 ");

    oss.str("");
    level_0->bfs(&ctxt, visitor_print{});
    assert(oss.str() == "0 ");

    level_0->left_child(-1);
    level_1 = level_0->right_child(1);
    assert(level_0->left_child()->payload == -1);
    assert(level_0->right_child()->payload == 1);

    oss.str("");
    level_0->dfs_preorder(&ctxt, visitor_print{});
    clog << oss.str() << endl;
    assert(oss.str() == "0 -1 1 ");

    oss.str("");
    level_0->bfs(&ctxt, visitor_print{});
    clog << oss.str() << endl;
    assert(oss.str() == "0 -1 1 ");

    level_1->left_child(-10);
    level_2 = level_1->right_child(10);
    assert(level_1->left_child()->payload == -10);
    assert(level_1->right_child()->payload == 10);

    oss.str("");
    level_0->dfs_inorder(&ctxt, visitor_print{});
    clog << oss.str() << endl;
    assert(oss.str() == "-1 0 -10 1 10 ");

    oss.str("");
    level_0->bfs(&ctxt, visitor_print{});
    clog << oss.str() << endl;
    assert(oss.str() == "0 -1 1 -10 10 ");

    level_2->left_child(-100);
    level_2->right_child(100);
    assert(level_2->left_child()->payload == -100);
    assert(level_2->right_child()->payload == 100);

    oss.str("");
    level_0->dfs_postorder(&ctxt, visitor_print{});
    clog << oss.str() << endl;
    assert(oss.str() == "-1 0 -10 1 -100 10 100 ");

    oss.str("");
    level_0->bfs(&ctxt, visitor_print{});
    clog << oss.str() << endl;
    assert(oss.str() == "0 -1 1 -10 10 -100 100 ");

    delete level_0;
}

int main()
{
    test_binary_tree_node();

    using my_bin_tree_node = bin_tree_node<double>;
    my_bin_tree_node* root = new my_bin_tree_node(0);

    my_bin_tree_node *node = root;
    my_bin_tree_node *last_node = root;

    // 此循环将持续读取用户的输入，直到 stod() 函数
    // 无法正常将空格分隔的字符串解析为浮点数而抛出异常为止。
    do {
        string buf;
        cin >> buf;

        double d;
        try {
            size_t sz;
            d = stod(buf, &sz);
        }
        catch (std::exception& e) {
            break;
        }

        if (d < 0) {
            last_node = node->left_child(d);
        }
        else if (d > 0) {
            last_node = node->right_child(d);
        }
        else {
            node = last_node;
        }

    } while (true);

    struct context_print {
        ostream& os;
    };

    struct visitor_print {
        void operator() (context_print* ctxt, const double& value) {
            ctxt->os << value << endl;
        }
    };

    context_print ctxt = { cout };
    clog << "DFS Traversal (preorder)\n";
    root->dfs_preorder(&ctxt, visitor_print{});

    clog << "DFS Traversal (inorder)\n";
    root->dfs_inorder(&ctxt, visitor_print{});

    clog << "DFS Traversal (postorder)\n";
    root->dfs_postorder(&ctxt, visitor_print{});

    clog << "BFS Traversal\n";
    root->bfs(&ctxt, visitor_print{});
    delete root;
}

