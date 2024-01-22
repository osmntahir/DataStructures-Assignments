/** 
* @file -->     Dugum.cpp
* @description  Kuyruk dugumlerini olusturan dugum sınıfının kaynak dosyası
* @course       2-C
* @assignment   2
* @date         13/12/2022 
* @author       Osman Tahir Özdemir osman.ozdemir3@ogr.sakarya.edu.tr
*/


#include "Dugum.hpp"

Dugum::Dugum(int veri)
{
    this->veri = veri;
    sonraki = 0;
}