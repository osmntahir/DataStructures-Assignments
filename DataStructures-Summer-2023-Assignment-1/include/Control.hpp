#ifndef CONTROL_HPP
#define CONTROL_HPP
#include "ManagerList.hpp"

class Control
{
private:
 
public:
     ManagerList *manager;
    Control(/* args */);
    void ReadFile();
    void printAvarege();
    ~Control();
};
#endif 