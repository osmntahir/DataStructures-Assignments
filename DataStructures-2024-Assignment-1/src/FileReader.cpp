/** 
* @file --> FileReader.cpp
* @description --> Txt dosyasini okuyarak dugumleri olusturur ve gerekli fonksiyonlari cagirir
* @assignment 1
* @date 30/10/2023
* @author OSMAN TAHİR ÖZDEMİR  osman.ozdemir3@ogr.sakarya.edu.tr
*/

#include "FileReader.hpp"

// FileReader sınıfının yapıcı fonksiyonu
FileReader::FileReader() {
    this->numbers = new numberList();
}

// Dosyayı okuyan ve verileri düğümlere dönüştüren fonksiyon
void FileReader::ReadFile() {
    std::ifstream Oku("doc//Sayilar.txt");

    // Dosyanın açılıp açılamadığını kontrol et
    if (!Oku.is_open()) {
        std::cerr << "Dosya bulunamadi: doc//Sayilar.txt" << std::endl;
        return;
    }

    std::string a;

    while (getline(Oku, a)) {
        std::istringstream iss(a);
        std::string strnum;

        while (getline(iss, strnum, ' ')) {
            try {
                int veri = std::stoi(strnum);
                numbers->addNumberNode(veri);
            } catch (const std::invalid_argument& e) {
                std::cerr << "Gecersiz veri: {FileReader::ReadFile()}" << strnum << std::endl;
            }
        }
    }

    numbers->reverseNodes();
    numbers->printNumberNodes();
    Oku.close();  // Dosyayı kapat
}

// Kullanıcıya menüyü gösteren ve seçimlerine göre işlem yapan fonksiyon
void FileReader::Start() {
    bool exitRequested = false;

    while (!exitRequested) {
        cout << "Menu:" << endl;
        cout << "1. Tekleri Basa Al" << endl;
        cout << "2. Basamaklari Tersle" << endl;
        cout << "3. En Buyugunu Cikar" << endl;
        cout << "4. Cikis" << endl;
        cout << "Seciminizi yapin: ";

        int choice;
        cin >> choice;

        switch (choice) {
           
            case 1:
                numbers->moveOddsToHead();
                numbers->printNumberNodes();
                break;
            
            case 2:
                numbers->reverseNodes();
                numbers->printNumberNodes();
                break;
            case 3:
                if (numbers->numberCounter == 0) {
                
                } else {
                    numbers->removeLargest();
                    numbers->printNumberNodes();
                }
                break;
            case 4:
                cout << "Programdan cikiliyor." << endl;
                exitRequested = true;
                break;
            default:
                cout << "Gecersiz secim. Lutfen tekrar deneyin." << endl;
                break;
        }
    }
}

// FileReader sınıfının yıkıcı fonksiyonu
FileReader::~FileReader() {
    delete numbers;
}
