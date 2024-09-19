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

    node* _tail;

public:
    // 构造函数
    forward_loop_list() {
        _tail = nullptr;
    }

    // 测试是否为空链表
    bool empty() {
        return (_tail == nullptr);
    }

    // 获取大小（节点数量）
    size_t size() {
        context_sizing ctxt = { 0 };
        traverse(&ctxt, visitor_sizing{});
        return ctxt.nr;
    }

    // 遍历链表节点
    template <typename context, typename visitor_func>
    node* traverse(context* ctxt, visitor_func visitor)
    {
        if (_tail == nullptr)
            return nullptr;

        // Start from the tail of the linked list
        node* current = _tail;

        // Traverse the linked list until reaching the tail
        do {
            // Move to the next node
            current = current->next;

            // call the visitor
            if (!visitor(ctxt, current->payload))
                break;

        } while (current != _tail);

        return current;
    }

    // 访问头部负载
    T& front() {
        if (_tail == nullptr)
            throw std::out_of_range(__func__);
        return _tail->next->payload;
    }

    const T& front() const {
        if (_tail == nullptr)
            throw std::out_of_range(__func__);
        return _tail->next->payload;
    }

    // 访问尾部负载
    T& back() {
        if (_tail == nullptr)
            throw std::out_of_range(__func__);
        return _tail->payload;
    }

    const T& back() const {
        if (_tail == nullptr)
            throw std::out_of_range(__func__);
        return _tail->payload;
    }

    // 压入头部
    void push_front(const T& value)
    {
        // Create a new node with the given value
        node* newnode = new node(value);

        if (_tail == nullptr) {
            _tail = newnode;
            newnode->next = _tail;
            return;
        }

        // Set the next pointer of the new node to the current head
        node* head = _tail->next;
        newnode->next = head;
    }

    // 弹出头部
    void pop_front()
    {
        if (_tail == nullptr)
            return;

        // Move the head pointer to the next node
        node* head = _tail->next;
        node* head_next = head->next;

        delete head;

        if (head == _tail)
            _tail = nullptr;
        else
            _tail->next = head_next;
    }

    // 压入尾部
    void push_back(const T& value)
    {
        // Create a new node with the given value
        node* newnode = new node(value);

        // If the list is empty, make the new node the head/tail
        if (_tail == nullptr) {
            _tail = newnode;
            newnode->next = newnode;
            return;
        }

        // Link the new node to the current tail
        newnode->next = _tail->next->next;
        _tail->next = newnode;
    }

    // Remove the last node of the linked list
    void pop_back()
    {
        if (_tail == nullptr)
            return;

        node* head = _tail->next;
        // If there is only one node in the list
        if (_tail == head) {
            delete _tail;
            _tail = nullptr;
            return;
        }

        // Find the second last node
        node* second_last = _tail->next;
        while (second_last->next->next != _tail)
            second_last = second_last->next;

        // Delete tail
        delete _tail;

        // Reset pointer to tail and change next of tail to head
        _tail = second_last;
        _tail->next = head;
    }

    void clear()
    {
        if (_tail == nullptr)
            return;

        node* current = _tail->next;
        while (current != _tail) {
            // Move to the next node
            node* next = current->next;
            delete current;
            current = next;
        }

        delete _tail;
        _tail = nullptr;
    }
};

using namespace std;

void test()
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
    assert(list.empty() == true);
}

int main()
{
    test();
}

