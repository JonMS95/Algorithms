#include <iostream>
#include "dp.hpp"

void testFibonacci(int n = 10)
{
    std::cout << "Testing Fibonacci number calculator functions:" << std::endl;
    
    for(int i = 0; i <= n; i++)
    {
        std::cout << "DP::fibonacci_memoization(" << i << ") = " << DP::fibonacci_memoization(i) << std::endl;
        std::cout << "DP::fibonacci_tabulation("  << i << ") = " << DP::fibonacci_tabulation(i)  << std::endl;
    }

    std::cout << std::endl;
}

void testCountBits(int n = 16)
{
    std::cout << "Testing bit number (1s) calculator functions:" << std::endl;

    std::cout << "DP::countBits_naive(" << n << ")" << std::endl;
    for(int num: DP::countBits_naive(n))
        std::cout << num << " ";
    std::cout << std::endl;

    std::cout << "DP::countBits_recursive(" << n << ")" << std::endl;
    for(int num: DP::countBits_recursive(n))
        std::cout << num << " ";
    std::cout << std::endl;

    std::cout << "DP::countBits_memoization(" << n << ")" << std::endl;
    for(int num: DP::countBits_memoization(n))
        std::cout << num << " ";
    std::cout << std::endl;

    std::cout << "DP::getNumOfOnes_tabulation(" << n << ")" << std::endl;
    for(int num: DP::getNumOfOnes_tabulation(n))
        std::cout << num << " ";
    std::cout << std::endl;

    std::cout << std::endl;
}

void testClimbStairs(int n = 10)
{
    for(int i = 1; i <= 10; i++)
    {
        std::cout << "DP::climbStairs_recursive(" << i << ") = " << DP::climbStairs_recursive(i) << std::endl;
        std::cout << "DP::climbStairs_memoization_driver(" << i << ") = " << DP::climbStairs_memoization_driver(i) << std::endl;
    }
}

int main()
{
    testFibonacci();
    testCountBits();
    testClimbStairs();

    return 0;
}