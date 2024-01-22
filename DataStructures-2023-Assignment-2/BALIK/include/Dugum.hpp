/** 
* @file -->     Dugum.hpp
* @description  Kuyruk dugumlerını olusturan dugum sınıfı
* @course       2-C
* @assignment   2
* @date         13/12/2022 
* @author       Osman Tahir Özdemir osman.ozdemir3@ogr.sakarya.edu.tr
*/

#ifndef Dugum_hpp
#define Dugum_hpp

class Dugum
{
public:
	Dugum(int veri);
	int veri;
	Dugum* sonraki;
};

#endif