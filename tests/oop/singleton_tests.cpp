#include "lib/oop/design_patterns/singletons.hpp"

// Declare static object
Singleton Singleton::s_Instance;

void singleton_basic_test()
{
    Singleton& instance = Singleton::GetInstance();
    instance.SomeFunction();
}

float singleton_random_generator_test()
{
    return Random::Float();
}

int main()
{
    singleton_basic_test();
    float num = singleton_random_generator_test();

    return 0;
}
