#include "Binary_Search.hpp"

int main()
{
    std::vector<int>  vec1 = {12, 23, 34, 45, 56, 67, 78, 89, 90};
    std::vector<char> vec2 = {'a', 'c', 'f', 'g', 'j', 'o', 'r', 'x'};

    BinarySearchClass::BinarySearchTest(vec1, 0, 100, 1);
    BinarySearchClass::BinarySearchTest(vec2, 'a', 'z', '\1');
}