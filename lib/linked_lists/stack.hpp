#ifndef STACK_H
#define STACK_H

#include <iostream>

class Node {
public:
    char* value;
    Node* next = nullptr;

    Node(char* value)
    {
        this->value = value;
    }
};

class Stack {
    Node* head = nullptr;
    Node* tail = nullptr;
    int size;
public:
    Stack()
    {
    }

    int push(char* value)
    {
        Node* node = new Node(value);

        if (!this->head) {
            this->head = node;   
            this->tail = node;   
        } else {
            Node* prev_head = this->head;
            node->next = prev_head;
            this->head = node;
        }

        this->size++;

        return 0;
    }

    int pop()
    {
        if (!this->head) return 1;

        Node* prev_head = this->head;
        this->head = prev_head->next;

        if (!this->head)
            this->tail = nullptr;

        this->size--;

        delete prev_head;

        return 0;
    }

    void print()
    {
        if (!this->head) return;

        Node* node = this->head;

        while (node) {
            std::cout << "-> " << node->value << std::endl;
            node = node->next;
        }
    }
};

#endif