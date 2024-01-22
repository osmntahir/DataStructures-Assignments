/** 
* @file -->     kontrol.hpp
* @description  Dosya Okuma , mutasyon ve organizma yazdıran kontrol sınıfı
* @course       2-C
* @assignment   2
* @date         18/12/2022 
* @author       Osman Tahir Özdemir osman.ozdemir3@ogr.sakarya.edu.tr
*/


#ifndef kontrol_hpp
#define kontrol_hpp

#include "organizma.hpp"

class kontrol
{
private:
    organizma * Organizma = new organizma;
public:
    kontrol();
    void DosyaOku();
    void Organizmayazdir();
    void  mutasyon();
    ~kontrol();
};

#endif