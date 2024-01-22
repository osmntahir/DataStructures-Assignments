#include <iostream>
using namespace std;

template<typename Tur>
class Node
{
public:
    Node(Tur* veri)
    {
        this->veri =veri;
        sonraki = 0;
    }
    Tur*veri;
    Node* sonraki;

};

template<typename Tur>
class LinkedList
{
public:
int dugumSayisi;
    LinkedList()
    {
         ilk=0;
         this->dugumSayisi =0;
    }
    ~LinkedList()
    {
        Node<Tur>* gecici = ilk;

        while(gecici!=0)
        {
            Node<Tur>* silinecek = gecici;

            gecici= gecici->sonraki;
            delete silinecek;
        }


    }
    void ekle( Tur* veri)
    {
        Node<Tur>* yeni = new Node<Tur>(veri);

        if(ilk==0)
        {
            ilk = yeni;
            dugumSayisi++;
            return;
        }
        //iterator ilk düğümü tutuyor
        Node<Tur>* gec = ilk;
        
        while(gec->sonraki!=0)
            gec=gec->sonraki
            ;
        
        gec->sonraki=yeni;
        dugumSayisi++;
    }
Node<Tur>* DugumGetir(int index)
{
    if ((index + 1) > dugumSayisi) return nullptr;

    Node<Tur>* gecici = ilk;

    while (index >= 0 && gecici != nullptr)
    {
        if (index == 0) return gecici;
        else
        {
            gecici = gecici->sonraki;
            index--;
        }
    }
    return gecici;
}
    void yazdir()
    {
        using namespace std;
        Node<Tur>* gecici = ilk;
        cout<<"-------------------------------"<<endl; 
        cout<<setw(10)<<"Adres:"<<setw(10)<<"Veri:"<<setw(15)<<"Sonraki:"<<endl; 
        cout<<"-------------------------------"<<endl;  
        while(gecici!=0)
        {
            cout<<setw(10)<<gecici<<setw(10)<<gecici->veri<<setw(15)<<gecici->sonraki<<endl;
            cout<<"-------------------------------"<<endl;
            gecici= gecici->sonraki;  
        }
    }
    void cikar()
    {
        if(ilk==0)  return;

        if(ilk->sonraki==0)
        {
            delete ilk;
            ilk=0;
        }
        else
        {
            Node<Tur>* gecici = ilk;

            while(gecici->sonraki->sonraki!=0)
            {
                gecici=gecici->sonraki;
            }

            delete gecici->sonraki;
            gecici->sonraki = 0;
        }
    }
private:
    Node<Tur>* ilk;
    
};

