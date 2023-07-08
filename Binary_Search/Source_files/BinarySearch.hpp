#include <vector>

class BinarySearch
{
private:
    int BSearchRecursivePrivate(std::vector<int>& nums, int target, int left, int right);
    
public:
    BinarySearch();
    ~BinarySearch();
    int BSearchIterative(std::vector<int>& nums, int target);
    int BSearchRecursive(std::vector<int>& nums, int target);
};
