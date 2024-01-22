/** 
* @file -->     doku.cpp
* @description  Hücreleri bir arada tutan doku sınıfının kaynak dosyasıı
* @course       2-C
* @assignment   2
* @date         14/12/2022 
* @author       Osman Tahir Özdemir osman.ozdemir3@ogr.sakarya.edu.tr
*/


#include "doku.hpp"

doku::doku()
{
    ilk = NULL;
    hucresayisi = 0;
}
void doku::hucreyazdir()
{
    hucre* gec = ilk;

    while (gec != 0)
    {
        cout << gec->veri << "  ";
        gec = gec->sonraki;
    }
}
void doku::hucreekle(hucre* Hucre)
{
    if (ilk == 0)
    {
        ilk = Hucre;
        hucresayisi++;
        return;
    }
    hucre* gec = ilk;
    while (gec->sonraki != 0)
    {
        gec = gec->sonraki;
    }
    gec->sonraki = Hucre;
    hucresayisi++;
}
hucre* doku::ortadegergetir()
{

    int sira = hucresayisi / 2;
    int index = 0;

    hucre* gec = ilk;

    while (index < sira)
    {
        gec = gec->sonraki;
        index++;
    }
    return gec;
}

doku::~doku()
{
    if (ilk == 0)
    {
        return;
    }
    hucre* gec = ilk;
    while (gec != 0)
    {
        hucre* sil = gec;
        gec = gec->sonraki;
        delete sil;
    }
}