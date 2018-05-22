#include <iostream>

using namespace std;

class Wierzcholek{
    public:
    int klucz;
    Wierzcholek *lSyn;
    Wierzcholek *pSyn;
    Wierzcholek *ojciec;
    string kolor;
    Wierzcholek(int klucz):klucz(klucz){
        this->lSyn=NULL;
        this->pSyn=NULL;
        this->ojciec=NULL;
    }
};

class DrzewoCzerwonoCzarne{
public:
    Wierzcholek* korzen;
    DrzewoCzerwonoCzarne(int klucz){
        Wierzcholek *k=new Wierzcholek(klucz);
        this->korzen=k;
    }
    void dodajBST(Wierzcholek *x){
        if(this->korzen==NULL){
            this->korzen=x;
        }
        else{
            Wierzcholek *y=this->korzen;
            Wierzcholek *z;
            while(y!=NULL){
                if(x->klucz<y->klucz){
                    z=y;
                    y=y->lSyn;
                }
                else{
                    z=y;
                    y=y->pSyn;
                }
            }
            if(x->klucz<z->klucz)
                z->lSyn=x;
            else
                z->pSyn=x;
            x->ojciec=z;
        }
    }

    void rotLewa(Wierzcholek *x){
        Wierzcholek *y=x->pSyn;
        x->pSyn=y->lSyn;
        if(x->pSyn!=NULL)
            x->pSyn->ojciec=x;
        y->ojciec=x->ojciec;
        if(y->ojciec==NULL)
            this->korzen=y;
        else if(x->ojciec->lSyn==x)
            x->ojciec->lSyn=y;
        else
            x->ojciec->pSyn=y;
        x->ojciec=y;
        y->lSyn=x;
    }

    void rotPrawa(Wierzcholek *x){
        Wierzcholek *y=x->lSyn;
        x->lSyn=y->pSyn;
        if(x->lSyn!=NULL)
            x->lSyn->ojciec=x;
        y->ojciec=x->ojciec;
        if(y->ojciec==NULL)
            this->korzen=y;
        else if(x->ojciec->lSyn==x)
            x->ojciec->lSyn=y;
        else
            x->ojciec->pSyn=y;
        x->ojciec=y;
        y->pSyn=x;
    }

    void dodajRB(Wierzcholek *x){
        dodajBST(x);
        x->kolor="red";
        while(x!=this->korzen && x->ojciec->kolor=="red"){
            if(x->ojciec==x->ojciec->ojciec->lSyn){
                Wierzcholek* y=x->ojciec->ojciec->pSyn;
                if(y->kolor=="red"){
                    x->ojciec->kolor="black";
                    x->ojciec->ojciec->kolor="red";
                    y->kolor="black";
                    x=x->ojciec->ojciec;
                }
                else if(x->ojciec->pSyn==x){
                    x=x->ojciec;
                    this->rotLewa(x);
                }
                else{
                    x->ojciec->kolor="black";
                    x->ojciec->ojciec->kolor="red";
                    this->rotPrawa(x->ojciec->ojciec);
                }
            }
            else{
                Wierzcholek* y=x->ojciec->ojciec->lSyn;
                if(y->kolor=="red"){
                    x->ojciec->kolor="black";
                    x->ojciec->ojciec->kolor="red";
                    y->kolor="black";
                    x=x->ojciec->ojciec;
                }
                else if(x->ojciec->lSyn==x){
                    x=x->ojciec;
                    this->rotPrawa(x);
                }
                else{
                    x->ojciec->kolor="black";
                    x->ojciec->ojciec->kolor="red";
                    this->rotLewa(x->ojciec->ojciec);
                }
            }
        }
        this->korzen->kolor="black";
    }
};

int main(){
    return 0;
}