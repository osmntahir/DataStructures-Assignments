/*
* yöneticilistesi.cpp
* Açıklama --> Yönetici Listesi sınıfının içeriğinin doldurulması
* Öğretim türü ve ders grubu -- > 2-C
* 1.Ödev
* 16.11.2022 17.00
* Osman Tahir Özdemir  osman.ozdemir3@ogr.sakarya.edu.tr
*/


#include "yoneticilistesi.hpp"

// ilk dugume 0 atamak
yoneticilistesi::yoneticilistesi()
{
	ilk = NULL;
}
// yonetici dugumu var mi yok mu kontrol eden fonksiyon
bool yoneticilistesi::bos_mu()
{
	if (ilk==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
// random sayi ureten fonksiyon
int yoneticilistesi::randomsayi(int sira)
{
	
		int randomsayi ;
		// Yonetici dugumunun satir listesi nesnesi ile satir dugum sayisini elde etmek ve 
		// random sayi elde etmek
		
		randomsayi = rand() % yoneticidugumGetir(sira)->satirlistesinesnesi->satirdugumSayac();
		
		return randomsayi;
	
}
// yonetici dugumunu donduren fonksiyon
yoneticidugum* yoneticilistesi::yoneticidugumGetir(int sira)
{
	yoneticidugum* gec = ilk;

	while (sira >= 0 && gec != 0)
	{

		if (sira == 0)
			return gec;
		gec = gec->sonraki;

		sira--;
	}
	return gec;
}
// yonetici dugumunu silme
void yoneticilistesi::yoneticidugumCikar(int sira)
{
	yoneticidugum* silinecek = yoneticidugumGetir(sira);

	if (silinecek)
	{

		yoneticidugum* silinecekOnceki = silinecek->onceki;
		yoneticidugum* silinecekSonraki = silinecek->sonraki;

		if (silinecekSonraki)
			silinecekSonraki->onceki = silinecekOnceki;

		if (silinecekOnceki)
			silinecekOnceki->sonraki = silinecekSonraki;
		else
			ilk = silinecekSonraki;
		delete silinecek->satirlistesinesnesi;
		delete silinecek;
	}

}


// ekrana yazdirirken cizgi ceken fonksiyon
void yoneticilistesi::cizgicek(int sira)
{
	cout << endl;
	for (int  i = 0; i < sira; i++)
	{
		cout << "----------" << setw(5) << " ";
	}
	cout << endl;
		
}
// yonetici dugumlerini yazdiran fonksiyon
void yoneticilistesi::yoneticidugumYazdir(int baslangic, int son)
{
	
	yoneticidugum* gecici = yoneticidugumGetir(baslangic);
	

		if (gecici != 0)
		{	
			int sayac = 0;
			for (gecici ; gecici!= yoneticidugumGetir(son); gecici=gecici->sonraki )
			{
				cout << " " <<setw(8)<< gecici << " " << setw(5) << " " ;
				sayac++;
			
			}
			
			gecici = yoneticidugumGetir(baslangic);
			cizgicek(sayac);
			for (gecici; gecici != yoneticidugumGetir(son); gecici = gecici->sonraki)
			{
				cout << "|" <<setw(8)<<  gecici->onceki << "|" << setw(5) << " ";

			}
			//cout << endl;
			gecici = yoneticidugumGetir(baslangic);
			cizgicek(sayac);
			
			for (gecici; gecici != yoneticidugumGetir(son); gecici = gecici->sonraki)
			{
				cout << "|" << setw(8) << gecici->ortalama << "|" << setw(5) << " ";

			}
			//cout << endl;
			gecici = yoneticidugumGetir(baslangic);
			cizgicek(sayac);
			for (gecici; gecici != yoneticidugumGetir(son); gecici = gecici->sonraki)
			{
				cout << "|" << gecici->sonraki << "|" << setw(5) << " ";

			}
			//cout << endl;
			gecici = yoneticidugumGetir(baslangic);
			cizgicek(sayac);
			gecici = gecici->sonraki;
			
		}
		cout << endl;
}
// yonetici dugum ekleme fonksiyon
 void yoneticilistesi::yoneticidugumEkle(yoneticidugum* &yoneticidugumu)
{
	if (ilk ==0)
	{
		ilk = yoneticidugumu;
	}
	else
	{
		yoneticidugum* gecici = ilk;

		while (gecici->sonraki != 0)
		{
			gecici = gecici->sonraki;
		}

		gecici->sonraki = yoneticidugumu;
		yoneticidugumu->onceki = gecici;
	}
		
}
// heap den alinan yonetici dugumlerini serbest birakmak
 yoneticilistesi::~yoneticilistesi()
 {
	 yoneticidugum* gec = ilk;
	 while (gec != 0)
	 {
		 yoneticidugum* silinecek = gec;
		 gec = gec->sonraki;

		 delete silinecek->satirlistesinesnesi;
		 delete silinecek;
	 }
 }
// rastgele satir dugumu silinirken ekrana silinecek yazisi cikartan fonksiyon
  void yoneticilistesi::silinecek(int x, int y) {
	 COORD c;

	 c.X = (x*15)+12;
	 c.Y = 8+(7*y)+4;

	 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
 }