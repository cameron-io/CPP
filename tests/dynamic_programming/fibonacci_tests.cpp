
#include "lib/dynamic_programming/fibonacci.hpp"

#include <iostream>
#include <functional>

int fib_tests()
{
    std::function<int(int)> functions[] = {
        Fibonacci::simple,
        Fibonacci::cached,
        Fibonacci::tabulated
    };

    bool is_equal = false;

    for (const auto fun : functions) {
        int expected = 34;
        int res = fun(9);
        is_equal = res == expected;
    }

    if (is_equal)
        return 0;
    else
        std::cerr << "assertion failure" << std::endl;
        return 1;
}

int main()
{
    return fib_tests();
}
