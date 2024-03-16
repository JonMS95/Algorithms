#ifndef DP_HPP
#define DP_HPP

#include <vector>

class DP
{
private:
    static unsigned int fibonacci_memoization_helper(const unsigned int n, std::vector<int>& fib_nums);

public:
    static unsigned int fibonacci_tabulation(const unsigned int n);
    static unsigned int fibonacci_memoization(const unsigned int n);
};

#endif