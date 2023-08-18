#include "queue.hpp"

/*
    Focus is on memory safety using Smart Pointers
*/

class Node {
public:
    std::string value;
    std::shared_ptr<Node> next = nullptr;

    Node(std::string value)
    {
        this->value = value;
    }
};

class Queue {
public:
    std::shared_ptr<Node> head;
    std::shared_ptr<Node> tail;
    int size = 0;
    
    void push(std::string value)
    {
        auto node = std::make_shared<Node>(value);
        if (!this->size) {
            this->head = node;
            this->tail = node;
        } else {
            auto old_tail = this->tail;
            old_tail->next = node;
            this->tail = node;
        }
        this->size++;
    }

    void pop()
    {
        switch(this->size) {
            case 0:
                return;
            case 1:
                this->head = this->head->next;
                this->tail = this->head->next;
                break;
            default:
                this->head = this->head->next;
        }
        this->size--;
    }

    void print_all()
    {
        auto node = this->head;
        while (node != nullptr) {
            std::cout << "-> " << node->value << std::endl;
            node = node->next;
        }
    }
};

void hash_table_test()
{
    auto queue = std::make_shared<Queue>();
    queue->push("Jaguar");
    queue->push("Envision");
    queue->push("Avalanche");
    queue->push("McLaren");
    std::cout << "1. initial values:" << std::endl;
    queue->print_all();
    std::cout << std::endl;
    queue->pop();
    std::cout << "2. new values:" << std::endl;
    queue->print_all();
}