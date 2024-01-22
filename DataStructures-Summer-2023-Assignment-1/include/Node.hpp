#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>
using namespace std;
class Node
{
private:
    /* data */
public:
    Node(int value);
    ~Node();
    Node *next;
    int data;
};

#endif // !