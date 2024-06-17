#include "lib/oop/design_patterns/singletons.hpp"
#include <stdexcept>

// Declare static object
Singleton Singleton::s_Instance;

void singleton_basic_test()
{
    Singleton& instance = Singleton::GetInstance();
    instance.IncrementCounter();
    instance.IncrementCounter();

    if (instance.GetCounterValue() != 2)
        throw new std::logic_error(
            "assertion failure");

    Singleton& instance2 = Singleton::GetInstance();
    
    if (instance.GetCounterValue() != instance2.GetCounterValue())
        throw new std::logic_error(
            "assertion failure");
}

int main()
{
    singleton_basic_test();
    
    return 0;
}
