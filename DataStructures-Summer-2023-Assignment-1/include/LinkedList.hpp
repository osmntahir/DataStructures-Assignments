#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include "Node.hpp"
class LinkedList
{
private:
    Node* head;
    int NodeCount;
public:
    LinkedList(/* args */);
     void InsertNode(Node *);
    Node* getNode(int index);
    ~LinkedList();
};



#endif // !