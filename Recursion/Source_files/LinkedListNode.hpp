#include <memory>

template <typename T>
class LinkedListNode
{
public:
    LinkedListNode(void): data(0), next(nullptr)
    {
        std::cout << "Created Linked List node with no data nor next element pointer." << std::endl;
    }
    LinkedListNode(T data): data(data)
    {
        std::cout << "Created Linked List node with data = " << data << "." << std::endl;
    }
    LinkedListNode(std::shared_ptr<LinkedListNode<T>> next): next(next)
    {
        std::cout << "Created Linked List node with a next element pointer" << std::endl;
    }
    LinkedListNode(T data, std::shared_ptr<LinkedListNode<T>> next): data(data), next(next)
    {
        std::cout << "Created Linked List node with data = " << data << " and a next element pointer." << std::endl;
    }

    virtual ~LinkedListNode()
    {
        std::cout << "Destroyed linked list node with data = " << this->data << "." << std::endl;
    }

    static T LinkedListSum(std::shared_ptr<LinkedListNode<T>> head)
    {
        if(head == nullptr)
            return 0;
        
        return head->data + LinkedListSum(head->next);
    }

    static T GetLLNthNodeData(std::shared_ptr<LinkedListNode<T>> head, unsigned int target, unsigned int current_index = 0)
    {
        if( (target == current_index))
            return head->data;
        
        if( (head == nullptr) || (target < 0))
            return 0;
        
        return GetLLNthNodeData(head->next, target, ++current_index);
    }
    
    std::shared_ptr<LinkedListNode<T>> next;
    T data;
};