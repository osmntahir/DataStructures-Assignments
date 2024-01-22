/** 
* @file --> number.cpp
* @description --> Basamak düğümlerini bir arada tutan sayı tekli bağlı liste
* @assignment 1
* @date 28/10/2023
* @author OSMAN TAHİR ÖZDEMİR  osman.ozdemir3@ogr.sakarya.edu.tr
*/

#include "number.hpp"


// Number sınıfının kurucu fonksiyonu
Number::Number(/* args */) {
    firstDigit = nullptr;    // İlk basamağı başlangıçta boş olarak ayarla
    this->numberOfDigits = 0; // Toplam basamak sayısını sıfırla
    this->stringOfNumber="";
}

// Yeni bir basamak ekler
void Number::addDigit(int value) {
    Digit* newDigit = new Digit(value);  // Yeni bir basamak oluştur
    if (firstDigit == nullptr) {
        firstDigit = newDigit;  // Eğer liste boşsa, ilk basamak olarak ayarla
        return;
    }
   
    Digit* current = firstDigit;
    while (current->nextDigit != nullptr) {
        current = current->nextDigit;  // Listenin sonuna git
    }
    current->nextDigit = newDigit;  // Yeni basamağı listenin sonuna ekle
    numberOfDigits++;  // Basamak sayısını artır
}


// Basamakları yıldızlarla bastırır
void Number::printStars() {
    for (int i = 0; i <= numberOfDigits; i++) {
        cout << " ******* ";
    }
}

// Basamakların bellek adreslerini bastırır
void Number::printAdress() {
    for (Digit* i = firstDigit; i != nullptr; i = i->nextDigit) {
        // Digit pointer'ını bir std::ostringstream'a yazarak bellek adresini elde et
        std::ostringstream addressStream;
        addressStream << i;
        // std::ostringstream'dan elde edilen stringi al
        std::string addressString = addressStream.str();

        // Adresin son 3 karakterini al
        std::string lastThreeCharacters = addressString.substr(addressString.size() - 3);

        // Son 3 karakteri ekrana bastır
        std::cout << " * " << lastThreeCharacters << " * ";
    }
}

// Tek basamakları liste başına taşır
void Number::moveOddsToHead() {
    if (firstDigit == nullptr) {
        cout << "Liste BOS";
        return;
    }
    Digit* prev = nullptr;    // Önceki düğüm işaretçisi
    Digit* current = firstDigit;  // Mevcut düğüm işaretçisi

    Digit* oddHead = nullptr;  // Tek sayıları başa taşıyan liste başı işaretçisi
    Digit* oddTail = nullptr;  // Tek sayıları başa taşıyan liste sonu işaretçisi

    // Listenin sonuna kadar tara
    while (current != nullptr) {
        // Mevcut düğüm tek sayı mı?
        if (current->value % 2 != 0) {
            // Eğer oddHead boşsa, tek sayıyı ilk düğüm olarak ayarla
            if (oddHead == nullptr) {
                oddHead = current;
                oddTail = current;
            } else {
                oddTail->nextDigit = current;  // Tek sayıyı sona ekle
                oddTail = current;
            }

            // Eğer mevcut düğümün önceki düğümü varsa, bağlantısını atla
            if (prev != nullptr) {
                prev->nextDigit = current->nextDigit;
            } else {
                firstDigit = current->nextDigit;  // Tek sayı ilk düğümse, listenin başını değiştir
            }

            current = current->nextDigit;  // Mevcut düğümü güncelle
            oddTail->nextDigit = nullptr;  // Tek sayı listesinin sonundaki bağlantıyı kes
        } else {
            prev = current;  // Mevcut düğümü önceki düğüm olarak güncelle
            current = current->nextDigit;  // Mevcut düğümü güncelle
        }
    }

    // Eğer tek sayılar varsa, tek sayı listesini listenin başına bağla
    if (oddHead != nullptr) {
        oddTail->nextDigit = firstDigit;
        firstDigit = oddHead;

        // Düğümlerdeki değerleri SayininStringi'ne ekle
        stringOfNumber ="";
        for (Digit* i = firstDigit; i != nullptr; i = i->nextDigit) {
            stringOfNumber += to_string(i->value);
        }
    }
}

// Basamakları ters çevirir
void Number::reverseDigits() {
    if (firstDigit == nullptr) {
        cout << "Liste BOS";
        return;
    }
    Digit* current = firstDigit;
    Digit* prev = nullptr, *next = nullptr;

    while (current != nullptr) {
        // Sonraki düğümü sakla
        next = current->nextDigit;
        // Mevcut düğümün işaretçisini ters çevir
        current->nextDigit = prev;
        // İşaretçileri bir pozisyon ileri taşı
        prev = current;
        current = next;
    }
    firstDigit = prev;

    // Düğümlerdeki değerleri SayininStringi'ne ekle
    stringOfNumber="";
    for (Digit* i = firstDigit; i != nullptr; i = i->nextDigit) {
        stringOfNumber += to_string(i->value);
    }
}


// Basamak değerlerini bastırır
void Number::printValue() {
    for (Digit *i = firstDigit; i != nullptr; i = i->nextDigit) {
        cout << " * "<< setw(3) << i->value << " * ";
    }
}

// Number sınıfının yıkıcı fonksiyonu
Number::~Number() {
    Digit* current = firstDigit;

    while (current != nullptr) {
        Digit* toBeDeleted = current;

        current = current->nextDigit;
        delete toBeDeleted;
    }
}
