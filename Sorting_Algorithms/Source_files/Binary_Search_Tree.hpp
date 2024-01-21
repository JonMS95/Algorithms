#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include <iostream>
#include <memory>
#include "Binary_Tree_Node.hpp"

template <typename T>
class BinarySearchTree
{
private:
    std::shared_ptr<BTNode<T>> pRoot;

    static void PrintNodeValue(std::shared_ptr<BTNode<T>> pNode)
    {
        std::cout << "Node value: " << pNode->data << "." << std::endl;
    }

    static void InsertNode_Private(std::shared_ptr<BTNode<T>> pNode/*, T data*/)
    {
        T data = 3;
        if(pNode == nullptr)
            return;

        if(pNode->data > data && pNode->left == nullptr)
        {
            pNode->left = std::make_shared<BTNode<T>>(data);
            return;
        }

        if(pNode->data < data && pNode->right == nullptr)
        {
            pNode->right = std::make_shared<BTNode<T>>(data);
            return;
        }
    }

    void BTTraversal_Private(   std::shared_ptr<BTNode<T>> pNode                                    ,
                                void (*preOrderFn) (std::shared_ptr<BTNode<T>> pNode)   = nullptr   ,
                                void (*inOrderFn)  (std::shared_ptr<BTNode<T>> pNode)   = nullptr   ,
                                void (*postOrderFn)(std::shared_ptr<BTNode<T>> pNode)   = nullptr   )
    {
        if(pNode == nullptr)
            return;

        if(preOrderFn != nullptr)
            preOrderFn(pNode);

        if(pNode->left != nullptr)
            this->BTTraversal_Private(pNode->left, preOrderFn, inOrderFn, postOrderFn);

        if(inOrderFn != nullptr)
            inOrderFn(pNode);

        if(pNode->right != nullptr)
            this->BTTraversal_Private(pNode->right, preOrderFn, inOrderFn, postOrderFn);

        if(postOrderFn != nullptr)
            postOrderFn(pNode);
    }

public:
    BinarySearchTree(void): pRoot(nullptr) { std::cout << "Created BT with no root." << std::endl; }

    BinarySearchTree(std::shared_ptr<BTNode<T>> pRoot): pRoot(pRoot) {}

    void InOrderTraversal(void)
    {
        this->BTTraversal_Private(this->pRoot, nullptr, BinarySearchTree::PrintNodeValue, nullptr);
    }

    void InsertNode(T data)
    {
        this->BTTraversal_Private(this->pRoot, nullptr, BinarySearchTree::InsertNode_Private, nullptr);
    }
};

#endif
