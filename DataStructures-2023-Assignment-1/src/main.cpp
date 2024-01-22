/** 
* main.cpp
* Açıklama --> Dosya okuma , yönetici ve satır düğümleri eklemek.İstenilen durumları gerçekleştirmek(düğümleri gezmek,silmek gibi)
* Öğretim türü ve ders grubu -- > 2-C
* 1.Ödev
* 18.11.2022 9.00
* Osman Tahir Özdemir  osman.ozdemir3@ogr.sakarya.edu.tr
*/

#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>

#include <ctime>
#include <conio.h>

#include "satirlistesi.hpp"
#include "yoneticilistesi.hpp"
#include "satirdugum.hpp"
#include "yoneticidugum.hpp"


std::string str;
using std::ifstream;
using std::string;
using std::getline;


 int main()
 {
	 // yonetici listesi nesnesi olusturma
	 yoneticilistesi* yoneticilistesinidoldur = new yoneticilistesi();

	//satir sayisini tutan degisken
	 int satirsayisi = 0;
	 ifstream dosya;

	 // dosya acma islemi
	 dosya.open("veriler.txt");
	 std::string token;
	 std::ifstream file("veriler.txt");
	 std::string str;
	// dosyanin satirlarini gezen while dongusu
	 while (std::getline(file, token)) {
		 std::istringstream ss(token);

		// her satirda bir yonetici dugumu olusturup yonetici listesine ekleme
		 yoneticidugum* yoneticidugumu = new yoneticidugum();
		 yoneticilistesinidoldur->yoneticidugumEkle(yoneticidugumu);

		// satirdaki verileri okuyan while dongusu
		 while (std::getline(ss, str, ' '))
		 {
			 int veri;
			 dosya >> veri;
				// okunan verileri satirlistesinin nesnesine satir dugumleri olarak ekleme
			 yoneticidugumu->satirlistesinesnesi->satirdugumEkle(veri);


		 }
		 // satir dugumlerinin ortalamasini hesaplama
		 yoneticidugumu->ortalama = yoneticidugumu->satirlistesinesnesi->ortalamaGetir();
		 satirsayisi++;
	 }
	// dosyalari kapatma
	 file.close();
	 dosya.close();


	 char secim;
	 int sira = 0;
	 // random sayi uretmek
	 int cikar = yoneticilistesinidoldur->randomsayi(sira);


	 int sayac = 0;

		// ekrana yazdirmak icin baslangic ve son indeksi
	 int baslangic = 0;
	 int son = 8;
	
	 system("CLS");

	 yoneticilistesinidoldur->yoneticidugumYazdir(baslangic, son);

	 yoneticilistesinidoldur->yoneticidugumGetir(sira)->satirlistesinesnesi
	 ->satirdugumYazdir(sira);

	  do
	 {
		 cin >> secim;

		 if (secim == 'c')
		 {
			 if (sira < son - 2)
			 {

				 if (yoneticilistesinidoldur->yoneticidugumGetir(sira+1))
				 {
					 sira++;
					 system("CLS");
					 yoneticilistesinidoldur->yoneticidugumYazdir(baslangic, son);
					 yoneticilistesinidoldur->yoneticidugumGetir(sira)
					 ->satirlistesinesnesi->satirdugumYazdir(sira);
				 }
				 else
				 {
					 system("CLS");
					 yoneticilistesinidoldur->yoneticidugumYazdir(baslangic, son);
					 yoneticilistesinidoldur->yoneticidugumGetir(sira)->
					 satirlistesinesnesi->satirdugumYazdir(sira);
				 }	 
				 sayac = 0;
			 }
			 
			 else
			 {
				 sira = son - 1;
				 system("CLS");
				 yoneticilistesinidoldur->yoneticidugumYazdir(baslangic, son);
				 yoneticilistesinidoldur->yoneticidugumGetir(sira)->satirlistesinesnesi->satirdugumYazdir(sira);
				 sayac = 0;
			 }
		 }
		 else if (secim == 'z')
		 {
			 if (sira > baslangic)
			 {
				 sira--;

				 system("CLS");
				 yoneticilistesinidoldur->yoneticidugumYazdir(baslangic, son);
				 yoneticilistesinidoldur->yoneticidugumGetir(sira)->satirlistesinesnesi->satirdugumYazdir(sira);
				 sayac = 0;
			 }
			 else
			 {
				 sira = baslangic;
				 system("CLS");
				 yoneticilistesinidoldur->yoneticidugumYazdir(baslangic, son);
				 yoneticilistesinidoldur->yoneticidugumGetir(sira)->satirlistesinesnesi->satirdugumYazdir(sira);
				 sayac = 0;
			 }

		 }
		 else if (secim == 'p')
		 {
			 if (yoneticilistesinidoldur->bos_mu())
			 {
				 cout << "Yonetici Dugumu Kalmadi";
			 }
			 else
			 {
					 if (yoneticilistesinidoldur->yoneticidugumGetir(sira+1))
					 {
						 yoneticilistesinidoldur->yoneticidugumCikar(sira);
						 system("CLS");
						 yoneticilistesinidoldur->yoneticidugumYazdir(baslangic, son);
						 yoneticilistesinidoldur->yoneticidugumGetir(sira)->satirlistesinesnesi->
						 satirdugumYazdir(sira);
					 }
					 else
					 {
							 yoneticilistesinidoldur->yoneticidugumCikar(sira);
							 system("CLS");
						
							 
							 if (yoneticilistesinidoldur->bos_mu())
							 {
								 cout << "yonetici dugumu kalmadi";
							 }
							 else
							 {
								 sira--;
								 if (sira< baslangic)
								 {	
									 baslangic -= 8;
									 son -= 8;
									 yoneticilistesinidoldur->yoneticidugumYazdir(baslangic, son);
									 yoneticilistesinidoldur->yoneticidugumGetir(sira)->
									 satirlistesinesnesi->satirdugumYazdir(sira);
								 }
								 else
								 {
									 yoneticilistesinidoldur->yoneticidugumYazdir(baslangic, son);
									 yoneticilistesinidoldur->yoneticidugumGetir(sira)->
									 satirlistesinesnesi->satirdugumYazdir(sira);
								 }
								 }	
					 }
			 }
		 }
		 else if (secim == 'a')
		 {
			 
					 baslangic -= 8;
					 son -= 8;
					 sira -= 8;

					 if (baslangic<0)
					 {
						 baslangic += 8; 
						 son += 8;
						 sira += 8;
						 system("CLS");
						 yoneticilistesinidoldur->yoneticidugumYazdir(baslangic, son);
						 yoneticilistesinidoldur->yoneticidugumGetir(sira)->satirlistesinesnesi->
						 satirdugumYazdir(sira);
					 }
					 else
					 {
						 system("CLS");
						 yoneticilistesinidoldur->yoneticidugumYazdir(baslangic, son);
						 yoneticilistesinidoldur->yoneticidugumGetir(sira)->satirlistesinesnesi->
						 satirdugumYazdir(sira);
					 }

		 }
		 else if (secim == 'd')
		 {
				baslangic += 8;
				son += 8;
				sira += 8;

				if (baslangic > satirsayisi)
				{
					baslangic -= 8;
					son -=8;
					sira -= 8;

					system("CLS");
					yoneticilistesinidoldur->yoneticidugumYazdir(baslangic, son);
					yoneticilistesinidoldur->yoneticidugumGetir(sira)->satirlistesinesnesi->
					satirdugumYazdir(sira);
				}
				else
				{
					system("CLS");
					if (yoneticilistesinidoldur->yoneticidugumGetir(sira))
					{
						yoneticilistesinidoldur->yoneticidugumYazdir(baslangic, son);
						yoneticilistesinidoldur->yoneticidugumGetir(sira)->satirlistesinesnesi->
						satirdugumYazdir(sira);
					}
					else
					{
						baslangic -= 8;
						son -= 8;
						sira -= 8;

						system("CLS");
						yoneticilistesinidoldur->yoneticidugumYazdir(baslangic, son);
						yoneticilistesinidoldur->yoneticidugumGetir(sira)->satirlistesinesnesi->
						satirdugumYazdir(sira);
					}
				}
		 }
		 else if (secim == 'k')
		 {	
			 sayac++;
			 if (sayac==1)
			 {
				 yoneticilistesinidoldur->silinecek(sira%8, yoneticilistesinidoldur->randomsayi(sira));
				  cout << "<----- silinecek";
				 yoneticilistesinidoldur->silinecek(0, 4);
			 }
			 if (sayac==2)
			 {
					 if (yoneticilistesinidoldur->yoneticidugumGetir(sira)->
					 satirlistesinesnesi->satirdugumSayac()==1)
					 {	
						if (yoneticilistesinidoldur->yoneticidugumGetir(sira+1))
						{
							 yoneticilistesinidoldur->yoneticidugumCikar(sira);

						 system("CLS");
						 yoneticilistesinidoldur->yoneticidugumYazdir(baslangic, son);
						 yoneticilistesinidoldur->yoneticidugumGetir(sira)->
						 satirlistesinesnesi->satirdugumYazdir(sira);
						 sayac = 0;
						}
						else
						{
							yoneticilistesinidoldur->yoneticidugumCikar(sira);
							 if (yoneticilistesinidoldur->bos_mu())
							 {
								 cout << "yonetici dugumu kalmadi";
							 }
							 else
							 {
								 sira--;
								 if (sira< baslangic)
								 {	
									 baslangic -= 8;
									 son -= 8;
									  system("CLS");
									 yoneticilistesinidoldur->yoneticidugumYazdir(baslangic, son);
									 yoneticilistesinidoldur->yoneticidugumGetir(sira)->
									 satirlistesinesnesi->satirdugumYazdir(sira);
								 }
								 else
								 {
									 system("CLS");
									 yoneticilistesinidoldur->yoneticidugumYazdir(baslangic, son);
									 yoneticilistesinidoldur->yoneticidugumGetir(sira)->
									 satirlistesinesnesi->satirdugumYazdir(sira);
								 }
							 }
							 sayac = 0;
						}
					 }
					 else {
						 yoneticilistesinidoldur->yoneticidugumGetir(sira)->satirlistesinesnesi->
						 satirdugumCikar(cikar);

						 yoneticilistesinidoldur->yoneticidugumGetir(sira)->ortalama
							 = yoneticilistesinidoldur->yoneticidugumGetir(sira)->satirlistesinesnesi->
							 ortalamaGetir();

						 system("CLS");
						 yoneticilistesinidoldur->yoneticidugumYazdir(baslangic, son);
						 yoneticilistesinidoldur->yoneticidugumGetir(sira)->satirlistesinesnesi->
						 satirdugumYazdir(sira);
						 sayac = 0;
					 }
			 }
		 }
	 } while (secim != 'q');
	 delete yoneticilistesinidoldur;
	 
 }
	 