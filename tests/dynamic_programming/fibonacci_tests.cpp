
#include "lib/dynamic_programming/fibonacci.hpp"

#include <iostream>
#include <functional>
#include <boost/assert.hpp>

void fib_tests()
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

    assert(is_equal);
}

int main()
{
    fib_tests();

    return 0;
}
