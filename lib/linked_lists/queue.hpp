#ifndef QUEUE_H
#define QUEUE_H

#include <string>
#include <iostream>

class Node {
public:
    std::string value;
    Node* next = nullptr;

    Node(std::string value)
    {
        this->value = value;
    }
};

class Queue {
    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;

public:
    int enqueue(std::string value)
    {
        Node* node = new Node(value);

        if (!this->head) {
            this->head = node;
            this->tail = node;
        } else {
            Node* old_tail = this->tail;
            old_tail->next = node;
            this->tail = node;
        }
        this->size++;

        return 0;
    }

    int dequeue()
    {
        if (!this->head) return 1;

        Node* prev_head = this->head;
        Node* new_head = prev_head->next;

        if (!new_head->next)
        {
            this->head = new_head;
            this->tail = new_head;
        } else {
            this->head = new_head;
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