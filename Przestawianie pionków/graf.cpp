#include <iostream>
#include <vector>
using namespace std;

struct wierzcholek{
    int klucz;
    int kolor; // 0.bialy, 1.szary, 2.czarny
    wierzcholek* poprzedni;
    int odleglosc;
    vector<wierzcholek*> sasiedzi;

    wierzcholek(int klucz){
    this->klucz=klucz;
    }
    wierzcholek(){};
};

Wierzcholek* popMin(vector<Wierzcholek*> q){
    Wierzcholek* minWierzcholek;
    int minWaga=MAX_INT;
    for(int i=0;i<q.size();i++){
        for(int j=0;j<q[i]->sasiedzi.size();j++)
        if(q[i]->sasiedzi->)
    }
}

class Graf{
public:
    vector<Wierzcholek*> wierzcholki;

    void dodajWierzcholek(char klucz){
        Wierzcholek* w1 = new Wierzcholek(klucz);
        wierzcholki.push_back(w1);
    }

    void dodajKrawedz(char a,char b){
        Wierzcholek* w1;
        Wierzcholek* w2;
        for(int i=0;i<wierzcholki.size();++i){
            if(wierzcholki[i]->klucz==a){
                w1=wierzcholki[i];
            }
            else if(wierzcholki[i]->klucz==b){
                w2=wierzcholki[i];
            }
        }
        w1->sasiedzi.push_back(w2);
    }

    void przeszukiwanieWszerz(Wierzcholek *s)
    {
        for(int i=0;i<wierzcholki.size();i++)
        {
            if(wierzcholki[i]->klucz==s->klucz)
            {
                wierzcholki[i]->kolor = 1;
                wierzcholki[i]->odleglosc = 0;
                wierzcholki[i]->poprzedni = NULL;
            }
            else
            {
                wierzcholki[i]->kolor = 0;
                wierzcholki[i]->odleglosc = -1; //najwieksza wartosc
                wierzcholki[i]->poprzedni = NULL;
            }
        }
        vector<Wierzcholek*> kolejka;
        Wierzcholek* u;
        Wierzcholek* v;
        kolejka.push_back(s);
        while(kolejka.size()>0)
        {
            u = kolejka[0];
            for(int i=0; i<u->sasiedzi.size(); i++)
            {
                v = u->sasiedzi[i];
                if(v->kolor==0)
                {
                    v->kolor = 1;
                    v->odleglosc = u->odleglosc + 1;
                    v->poprzedni = u;
                    kolejka.push_back(v);
                }
            }
            kolejka.erase(kolejka.begin());
            u->kolor = 2;
            cout << u->klucz << endl;
        }
    }

    void przeszukiwanieWglab(){
        for(int i=0;i<wierzcholki.size();i++){
            wierzcholki[i]->kolor=0;
        }
        time=0;
        for(int i=0;i<wierzcholki.size();i++){
            if(wierzcholki[i]->kolor==0)
                odwiedz(wierzcholki[i]);
        }
    }

    void odwiedz(Wierzcholek* u){
        u->kolor=1;
        time++;
        u->odleglosc=time;
        cout << "Poczatek " << u->klucz << " " << time << endl;
        for(int i=0;i<u->sasiedzi.size();i++){
            Wierzcholek* v=u->sasiedzi[i];
            if(v->kolor==0){
                v->poprzedni=u;
                odwiedz(v);
            }
        }
        u->kolor=2;
        time++;
        u->koniec=time;
        cout << "Koniec " << u->klucz << " " << time << endl;
    }

    void algorytmDijkstry(Wierzcholek* s){
        initcjalizuj(s);
        vector<Wierzcholek*> q=this->wierzcholki;
        while(q.size()>0){
            Wierzcholek* u=popMin(q);
        }
    }

};

int main()
{
    Graf* g1 = new Graf();
    g1->dodajWierzcholek('A');
    g1->dodajWierzcholek('B');
    g1->dodajWierzcholek('C');
    g1->dodajWierzcholek('D');
    g1->dodajWierzcholek('E');
    g1->dodajWierzcholek('F');

    g1->dodajKrawedz('A','B');
    g1->dodajKrawedz('A','C');
    g1->dodajKrawedz('B','C');
    g1->dodajKrawedz('C','D');
    g1->dodajKrawedz('D','B');
    g1->dodajKrawedz('E','D');
    g1->dodajKrawedz('E','F');
    g1->dodajKrawedz('F','F');

    for(int i=0;i<g1->wierzcholki.size();++i){
        cout << g1->wierzcholki[i]->klucz << " sasiedzi ";
        for(int j=0;j<g1->wierzcholki[i]->sasiedzi.size();++j){
            cout << g1->wierzcholki[i]->sasiedzi[j]->klucz << " ";
        }
        cout << endl;
    }
    cout << "================" << endl;

    g1->przeszukiwanieWglab();

    return 0;
}