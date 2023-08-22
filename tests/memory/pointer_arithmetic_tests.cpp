#include <memory>
#include <iostream>

int CountMemory(int* arr, int size)
{
    return size * sizeof(int);
}

int* PrintArray(int* arr, int byte_count)
{
    /*
        store array address in pointer using type punning
        this allows the specification of the pointer to locate
        the single byte denoting the start of the array.

        the offset will be based on this value
    */
    char* ptr = (char*) arr;

    int offset = 0;

    while (offset < byte_count) {
        /*
            cast to integer to correctly interpret memory allocation 
        */
        int* address = (int *)(ptr + offset);

        std::cout << "Offset (bytes): " << offset << "\n";
        std::cout << "-> value: " << *address << "\n";
        std::cout << "-> address: " << address << std::endl;

        offset += sizeof(int);
    }

    return arr;
}

int main ()
{
    int size = 10;
    int* arr = (int*) malloc(size * sizeof(int));;

    for (int i = 0; i < size; i++)
    {
        arr[i] = (i+1) * 5;
    }

    int byte_count = CountMemory(arr, size);

    PrintArray(arr, byte_count);

    free(arr);

    return 0;
}