#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <string>
#include <vector>
#include <memory>
#include <iostream>

#include "../linked_lists/queue.hpp"

class BinarySearchTree {
public:
    Node* root = nullptr;

    void Insert(int value)
    {
        auto node = new Node(value);
        if (this->root == nullptr) {
            this->root = node;
            return;
        } else {
            auto current = this->root;
            while(true) {
                if (value == current->value) 
                    return;
                
                if (value < current->value) {
                    if (current->prev == nullptr) {
                        current->prev = node;
                        return;
                    }
                    current = current->prev;
                } else {
                    if (current->next == nullptr) {
                        current->next = node;
                        return;
                    }
                    current = current->next;
                }
            }
        }
    }

    bool Contains(int value)
    {
        if (this->root == nullptr)
            return false;
        
        auto current = this->root;
        bool found = false;
        while(current && !found) {
            if(value < current->value) {
                current = current->prev;
            } else if(value > current->value) {
                current = current->next;
            } else {
                return true;
            }
        }
        return false;
    }

    std::vector<int> DFSPreOrder(Node* node)
    {
        std::vector<int> data = {};
        return traverse(data, this->root);
    }

private:
    std::vector<int> traverse(std::vector<int> data, Node* node)
    {
        data.push_back(node->value);
        if(node->prev) traverse(data, node->prev);
        if(node->next) traverse(data, node->next);
        return data;
    }
};


#endif