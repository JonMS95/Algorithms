#ifndef RECURSION_HPP
#define RECURSION_HPP

#include <iostream>
#include <vector>
#include <string>

class Recursion
{
public:
    Recursion()     = delete;
    ~Recursion()    = delete;

    static unsigned long int summation(unsigned long int n)         ;
    static unsigned long int summationIterative(unsigned long int n);
    static unsigned long int factorial(unsigned long int n)         ;
    static unsigned long int factorialIterative(unsigned long int n);
    static unsigned long int fibonacci(unsigned long int n)         ;
    static unsigned long int fibonacciIterative(unsigned long int n);
    
    static bool testRecursiveFunction(  unsigned long int(*recursiveFunction)(unsigned long int),
                                        unsigned long int(*iterativeFunction)(unsigned long int),
                                        unsigned int n                                          ,
                                        std::string function_name                               );
};

#endif
