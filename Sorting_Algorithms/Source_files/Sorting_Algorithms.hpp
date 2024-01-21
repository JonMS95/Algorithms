#ifndef SORTING_ALGORITHMS
#define SORTING_ALGORITHMS

#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

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
    static void RandomizeVectorValues(std::vector<T>& vec, T min_value, T max_value)
    {
        srand(time(NULL));

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
    static void BubbleSort(std::vector<T>& vec)
    {
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

public:
    template <typename T>
    static void BubbleSortTest(int vector_num = 10, int vector_size = 100)
    {
        std::vector<T> vec(100, 0);

        for(int i = 0; i < vector_num; i++)
        {
            std::cout << "Test i: " << i << std::endl;

            SortingAlgorithms::RandomizeVectorValues(vec, 1, 1000);
            
            std::cout << "Before sorting: ";
            SortingAlgorithms::PrintVector(vec);

            SortingAlgorithms::BubbleSort(vec);

            std::cout << "After sorting: ";
            SortingAlgorithms::PrintVector(vec);

            std::cout << "Test i: "<< i << " result: " << (SortingAlgorithms::LinearSortTest(vec) ? "OK" : "NOK") << std::endl << std::endl;
        }
    }
};

#endif
