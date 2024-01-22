/** 
* @file -->     Kuyruk.cpp
* @description  Radix sort için kullanılan kuyruk sınıfının kaynak dosyası
* @course       2-C
* @assignment   2
* @date         13/12/2022 
* @author       Osman Tahir Özdemir osman.ozdemir3@ogr.sakarya.edu.tr
*/


#include "Kuyruk.hpp"

Kuyruk::Kuyruk()
{
    ilk = son = 0;
    elemanSayisi = 0;
}
Kuyruk::~Kuyruk()
{
    while (ilk != 0)
    {
        Dugum* gec = ilk;
        ilk = ilk->sonraki;
        delete gec;
    }
}
bool Kuyruk::bosmu()
{
    if (ilk == 0)
        return true;
    return false;
}

void Kuyruk::ekle(int veri)
{
    if (ilk == 0)
    {
        ilk = new Dugum(veri);
        son = ilk;

    }
    else
    {
        Dugum* yeni = new Dugum(veri);
        son->sonraki = yeni;
        son = yeni;

    }
    elemanSayisi++;
}
void Kuyruk::cikar()
{
    if (ilk != 0)
    {
        Dugum* gec = ilk->sonraki;
        delete ilk;
        ilk = gec;
        if (ilk == 0)
            son = 0;
        elemanSayisi--;
    }
}
int Kuyruk::getir()
{
    if (ilk != 0)
        return ilk->veri;
    throw std::out_of_range("Kuyruk Bos");
}

int Kuyruk::elemanSayisiGetir()
{
    return elemanSayisi;
}
ostream& operator<<(ostream& os, Kuyruk& kuyruk)
{
    if (kuyruk.ilk == 0)
        os << "----KUYRUK BOS----";
    Dugum* gec = kuyruk.ilk;
    while (gec != 0)
    {
        os << setw(5) << gec->veri;
        gec = gec->sonraki;
    }

    os << endl;
    return os;
}
