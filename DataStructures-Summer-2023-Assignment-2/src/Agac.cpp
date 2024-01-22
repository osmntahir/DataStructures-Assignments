#include "Agac.hpp"

Agac::Agac(/* args */)
{
     kok = NULL;
     this->id =0;
     this->toplam = 0;
    elemansayisi = 0;
   // cout << "Agac olusturuldu ;) " <<endl;
}
 
int Agac::ToplamiBul()
{
   return Toplam(kok);
}
int Agac::Toplam(Hucre * kok)
{
    if (kok == nullptr) {
        return 0;
    }

    int leftSubtreeSum = Toplam(kok->sol);
    int rightSubtreeSum = Toplam(kok->sag);

    // root düğümündeki veriyi dahil ederek alt ağaçlardaki verilerin toplamını hesapla
    return kok->sayi + leftSubtreeSum + rightSubtreeSum;
}
void Agac::postorder(Hucre *p){
    if(p){
        postorder(p->sol);
        postorder(p->sag);
        char asciiValue = static_cast<char>(p->sayi);
        std::cout << asciiValue << "   " ;
    }
}

  
void Agac::ekle(Hucre *eklenecek){
    bool eklendi = false;
    Hucre *tara; Hucre *yeni = new Hucre;
    tara = kok;
    *yeni = *eklenecek; yeni->sol = NULL; yeni->sag = NULL;
  
    if(kok == NULL){
        kok = yeni;
      //  cout << "Ilk eleman eklendi ! (" << kok->sayi << ")"<<endl;
        elemansayisi++;
        return;
    }
    while((tara != NULL) && (!eklendi))
    {
        if( yeni->sayi < tara->sayi)
        {
            if(tara->sol != NULL) { tara = tara->sol; }
            else
            {
           //     cout << tara->sayi << " dugumunun soluna " << yeni->sayi << " elemanini ekledim, sanirim :D" << endl;
                tara->sol = yeni;
                eklendi = true;
            }
        }
        else if ( yeni->sayi > tara->sayi)
        {
          if(tara->sag != NULL) tara = tara->sag;
          else
          {
         //     cout << tara->sayi << " dugumunun sagina " << yeni->sayi << " elemanini ekledim, sanirim :D " << endl;
              tara->sag = yeni;
              eklendi = true;
          }
        }else { 
           // cout << "Kopya" << endl;  
            return;}
    }
    if(eklendi == true) { elemansayisi++; }
   // cout << "Eleman sayisi : " << elemansayisi  << endl  ;
   
   // cout << "POSTORDER :\t\t"; postorder(kok);
   // cout << endl;
}
int Agac::maxDerinlik(Hucre* kok)
{
    if (kok == NULL || (kok->sol == NULL && kok->sag == NULL))
        return 0;

    int solDerinlik = maxDerinlik(kok->sol);
    int sagDerinlik = maxDerinlik(kok->sag);

    return solDerinlik > sagDerinlik ?
        solDerinlik + 1 : sagDerinlik + 1;
}

 void Agac::AgaclariSil(Hucre *p)
 {
   if (kok == nullptr) {
        return;
    }

    // Önce sol alt ağacı sil
    AgaclariSil(p->sol);
    // Sonra sağ alt ağacı sil
    AgaclariSil(p->sag);
    // Düğümü siliyoruz
    delete p;
 }
Agac::~Agac()
{
    AgaclariSil(kok);
}
