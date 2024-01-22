/** 
* @file -->     doku.hpp
* @description  Hücreleri bir arada tutan doku sınıfı
* @course       2-C
* @assignment   2
* @date         14/12/2022 
* @author       Osman Tahir Özdemir osman.ozdemir3@ogr.sakarya.edu.tr
*/

#ifndef doku_hpp
#define doku_hpp

#include "hucre.hpp"
class doku
{
private:
    hucre* ilk;
    int hucresayisi;
public:
    doku();
    void hucreyazdir();
    void hucreekle(hucre* hucre);
    hucre* ortadegergetir();

    ~doku();
};


#endif