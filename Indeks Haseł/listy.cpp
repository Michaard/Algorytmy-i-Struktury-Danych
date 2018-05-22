#include <iostream>

using namespace std;

class Osoba{
public:
    string imie;
    string nazwisko;
    int id;
    Osoba *nastepny;
    Osoba(string imie,string nazwisko,int id):imie(imie),nazwisko(nazwisko),id(id){
        nastepny=0;
    }
};

class ListaOsob{
private:
    Osoba *pierwszy;
public:
    ListaOsob(){pierwszy=0;}
    void wyswietl();
    Osoba* wyszukaj(int);
    void dodaj(string,string,int);
    void usun(int);
};

void ListaOsob::dodaj(string imie,string nazwisko,int id){
    Osoba *osoba=new Osoba(imie,nazwisko,id);
    if(pierwszy==0){
        pierwszy=osoba;
    }
    else{
        Osoba *tmp=pierwszy;
        while(tmp->nastepny!=0)
            tmp=tmp->nastepny;
        tmp->nastepny=osoba;
    }
}

void ListaOsob::wyswietl(){
    if(pierwszy==0)
        cout << "lista pusta" << endl;
    else{
        Osoba *tmp=pierwszy;
        cout << tmp-> id << ". " << tmp->imie << " " << tmp->nazwisko << endl;
        while(tmp->nastepny!=0){
            tmp=tmp->nastepny;
            cout << tmp-> id << ". " << tmp->imie << " " << tmp->nazwisko << endl;
        }
    }
}

void ListaOsob::usun(int id){
    if(pierwszy==0)
        return;
    Osoba *tmp;
    if(pierwszy->id==id){
        tmp=pierwszy->nastepny;
        delete pierwszy;
        pierwszy=tmp;
    }
    else{
        tmp=pierwszy;
        while(tmp->nastepny!=0){
            if(tmp->nastepny->id==id){
                Osoba *usuwany=tmp->nastepny;
                tmp->nastepny=tmp->nastepny->nastepny;
                delete usuwany;
                return;
            }
            tmp=tmp->nastepny;
        }
    }
}

int main(){
    ListaOsob lista;
    lista.dodaj("Jan","Kowalski",1);
    lista.dodaj("Andrzej","Kapusta",2);
    lista.dodaj("Adam","Nowak",3);
    lista.dodaj("Bozydar","Iwanow",4);
    lista.wyswietl();
    cout << endl;
    lista.usun(1);
    lista.usun(3);
    lista.usun(2);
    lista.usun(4);
    lista.wyswietl();
    return 0;
}
