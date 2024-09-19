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

template <typename T>
struct node {

    T payload;      // 节点负载
    node* next;     // 指向下一个节点的指针

    // 节点的构造函数。
    node(const T& value) {
        this->payload = value;
        this->next = nullptr;
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

// 遍历节点
template <typename node, typename visit_func>
void traverse(node* head, visit_func visitor)
{
    // Start from the head of the linked list
    node* current = head;

    // Traverse the linked list until reaching the end (nullptr)
    while (current != nullptr) {

        // call the call back function
        if (!visitor(current->payload))
            break;

        // Move to the next node
        current = current->next;
    }
}

// 在给定节点之后插入新节点（不会修改头部）
template <typename node, typename T>
void insert_after(node* current, const T& value)
{
    // Create a new node with the given value
    node* newnode = new node(value);

    // Link the original next node to the new node.
    newnode->next = current->next;

    // Link the new node to the current last node
    current->next = newnode;
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
    }
}

// 在头部压入新节点，返回新的头部节点
template <typename node, typename T>
node* push_front(node* head, const T& value)
{
    // Create a new node with the given value
    node* newnode = new node(value);

    // Set the next pointer of the new node to the current head
    newnode->next = head;

    // Move the head to point to the new node
    head = newnode;

    // Return the new head of the linked list
    return head;
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

    // If the list is empty, make the new node the head
    if (head == nullptr)
        return newnode;

    // Traverse the list until the last node is reached
    node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    // Link the new node to the current last node
    current->next = newnode;
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

    // Find the second last node
    node* second_last = head;
    while (second_last->next->next != nullptr)
        second_last = second_last->next;

    // Delete last node
    delete (second_last->next);

    // Change next of second last
    second_last->next = nullptr;

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

bool print_positive_value(double payload)
{
    if (payload > 0)
        cout << payload << endl;

    return true;
}

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

    traverse(head, print_positive_value);
    clear(head);
}

