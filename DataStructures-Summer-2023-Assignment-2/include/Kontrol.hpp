#ifndef KONTROL_HPP
#define KONTROL_HPP

#include <fstream>
#include <sstream>
#include <istream>
#include <iomanip>
#include "BagliListe.hpp"
#include "Agac.hpp"
#include "Yigin.hpp"
class Kontrol
{
private:
LinkedList <Yigin>* yiginlar ;
LinkedList <Agac>* agaclar ;
public:
   
    Kontrol(/* args */);
    void DosyayiOku();
    void YiginlardanAgaclariOlustur();
    Agac* enyuksekAgac();
    ~Kontrol();
};
#endif 