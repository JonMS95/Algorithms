#ifndef BINARY_TREE_NODE
#define BINARY_TREE_NODE

#include <memory>

template <typename T> 
class BTNode
{
public:
    T data;
    std::shared_ptr<BTNode> left;
    std::shared_ptr<BTNode> right;

    BTNode(void): data(0), left(nullptr), right(nullptr) {}
    BTNode(T data): data(data), left(nullptr), right(nullptr) {}
    BTNode(T data, std::shared_ptr<BTNode> left, std::shared_ptr<BTNode> right): data(data), left(left), right(right) {}
    virtual ~BTNode(void) {}
};

#endif
