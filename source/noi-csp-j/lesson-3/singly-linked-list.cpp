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

    // 节点的构造函数。
    node(const T& value) {
        this->payload = value;
        this->next = nullptr;
    }

    // Traverse and print the elements of the linked list
    void travese(node* head)
    {
        // Start from the head of the linked list
        node* current = head;

        // Traverse the linked list until reaching the end (nullptr)
        while (current != nullptr) {

            // Print the data of the current node
            std::cout << current->payload << " ";

            // Move to the next node
            current = current->next;
        }

        std::cout << std::endl;
    }

    // Insert a new node at the beginning of the linked list
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

    // Remove the first node of the linked list
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

    // Insert a node at the end of the linked list
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

    // Remove the last node of the linked list
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

    // Clear the linked list
    node* clear(node* head)
    {
        while (head) {
            node* next = head->next;
            delete head;
            head = next;
        };

        return nullptr;
    }

};

using namespace std;

int main()
{
}

