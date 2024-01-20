#ifndef BINARY_SEARCH_HPP
#define BINARY_SEARCH_HPP

#include <iostream>
#include <vector>

class BinarySearchClass
{
private:
    template <typename T>
    static int IterativeBinarySearch(std::vector<T>& vec, T target)
    {
        int l = 0;
        int r = vec.size() - 1;
        int mid;

        while(l <= r)
        {
            mid = l + (r - l) / 2;

            if(vec[mid] == target)
                return mid;

            if(target < vec[mid])
                r = mid - 1;
            else
                l = mid + 1;
        }

        return -1;
    }

    template <typename T>
    static int RecursiveBinarySearch(std::vector<T>& vec, T target, int l, int r)
    {
        if(l > r)
            return -1;

        int mid = l + (r - l) / 2;

        if(vec[mid] == target)
            return mid;

        if(target < vec[mid])
            return BinarySearchClass::RecursiveBinarySearch(vec, target, l, mid - 1);
        else
            return BinarySearchClass::RecursiveBinarySearch(vec, target, mid + 1, r);
    }

public:
    template <typename T>
    static void BinarySearchTest(std::vector<T>& vec, T min, T max, T step)
    {
        int iter_bs_ret;
        int rec_bs_ret;

        for(auto i = min; i <= max; i += step)
        {
            iter_bs_ret = BinarySearchClass::IterativeBinarySearch(vec, i);
            rec_bs_ret  = BinarySearchClass::RecursiveBinarySearch(vec, i, 0, (vec.size() - 1));

            if( (iter_bs_ret != -1) || (rec_bs_ret != -1) )
                std::cout << "Element: " << i << "\tfound at index: " << iter_bs_ret << " (iterative), " << rec_bs_ret << " (recursive)." << std::endl;
        }

        std::cout << std::endl;
    }
};

#endif
