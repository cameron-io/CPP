#include "singletons.hpp"

// Declare static object
Singleton Singleton::s_Instance;

void use_singleton()
{
    Singleton& instance = Singleton::GetInstance();
    instance.SomeFunction();
}

float use_random()
{
    return Random::Float();
}
