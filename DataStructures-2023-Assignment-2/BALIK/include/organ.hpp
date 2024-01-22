/** 
* @file -->     organ.hpp
* @description  İçinde ikili arama ağacı bulunduran ve sistem sınıfının düğümünü temsil eden organ sınıfı
* @course       2-C
* @assignment   2
* @date         14/12/2022 
* @author       Osman Tahir Özdemir osman.ozdemir3@ogr.sakarya.edu.tr
*/


#ifndef organ_hpp
#define organ_hpp

#include "agac.hpp"

class organ
{
public:
    organ();
    ~organ();
    agac* ikiliagac = new  agac;
    organ* sonraki;

private:

};

#endif
 
   