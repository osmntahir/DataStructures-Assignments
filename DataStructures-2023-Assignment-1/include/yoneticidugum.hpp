/*
* yoneticidugum.hpp
* Açıklama --> Satir listelerini icinde barindiran yonetici dugum sinifi
* Öğretim türü ve ders grubu -- > 2-C
* 1.Ödev
* 13.11.2022 9.00
* Osman Tahir Özdemir  osman.ozdemir3@ogr.sakarya.edu.tr
*/

#ifndef yoneticidugum_hpp
#define yoneticidugum_hpp

#include "satirlistesi.hpp"

class yoneticidugum
{
public:
	satirlistesi* satirlistesinesnesi = new satirlistesi(); // satir listesi nesnesi
	yoneticidugum* onceki = NULL;
	yoneticidugum* sonraki = NULL;
	float ortalama ;
private:
	
};


#endif