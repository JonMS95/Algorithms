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
    static void SortTest(void (*SortingAlgorithm)(std::vector<T>&), int vector_num = 10, int vector_size = 100)
    {
        std::vector<T> vec(vector_size, 0);
        std::vector<bool> results(vector_num, false);

        for(int i = 0; i < vector_num; i++)
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

        std::cout << "Overall result: " << (( results[0] == true && SortingAlgorithms::LinearSortTest(results) ) ? "OK" : "NOK") << std::endl << std::endl;
    }
};

#endif
