#include <iostream>
#include "dp.hpp"

int main()
{
    for(int i = 0; i <= 10; i++)
    {
        std::cout << "DP::fibonacci_memoization(" << i << ") = " << DP::fibonacci_memoization(i) << std::endl;
        std::cout << "DP::fibonacci_tabulation("  << i << ") = " << DP::fibonacci_tabulation(i)  << std::endl;
    }

    return 0;
}