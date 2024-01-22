#include <iostream>
using namespace std;
#include "Kontrol.hpp"
int main()
{
  Kontrol * kontrol = new Kontrol();
  kontrol->DosyayiOku();
  delete kontrol;
    // Programın sonlanabilmesi için kullanıcıdan herhangi bir giriş beklenir.
        cout <<"\n\n Hellooooo !!";
    std::cout << "\n\nPress Enter to exit.";
    std::cin.ignore(); // Daha önceki girişleri yok sayar
    std::cin.get(); // Kullanıcının Enter tuşuna basmasını bekler


}