#ifndef NODE_HPP
#define NODE_HPP

#include "number.hpp"

class numberNode
{
private:
    /* data */
public:
    numberNode(int);
    Number * number;
    int value;
    numberNode * nextNode;
    ~numberNode();
};


#endif