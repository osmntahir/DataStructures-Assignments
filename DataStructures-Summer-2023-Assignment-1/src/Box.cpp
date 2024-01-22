#include "Box.hpp"

Box::Box()
{   LocationA = new LinkedList();
    LocationB = new LinkedList();
    nextBox =nullptr;
}

Box::~Box()
{
  if (LocationA != nullptr) delete LocationA;
  if(LocationB != nullptr) delete LocationB;
}
