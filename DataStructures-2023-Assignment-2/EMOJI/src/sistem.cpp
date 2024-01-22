/** 
* @file -->     sistem.cpp
* @description  Organları bir arada tutan ve organizma sınıfının 
                düğümünü temsil eden sistem sınıfının kaynak dosyası
* @course       2-C
* @assignment   2
* @date         14/12/2022 
* @author       Osman Tahir Özdemir osman.ozdemir3@ogr.sakarya.edu.tr
*/


#include "sistem.hpp"

sistem::sistem()
{
    ilkorgan = NULL;
    organsayisi = 0;
    sonraki = NULL;
}
void sistem::organyazdir()
{
    organ* gec = ilkorgan;
    while (gec!=0)
    {
        cout << "Organ : " << gec->ikiliagac->kok->veri << endl;
        gec = gec->sonraki;
    }
}
void sistem::organekle(organ* yeni)
{
    if (ilkorgan == NULL)
    {
        ilkorgan = yeni;
        organsayisi++;
        return;
    }


    organ* gec = ilkorgan;
    while (gec->sonraki != NULL)
    {
        gec = gec->sonraki;
    }
    gec->sonraki = yeni;
    organsayisi++;
  
}
sistem::~sistem()
{
    if (ilkorgan == NULL)
    {
        return;
    }
    organ* gec = ilkorgan;
    while (gec != 0)
    {
        organ* sil = gec;
        gec = gec->sonraki;
        delete sil;
    }
}