/** 
* @file -->     sistem.hpp
* @description  Organları bir arada tutan ve organizma sınıfının 
                düğümünü temsil eden sistem sınıfı
* @course       2-C
* @assignment   2
* @date         14/12/2022 
* @author       Osman Tahir Özdemir osman.ozdemir3@ogr.sakarya.edu.tr
*/


#ifndef sistem_hpp
#define sistem_hpp

#include "organ.hpp"

class sistem
{
public:

    void organekle(organ* yeni);
    void organyazdir();
    sistem();
    ~sistem();
    organ* ilkorgan;
    sistem* sonraki;
private:

    int organsayisi;
};

#endif