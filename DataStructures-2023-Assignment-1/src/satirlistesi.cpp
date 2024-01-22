/*
* satirlistesi.cpp
* Açıklama --> Satır listesi sınıfının içeriğinin doldurulması
* Öğretim türü ve ders grubu -- > 2-C
* 1.Ödev
* 14.11.2022 15.00
* Osman Tahir Özdemir  osman.ozdemir3@ogr.sakarya.edu.tr
*/
#include "satirlistesi.hpp"

satirlistesi::satirlistesi()
{
	// ilk satir dugumune 0 atama islemi
	ilk = 0;
}
// dugumleri yazdirirken araya cizgi ceken fonksiyon
void satirlistesi::satircizgicek(int sira)
{
	cout << endl;
	cout << setw((sira % 8) * 15) << "" << "---------- ";
	cout << endl;
}
// bir satirda kac tane sayi oldugunu gosteren fonksiyon
int satirlistesi::elemansayisi()
{
	int elemansayisi = 0;
	satirdugum* gec = ilk;
	while (gec!=0)
	{
		elemansayisi++;
		gec = gec->sonraki;

	}
	return elemansayisi;
}
// satir dugum donduren fonksiyon
satirdugum* satirlistesi::satirdugumGetir(int sira)
{
	satirdugum* gec = ilk;

	while (sira >= 0 && gec != 0)
	{

		if (sira == 0)
			return gec;
		gec = gec->sonraki;

		sira--;
	}
	return gec;
}
// satirdugumu silen fonksiyon
void satirlistesi::satirdugumCikar(int sira)
{
	satirdugum* silinecek = satirdugumGetir(sira);

	if (silinecek)
	{

		satirdugum* silinecekOnceki = silinecek->onceki;
		satirdugum* silinecekSonraki = silinecek->sonraki;

		if (silinecekSonraki)
			silinecekSonraki->onceki = silinecekOnceki;

		if (silinecekOnceki)
			silinecekOnceki->sonraki = silinecekSonraki;
		else
			ilk = silinecekSonraki;
		delete silinecek;
		satirdugumsayac--;
	}
}
// satir dugum yazdiran fonk
void satirlistesi::satirdugumYazdir(int sira)
{
	// ilk dugumun adresini gecici nesnesine atamak
	satirdugum* gecici = ilk;
	
	cout << setw((sira % 8) * 15) << "" << "^^^^^^^^^^" << setw(5) << " " << endl;
	

	while (gecici!=0)
	{
		cout << setw((sira % 8) * 15)<<""<<"|"<<setw(8) << gecici << "|";
		satircizgicek(sira);
		cout << setw((sira % 8) * 15) << "" << "|" << setw(8) << gecici->veri << "|";
		satircizgicek(sira);
		cout << setw((sira % 8) * 15) << "" << "|" << setw(8) << gecici->sonraki << "|";
		satircizgicek(sira);
		
		// bir sonraki dugume gecis yapmak
		gecici = gecici->sonraki;
		cout << endl;
	}
	
}
// okunan veriyi satir dugum olarak ekleyen fonksiyon
void satirlistesi::satirdugumEkle(int  veri)
{
	satirdugum* yeniDugum = new satirdugum(veri);
	if (ilk == 0)
	{
	ilk = yeniDugum;
	}
	else
	{
		satirdugum* gecici = ilk;

		while (gecici->sonraki != 0)
		{
			gecici = gecici->sonraki;
		}

		gecici->sonraki = yeniDugum;
		yeniDugum->onceki = gecici;
	}
	++satirdugumsayac;
}
// satir dugum sayan fonksiyon
int satirlistesi::satirdugumSayac()
{
	return satirdugumsayac;
}
// satir dugumlerin ortalamasini hesaplayan fonksiyon
float satirlistesi::ortalamaGetir()
{
	satirdugum* gec = ilk;
	float ortalama = 0;
	float toplam = 0;
	
	if (ilk == 0)
	{
		
		return toplam;
	}
	else
	{
		while (gec != 0)
		{
			
			toplam += gec->veri;
			gec = gec->sonraki;
		}
		return (toplam / satirdugumSayac());
		
	}

}
// satir listeinde dugum var mi yok mu sorgulayan fonksiyon
bool satirlistesi::bos_mu()
{
	if (ilk == 0)
	{
		return true;
	}

	return false;

}
// program biterken heapte olusan nesneleri serbest birakma islemi
satirlistesi::~satirlistesi()
{
	satirdugum* gec = ilk;
	while (gec != 0)
	{
		satirdugum* silinecek = gec;
		gec = gec->sonraki;

		delete silinecek;
	}
}