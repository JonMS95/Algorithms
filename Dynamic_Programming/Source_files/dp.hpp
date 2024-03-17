#ifndef DP_HPP
#define DP_HPP

#include <vector>

class DP
{
private:
    static unsigned int fibonacci_memoization_helper(const unsigned int n, std::vector<int>& fib_nums);

    static int getLE2Power(int n);
    static int getNumOfOnes_recursive(int n);

public:
    static unsigned int fibonacci_tabulation(const unsigned int n);
    static unsigned int fibonacci_memoization(const unsigned int n);

    static std::vector<int> countBits_naive(int n);
    static std::vector<int> countBits_recursive(int n);
    static int getNumOfOnes_memoization(int n, std::vector<int>& known_values);
    static std::vector<int> countBits_memoization(int n);
};

#endif