#ifndef FILEREADER_HPP
#define FILEREADER_HPP
#include "number.hpp"
#include "numberList.hpp"


#include <fstream>

class FileReader
{
private:
    numberList *numbers;
public:
    FileReader(/* args */);
    
    void ReadFile();
    void Start();
    ~FileReader();
};




#endif