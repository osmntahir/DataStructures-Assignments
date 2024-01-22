/** 
* @file -->     agac.cpp
* @description  Dokuları tutan ikili arama ağacının sınıfının kaynak dosyası
* @course       2-C
* @assignment   2
* @date         15/12/2022 
* @author       Osman Tahir Özdemir osman.ozdemir3@ogr.sakarya.edu.tr
*/


#include "agac.hpp"

int agac::maxDerinlik(hucre* kok)
{
    if (kok == NULL || (kok->onceki == NULL && kok->sonraki == NULL))
        return 0;

    int solDerinlik = maxDerinlik(kok->onceki);
    int sagDerinlik = maxDerinlik(kok->sonraki);

    return solDerinlik > sagDerinlik ?
        solDerinlik + 1 : sagDerinlik + 1;
}

int agac::minDerinlik(hucre *kok)
{
    if (kok == NULL || (kok->onceki == NULL && kok->sonraki == NULL))
        return 0;

    int solDerinlik = minDerinlik(kok->onceki);
    int sagDerinlik = minDerinlik(kok->sonraki);

    return solDerinlik < sagDerinlik ?
        solDerinlik + 1 : sagDerinlik + 1;
}

bool agac::isBalanced(hucre* kok)
{
    if (maxDerinlik(kok) - minDerinlik(kok) <= 1)
        return true;
    else
        return false;
}
agac::agac()
{
    sayac = -1;
    kok = 0;
    elemansayisi = 0;
}

void agac::agacsil(hucre * kok)
 {
     if (kok==NULL)
       {
           return;
       }
       agacsil(kok->onceki);
       agacsil(kok->sonraki);
       free (kok);
            
 }

void agac::preorder(hucre* p) 
{
    if (p) 
    {
     
        preorder(p->onceki);
        preorder(p->sonraki);
        
    }
   
}
void  agac::postorder(hucre* p)
 {
    
    if (p) 
    {      
        postorder(p->onceki);
        postorder(p->sonraki);
        if (p->veri%2==0)
        {
            sayac++;
            dizi[sayac].veri=p->veri/2;
        }
        else  
        {
            sayac++;
            dizi[sayac].veri=p->veri;
        }
       
    }
     
        
}

void agac::ekle(hucre* eklenecek) {
    bool eklendi = false;
    hucre* tara; hucre* yeni = new hucre;
    tara = kok;
    
        *yeni = *eklenecek; yeni->onceki = NULL; yeni->sonraki = NULL;
    
    if (kok == NULL) {
        kok = yeni;
      //  cout << "Ilk eleman eklendi ! (" << kok->veri << ")" << endl;
        elemansayisi++;
        return;
    }
    while ((tara != NULL) && (!eklendi))
    {
        if (yeni->veri <= tara->veri)
        {
            if (tara->onceki != NULL) { tara = tara->onceki; }
            else
            {
            //   cout << tara->veri << " dugumunun soluna " << yeni->veri << " elemanini ekledim, sanirim :D" << endl;
                tara->onceki = yeni;
                eklendi = true;
            }
        }
        else if (yeni->veri > tara->veri)
        {
            if (tara->sonraki != NULL) tara = tara->sonraki;
            else
            {
             //  cout << tara->veri << " dugumunun sagina " << yeni->veri << " elemanini ekledim, sanirim :D " << endl;
                tara->sonraki = yeni;
                eklendi = true;
            }
        }
        else 
        {return; }
    }
    if (eklendi == true) { elemansayisi++; }
   /*  cout << "Eleman sayisi : " << elemansayisi << endl;
     cout << "Agac yuksekligi :" << agacyukseklik(kok) << endl;
     cout << "PREORDER :\t\t"; preorder(kok);
     cout << endl;
     cout << "INORDER :\t\t"; inorder(kok);
     cout << endl;
     cout << "POSTORDER :\t\t"; postorder(kok);
     cout << endl;
     cout << "Agac yukseklik farki " << yukseklikfarki(kok) << endl;
     cout << endl;*/

}

agac::~agac()
{
   agacsil(kok);
   delete[] dizi;
}