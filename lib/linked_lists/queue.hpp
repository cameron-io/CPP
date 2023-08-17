#ifndef QUEUE_H
#define QUEUE_H

#include <string>

class Queue {
public:
    void push(std::string value);
    void pop();
    void print_all();
};

#endif