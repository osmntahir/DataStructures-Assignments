/** 
* @file --> numberNode.cpp
* @description --> İçinde int sayı ve sayı tekli bağlı listeyi tutan Düğüm dosyası
* @assignment 1
* @date 29/10/2023
* @author OSMAN TAHİR ÖZDEMİR  osman.ozdemir3@ogr.sakarya.edu.tr
*/

#include "numberNode.hpp"

// numberNode sınıfının yapıcı fonksiyonu
numberNode::numberNode(int value)
{
    // sayı tekli bağlı listeye nullptr atanır
    this->number = nullptr;
    this->value = value;
    this->nextNode = nullptr;
}

// numberNode sınıfının yıkıcı fonksiyonu
numberNode::~numberNode()
{
}
