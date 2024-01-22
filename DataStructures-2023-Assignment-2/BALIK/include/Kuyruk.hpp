/** 
* @file -->     Kuyruk.hpp
* @description  Radix sort için kullanılan Kuyruk sınıfı
* @course       2-C
* @assignment   2
* @date         13/12/2022 
* @author       Osman Tahir Özdemir osman.ozdemir3@ogr.sakarya.edu.tr
*/


#ifndef Kuyruk_hpp
#define Kuyruk_hpp

#include "Dugum.hpp"
#include "hucre.hpp"
#include <iomanip>

class Kuyruk
{
public:
	Kuyruk();
	~Kuyruk();
	void ekle(int veri);
	void cikar();
	bool bosmu();
	int getir();
	int elemanSayisiGetir();
	friend ostream& operator<<(ostream& os, Kuyruk& kuyruk);
private:
	Dugum* ilk;
	Dugum* son;
	int elemanSayisi;
};

#endif