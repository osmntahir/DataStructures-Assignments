/** 
* @file -->     Radıx.hpp
* @description  Sayıları küçükten büyüğe sıralamak için kullanılan Radix sınıfı
* @course       2-C
* @assignment   2
* @date         13/12/2022 
* @author       Osman Tahir Özdemir osman.ozdemir3@ogr.sakarya.edu.tr
*/


#ifndef Radix_hpp
#define Radix_hpp

#include "Kuyruk.hpp"

class Radix
{
public:
	Radix(int* sayilar, int adet);
	~Radix();
	int* sirala();

private:
	int     maxBasamakSayisiGetir();
	int     basamakSayisiGetir(int sayi);
	void    kuyrukUzunluklariGetir(int* uzunluklar);
	void 	kuyruklariYazdir();
	Kuyruk** kuyruklar;
	int* sayilar;
	int     sayiAdedi;
};

#endif