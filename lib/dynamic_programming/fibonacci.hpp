#ifndef FIBONACCI_H
#define FIBONACCI_H

#include <map>
#include <vector>

class Fibonacci {
public:
    // Using Recursion, a Top-Down approach

    // Simple, but very slow O(2^n)

    static int simple(int n)
    {
        if (n <= 2) return 1;
        return simple(n-1) + simple(n-2);
    }

    // Memoized

    // this is getting better & is a lot faster: O(n)
    // - However, this will not scale as recursion will exceed 
    //   the limit of stack memory allocation at a certain point, 
    //   eg. n=1000

    static int cached(int n)
    {
        std::map<int, int> cache = {
            {1, 1},
            {2, 1}
        };
        int res = cached_loop(n, cache);
        return res;
    }

    // To resolve this, use Tabulation:
    // - which incorporates a Bottom-Up approach

    static int tabulated(int n)
    {
        auto nums = std::vector<int>{0, 1, 1};

        for (int i = 3; i <= n; i++) {
            nums.push_back(nums[i-1] + nums[i-2]);
        }
        return nums[n];
    }
private:
    static int cached_loop(int n, std::map<int, int> cache)
    {
        if(auto s = cache.find(n); s != cache.end())
            return s->second;
        // Cache Miss
        auto res = cached_loop(n-1, cache) + cached_loop(n-2, cache);
        cache[n] = res;
        return res;
    }
};

#endif