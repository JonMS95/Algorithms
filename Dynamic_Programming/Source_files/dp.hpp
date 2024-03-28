#ifndef DP_HPP
#define DP_HPP

#include <vector>
#include <map>

class DP
{
private:
    static unsigned int fibonacci_memoization_helper(const unsigned int n, std::vector<int>& fib_nums);

    static int getLE2Power(int n);
    static int getNumOfOnes_recursive(int n);

    static int climbStairs_memoization(int n, std::map<int, int>& known_cases);
    
    static int houseRobber_recursive(std::vector<int>& nums, int index);

    static int houseRobber_tabulation(std::vector<int>& nums, int index, std::vector<int>& known_cases);

public:
    static unsigned int fibonacci_tabulation(const unsigned int n);
    static unsigned int fibonacci_memoization(const unsigned int n);

    static std::vector<int> countBits_naive(int n);
    static std::vector<int> countBits_recursive(int n);
    static int getNumOfOnes_memoization(int n, std::vector<int>& known_values);
    static std::vector<int> countBits_memoization(int n);
    static std::vector<int> getNumOfOnes_tabulation(int n);

    static int climbStairs_recursive(int n);
    static int climbStairs_memoization_driver(int n);

    static int houseRobber_recursive_driver(std::vector<int>& nums);

    static int houseRobber_tabulation_driver(std::vector<int>& nums);
};

#endif