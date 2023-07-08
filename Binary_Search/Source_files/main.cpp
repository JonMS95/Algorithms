#include "BinarySearch.hpp"
#include <cstdlib>
#include <algorithm>
#include <iostream>

int LinearSearch(std::vector<int>& nums, int target)
{
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == target)
            return i;
    }

    return -1;
}

int main()
{
    int min = 0;
    int max = 100;

    int num_amount = 50;

    std::vector<int> random_numbers(num_amount);

    for(int i = 0; i < num_amount; i++)
    {
        int rand_num;

        do
        {
            rand_num = rand() % (max + 1) + min;
        }
        while(std::find(random_numbers.begin(), random_numbers.end(), rand_num) != random_numbers.end());
        
        random_numbers[i] = rand_num;
    }

    std::sort(random_numbers.begin(), random_numbers.end());

    for(auto i:random_numbers)
        std::cout << i << " ";
    std::cout << std::endl;

    BinarySearch binary_search;

    int num_trys = 10;

    for(int i = 0; i < num_trys; i++)
    {
        int target = rand() % (random_numbers[random_numbers.size() - 1] + 1) + random_numbers[0];
        int linear_search_index = LinearSearch(random_numbers, target);
        int linear_search_iterative_index = binary_search.BSearchIterative(random_numbers, target);
        int linear_search_recursive_index = binary_search.BSearchRecursive(random_numbers, target);
        std::cout << "******************************" << std::endl;
        std::cout << "Target number = " << target << ", index = " << linear_search_index << std::endl;
        std::cout << "Target number index = " << linear_search_iterative_index << " using iterative approach." << std::endl;
        std::cout << "Target number index = " << linear_search_recursive_index << " using recursive approach." << std::endl;
        std::cout << "Result: " << ((linear_search_index == linear_search_iterative_index && linear_search_iterative_index == linear_search_recursive_index) ? "OK" : "NOK") << std::endl << std::endl;
    }
}