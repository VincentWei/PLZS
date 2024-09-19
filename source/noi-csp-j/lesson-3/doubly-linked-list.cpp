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
struct node {
    T payload;      // 节点负载
    node* next;     // 指向下一个节点的指针
    node* prev;     // 指向上一个节点的指针

    // 节点的构造函数。
    node(const T& value) {
        this->payload = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

// 测试是否为空链表。
template <typename node>
bool empty(node* head) {
    return (head == nullptr);
}

// 返回链表的节点数量。
template <typename node>
size_t size(node* head) {
    size_t sz = 0;

    while (head) {
        sz++;
        head = head->next;
    }

    return sz;
}

// 前向遍历节点
template <typename node, typename visit_func>
size_t traverse_forward(node* head, visit_func visitor)
{
    size_t nr_visited = 0;

    // Start from the head of the linked list
    node* current = head;

    // Traverse the linked list until reaching the end (nullptr)
    while (current != nullptr) {

        // call the visitor
        if (!visitor(current->payload))
            break;

        nr_visited++;

        // Move to the next node
        current = current->next;
    }

    return nr_visited;
}

// 定位尾部
template <typename node>
node* locate_tail(node* current) {
    node *tail = current;
    while (tail && tail->next) {
        tail = tail->next;
    }
    return tail;
}

// 后向遍历节点
template <typename node, typename visit_func>
size_t traverse_backward(node* head, visit_func visitor)
{
    size_t nr_visited = 0;

    // Start from the tail of the linked list
    node* current = locate_tail(head);

    // Traverse the linked list until reaching the head (nullptr)
    while (current != nullptr) {

        // call visitor
        if (!visitor(current->payload))
            break;

        nr_visited++;

        // Move to the previous node
        current = current->prev;
    }

    return nr_visited;
}

// 在给定节点之后插入新节点（不会修改头部）
template <typename node, typename T>
void insert_after(node* current, const T& value)
{
    // Create a new node with the given value
    node* newnode = new node(value);

    // Set the previous of new node to current
    newnode->prev = current;
    // Set the next of new node to next of current
    newnode->next = current->next;

    // Update the next of current node to new node
    current->next = newnode;

    // If the new node is not the tail, update previous of next node to new node
    if (newnode->next != nullptr)
        newnode->next->prev = newnode;
}

// 移除给定节点之后的节点（不会修改头部）
template <typename node>
void erase_after(node* current)
{
    if (current->next) {
        node* next_next = current->next->next;

        // Delete last node
        delete (current->next);

        // Change the next of current
        current->next = next_next;

        if (next_next) {
            // Update the previous of next of next to current
            next_next->prev = current;
        }
    }
}

// 定位头部
template <typename node>
node* locate_head(node* current) {
    node *head = current;
    while (head && head->prev) {
        head = head->prev;
    }
    return head;
}

// 在给定节点之前插入新节点；可能修改头部，返回新的头部
template <typename node, typename T>
node* insert_before(node* current, const T& value)
{
    // Create a new node with the given value
    node* newnode = new node(value);

    node* head = locate_head(current);
    if (head == nullptr) {
        // make newnode the head
        return newnode;
    }

    // Set previous of new node to previous of given node
    newnode->prev = current->prev;
    // Set next of new node to given node
    newnode->next = current;

    // Update next of given node's previous to new node
    if (current->prev != nullptr) {
        newnode->prev->next = newnode;
    }
    else {
        // If the current node is the head, update the head
        head = newnode;
    }

    // Update previous of given node to new node
    current->prev = newnode;

    // Return the head of the doubly linked list
    return head;
}

// 移除给定节点之前的节点；可能修改头部，返回新的头部
template <typename node>
node* erase_before(node* current)
{
    node* head = locate_head(current);
    if (head == nullptr) {
        // If it is an empty list
        return nullptr;
    }

    if (current->prev) {
        node* prev_prev = current->prev->prev;

        // If the deleted node is head, update head to the current
        if (current->prev == head)
            head = current;

        // Delete previous node
        delete (current->prev);

        // Change the next of current
        current->prev = prev_prev;

        if (prev_prev) {
            // Update next of previous of previous to current
            prev_prev->next = current;
        }

    }

    return head;
}

// 在头部压入新节点，返回新的头部节点
template <typename node, typename T>
node* push_front(node* head, const T& value)
{
    // Create a new node with the given value
    node* newnode = new node(value);

    // Set the next pointer of the new node to the current head
    newnode->next = head;

    // Return the new head of the linked list
    return newnode;
}

// 弹出头部节点，返回新的头部节点
template <typename node>
node* pop_front(node* head)
{
    if (head == nullptr)
        return nullptr;

    // Move the head pointer to the next node
    node* temp = head;
    head = head->next;

    delete temp;

    return head;
}

// 在尾部压入新节点，返回新的头部节点
template <typename node, typename T>
node* push_back(node* head, const T& value)
{
    // Create a new node with the given value
    node* newnode = new node(value);

    // Locate the tail
    node* tail = locate_tail(head);
    if (tail == nullptr) {
        // If the list is empty, make the new node the head
        head = newnode;
        goto done;
    }

    // Link the new node to the current last node
    tail->next = newnode;
    newnode->prev = tail;

done:
    return head;
}

// 弹出尾部节点，返回新的头部节点
template <typename node>
node* pop_back(node* head)
{
    if (head == nullptr)
        return nullptr;

    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    node* tail = locate_tail(head);

    // Change next of second last
    if (tail->prev)
        tail->prev->next = nullptr;

    // Delete last node
    delete (tail);

    // If tail is head, the list is empty
    if (head == tail)
        return nullptr;

    return head;
}

// 清空链表，返回新的头部节点（始终为 nullptr）
template <typename node>
node* clear(node* head)
{
    while (head) {
        node* next = head->next;
        delete head;
        head = next;
    };

    return nullptr;
}

using namespace std;

// 使用函数对象，重载 () 运算符，从而使用对象完成函数调用功能。
struct print_positive_value
{
    bool operator() (double value) {
        if (value > 0) {
            cout << value << endl;
        }
        else if (value < 0) {
            return false;
        }

        return true;
    }
};

int main()
{
    node<double>* head = nullptr;

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

        head = push_back(head, d);
    } while (true);

    traverse_backward(head, print_positive_value{});
    clear(head);
}

