/** 
* @file --> numberList.cpp
* @description --> numberNode'ları (düğümleri) bir arada tutan tekli bağlı liste
* @assignment 1
* @date 29/10/2023
* @author OSMAN TAHİR ÖZDEMİR  osman.ozdemir3@ogr.sakarya.edu.tr
*/
#include <string>
#include "numberList.hpp"

// numberList sınıfının yapıcı fonksiyonu
numberList::numberList(/* args */)
{
    this->firstNumber = nullptr;
    this->numberCounter = 0;
}

// Yeni bir NumberNode ekleyen fonksiyon
void numberList::addNumberNode(int value) {
   
    numberNode* newNode = new numberNode(value); 
    newNode->number = new Number();
    int currentNumber = value;
    while (currentNumber >= 0) {
        int digit = currentNumber % 10; // Son basamağı al
        newNode->number->addDigit(digit);
        currentNumber /= 10; // Bir basamak sağa kaydır
        // 0 ı da dahil etmek için bu yapıyı kullandım
        if(currentNumber ==0)
        {
            break;
        }
    }

    if (firstNumber == nullptr) {
        firstNumber = newNode;
        return;
    }

    numberNode* current = firstNumber;
    while (current->nextNode != nullptr) {
        current = current->nextNode;
    }
    current->nextNode = newNode;
    numberCounter++;
}

// numberList sınıfının en büyük değeri çıkaran fonksiyonu
void numberList::removeLargest() {
    if (!firstNumber) {
        std::cout << "\n LISTE BOS \n" << std::endl;
        return;
    }

    numberNode* current = firstNumber;
    numberNode* prev = nullptr;
    numberNode* largest = firstNumber;
    numberNode* prevOfLargest = nullptr;

    // Liste içinde en büyük düğümü bulmak için liste üzerinde dolaş
    while (current) {
        if (current->value > largest->value) {
            largest = current;
            prevOfLargest = prev;
        }
        prev = current;
        current = current->nextNode;
    }

    // Eğer en büyük düğüm ilk düğümse
    if (prevOfLargest == nullptr) {
        firstNumber = largest->nextNode;
    } else {
        prevOfLargest->nextNode = largest->nextNode;
    }

    // En büyük düğümü bellekten serbest bırakmak için silelim
    delete largest;
}


/* numberListdeki düğümleri gezerek sayı tekli bağlı listeye erişip basamakları
tersle fonksıyonunu cagırır */ 

void numberList::reverseNodes()
{

    if (!firstNumber) {
        std::cout << "\n LISTE BOS \n" << std::endl;
        return;
    }

    for (numberNode* i = firstNumber; i != nullptr; i = i->nextNode) {
   
        i->number->reverseDigits();
         i->value=std::stoi(i->number->stringOfNumber) ;
    }
}


/* numberListdeki düğümleri gezerek sayı tekli bağlı listeye erişip tekli basamakları
başa alan fonksıyonunu cagırır */ 
void numberList::moveOddsToHead()
{   if (!firstNumber) {
        std::cout << "\n LISTE BOS \n" << std::endl;
        return;
    }
    for (numberNode* i = firstNumber; i != nullptr; i = i->nextNode) {
        
        i->number->moveOddsToHead();
        i->value=std::stoi(i->number->stringOfNumber) ;
    }
}

// numberList sınıfının düğümlerini ekrana basan fonksiyon
void numberList::printNumberNodes()
{
    if (firstNumber == nullptr) {
      
        return;
    }

    numberNode* current = firstNumber;
    for (current; current != nullptr; current = current->nextNode) {
        cout << "############     ";
        current->number->printStars();
        cout << endl;
        cout << "#" << setw(10) << current->number << "#     ";
        current->number->printAdress();
        cout << "\n";
        cout << "#----------#     ";
        current->number->printStars();
        cout << endl;
        cout << "#" << setw(10) << std::dec << current->value << "#     ";
        current->number->printValue();
        cout << endl;
        cout << "############     ";
        current->number->printStars();
        cout << endl;

        cout << endl << endl;
    }
}

// numberList sınıfının yıkıcı fonksiyonu
numberList::~numberList()
{
    numberNode* current = firstNumber;

    while (current != nullptr) {
        numberNode* toBeDeleted = current;

        current = current->nextNode;
        
        // numberNode sınıfındaki Number nesnesini sil.
        delete toBeDeleted->number;
        
        delete toBeDeleted;
    }
}
