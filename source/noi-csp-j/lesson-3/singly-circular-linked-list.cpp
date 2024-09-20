/*
 * One example for NOI CSP-J Lesson 3:
 * <https://courses.fmsoft.cn/plzs/noijunior-linear-data-structures.html>
 *
 * Author: Vincent Wei
 *  - <https://github.com/VincentWei>
 *  - <https://gitee.com/vincentwei7>
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * License: GPLv3
 */
#include <iostream>     // for cin and cout
#include <string>       // for stod()
#include <stdexcept>    // for std::out_of_range
#include <cassert>      // for assert()

template <class T>
class forward_loop_list {
private:
    struct context_sizing {
        size_t nr;
    };

    struct visitor_sizing {
        bool operator() (context_sizing* ctxt, const T& /* value */) {
            ctxt->nr++;
            return true;
        }

        size_t nr;
    };

    struct node {
        T payload;      // 节点负载
        node* next;     // 指向下一个节点的指针

        // 节点的构造函数。
        node(const T& value) {
            this->payload = value;
            this->next = nullptr;
        }
    };

    node* _head;

public:
    // 构造函数
    forward_loop_list() {
        _head = nullptr;
    }

    // 析构函数
    ~forward_loop_list() {
        clear();
    }

    // 测试是否为空链表
    bool empty() {
        return (_head == nullptr);
    }

    // 获取大小（节点数量）
    size_t size() {
        context_sizing ctxt = { 0 };
        traverse(&ctxt, visitor_sizing{});
        return ctxt.nr;
    }

    // （只读）遍历链表节点
    template <typename context, typename visitor_func>
    const node* traverse(context* ctxt, visitor_func visitor) const
    {
        // Start from the tail of the linked list
        node* current = _head;

        // Traverse the linked list until reaching the tail
        while (current) {
            // call the visitor
            if (!visitor(ctxt, current->payload))
                break;

            // Move to next node
            current = current->next;

            // Test if reached the tail
            if (current == _head)
                break;
        }

        return current;
    }

    // 访问头部负载
    T& front() {
        if (empty())
            throw std::out_of_range(__func__);
        return _head->payload;
    }

    const T& front() const {
        if (empty())
            throw std::out_of_range(__func__);
        return _head->payload;
    }

    // 访问尾部负载
    T& back() {
        if (empty())
            throw std::out_of_range(__func__);

        // Find the tail
        node* tail = _head;
        while (tail->next != _head)
            tail = tail->next;
        return tail->payload;
    }

    const T& back() const {
        if (empty())
            throw std::out_of_range(__func__);

        // Find the tail
        node* tail = _head;
        while (tail->next != _head)
            tail = tail->next;
        return tail->payload;
    }

    // 压入头部
    void push_front(const T& value)
    {
        // Create a new node with the given value
        node* newnode = new node(value);

        // Check if the list is empty before pushing
        if (_head == nullptr) {
            _head = newnode;
            _head->next = _head;
            return;
        }

        // Find the tail
        node* tail = _head;
        while (tail->next != _head)
            tail = tail->next;

        // Set the next of the tail new node
        tail->next = newnode;
        // Set the next of the new node to the current head
        newnode->next = _head;
        // Reset head
        _head = newnode;
    }

    // 弹出头部
    void pop_front()
    {
        if (empty())
            return;             // Return silently

        // Save original head temporarily
        node *org_head = _head;

        // Find the tail
        node* tail = _head;
        while (tail->next != _head)
            tail = tail->next;

        // Set the next of the tail new head
        tail->next = _head->next;

        // Move the head pointer to the next node
        _head = _head->next;

        // Delete the original head
        delete org_head;

        // Check if there was only one node before popping
        if (_head == org_head) {
            _head = nullptr;
        }
    }

    // 压入尾部
    void push_back(const T& value)
    {
        // Create a new node with the given value
        node* newnode = new node(value);

        // If the list is empty, make the new node the head/tail
        if (_head == nullptr) {
            _head = newnode;
            newnode->next = newnode;
            return;
        }

        // Find the tail
        node* tail = _head;
        while (tail->next != _head)
            tail = tail->next;

        // Link the new node to the current tail
        newnode->next = tail->next;
        tail->next = newnode;
    }

