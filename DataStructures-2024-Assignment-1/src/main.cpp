/** 
* @file --> main.cpp
* @description --> Programin test edildigi main.cpp dosyasi
* @assignment 1
* @date 30/10/2023
* @author OSMAN TAHİR ÖZDEMİR  osman.ozdemir3@ogr.sakarya.edu.tr
*/
#include "FileReader.hpp"

using namespace std;

int main()
{
   FileReader *reader = new FileReader();
   reader->ReadFile();
   reader->Start();
   delete reader;
}