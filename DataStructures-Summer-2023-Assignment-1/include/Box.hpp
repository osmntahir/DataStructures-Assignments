#ifndef BOX_HPP
#define BOX_HPP

#include "LinkedList.hpp"
class Box
{
private:
    /* data */
public:
    Box();
    
    LinkedList *LocationA;
    LinkedList *LocationB;
    Box * nextBox;

    ~Box();
};


#endif 
