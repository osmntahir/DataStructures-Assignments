#ifndef DIGIT_HPP
#define DIGIT_HPP

#include<string.h>
#include <iostream>
using namespace std;
#include<iomanip>

class Digit
{
private:
public:
    Digit(int);
    Digit *nextDigit;
    int value;
    ~Digit();
};

#endif
