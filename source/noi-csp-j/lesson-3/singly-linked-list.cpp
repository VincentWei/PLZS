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

// 遍历节点时的回调函数类型；返回 false 将停止遍历。
template <class T>
using cb_on_node = bool (*)(T& value);

template <class T>
class node {

    T payload;      // 节点负载
    node* next;     // 指向下一个节点的指针

    // 节点的构造函数。
    node(const T& value) {
        this->payload = value;
        this->next = nullptr;
    }
};

// 测试是否为空链表。
template <class node>
bool empty(node* head) {
    return (head == nullptr);
}

// 返回链表的节点数量。
template <class node>
size_t size(node* head) {
    size_t sz = 0;

    while (head) {
        sz++;
        head = head->next;
    }

    return sz;
}

// 遍历节点
template <class node, class T, typename cb_on_node>
void traverse(node* head, cb_on_node cb)
{
    // Start from the head of the linked list
    node* current = head;

    // Traverse the linked list until reaching the end (nullptr)
    while (current != nullptr) {

        // call the call back function
        if (!cb(current->payload))
            break;

        // Move to the next node
        current = current->next;
    }
}

// 在给定节点之后插入新节点（不会修改头部）
template <class node, class T>
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
template <class node>
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

// 在头部插入节点，返回新的头部节点
template <class node, class T>
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

// 移除头部节点，返回新的头部节点
template <class node>
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

// 在尾部插入节点，返回新的头部节点
template <class node, class T>
node* push_back(node* head, const T& value)
{
    // Create a new node with the given value
    node* newnode = new node(value);

    // If the list is empty, make the new node the head
    if (head == nullptr)
        return newnode;

    // Traverse the list until the last node is reached
    node* current = *head;
    while (current->next != nullptr) {
        current = current->next;
    }

    // Link the new node to the current last node
    current->next = newnode;
    return head;
}

// 移除尾部节点，返回新的头部节点
template <class node>
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
template <class node>
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

int main()
{
}

