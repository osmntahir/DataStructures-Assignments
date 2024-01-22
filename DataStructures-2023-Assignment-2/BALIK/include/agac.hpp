/** 
* @file -->     agac.hpp
* @description  Dokuları tutan ikili arama ağacının sınıfı
* @course       2-C
* @assignment   2
* @date         15/12/2022 
* @author       Osman Tahir Özdemir osman.ozdemir3@ogr.sakarya.edu.tr
*/



#ifndef agac_hpp
#define agac_hpp

#include "doku.hpp"

class agac {
public:
    hucre* kok;
    int elemansayisi;
    void ekle(hucre*);
    agac();
    void agacsil(hucre *);
    int sayac;
    hucre*dizi=new hucre[20];
   
    ~agac(); 
    void postorder(hucre*);   
    void preorder(hucre*); 
    int maxDerinlik(hucre* kok);
    int minDerinlik(hucre* kok);
    bool isBalanced(hucre* kok);
};


#endif