    // 弹出尾部
    void pop_back()
    {
        if (empty())
            return;

        // If there is only one node in the list
        if (_head->next == _head) {
            delete _head;
            _head = nullptr;
            return;
        }

        // Find the second last
        node* second_last = _head;
        while (second_last->next->next != _head)
            second_last = second_last->next;

        // Remove tail from list
        node *tail = second_last->next;
        second_last->next = _head;

        // Delete tail
        delete tail;
    }

    // 清空链表
    void clear()
    {
        // Start from the head of the linked list
        node* current = _head;

        // Traverse the linked list until reaching the tail
        while (current) {
            // Save next node temporarily.
            node* next = current->next;

            // Delete current node
            delete current;

            // Check if reached the tail
            if (next == _head)
                break;

            // Move to next
            current = next;
        }

        _head = nullptr;
    }
};

using namespace std;

void test_forward_loop_list()
{
    struct context_print {
        ostream& os;
    };

    struct visitor_print {
        bool operator() (context_print* ctxt, const double& value) {
            ctxt->os << value << endl;
            return true;
        }

        size_t nr;
    };

    forward_loop_list<double> list;

    assert(list.empty() == true);

    list.push_front(0);

    context_print ctxt = { cout };
    list.traverse(&ctxt, visitor_print{});

    assert(list.empty() == false);
    assert(list.size() == 1);
    assert(list.front() == 0);
    assert(list.back() == 0);

    list.push_back(1);
    list.traverse(&ctxt, visitor_print{});

    assert(list.size() == 2);
    assert(list.front() == 0);
    assert(list.back() == 1);

    list.clear();
    assert(list.empty());
    cout << "clear() passed\n";

    list.push_front(0);
    list.traverse(&ctxt, visitor_print{});
    assert(list.size() == 1);
    cout << "#1 push_front() passed\n";

    list.push_front(1);
    list.traverse(&ctxt, visitor_print{});
    assert(list.size() == 2);
    cout << "#2 push_front() passed\n";

    list.push_front(2);
    list.traverse(&ctxt, visitor_print{});
    assert(list.size() == 3);
    cout << "#3 push_front() passed\n";

    list.push_front(3);
    assert(list.size() == 4);
    cout << "#4 push_front() passed\n";

    list.push_back(-1);
    list.traverse(&ctxt, visitor_print{});
    assert(list.size() == 5);
    cout << "#1 push_back() passed\n";

    list.push_back(-2);
    list.traverse(&ctxt, visitor_print{});
    assert(list.size() == 6);
    cout << "#2 push_back() passed\n";

    list.push_back(-3);
    list.traverse(&ctxt, visitor_print{});
    assert(list.size() == 7);
    cout << "#3 push_back() passed\n";

    assert(list.front() == 3);
    assert(list.back() == -3);
    cout << "push_front() and push_back() passed\n";

    list.pop_front();
    list.traverse(&ctxt, visitor_print{});
    assert(list.size() == 6);
    assert(list.front() == 2);
    assert(list.back() == -3);
    cout << "#1 pop_front() passed\n";

    list.pop_front();
    list.traverse(&ctxt, visitor_print{});
    assert(list.size() == 5);
    assert(list.front() == 1);
    assert(list.back() == -3);
    cout << "#2 pop_front() passed\n";

    list.pop_front();
    list.traverse(&ctxt, visitor_print{});
    assert(list.size() == 4);
    assert(list.front() == 0);
    assert(list.back() == -3);
    cout << "#3 pop_front() passed\n";

    list.pop_back();
    list.traverse(&ctxt, visitor_print{});
    assert(list.size() == 3);
    assert(list.front() == 0);
    assert(list.back() == -2);
    cout << "#1 pop_back() passed\n";

    list.pop_back();
    list.traverse(&ctxt, visitor_print{});
    assert(list.size() == 2);
    assert(list.front() == 0);
    assert(list.back() == -1);
    cout << "#2 pop_back() passed\n";

    list.pop_back();
    list.traverse(&ctxt, visitor_print{});
    assert(list.size() == 1);
    assert(list.front() == 0);
    assert(list.back() == 0);
    cout << "#3 pop_back() passed\n";

    list.clear();
    assert(list.empty());
}

int main()
{
    test_forward_loop_list();
}

