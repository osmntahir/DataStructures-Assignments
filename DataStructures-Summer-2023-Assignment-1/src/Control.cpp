#include "Control.hpp"
#include <fstream>
#include <sstream>



Control::Control()
{
    manager = new ManagerList();
}
void Control::ReadFile()
{
    std::ifstream Read("doc//Numbers.txt");
    std::string a;
    int index = 0; 
    
    while (getline(Read, a))
    {    
            std::istringstream iss(a);
            std::string strnum;

          Box * currentBox = new Box();
       
                // her bir satiri temsil eder
                while (getline(iss, strnum, ' '))
                {
                  
                    // satirdaki her bir sayiyi temsil eder
                    int value = std::stoi(strnum);
                    // 10 lar basamagi Location A ya gidicek
                    int Tens = value /10;
                    // Birler basamagi Location B ye gidicek
                    int Ones = value %10;
                  Node * NodeTens = new Node(Tens);
                   currentBox->LocationA->InsertNode(NodeTens);
                  Node *NodeOnes = new Node(Ones);
                  currentBox->LocationB->InsertNode(NodeOnes);
             
                }

               
    manager->addBox(currentBox);
}
}
void Control::printAvarege()
{
 std::cout << "\n  avarage is in LocA :" <<  manager->calculateAvarageLocA() << "  \n";
  std::cout << "  avarage is in LocB :" <<  manager->calculateAvarageLocB() << "";
}
Control::~Control()
{
  delete manager;
}
