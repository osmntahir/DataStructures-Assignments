#ifndef NUMBERLIST_HPP
#define NUMBERLIST_HPP
#include "numberNode.hpp"


class numberList
{
private:
    numberNode * firstNumber;
  
public:
    numberList(/* args */);
    void addNumberNode(int);
    void printNumberNodes();
    void moveOddsToHead();
    void removeLargest();
    void reverseNodes();
    void printValue();
    int numberCounter;

    ~numberList();
};


#endif