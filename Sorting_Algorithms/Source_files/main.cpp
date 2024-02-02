#include "Sorting_Algorithms.hpp"

int main()
{
    unsigned int number_of_vectors  = 100   ;
    unsigned int vector_size        = 1000  ;

    std::vector<bool> results;

    results.emplace_back(   SortingAlgorithms::SortTest<int>(SortingAlgorithms::BubbleSort              , number_of_vectors ,   vector_size)    );
    results.emplace_back(   SortingAlgorithms::SortTest<int>(SortingAlgorithms::InsertionSort           , number_of_vectors ,   vector_size)    );
    results.emplace_back(   SortingAlgorithms::SortTest<int>(SortingAlgorithms::SelectionSort           , number_of_vectors ,   vector_size)    );
    results.emplace_back(   SortingAlgorithms::SortTest<int>(SortingAlgorithms::BinarySearchTreeSort    , number_of_vectors ,   vector_size)    );
    results.emplace_back(   SortingAlgorithms::SortTest<int>(SortingAlgorithms::QuickSortEnd            , number_of_vectors ,   vector_size)    );
    results.emplace_back(   SortingAlgorithms::SortTest<int>(SortingAlgorithms::QuickSort               , number_of_vectors ,   vector_size)    );

    for(auto i = 0; i < results.size(); i++)
        if(!results[i])
        {
            std::cout << "TEST " << i << " FAILED!" << std::endl;
            return -1;
        }

    std::cout << "ALL TESTS ARE OK." << std::endl;

    return 0;
}