#include "Recursion.hpp"

unsigned long int Recursion::summation(unsigned long int n)
{    
    if(n > 1)
        return n + summation(n - 1);
    
    return n;
}

unsigned long int Recursion::summationIterative(unsigned long int n)
{
    unsigned long int sum = 0;

    for(unsigned long int i = 1; i <= n; i++)
        sum += i;

    return sum;
}

unsigned long int Recursion::factorial(unsigned long int n)
{
    if(n > 1)
        return n * factorial(n - 1);
    
    return n;
}

unsigned long int Recursion::factorialIterative(unsigned long int n)
{
    if(n < 1)
        return n;

    unsigned long int factorial_iterative = 1;
    
    for(unsigned long int i = 2; i <= n; i++)
        factorial_iterative *= i;
    
    return factorial_iterative;
}

unsigned long int Recursion::fibonacci(unsigned long int n)
{
    if( (n == 0) || (n == 1) )
        return n;
    
    return fibonacci(n - 1) + fibonacci(n - 2);
}

unsigned long int Recursion::fibonacciIterative(unsigned long int n)
{
    if(n == 0 || n == 1)
        return n;
    
    std::vector<unsigned long int> fib_nums(n + 1, 0);
    fib_nums[1] = 1;

    for(unsigned long int i = 2; i <= n; i++)
        fib_nums[i] = fib_nums[i - 1] + fib_nums[i - 2];
    
    return fib_nums[fib_nums.size() - 1];
}

bool Recursion::testRecursiveFunction(  unsigned long int(*recursiveFunction)(unsigned long int),
                                        unsigned long int(*iterativeFunction)(unsigned long int),
                                        unsigned int n                                          ,
                                        std::string function_name                               )
{
    unsigned long int recursive;
    unsigned long int iterative;

    std::cout << "Testing " << function_name << ":" << std::endl << std::endl; 

    for(int i = 0; i <= n; i++)
    {
        unsigned long int recursive = recursiveFunction(i);
        unsigned long int iterative = iterativeFunction(i);

        std::cout << "Recursive "<< function_name << "(" << i << ") = " << recursive << std::endl;
        std::cout << "Iterative " << function_name << "(" << i << ") = " << iterative << std::endl;

        if(recursive != iterative)
        {
            std::cout << "Recursive and iterative approaches do not match each other!" << std::endl;
            return false;
        }

        std::cout << std::endl;
    }

    std::cout << "All tests for " << function_name << " went OK!" << std::endl;

    return true;
}