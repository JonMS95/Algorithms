#ifndef SORTING_ALGORITHMS
#define SORTING_ALGORITHMS

#include <iostream>
#include <vector>

class SortingAlgorithms
{
private:
    template <typename T>
    static void PrintVector(std::vector<T>& vec)
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
    static void BubbleSort(std::vector<T>& vec)
    {
        auto vec_size = vec.size();

        for(auto i = 0; i < vec_size - 1; i++)
        {
            for(auto j = 0; j < (vec_size - 1 - i); j++)
            {
                if(vec[j] > vec[j + 1])
                    std::swap(vec[j], vec[j + 1]);
            }
        }
    }

public:
    template <typename T>
    static void BubbleSortTest(std::vector<T>& vec)
    {
        std::cout << "Before sorting: ";
        SortingAlgorithms::PrintVector(vec);
        
        SortingAlgorithms::BubbleSort(vec);

        std::cout << "After sorting: ";
        SortingAlgorithms::PrintVector(vec);
    }
};

#endif
