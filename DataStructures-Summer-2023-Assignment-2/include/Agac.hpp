#ifndef AGAC_HPP
#define AGAC_HPP
#include "Hucre.hpp"
#include <iostream>
#include <chrono>
#include <thread>
class Agac
{
private:
    /* data */
     int toplam;
     int Toplam(Hucre *kok);
public:
    Agac(/* args */);
    Hucre *kok;
    int elemansayisi;
    int id;
    int maxDerinlik(Hucre*);
    void ekle(Hucre *);
    void yazdir();
    int ToplamiBul();
    void postorder(Hucre *);
    void AgaclariSil(Hucre *);
     ~Agac(/* args */);
};




#endif //  AGAC_HPP
