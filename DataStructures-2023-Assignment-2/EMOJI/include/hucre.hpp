/** 
* @file -->     hucre.hpp
* @description  Sayıları temsil eden hücre sınıfı 
* @course       2-C
* @assignment   2
* @date         14/12/2022 
* @author       Osman Tahir Özdemir osman.ozdemir3@ogr.sakarya.edu.tr
*/


#ifndef hucre_hpp
#define hucre_hpp
#include <iostream>
using namespace std;

class hucre
{
public:
    hucre();
    int veri;
    hucre* sonraki;
    hucre* onceki;
    ~hucre();
private:
};

#endif