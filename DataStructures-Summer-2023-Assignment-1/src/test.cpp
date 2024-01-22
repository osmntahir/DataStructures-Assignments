
#include "Control.hpp"
#include "Box.hpp"
#include "LinkedList.hpp"
#include "ManagerList.hpp"
#include "Node.hpp"

int main()
{
    Control * control = new Control();
    control->ReadFile();
    int loc1;
    int loc2;
    cout << "enter the index of LocationA that you want to change ";
    cin >> loc1;
    cout << "enter the index of LocationB that you want to change ";
    cin >> loc2;
    control->manager->swapLinkedList(loc1,loc2);
    control->printAvarege();
    cout << "\n\n hello world \n\n";
     std::cout << "Press Enter to exit.";
    std::cin.ignore(); // Ignore any previous input
    std::cin.get(); // Wait for the user to press Enter
}