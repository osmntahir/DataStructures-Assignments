#include "ManagerList.hpp"

ManagerList::ManagerList()
{
    firstBox = nullptr;
    boxCount = 0;
    fullboxCount = 0;
}
void ManagerList::swapLinkedList(int location1 , int location2)
{
    if(location1+1 >boxCount || location2+1 > boxCount)
    {
    std::cout<< " hatali location girdiniz !";
     return;
    }
    else
    {
    LinkedList * temp =getBox(location2)->LocationB;
    getBox(location2)->LocationB = getBox(location1)->LocationA;
    getBox(location1)->LocationA = temp;
       }

}
bool ManagerList::IsThereNodeInBoxesLocA(int index)
{
    Box* currentBox = firstBox;
    while(currentBox->nextBox !=nullptr)
    {
        if(currentBox->LocationA->getNode(index) != nullptr)
        {
            
            IsThereNode =true;
            return IsThereNode;
          
        }
        else
        {
             IsThereNode = false;
        }
        currentBox = currentBox->nextBox;
    }
 
    return IsThereNode;
}
int ManagerList::findFullBoxCount(int index)
{
     Box* currentBox = firstBox;
    while(currentBox !=nullptr)
    {
        if(currentBox->LocationA->getNode(index) != nullptr)
        {
           fullboxCount++;
        }
        currentBox = currentBox->nextBox;
    }
    return fullboxCount;

}
bool ManagerList::IsThereNodeInBoxesLocB(int index)
{
     Box* currentBox = firstBox;
    while(currentBox->nextBox !=nullptr)
    {
        if(currentBox->LocationB->getNode(index) != nullptr)
        {
            
            IsThereNode =true;
            return IsThereNode;
          
        }
        else
        {
             IsThereNode = false;
        }
        currentBox = currentBox->nextBox;
    }
 
    return IsThereNode;

}
double ManagerList::calculateAvarageLocA()
{
   
   if (firstBox == nullptr) return 0;

   Box* currentBox = firstBox;
   int index = 0;
   double sum = 0;
   double avarege=0;
 while (true)
 {
    
    if (!IsThereNodeInBoxesLocA(index))
    {
       break;
    }
    findFullBoxCount(index);
    currentBox = firstBox;
    while (currentBox !=nullptr)
    { 
        if (currentBox->LocationA->getNode(index) != nullptr)
        {
         
     //  std::cout << ""<< currentBox->LocationA->getNode(index)->data <<"";
           sum+=currentBox->LocationA->getNode(index)->data;
            currentBox = currentBox->nextBox;
        }
        else
        {
            
     //   std::cout << " ";
            currentBox = currentBox->nextBox;
        }
       
    }
  
    
 //std::cout << "\n\n sum : " << sum << "  full of box count : " << fullboxCount << "  \n\n";
    avarege +=  (sum/ fullboxCount);
   // std::cout << "avarege is : " << avarege << std::endl;
    sum=0;
    fullboxCount=0;
    currentBox = firstBox;
    index++;
 }
 
  return avarege ;
}
double ManagerList::calculateAvarageLocB()
{

 if (firstBox == nullptr) return 0;


Box* currentBox = firstBox;
   int index = 0;
   double sum = 0;
   double avarege=0;
 while (true)
 {
    
    if (!IsThereNodeInBoxesLocB(index))
    {
       break;
    }
    findFullBoxCount(index);
    currentBox = firstBox;
    while (currentBox !=nullptr)
    { 
        if (currentBox->LocationB->getNode(index) != nullptr)
        {
         
        //    std::cout << "|"<< currentBox->LocationB->getNode(index)->data <<"|";
           sum+=currentBox->LocationB->getNode(index)->data;
            currentBox = currentBox->nextBox;
        }
        else
        {
            
      //   std::cout << "   ";
            currentBox = currentBox->nextBox;
        }
       
    }
// std::cout << " sum : " << sum << "  box count : " << fullboxCount << "  ";
    avarege +=  (sum/fullboxCount);
 //  std::cout << "avarege is : " << avarege << std::endl;
    sum=0;
    fullboxCount=0;
    currentBox = firstBox;
    index++;
 }
 
  return avarege ;
}
  

void ManagerList::addBox(Box* newBox)
{
    if (firstBox == nullptr)
    {
        firstBox = newBox;
        boxCount++;
    }
    else
    {
        Box * currentBox = firstBox;
        while (currentBox->nextBox !=nullptr)
        {
            currentBox = currentBox->nextBox;
        }
        currentBox->nextBox=newBox;
        
       boxCount++;
    }
    
}
  Box * ManagerList::getBox(int index)
  {
    if(index+1 > boxCount) return nullptr; 


    Box* current = firstBox;
	while (index >= 0 && current != nullptr)
	{

		if (index == 0) return current;
			
		current = current->nextBox;

		index--;
	}
	return current;
}

ManagerList::~ManagerList()
{
    if(firstBox == nullptr) return;

    Box* currentBox = firstBox;
	 while (currentBox != nullptr)
	 {
		 Box* deletedBox = currentBox;
		 currentBox = currentBox->nextBox;
		 delete deletedBox;
	 }
}
