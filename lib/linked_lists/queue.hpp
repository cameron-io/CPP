#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

class Node {
public:
    int value;
    Node* prev = nullptr;
    Node* next = nullptr;

    Node(int value)
    {
        this->value = value;
    }
};

class Queue {
    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;

public:
    int enqueue(int value)
    {
        Node* node = new Node(value);

        if (!this->head) {
            this->head = node;
            this->tail = node;
        } else {
            Node* old_tail = this->tail;
            old_tail->next = node;
            node->prev = old_tail;
            this->tail = node;
        }
        this->size++;

        return 0;
    }

    int dequeue()
    {
        if (!this->head) return 1;

        Node* prev_head = this->head;

        if (!prev_head->next)
        {
            this->head = nullptr;
            this->tail = nullptr;
        } else {
            this->head = prev_head->next;
            this->head->prev = nullptr;
        }

        delete prev_head;

        this->size--;

        return 0;
    }

    void print()
    {
        Node* node = this->head;
        while (node) {
            std::cout << "-> " << node->value << "\n";
            node = node->next;
        }
        std::cout << std::endl;
    }
};

#endif