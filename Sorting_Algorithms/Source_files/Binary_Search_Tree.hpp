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
    unsigned long int vec_index;

    void PrintBST_Priv(std::shared_ptr<BTNode<T>> pNode)
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

    void InsertNode_Priv(std::shared_ptr<BTNode<T>> pNode, T data)
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

    void GetBSTAsSortedVector(std::shared_ptr<BTNode<T>> pNode, std::vector<T>& vec)
    {
        if(pNode == nullptr)
            return;

        if(pNode->left != nullptr)
            this->GetBSTAsSortedVector(pNode->left, vec);

        vec[this->vec_index++] = pNode->data;

        if(pNode->right != nullptr)
            this->GetBSTAsSortedVector(pNode->right, vec);
    }

    void ResetVecIndex()
    {
        this->vec_index = 0;
    }

public:
    BinarySearchTree(void): pRoot(nullptr) { std::cout << "Created BT with no root." << std::endl; }
    BinarySearchTree(T data): pRoot(std::make_shared<BTNode<T>>(data)) { std::cout << "Created BT with root == " << data << "." << std::endl; }
    BinarySearchTree(std::shared_ptr<BTNode<T>> root): pRoot(root) { std::cout << "Created BT with root == " << pRoot->data << "." << std::endl; }
    BinarySearchTree(std::vector<T>& values)
    {
        if(values.size() == 0)
        {
            std::cout << "Vector has no values!" << std::endl;
            return;
        }

        this->pRoot = std::make_shared<BTNode<T>>(values[0]);

        for(auto i = 1; i < values.size(); i++)
        {
            this->InsertNode(values[i]);
        }
    }

    std::shared_ptr<BTNode<T>> GetBSTRoot(void)
    {
        return this->pRoot;
    }

    void PrintBST(void)
    {
        this->PrintBST_Priv(this->pRoot);
    }

    void InsertNode(T data)
    {
        this->InsertNode_Priv(this->pRoot, data);
    }

    static void BSTSort(std::vector<T>& vec)
    {
        BinarySearchTree<T> bt(vec);

        bt.ResetVecIndex();

        bt.GetBSTAsSortedVector(bt.GetBSTRoot(), vec);
    }
};

#endif
