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

Anyway, those can be easily stored as well in a variable that may be outside our function scope, so that there's no need to calculate it
again if it has already been done so. For example, if we have calculated first 5!, we need to calculate the factorial for any lower number.
If we wanted to calculate 3!, there would be no need to perform any mathematical operation again as it would have been already done.
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

/*
Let's see another example: given an integer n, return a vector which contains the amount of bits for every number from 0 to n.
Examples:
    n = 2 -> [0, 1, 1]
    n = 5 -> [0, 1, 1, 2, 1, 2]
Source: https://leetcode.com/problems/counting-bits/
*/

/*
Naïve approach: calculate first the size of the integer. Then, for i = 0; i < size_of_int; i++, divide it by two (or apply single bit mask AND),
and add 1 each time a one is found in the current number's binary representation.
Cost: O(n) * O(K) where K is equal to the number of bits in an integer (typically 32).
*/

std::vector<int> DP::countBits_naive(int n)
{
    std::vector<int> ret(n + 1);
    
    for(int i = 0; i <= n; i++)
    {
        int num_to_divide = i;
        int count_ones_curr_num = 0;
        
        for(int j = 0; j < (int)(sizeof(n) * 8); j++)
        {
            if(num_to_divide % 2 == 1)
                ++count_ones_curr_num;
            num_to_divide /= 2;
        }

        ret[i] = count_ones_curr_num;
    }

    return ret;
}

/*
Recursive approach: realise the pattern.
N(0)    = 0     
N(1)    = 1     = N(0) + 1
N(2)    = 1     = N(0) + 1
N(3)    = 2     = N(1) + 1  = N(0) + 1 + 1
N(4)    = 1     = N(0) + 1
N(5)    = 2     = N(1) + 1  = N(0) + 1
N(6)    = 2     = N(2) + 1  = N(0) + 1 + 1
N(7)    = 3     = N(3) + 1  = N(1) + 1 + 1  = N(0) + 1 + 1 + 1
N(8)    = 1     = N(0) + 1
N(9)    = 2     = N(1) + 1  = N(0) + 1 + 1
N(10)   = 2     = N(2) + 1  = N(0) + 1 + 1
N(11)   = 3     = N(3) + 1  = N(1) + 1      = N(0) + 1 + 1
N(12)   = 2     = N(4) + 1  = N(0) + 1 + 1
N(13)   = 3     = N(5) + 1  = N(1) + 1      = N(0) + 1 + 1
N(14)   = 3     = N(6) + 1  = N(2) + 1 + 1  = N(0) + 1 + 1 + 1
N(15)   = 4     = N(7) + 1  = N(3) + 1 + 1  = N(1) + 1 + 1 + 1 = N(0) + 1 + 1 + 1 + 1
N(16)   = 1     = N(0) + 1
...

Therefore, we can infere that:
N(n)    = 0 if n == 0
        = N(n - p) + 1 if n > 0, where p is the nearest lower power of two

For example, for N(5), p = 4 (2 ^ 2), thus N(5) = N(5 - 4) + 1 = N(1) + 1.
In the case of N(1), p = 1 (2 ^ 0), which leaves us with N(1) = N(1 - 1) + 1 = N(0) + 1 = 1
So finally, N(5) = N(0) + 1 + 1

As a consequence of having to find p, an auxiliary function should be designed to fulfill the mentioned purpose.
*/

int DP::getLE2Power(int n)
{
    if(n <= 0)
        return -1;
    
    for(int i = 0; i < (int)(sizeof(n) * 8); i++)
        if( (n >= (1 << i) ) && (n < (1 << (i + 1) ) ) )
            return (1 << i);
    
    return -1;
}

int DP::getNumOfOnes_recursive(int n)
{
    if(n == 0)
        return 0;
    
    return (DP::getNumOfOnes_recursive(n - DP::getLE2Power(n)) + 1);
}

std::vector<int> DP::countBits_recursive(int n)
{
    std::vector<int> ret(n + 1);

    for(int i = n; i >= 0; i--)
        ret[i] = DP::getNumOfOnes_recursive(i);
    
    return ret;
}

/*
Once the problem has been solved by using an iterative approach, it's time to avoid redundant calculations.
For instance, if we were to calculate N(15), there would be no need to calculate any other value, since those have already been
calculated previously. This can be easily solved by using the array in which all of the results are stored as a look up table.
*/

