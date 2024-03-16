/*
Memoization is a technique in which computed values are stored in order to avoid any potential redundant calculation.
Our first example will be a function to get Fibonacci number, which will also lead us to know which is the main difference
between DP and recursion.

Recursion consists in a function that calls itself within the function's body, and that's all. On the other hand, memoization
can also call itself, but it makes sure redundant computation is not performed whatsoever.

When calculating Fibonacci number by using recursion, more computation that needed is actually done. For example:
F(4) = F(3) + F(2)
Get F(3) first:
F(3) = F(2) + F(1)
F(2) = F(1) + F(0)
Now get F(2):
F(2) = F(1) + F(0)

So as we can notice, F(2) has been calculated twice. That situation may have been avoided if those results had been stored somewhere
the first time they had been calculated.

In order to accomplish the required prior calculations, two approaches may be followed:
    ·Bottom-top approach (tabulation): get from the lowest n to the target and calculate every solution for each of the values for n.
    ·Top-bottom approach (memoization): in order to calculate F(n), I need first to calculate F(n - 1) and F(n - 2). To calculate F(n - 1),
     I need to calculate first F(n - 2) and F(n - 3) ... and so on. It's the same approach as the recursion one, but solutions
     for each value of n are stored each time.

Note that for n: 4, 4 values have to be computated previously. In a general case, n values are required.
Therefore, a space can be reserved (by using a vector, for instance), in which those values could be stored.

Something that is worth pointing out (again), is that there is no reason to solve a recursion problem by using DP if involved calculations
are not prone to be repeated. For example, to calculate 1..n sum (1 + 2 + 3 + ... + n), the function that solves it may be described as follows:
S(n) = 
{
    n               if n == 0 || n == 1 ;
    n + S(n - 1)    if n > 1            ;
}

Thus, for n == 3:
S(3) = 3 + S(2)
S(2) = 2 + S(1)
S(1) = 1

And as shown above, each calculation has to be performed just once, so there is no need to store those results each time.
*/

#include "dp.hpp"

/*
The function below follows the bottom-top approach (tabulation), so it calculates the terms for the fibonacci series from the
beginning to the end.
*/

unsigned int DP::fibonacci_tabulation(const unsigned int n)
{
    std::vector<unsigned int> fib_nums(n + 1);

    fib_nums[0] = 0;
    fib_nums[1] = 1;

    for(unsigned int i = 2; i <= n; i++)
    {
        fib_nums[i] = fib_nums[i - 2] + fib_nums[i - 1];
    }

    return fib_nums[n];
}

/*
The following couple of functions follow a top-bottom approach (memoization), so for every number it is checked whether or not
do the required terms exist, and if not, they are calculated. 
*/

unsigned int DP::fibonacci_memoization_helper(const unsigned int n, std::vector<int>& fib_nums)
{
    if(fib_nums[n] < 0)
        fib_nums[n] = fibonacci_memoization_helper(n - 1, fib_nums) + fibonacci_memoization_helper(n - 2, fib_nums);
 
    return fib_nums[n];
}

unsigned int DP::fibonacci_memoization(const unsigned int n)
{
    std::vector<int> fib_nums(n + 1, -1);
    fib_nums[0] = 0;
    fib_nums[1] = 1;    

    return fibonacci_memoization_helper(n, fib_nums);
}
