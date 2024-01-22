/** 
* @file -->     organ.cpp
* @description  İçinde ikili arama ağacı bulunduran ve sistem sınıfın 
                düğümünü temsil eden organ sınıfının kaynak dosyası
* @course       2-C
* @assignment   2
* @date         14/12/2022 
* @author       Osman Tahir Özdemir osman.ozdemir3@ogr.sakarya.edu.tr
*/

#include "organ.hpp"
organ::organ()
{
    sonraki = NULL;
}

organ::~organ()
{
    delete ikiliagac;
  
}
