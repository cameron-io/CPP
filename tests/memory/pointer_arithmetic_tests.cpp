
#include "lib/memory/pointer_arithmetic.hpp"

int main ()
{
    Array* arr = new Array(8);

    arr->CountTo(5);

    delete arr;

    return 0;
}