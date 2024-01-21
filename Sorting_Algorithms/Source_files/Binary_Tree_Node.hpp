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

    BTNode(void): data(0), left(nullptr), right(nullptr)
    { 
        std::cout << "Created node with no parameters." << std::endl;
    }
    
    BTNode(T data): data(data), left(nullptr), right(nullptr)
    {
        std::cout << "Created node with data: " << this->data << "." << std::endl;
    }

    BTNode(T data, std::shared_ptr<BTNode> left, std::shared_ptr<BTNode> right): data(data), left(left), right(right)
    {
        std::cout << "Created node with data: " << this->data << " and populated pending nodes." << std::endl;
    }

    ~BTNode(void)
    {
        std::cout << "Destroyed node with data: " << this->data << "." << std::endl;
    }
};

#endif
