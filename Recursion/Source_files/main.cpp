#include <iostream>
#include <vector>
#include "Recursion.hpp"
#include "LinkedListNode.hpp"

int main()
{
    int num_of_tests = 10;
    std::vector<bool> results;

    results.emplace_back(Recursion::testRecursiveFunction(Recursion::summation, Recursion::summationIterative, num_of_tests, "Summation"));
    results.emplace_back(Recursion::testRecursiveFunction(Recursion::factorial, Recursion::factorialIterative, num_of_tests, "Factorial"));
    results.emplace_back(Recursion::testRecursiveFunction(Recursion::fibonacci, Recursion::fibonacciIterative, num_of_tests, "Fibonacci"));

    for(bool r:results)
        if(!r)
        {
            std::cout << std::endl << "Some test failed!" << std::endl;
            return -1;
        }
    
    std::shared_ptr<LinkedListNode<int>> lln5 = std::make_shared<LinkedListNode<int>>(5);
    std::shared_ptr<LinkedListNode<int>> lln4 = std::make_shared<LinkedListNode<int>>(4, lln5);
    std::shared_ptr<LinkedListNode<int>> lln3 = std::make_shared<LinkedListNode<int>>(3, lln4);
    std::shared_ptr<LinkedListNode<int>> lln2 = std::make_shared<LinkedListNode<int>>(2, lln3);
    std::shared_ptr<LinkedListNode<int>> lln1 = std::make_shared<LinkedListNode<int>>(1, lln2);

    std::cout << "LL recursive Sum: " << LinkedListNode<int>::LinkedListSum(lln1) << std::endl;

    std::cout << "GetLLNthNodeData: " << LinkedListNode<int>::GetLLNthNodeData(lln1, 2) << std::endl;

    std::cout << std::endl << "All tests went OK!" << std::endl;
    return 0;
}