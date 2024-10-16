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
#include <queue>        // for queue

template <typename T>
class tree_node {
  public:
    T payload;                          // 节点负载
    std::vector<tree_node*> children;   // 子节点矢量

    // 节点的构造函数
    tree_node(const T& value) {
        payload = value;
    }

    // 节点的析构函数
    ~tree_node() {
        for (size_t i = 0; i < this->children.size(); i++) {
            delete children[i];
            children[i] = nullptr;
        }
    }

    // 返回节点的子节点数量。
    size_t nr_children(const tree_node* node) const {
        return node->children.size();
    }

    // 深度优先（depth-first）遍历
    template <typename context, typename visitor_func>
    void dfs(context* ctxt, visitor_func visitor) const
    {
        // call the visitor for the current node
        visitor(ctxt, payload);

        size_t nr_children = children.size();
        for (size_t i = 0; i < nr_children; i++) {
            children[i]->dfs(ctxt, visitor);
        }
    }

    // 广度优先（breadth-first）遍历
    template <typename context, typename visitor_func>
    void bfs(context* ctxt, visitor_func visitor) const
    {
        std::queue<const tree_node*> queue;
        queue.push(this);

        while (!queue.empty()) {
            const tree_node* node = queue.front();
            queue.pop();

            // call the visitor for current node
            visitor(ctxt, node->payload);

            size_t nr_children = node->children.size();
            for (size_t i = 0; i < nr_children; i++) {
                queue.push(node->children[i]);
            }
        }
    }

    // 在当前节点的子节点头部压入新节点，返回新节点
    tree_node* push_front(const T& value)
    {
        // Create a new node with the given value
        tree_node* child = new tree_node(value);
        // Push the pointer to the front of children
        children.insert(children.begin(), child);
        return child;
    }

    // 弹出当前节点头部的子节点
    void pop_front()
    {
        if (children.size() > 0) {
            delete children.front();
            children.erase(children.begin());
        }
    }

    // 在当前节点的子节点尾部压入新节点，返回新节点
    tree_node* push_back(const T& value)
    {
        // Create a new node with the given value
        tree_node* child = new tree_node(value);
        // Push the pointer to the front of children
        children.push_back(child);
        return child;
    }

    // 弹出当前节点尾部的子节点
    void pop_back()
    {
        if (children.size() > 0) {
            delete children.back();
            children.pop_back();
        }
    }
};

#include <iostream>     // for cin and cout
#include <sstream>      // for ostringstream
#include <string>       // for stod()
#include <cassert>      // for assert()

using namespace std;

void test_tree_node()
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
    using my_tree_node = tree_node<int>;
    my_tree_node *level_0, *level_1, *level_2;

    level_0 = new my_tree_node(0);

    oss.str("");
    level_0->dfs(&ctxt, visitor_print{});
    assert(oss.str() == "0 ");

    oss.str("");
    level_0->bfs(&ctxt, visitor_print{});
    assert(oss.str() == "0 ");

    level_0->push_front(-1);
    level_0->push_front(-2);
    level_1 = level_0->push_back(0);
    level_0->push_back(1);
    level_0->push_back(2);

    oss.str("");
    level_0->dfs(&ctxt, visitor_print{});
    clog << oss.str() << endl;
    assert(oss.str() == "0 -2 -1 0 1 2 ");

    oss.str("");
    level_0->bfs(&ctxt, visitor_print{});
    clog << oss.str() << endl;
    assert(oss.str() == "0 -2 -1 0 1 2 ");

    level_1->push_front(-10);
    level_1->push_front(-20);
    level_2 = level_1->push_back(0);
    level_1->push_back(10);
    level_1->push_back(20);

    oss.str("");
    level_0->dfs(&ctxt, visitor_print{});
    clog << oss.str() << endl;
    assert(oss.str() == "0 -2 -1 0 -20 -10 0 10 20 1 2 ");

    oss.str("");
    level_0->bfs(&ctxt, visitor_print{});
    clog << oss.str() << endl;
    assert(oss.str() == "0 -2 -1 0 1 2 -20 -10 0 10 20 ");

    level_2->push_front(-100);
    level_2->push_front(-200);
    level_2->push_front(-300);
    level_2->push_back(0);
    level_2->push_back(100);
    level_2->push_back(200);
    level_2->push_back(300);

    oss.str("");
    level_0->dfs(&ctxt, visitor_print{});
    clog << oss.str() << endl;
    assert(oss.str() == "0 -2 -1 0 -20 -10 0 -300 -200 -100 0 100 200 300 10 20 1 2 ");

    oss.str("");
    level_0->bfs(&ctxt, visitor_print{});
    clog << oss.str() << endl;
    assert(oss.str() == "0 -2 -1 0 1 2 -20 -10 0 10 20 -300 -200 -100 0 100 200 300 ");

    delete level_0;
}

int main()
{
    test_tree_node();

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
    root->dfs(&ctxt, visitor_print{});

    clog << "BFS Traversal\n";
    root->bfs(&ctxt, visitor_print{});
    delete root;
}

