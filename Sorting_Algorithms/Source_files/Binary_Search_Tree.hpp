#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include <iostream>
#include <memory>
#include <vector>
#include "Binary_Tree_Node.hpp"

template <typename T>
class BinarySearchTree
{
private:
    std::shared_ptr<BTNode<T>> pRoot;

    void PrintBST_Priv(const std::shared_ptr<BTNode<T>> pNode)
    {
        if(pNode == nullptr)
            return;

        if(pNode->left != nullptr)
        {
            PrintBST_Priv(pNode->left);
        }

        std::cout << "pNode: " << pNode->data << "." << std::endl;

        if(pNode->right != nullptr)
        {
            PrintBST_Priv(pNode->right);
        }
    }

    void InsertNode_Priv(const std::shared_ptr<BTNode<T>> pNode, T data)
    {
        if(pNode == nullptr || pNode->data == data)
            return;

        if(data < pNode->data)
        {
            if(pNode->left == nullptr)
            {
                pNode->left = std::make_shared<BTNode<T>>(data);
                return;
            }
            else
                InsertNode_Priv(pNode->left, data);
        }
        else
        {
            if(pNode->right == nullptr)
            {
                pNode->right = std::make_shared<BTNode<T>>(data);
                return;
            }
            else
                InsertNode_Priv(pNode->right, data);
        }
    }

    void GetBSTAsSortedVector(const std::shared_ptr<BTNode<T>> pNode, std::vector<T>& vec)
    {
        if(pNode == nullptr)
            return;

        if(pNode->left != nullptr)
            this->GetBSTAsSortedVector(pNode->left, vec);

        vec.emplace_back(pNode->data);

        if(pNode->right != nullptr)
            this->GetBSTAsSortedVector(pNode->right, vec);
    }

public:
    BinarySearchTree(void): pRoot(nullptr) { std::cout << "Created BT with no root." << std::endl; }
    BinarySearchTree(const T data): pRoot(std::make_shared<BTNode<T>>(data)) { std::cout << "Created BT with root == " << data << "." << std::endl; }
    BinarySearchTree(const std::shared_ptr<BTNode<T>> root): pRoot(root) { std::cout << "Created BT with root == " << pRoot->data << "." << std::endl; }
    BinarySearchTree(const std::vector<T>& values)
    {
        if(values.size() == 0)
        {
            std::cout << "Vector has no values!" << std::endl;
            return;
        }

        this->pRoot = std::make_shared<BTNode<T>>(values[0]);

        for(auto i = 1; i < values.size(); i++)
            this->InsertNode(values[i]);
    }

    std::shared_ptr<BTNode<T>> GetBSTRoot(void)
    {
        return this->pRoot;
    }

    void PrintBST(void)
    {
        this->PrintBST_Priv(this->pRoot);
    }

    void InsertNode(const T data)
    {
        this->InsertNode_Priv(this->pRoot, data);
    }

    static void BSTSort(std::vector<T>& vec)
    {
        std::vector<T> sorted_vec;

        BinarySearchTree<T> bt(vec);

        bt.GetBSTAsSortedVector(bt.GetBSTRoot(), sorted_vec);

        // Keep in mind that the current implementation of this BST does not allow storing repeated elements.
        vec = sorted_vec;
    }
};

#endif
