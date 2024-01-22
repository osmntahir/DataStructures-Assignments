/** 
* @file -->     organizma.cpp
* @description  Sistemleri bir arada tutan organizma sınıfının kaynak dosyası
* @course       2-C
* @assignment   2
* @date         14/12/2022 
* @author       Osman Tahir Özdemir osman.ozdemir3@ogr.sakarya.edu.tr
*/


#include "organizma.hpp"

organizma::organizma()
{
    ilksistem = NULL;
}
void organizma::sistemekle(sistem* yeni)
{
    if (ilksistem == NULL)
    {
        ilksistem = yeni;
        return;
    }
    sistem* gec = ilksistem;
    while (gec->sonraki != NULL)
    {
        gec = gec->sonraki;
    }
    gec->sonraki = yeni;
}

organizma::~organizma()
{
    if (ilksistem==NULL)
    {
        return;
    }
    sistem* gec = ilksistem;
    while (gec!=0)
    {
        sistem* sil = gec;
        gec = gec->sonraki;
        delete sil;
    }
}