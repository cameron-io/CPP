
#include "lib/dynamic_programming/fibonacci.hpp"

#include <iostream>
#include <functional>

int fib_tests()
{
    std::function<int(int)> fib_functions[] = {
        Fibonacci::simple,
        Fibonacci::cached,
        Fibonacci::tabulated
    };

    for (const auto fun : fib_functions) {
        int expected = 34;
        int res = fun(9);
        if (res != expected);
            return 1;
    }

    return 0;
}

int main()
{
    return fib_tests();
}
