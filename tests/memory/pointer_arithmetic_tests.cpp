#include <memory>
#include <iostream>

void CountMemory(int* arr, int size)
{
    // Replace initial zero-out values with memory counter
    for (unsigned int i = 0; i < size; i++)
    {
        arr[i] = i * sizeof(int);
    }
}

void PrintArray(int* arr, int size)
{
    // store array address in pointer
    int* ptr = arr;
    for (int i = 0; i < size; i++) {
        std::cout << "Index: " << i << "\n";
        std::cout << "-> *ptr: " << *ptr << "\n";
        std::cout << "-> ptr: " << ptr << "\n";
        std::cout << std::endl;

        // point to the next location
        ptr++;
    }
}

int main ()
{
    int size = 10;
    int* arr = (int*) malloc(size * sizeof(int));

    CountMemory(arr, size);

    PrintArray(arr, size);

    delete arr;

    return 0;
}