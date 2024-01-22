/*
* satirlistesi.hpp
* Açıklama --> satır dugumlerı ile ilgili islemleri yaptigim satir listesi sinifi
* Öğretim türü ve ders grubu -- > 2-C
* 1.Ödev
* 13.11.2022 9.00
* Osman Tahir Özdemir  osman.ozdemir3@ogr.sakarya.edu.tr
*/


#ifndef satirlistesi_hpp
#define  satirlistesi_hpp

#include <iomanip>
#include <iostream>
using namespace std;

#include "satirdugum.hpp"
class satirlistesi
{
public:
	satirlistesi();
	~satirlistesi();
	
	bool bos_mu();
	void satirdugumEkle(int  veri);
	void satirdugumCikar(int sira);
	//satirdugum* satirdugumGetir();
	int satirdugumSayac();
	void satirdugumYazdir(int sira);
	float ortalamaGetir();
	satirdugum* satirdugumGetir(int sira);
	int elemansayisi();
	void satircizgicek(int sira);

private:
	satirdugum* ilk;
	int satirdugumsayac = 0;
	

};

#endif