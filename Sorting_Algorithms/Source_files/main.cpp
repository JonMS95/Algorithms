#include "Sorting_Algorithms.hpp"
#include "Binary_Search_Tree.hpp"

int main()
{
    int number_of_vectors = 5;
    int vector_size = 10;
    SortingAlgorithms::SortTest<int>(SortingAlgorithms::BubbleSort              , number_of_vectors ,   vector_size);
    SortingAlgorithms::SortTest<int>(SortingAlgorithms::InsertionSort           , number_of_vectors ,   vector_size);
    SortingAlgorithms::SortTest<int>(SortingAlgorithms::SelectionSort           , number_of_vectors ,   vector_size);
    SortingAlgorithms::SortTest<int>(SortingAlgorithms::BinarySearchTreeSort    , number_of_vectors ,   vector_size);
}