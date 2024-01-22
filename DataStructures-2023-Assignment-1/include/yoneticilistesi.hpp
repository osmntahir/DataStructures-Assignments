/*
* yöneticilistesi.cpp
* Açıklama --> Yonetici dugum ile ilgili islemleri yapan yonetici listesi sinifi
* Öğretim türü ve ders grubu -- > 2-C
* 1.Ödev
* 16.11.2022 9.00
* Osman Tahir Özdemir  osman.ozdemir3@ogr.sakarya.edu.tr
*/

#ifndef yoneticilistesi_hpp
#define yoneticilistesi_hpp

#include "yoneticidugum.hpp"

#include <Windows.h>


	class yoneticilistesi
{
public:
	yoneticilistesi();
	~yoneticilistesi();
	void yoneticidugumYazdir(int baslangic , int son);
	yoneticidugum* yoneticidugumGetir(int sira);
	void yoneticidugumleriniSirala();
	void yoneticidugumCikar(int sira);
	void yoneticidugumEkle(yoneticidugum*& yoneticidugumu);
	int randomsayi(int sira);
	bool bos_mu();
	void cizgicek(int sira);
	void silinecek(int x, int y);
private:
	yoneticidugum* ilk;
	
};
#endif