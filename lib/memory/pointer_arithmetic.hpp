#ifndef POINTER_ARITHMETIC_H
#define POINTER_ARITHMETIC_H

#include <iostream>
#include <memory>

class Array {
public:
    int size;
    int* arr;

    Array(int size)
    {
        this->size = size;
        this->arr = (int*) malloc(size * sizeof(int));

        // Replace initial zero-out values with memory counter
        for (unsigned int i = 0; i < size; i++)
        {
            this->arr[i] = i * sizeof(int);
        }
    }

    ~Array()
    {
        free(this->arr);
    }

    void CountTo(int number)
    {
        // store array address in pointer
        int* ptr = arr;
        for (int i = 0; i < this->size; i++) {
            std::cout << "Index: " << i << "\n";
            std::cout << "-> *ptr: " << *ptr << "\n";
            std::cout << "-> ptr: " << ptr << "\n";
            std::cout << std::endl;

            // point to the next location
            ptr++;
        }
    }
};

#endif