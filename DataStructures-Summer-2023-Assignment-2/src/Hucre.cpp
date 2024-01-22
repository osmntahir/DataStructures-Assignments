#include "Hucre.hpp"
Hucre::Hucre( )
{
    this->sayi =0;
    this->sag = nullptr;
    this->sol=nullptr;
}

Hucre::~Hucre()
{
    delete this->sag;
    delete this->sol;
}