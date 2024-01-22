/** 
* @file -->     organizma.hpp
* @description  Sistemleri bir arada tekli bağlı liste ile tutan organizma sınıfı
* @course       2-C
* @assignment   2
* @date         14/12/2022 
* @author       Osman Tahir Özdemir osman.ozdemir3@ogr.sakarya.edu.tr
*/


#ifndef organizma_hpp
#define organizma_hpp

#include "sistem.hpp"

class organizma
{
public:
    organizma();
    ~organizma();
    sistem* ilksistem = new sistem;
    void sistemekle(sistem* yeni);
 
private:

};

#endif