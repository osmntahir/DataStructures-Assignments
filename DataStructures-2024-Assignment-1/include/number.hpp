#ifndef NUMBER_HPP
#define NUMBER_HPP


#include "digit.hpp"
class Number
{
private:
   Digit *firstDigit;
public:
    Number(/* args */);
    void addDigit(int);
    void printDigits();
    void printStars();
    void printAdress();
    void moveOddsToHead();
    void printValue();
    string stringOfNumber;
    int numberOfDigits;
    void reverseDigits();
    

    ~Number();
};






#endif