#ifndef MANAGERLIST_HPP
#define MANAGERLIST_HPP

#include "Box.hpp"

class ManagerList
{
private:
    Box * firstBox;
    int boxCount;
    bool IsThereNode;
    int fullboxCount;
    int findFullBoxCount(int index);
public:
    ManagerList(/* args */);
    void addBox(Box *newBox);
    Box * getBox(int index);
    double calculateAvarageLocA();
    double calculateAvarageLocB();
    bool IsThereNodeInBoxesLocA(int);
    bool IsThereNodeInBoxesLocB(int);
    void swapLinkedList(int location1 , int location2);
    ~ManagerList();
};




#endif 
