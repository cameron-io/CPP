#ifndef QUEUE_H
#define QUEUE_H

#include <string>
#include <iostream>
#include <memory>

class Queue {
public:
    void push(std::string value);
    void pop();
    void print_all();
};

#endif