int DP::getNumOfOnes_memoization(int n, std::vector<int>& known_values)
{
    if(n == 0)
        return 0;
    
    int required_arg = n - DP::getLE2Power(n);
    if(known_values[required_arg] == -1)
        known_values[required_arg] = DP::getNumOfOnes_memoization(required_arg, known_values);

    return (known_values[required_arg] + 1);
}

std::vector<int> DP::countBits_memoization(int n)
{
    std::vector<int> ret(n + 1, -1);

    for(int i = n; i >= 0; i--)
        ret[i] = DP::getNumOfOnes_memoization(i, ret);
    
    return ret;
}

/*
Another approach is the one based on tabulation (bottom-up). This one optimizes the iterative case.
It is based on calculating first the simpler terms, and leaving the most complex terms (which
require the prior ones) for the end. Same as memoization, it requires to store the terms that have
already been calculated somewhere. 
*/

std::vector<int> DP::getNumOfOnes_tabulation(int n)
{
    std::vector<int> nums(n + 1);

    nums[0] = 0;

    for(int i = 1; i <= n; i++)
        nums[i] = nums[i - DP::getLE2Power(i)] + 1;

    return nums;
}

/*
Let's see another example now: climbing stairs (based on https://leetcode.com/problems/climbing-stairs/description/).
Same as in prior examples, we shall start by coming up with a recursive solution to build some intuition for further approaches.
*/
int DP::climbStairs_recursive(int n)
{
    if(n == 0)
        return 1;
    
    if(n < 0)
        return 0;
    
    return (DP::climbStairs_recursive(n - 1) + DP::climbStairs_recursive(n - 2));
}

/*
Memoization approach: similar to what we have already seen while talking about geeting an arbitrary Fibonacci sequence number,
many calculations can be avoided if they are stored in memory after they have been calculated for the first time. For instance,
we know that there's only one way to get 1 step further (jumping a single level). Same goes for 2 steps: we can only jump once
twice, or jump two levels above once (2 ways). So the proper approach here would be store those results and retrieve them
later if necessary.
Note that n == 0 is stored beforehand in the map we are about to use since it's the already known base case.
*/
int DP::climbStairs_memoization(int n, std::map<int, int>& known_cases)
{
    if(n < 0)
        return 0;
    
    if(!known_cases.count(n))
        known_cases[n] = DP::climbStairs_memoization(n - 1, known_cases) + DP::climbStairs_memoization(n - 2, known_cases);
    
    return known_cases[n];
}

int DP::climbStairs_memoization_driver(int n)
{
    std::map<int, int> known_cases = {{0, 1}};
    return DP::climbStairs_memoization(n, known_cases);
}

/*
Yet another example, based on https://leetcode.com/problems/house-robber/description/.
*/
int DP::houseRobber_recursive(std::vector<int>& houses, int index)
{
    int biggest_rob = 0;

    for(unsigned long int i = index + 2; i < houses.size(); i++)
    {
        int rob_try = DP::houseRobber_recursive(houses, i);
        if(rob_try > biggest_rob)
            biggest_rob = rob_try;
    }

    return houses[index] + biggest_rob;
}

int DP::houseRobber_recursive_driver(std::vector<int>& nums)
{
    int biggest_rob = 0;

    for(unsigned long int i = 0; i < nums.size(); i++)
    {
        int rob_try = DP::houseRobber_recursive(nums, i);
        if(rob_try > biggest_rob)
            biggest_rob = rob_try;
    }

    return biggest_rob;
}

/*
In this case, optimized approach should be tabulation driven, as the problem is intrinsically bottom-up solvable.
*/
int DP::houseRobber_tabulation(std::vector<int>& houses, int index, std::vector<int>& known_values)
{
    if(known_values[index] == -1)
    {
        known_values[index] = 0;
        for(unsigned long int i = index + 2; i < houses.size(); i++)
        {
            int rob_try = DP::houseRobber_tabulation(houses, i, known_values);
            if(rob_try > known_values[index])
                known_values[index] = rob_try;
        }
    }

    return houses[index] + known_values[index];
}

int DP::houseRobber_tabulation_driver(std::vector<int>& nums)
{
    int biggest_rob = 0;

    std::vector<int> known_values(nums.size(), -1);

    for(unsigned long int i = 0; i < nums.size(); i++)
    {
        int rob_try = DP::houseRobber_tabulation(nums, i, known_values);
        if(rob_try > biggest_rob)
            biggest_rob = rob_try;
    }

    return biggest_rob;
}