#include <boost/assert.hpp>
#include "lib/oop/design_patterns/singleton.hpp"
#include <stdexcept>
#include <chrono>
#include <future>
#include <iostream>

// Declare static object
Singleton Singleton::s_Instance;

void singleton_basic_test()
{
    Singleton& instance = Singleton::GetInstance();
    instance.IncrementCounter();
    instance.IncrementCounter();

    assert(instance.GetCounterValue() == 2);

    Singleton& instance2 = Singleton::GetInstance();
    
    assert(instance.GetCounterValue() == instance2.GetCounterValue());
}

constexpr auto tenMill = 10000000;

std::chrono::duration<double> getTime()
{
    auto begin= std::chrono::system_clock::now();
    for (size_t i = 0; i < tenMill; i++) {
        Singleton::GetInstance();
    }
    return std::chrono::system_clock::now() - begin;
};

void singleton_multithreaded_test()
{
    auto fut1 = std::async(std::launch::async, getTime);
    auto fut2 = std::async(std::launch::async, getTime);
    auto fut3 = std::async(std::launch::async, getTime);
    auto fut4 = std::async(std::launch::async, getTime);
    
    auto total = fut1.get() + fut2.get() + fut3.get() + fut4.get();
    std::cerr << "Total count: " << total.count() << std::endl;
}

int main()
{
    singleton_basic_test();

    singleton_multithreaded_test();
    
    return 0;
}
