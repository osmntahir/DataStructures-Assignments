#include "Kontrol.hpp"
#include <windows.h> 


Kontrol::Kontrol(/* args */)
{
    
}
void Kontrol::DosyayiOku()
{
      std::ifstream Reader("doc//Sayilar.txt");
    std::string a;
    int index = 0;

    // Dosya satır satır okunur
   
    while (getline(Reader, a))
    {
         Yigin *yeniYigin = new Yigin();
        this->yiginlar = new LinkedList <Yigin>();
        std::istringstream iss(a);
        std::string strnum;
        // Satırdaki her bir sayı işlenir
        while (getline(iss, strnum, ' '))
        {
            // Satırdaki her bir sayıyı tamsayıya dönüştürür
            int value = std::stoi(strnum);
            if (yeniYigin->BosMu())
            {
                yeniYigin->ekle(value);

            }
            else if(value % 2 ==0 && value > yeniYigin->getir())
            {
                yiginlar->ekle(yeniYigin);
                yeniYigin = new Yigin();
                yeniYigin->ekle(value);
            }   
            else{
                  yeniYigin->ekle(value);
                
            }
        }
        yiginlar->ekle(yeniYigin);
        YiginlardanAgaclariOlustur();
        Agac * enyuksek =enyuksekAgac();
        enyuksek->postorder(enyuksek->kok);
        cout << endl;
        Sleep(10); // 10 ms bekleme yapilir
       
        //std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    Reader.close();
}
void Kontrol::YiginlardanAgaclariOlustur()
{
    if(yiginlar == nullptr ) return;
    this->agaclar = new LinkedList <Agac>();
    Agac *yeniAgac ;

    for (int i = 0; i < yiginlar->dugumSayisi; i++)
    {
        yeniAgac = new Agac(); // her yigin icin bir agac olustur
        yeniAgac->id = i; // agacin olusma sirasina gore id ver
        while(!yiginlar->DugumGetir(i)->veri->BosMu())
        {
           int deger= yiginlar->DugumGetir(i)->veri->getir();
           Hucre *hucre = new Hucre();
           hucre->sayi = deger;
           yeniAgac->ekle(hucre);
           yiginlar->DugumGetir(i)->veri->cikar();
        }
        agaclar->ekle(yeniAgac);
      //cout << yiginlar->DugumGetir(i)->veri;
    }
}
 Agac* Kontrol::enyuksekAgac() {
    if (agaclar == nullptr) {
        return nullptr;
    }

    Agac* enyuksekagac = agaclar->DugumGetir(0)->veri;
    int highest_height = agaclar->DugumGetir(0)->veri->maxDerinlik(agaclar->DugumGetir(0)->veri->kok);
    int highest_sum = agaclar->DugumGetir(0)->veri->ToplamiBul();
    int YuksekId = agaclar->DugumGetir(0)->veri->id;

  //  cout << "\n\n\n\n " << highest_height  << "   " << highest_sum << "   " << endl;

    for (int i = 1; i < agaclar->dugumSayisi; ++i) {
        Agac* agac = agaclar->DugumGetir(i)->veri;
        int current_height = agac->maxDerinlik(agac->kok);
        int current_sum =  agac->ToplamiBul();
        int geciciId = agac->id;

        if (current_height > highest_height) {
            enyuksekagac = agac;
            highest_height = current_height;
            highest_sum = current_sum;
        } else if (current_height == highest_height) {
            if (current_sum > highest_sum) {
                enyuksekagac = agac;
                highest_sum = current_sum;
            }
            else if(current_sum == highest_sum)
            {   
              
            }
        }
    }
      return enyuksekagac;
}

Kontrol::~Kontrol()
{
    if(yiginlar != nullptr) delete yiginlar;
    if(agaclar != nullptr) delete agaclar;
}
/*
Her satır için, oluşan ikili arama
ağaçlarından en büyük yüksekliğe sahip ikili arama ağacı seçilecektir. Eğer yükseklikler eşit olursa
düğüm değerleri toplamı büyük olan ağaç seçilecektir. Toplam değerleri de eşit olan ağaçlardan önce
oluşturulan ağaç seçilecektir. Seçilen maksimum yüksekliğe sahip ikili arama ağacı postorder okunup
sayısal değerlerin ASCII karakter karşılıkları ekrana yazılıp ekranda 10 milisaniye beklenip*/