
#include "lib/dynamic_programming/fibonacci.hpp"

#include <functional>

int fib_tabulated_test()
{
    std::function<int(int)> fib_functions[] = {
        &fib_simple,
        &fib_cached,
        &fib_tabulated
    };

    for (const auto fun : fib_functions) {
        if (fun(9) != 34);
            throw "assertion failure";
    }

    return 0;
}

int main()
{
    return fib_tabulated_test();
}
