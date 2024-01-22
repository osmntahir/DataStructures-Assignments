/** 
* @file -->     kontrol.cpp
* @description  Dosya okuma , mutasyon ve organizmayı ekrana yazdıran kontrol sınıfının kaynak dosyası
* @course       2-C
* @assignment   2
* @date         18/12/2022 
* @author       Osman Tahir Özdemir osman.ozdemir3@ogr.sakarya.edu.tr
*/


#include "kontrol.hpp"
#include "Radix.hpp"
#include <fstream>
#include <sstream>

kontrol::kontrol()
{

}
kontrol::~kontrol()
{
    delete Organizma;
}
void kontrol::DosyaOku()
{
    std::ifstream Oku("doc//Veri.txt");
    std::string a;

    int index = 0; 
   
   sistem* Sistem =new sistem;
   organ* Organ = new organ;

    while (getline(Oku, a))
    {    
            std::istringstream iss(a);
            std::string strnum;
            int elemansayisi = 0;
            int sayilar[30];
            
                while (getline(iss, strnum, ' '))
                {
                    int veri = std::stoi(strnum);
                    //cout << veri <<" ";
                    sayilar[elemansayisi] = veri;
                    elemansayisi++;
                }
            Radix* radix = new Radix(sayilar, elemansayisi);
            int* siralanmissayilar = radix->sirala();

            doku* Doku = new doku;

            for (int i = 0; i < elemansayisi; i++)
            {
                hucre* Hucre = new hucre;
                Hucre->veri = siralanmissayilar[i];
                Doku->hucreekle(Hucre);
            }
           
            Organ->ikiliagac->ekle(Doku->ortadegergetir());

            ++index;
           
            if (Oku.eof())          
              {             
              
                Organizma->sistemekle(Sistem);
                Oku.close();
                break;            
            }
           
            if (index%2000==0)
            {             
               
                Organizma->sistemekle(Sistem);      
                Sistem = new sistem ;
             
            }
          
            if (index%20==0)
            {
               Sistem->organekle(Organ);  
               Organ=new organ;
            }
           }
    
}
void kontrol::mutasyon()
{
  
     sistem* gec = Organizma->ilksistem;
        while (gec != NULL)
        {
            organ* geciciorgan = gec->ilkorgan;
            while (geciciorgan != NULL)
            {
                if (geciciorgan->ikiliagac->kok->veri % 50 == 0)
                {
                    //mutasyon islemi     
                       
              
                     geciciorgan->ikiliagac->postorder(geciciorgan->ikiliagac->kok);
                 
                     geciciorgan->ikiliagac->agacsil(geciciorgan->ikiliagac->kok);
                     geciciorgan->ikiliagac->kok=NULL;
                        for (int i = 0; i < geciciorgan->ikiliagac->sayac; i++)
                        {   
                              hucre *Hucre = new hucre;                          
                              Hucre->veri= geciciorgan->ikiliagac->dizi[i].veri;
                              geciciorgan->ikiliagac->ekle(Hucre);                                                                      
                        }                
                              geciciorgan = geciciorgan->sonraki;
                  }
                else
                {
                geciciorgan = geciciorgan->sonraki;
                }
                
             
            }
          
            gec = gec->sonraki;
        }
}
void kontrol::Organizmayazdir() 
{   
            
    sistem* gec = Organizma->ilksistem;
        
    while (gec != NULL)
    {
        organ* geciciorgan = gec->ilkorgan;
        while (geciciorgan != 0)
        {

            if (geciciorgan->ikiliagac->isBalanced(geciciorgan->ikiliagac->kok))
            {
            cout << " ";
            }
            else
            {
                cout << "#";
            }
            geciciorgan = geciciorgan->sonraki;
            }         
            
            cout << endl;
            gec = gec->sonraki;
            }
        }
       
    