/** 
* @file --> digit.cpp
* @description --> Basamaklari tutan basamak dugum sinifi
* @assignment 1
* @date 28/10/2023
* @author OSMAN TAHİR ÖZDEMİR  osman.ozdemir3@ogr.sakarya.edu.tr
*/


#include "digit.hpp"

    Digit::Digit(int value)
    {
        // sonraki basamağı gösteren pointera null atanır
        nextDigit = nullptr;
        // parametere olarak alınan value değeri düğümdeki value değerine atanır
        this->value = value;

    }
   Digit::~Digit()
   {

   }
