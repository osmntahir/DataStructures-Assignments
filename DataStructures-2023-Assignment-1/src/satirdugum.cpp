
/*
* satirdugum.cpp
* Açıklama --> satır dugum sınıfı
* Öğretim türü ve ders grubu -- > 2-C
* 1.Ödev
* 12.11.2022 9.00
* Osman Tahir Özdemir  osman.ozdemir3@ogr.sakarya.edu.tr
*/
#include "satirdugum.hpp"

satirdugum::satirdugum(int veri)
{
	this->veri = veri;
	this->onceki= NULL;
	this->sonraki=NULL;
}

satirdugum::~satirdugum()
{
	
}
