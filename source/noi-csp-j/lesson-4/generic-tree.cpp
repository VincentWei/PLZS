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
#include <vector>       // for vector

template <typename T>
struct tree_node {
    T payload;                          // 节点负载
    std::vector<tree_node*> children;   // 子节点矢量

    // 节点的构造函数
    tree_node(const T& value) {
        this->payload = value;
    }

    // 节点的析构函数
    ~tree_node() {
        for (size_t i = 0; i < this->children.size(); i++) {
            delete this->children[i];
            this->children[i] = nullptr;
        }
    }

    // 返回节点的子节点数量。
    size_t nr_children(tree_node* node) {
        return node->children.size();
    }

    // 深度优先遍历
    template <typename context, typename visitor_func>
    void dfs(const tree_node* node, context* ctxt, visitor_func visitor) const
    {
        size_t nr_children = node->children.size();
        for (size_t i = 0; i < nr_children; i++) {
            // depth-first
            dfs(node->children[i], ctxt, visitor);
        }

        // call the visitor for current node
        visitor(ctxt, node->payload);
    }

    // 广度优先遍历
    template <typename context, typename visitor_func>
    void bfs(const tree_node* node, context* ctxt, visitor_func visitor) const
    {
        size_t nr_children = node->children.size();

        // call the visitor for current node
        visitor(ctxt, node->payload);

        for (size_t i = 0; i < nr_children; i++) {
            // breadth-first
            bfs(node->children[i], ctxt, visitor);
        }

    }

    // 在给定节点的子节点头部压入新节点，返回新节点
    tree_node* push_front(const T& value)
    {
        // Create a new node with the given value
        tree_node* child = new tree_node(value);
        // Push the pointer to the front of children
        children.insert(children.begin(), child);
        return child;
    }

    // 弹出给定节点头部的子节点
    void pop_front()
    {
        if (children.size() > 0) {
            delete children.front();
            children.erase(children.begin());
        }
    }

    // 在给定节点的子节点尾部压入新节点，返回新节点
    tree_node* push_back(const T& value)
    {
        // Create a new node with the given value
        tree_node* child = new tree_node(value);
        // Push the pointer to the front of children
        children.push_back(child);
        return child;
    }

    // 弹出给定节点尾部的子节点
    void pop_back()
    {
        if (children.size() > 0) {
            delete children.back();
            children.pop_back();
        }
    }
};

#include <iostream>     // for cin and cout
#include <string>       // for stod()
#include <cassert>      // for assert()

using namespace std;

int main()
{
    using my_tree_node = tree_node<double>;
    my_tree_node* root = new my_tree_node(0);

    my_tree_node *node = root;

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
            node->push_front(d);
        }
        else if (d > 0) {
            node->push_back(d);
        }
        else {
            node = node->push_back(d);
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
    clog << "DFS Traversal\n";
    root->dfs(root, &ctxt, visitor_print{});

    clog << "BFS Traversal\n";
    root->bfs(root, &ctxt, visitor_print{});
    delete root;
}

