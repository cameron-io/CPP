#include "fibonacci.hpp"

#include <vector>

// Using Recursion, a Top-Down approach

// Simple, but very slow O(2^n)

int fib_simple(int n)
{
    if (n <= 2) return 1;
    return fib_simple(n-1) + fib_simple(n-2);
}

// Memoized

// this is getting better & is a lot faster: O(n)
// - However, this will not scale as recursion will exceed 
//   the limit of stack memory allocation at a certain point, 
//   eg. n=1000

int fib_cached(int n, std::map<int, int> cache)
{
    if(auto s = cache.find(n); s != cache.end())
        return s->second;
    // Cache Miss
    auto res = fib_cached(n-1, cache) + fib_cached(n-2, cache);
    cache[n] = res;
    return res;
}

int fib_cached(int n)
{
    std::map<int, int> cache = {
        {1, 1},
        {2, 1}
    };
    return fib_cached(n, cache);
}

// To resolve this, use Tabulation:
// - which incorporates a Bottom-Up approach

int fib_tabulated(int n)
{
    auto fib_nums = std::vector<int>{0, 1, 1};

    for (int i = 3; i <= n; i++) {
        fib_nums.push_back(fib_nums[i-1] + fib_nums[i-2]);
    }
    return fib_nums[n];
}

