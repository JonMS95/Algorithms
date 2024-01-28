#ifndef SORTING_ALGORITHMS
#define SORTING_ALGORITHMS

#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "Binary_Search_Tree.hpp"

class SortingAlgorithms
{
private:
    template <typename T>
    static void PrintVector(const std::vector<T>& vec)
    {
        std::cout << "{";

        for(auto i = 0; i < vec.size(); i++)
        {
            std::cout << vec[i];
            if(i != vec.size() - 1)
                std::cout << ", ";
        }

        std::cout << "}" << std::endl;
    }

    template <typename T>
    static void RandomizeVectorValues(std::vector<T>& vec, T min_value, T max_value)
    {
        for(int i = 0; i < vec.size(); i++)
            vec[i] = rand() % max_value + min_value;
    }

    template <typename T>
    static bool LinearSortTest(std::vector<T>& vec)
    {
        for(auto i = 0; i < vec.size() - 1; i++)
            if(vec[i] > vec[i + 1])
                return false;
        
        return true;
    }

    template <typename T>
    static unsigned long int QuickSortPartition(std::vector<T>& vec, unsigned long int left, unsigned long int right)
    {
        T pivot = vec[left];

        for(unsigned long int i = left + 1; i <= right; i++)
        {
            if(vec[i] < pivot)
            {
                std::swap(vec[i], vec[left++]);
            }
        }

        std::swap(pivot, vec[left]);

        return left;
    }

    template <typename T>
    static void QuickSort_Priv(std::vector<T>& vec, unsigned long int left, unsigned long int right)
    {
        if(left < right)
        {
            unsigned long int pivot_index = SortingAlgorithms::QuickSortPartition(vec, left, right);

            SortingAlgorithms::QuickSort_Priv(vec, left, pivot_index);
            SortingAlgorithms::QuickSort_Priv(vec, pivot_index + 1, right);
        }
    }

public:
    template <typename T>
    static void BubbleSort(std::vector<T>& vec)
    {
        std::cout << "Applying bubble sort ..." << std::endl;

        auto vec_size = vec.size();
        bool exchanges_needed;

        for(auto i = 0; i < vec_size - 1; i++)
        {
            exchanges_needed = false;

            for(auto j = 0; j < (vec_size - 1 - i); j++)
            {
                if(vec[j] > vec[j + 1])
                {
                    exchanges_needed = true;
                    std::swap(vec[j], vec[j + 1]);
                }
            }

            if(!exchanges_needed)
                return;
        }
    }

    template <typename T>
    static void InsertionSort(std::vector<T>& vec)
    {
        std::cout << "Applying insertion sort ..." << std::endl;
        
        for(auto i = 1; i < vec.size(); i++)
        {
            T key = vec[i];

            auto j = i - 1;

            while (j >= 0 && vec[j] > key) 
            {
                vec[j + 1] = vec[j];
                j = j - 1;
            }

            vec[j + 1] = key;
        }
    }

    template <typename T>
    static void SelectionSort(std::vector<T>& vec)
    {
        std::cout << "Applying selection sort ..." << std::endl;
        T min_index;
        
        for(auto i = 0; i < vec.size() - 1; i++)
        {
            min_index = i;
            
            for(auto j = i; j < vec.size(); j++)
            {
                if(vec[j] < vec[min_index])
                    min_index = j;
            }

            std::swap(vec[i], vec[min_index]);
        }
    }

    template <typename T>
    static void BinarySearchTreeSort(std::vector<T>& vec)
    {
        std::cout << "Applying BST sort ..." << std::endl;

        std::cout << "***** WARNING: The current implementation of BST does not allow storing repeated elements. Resulting vector may end up being shorter than the original. *****" << std::endl;
        BinarySearchTree<int>::BSTSort(vec);
    }

    template <typename T>
    static void QuickSort(std::vector<T>& vec)
    {
        std::cout << "Applying QuickSort ..." << std::endl;
        SortingAlgorithms::QuickSort_Priv(vec, 0, vec.size() - 1);
    }

    template <typename T>
    static bool SortTest(void (*SortingAlgorithm)(std::vector<T>&), unsigned int vector_num = 10, unsigned int vector_size = 100)
    {
        std::vector<T> vec(vector_size, 0);
        std::vector<bool> results(vector_num, false);
        srand(time(NULL));

        // Keep in mind that BST sort may lead the vector size to shrink as tests go by, since repeated elements are removed in the current implementation.

        for(auto i = 0; i < vector_num; i++)
        {
            std::cout << "Test i: " << i << std::endl;

            SortingAlgorithms::RandomizeVectorValues(vec, 1, 1000);
            
            std::cout << "Before sorting: ";
            SortingAlgorithms::PrintVector(vec);

            SortingAlgorithm(vec);

            std::cout << "After sorting: ";
            SortingAlgorithms::PrintVector(vec);

            results[i] = SortingAlgorithms::LinearSortTest(vec);
            std::cout << "Test i: "<< i << " result: " << (results[i] ? "OK" : "NOK") << std::endl << std::endl;
        }

        bool test_result = ( results[0] == true && SortingAlgorithms::LinearSortTest(results) );
        
        std::cout << "Overall result: " << (test_result ? "OK" : "NOK") << std::endl << std::endl;

        return test_result;
    }
};

#endif
