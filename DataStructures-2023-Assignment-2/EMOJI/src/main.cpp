/** 
* @file -->     main.cpp
* @description  yazılan kodları ve yapılan işlemleri test eden Test Programı
* @course       2-C
* @assignment   2
* @date         18/12/2022 
* @author       Osman Tahir Özdemir osman.ozdemir3@ogr.sakarya.edu.tr
*/

#include "agac.hpp"
#include "doku.hpp"
#include "Dugum.hpp"
#include "hucre.hpp"
#include "Kuyruk.hpp"
#include "organ.hpp"
#include "organizma.hpp"
#include "Radix.hpp"
#include "sistem.hpp"
#include "Kontrol.hpp"


int main()
{  
  kontrol *Kontrol = new kontrol;
  
  Kontrol->DosyaOku();
  system("cls");
  
  cout << "                 ORGANIZMA " << endl ;
  Kontrol->Organizmayazdir();  
  do
  {
      if (cin.ignore())
      {
        system("cls");
        Kontrol->mutasyon();
        cout << "                 ORGANIZMA (MUTASYONA UGRADI)  " << endl ;
        Kontrol->Organizmayazdir();
        break;
      }
      else 
      {
          cout << "ENTER TUSUNDAN FARKLI BIR TUSA BASTINIZ !! LUTFEN ENTER TUSUNA BASINIZ " << endl;
      }
      
  } while (true);


   delete Kontrol;
   system("pause"); 
}

