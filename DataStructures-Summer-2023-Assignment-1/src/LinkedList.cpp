#include "LinkedList.hpp"

LinkedList::LinkedList(/* args */)
{
    head= nullptr;
}
void LinkedList::InsertNode(Node* newNode)
{
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node * current = head;
        while (current->next != nullptr)
        {
            current = current->next;
            
        }
        
        current->next = newNode;
    }
    NodeCount++;
}
Node* LinkedList::getNode(int index)
{
  if((index+1) >NodeCount) return nullptr;
  
	Node* currentNode = head;

	while (index >= 0 && currentNode != nullptr)
	{   
		if (index == 0) return currentNode;
		else
        {
		currentNode = currentNode->next;
		index--;
        }
	}
	return currentNode;
}
LinkedList::~LinkedList()
{
    if(head== nullptr) return ;

    Node* current = head;
	while (current != nullptr)
	{
		Node* deleteNode = current;
		current = current->next;

		delete deleteNode;
	}
}

