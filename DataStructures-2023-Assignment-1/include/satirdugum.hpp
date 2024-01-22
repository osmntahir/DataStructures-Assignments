/*
* satirdugum.hpp
* Açıklama --> satır dugum sınıfı
* Öğretim türü ve ders grubu -- > 2-C
* 1.Ödev
* 12.11.2022 9.00
* Osman Tahir Özdemir  osman.ozdemir3@ogr.sakarya.edu.tr
*/

#ifndef satirdugum_hpp
#define  satirdugum_hpp

#include <iostream>

class satirdugum
{
public:
	satirdugum(int veri);
	~satirdugum();
	int veri ;
	satirdugum* onceki ;
	satirdugum* sonraki ;

private:

};

#endif