#include "lib/oop/object_copy.hpp"
#include <iostream>

/*
    In most cases, an object must be passed in by
    (const) reference, to prevent unnecessary copies
    unless explicitly required
*/
void someFunction(const String& string)
{
    std::cout << string << std::endl;
}

void objectCopyTest()
{
    String first = "test";
    String second = first;

    // Must not update first variable
    second[2] = 'n';

    someFunction(first);
    someFunction(second);

    std::cout << first << std::endl;
    std::cout << second << std::endl;
}

int main()
{
    objectCopyTest();
    return 0;
}
