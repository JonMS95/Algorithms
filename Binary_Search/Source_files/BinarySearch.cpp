#include "BinarySearch.hpp"

BinarySearch::BinarySearch(){};
BinarySearch::~BinarySearch(){};

int BinarySearch::BSearchIterative(std::vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    int middle = 0;

    while(left <= right)
    {
        middle = (left + right) / 2;

        if(target < nums[middle])
        {
            right = middle - 1;
            continue;
        }

        if(target > nums[middle])
        {
            left = middle + 1;
            continue;
        }

        return middle;
    }

    return -1;
}

int BinarySearch::BSearchRecursivePrivate(std::vector<int>& nums, int target, int left, int right)
{
    int middle = (left + right) / 2;

    if(left > right)
        return -1;

    if(target < nums[middle])
        return this->BSearchRecursivePrivate(nums, target, left, middle -1);

    if(target > nums[middle])
        return this->BSearchRecursivePrivate(nums, target, middle + 1, right);

    return middle;
}

int BinarySearch::BSearchRecursive(std::vector<int>& nums, int target)
{
    return this->BSearchRecursivePrivate(nums, target, 0, nums.size() - 1);
}