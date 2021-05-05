#include <iostream>
#include <list>
using namespace std;

class ogrenci{
public:
    int numara;
    string isim;
    string adres;
};

list<ogrenci> l;

void olustur(){
    ogrenci x;
    cout<<"Ogrencinin Adini Giriniz: "<<endl;
    cin>>x.isim;
    cout<<"Ogrencinin Numarasini Giriniz: "<<endl;
    cin>>x.numara;
    cout<<"Ogrencinin Adresini Giriniz: "<<endl;
    cin>>x.adres;

    l.push_back(x);
    cout<<"Yeni Ogrenci Basariyla Eklendi."<<endl;
}

void bul(){
    if(l.empty()){
        cout<<"Veritabaninda Ogrenci Yok."<<endl;
        return;
    }

    int r, dogru=0;
    cout<<"Ogrencinin Numarasini Giriniz: "<<endl;
    cin>>r;

    list<ogrenci>::iterator itr;
    for(itr=l.begin();itr!=l.end();++itr){
        if(itr->numara==r){
            cout<<"Ismi: "<<itr->isim<<endl;
            cout<<"Numarasi: "<<itr->numara<<endl;
            cout<<"Adresi: "<<itr->adres<<endl;
            dogru=1;
            break;
        }
    }

    if(!dogru){
        cout<<"Ogrenci Bulunamadi."<<endl;
        bul();
    }
}

void oku(){
    if(!l.empty()){
        cout<<"Butun Bilgiler: "<<l.size()<<endl;
        list<ogrenci>::iterator itr;

        for(itr=l.begin();itr!=l.end();++itr){
            cout<<"Ismi: "<<itr->isim<<endl;
            cout<<"Numarasi: "<<itr->numara<<endl;
            cout<<"Adresi: "<<itr->adres<<endl;
        }
    }
    else{
        cout<<"Veritabaninda Ogrenci Yok."<<endl;
    }
}

void guncelle(){
    if(l.empty()){
        cout<<"Veritabaninda Ogrenci Yok."<<endl;
        return;
    }

    list<ogrenci>::iterator itr;
    int r, dogru=0;

    cout<<"Ogrencinin Numarasini Giriniz: "<<endl;
    cin>>r;

    for(itr=l.begin();itr!=l.end();++itr){
        if(itr->numara==r){
            cout<<"Ismi Girin: "<<endl;
            cin>>itr->isim;
            cout<<"Numarayi Girin: "<<endl;
            cin>>itr->numara;
            cout<<"Adresi Girin: "<<endl;
            cin>>itr->adres;
            dogru=1;
            break;
        }
    }

    if(dogru){
        cout<<"Basariyla Guncellendi."<<endl;
    }
    else{
        cout<<"Ogrenci Bulunamadi."<<endl;
        guncelle();
    }
}

void kaldir(){
    if(l.empty()){
        cout<<"Veri Tabaninda Ogrenci Yok."<<endl;
        return;
    }

    list<ogrenci>::iterator itr;
    int r, dogru=0;

    cout<<"Ogrencinin Numarasini Giriniz: "<<endl;
    cin>>r;

    for(itr=l.begin();itr!=l.end();++itr){
        if(itr->numara==r){
            l.erase(itr);
            dogru=1;
            break;
        }
    }

    if(dogru){
        cout<<"Basariyla Silindi."<<endl;
    }
    else{
        cout<<"Ogrenci Bulunamadi."<<endl;
        kaldir();
    }
}

int main(){
    int tercih;

    while(1){
        cout<<"OGRENCI VERITABANI"<<endl;
        cout<<"-----------------------------------"<<endl;
        cout<<"Menu: "<<endl;
        cout<<"1 -> Yeni Ogrenci Ekle"<<endl;
        cout<<"2 -> Bir Ogrenci Bul"<<endl;
        cout<<"3 -> Tum Ogrencileri Goster"<<endl;
        cout<<"4 -> Ogrenci Ayrintilarini Guncelle"<<endl;
        cout<<"5 -> Bir Ogrenciyi Sil"<<endl;
        cout<<"6 -> Cikis"<<endl;
        cout<<"-----------------------------------"<<endl;
        cout<<"Tercihini Gir: "<<endl;
        cin>>tercih;

        switch(tercih){
        case 1:
            olustur();
            break;
        case 2:
            bul();
            break;
        case 3:
            oku();
            break;
        case 4:
            guncelle();
            break;
        case 5:
            kaldir();
            break;
        case 6:
            exit(0);
        default:
            cout<<"Gecersiz Secim, Tekrar Deneyin."<<endl;
        }
    }

    return 0;
}

