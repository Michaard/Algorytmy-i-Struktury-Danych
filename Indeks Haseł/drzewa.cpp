#include <iostream>

using namespace std;

class Wierzcholek{
    public:
    int klucz;
    Wierzcholek *lSyn;
    Wierzcholek *pSyn;
    Wierzcholek *ojciec;
    Wierzcholek(int klucz):klucz(klucz){
        this->lSyn=NULL;
        this->pSyn=NULL;
        this->ojciec=NULL;
    }
};

class Drzewo{
public:
    Wierzcholek *korzen;
    Drzewo(int klucz){
        Wierzcholek *k=new Wierzcholek(klucz);
        this->korzen=k;
    }
    void inOrder(Wierzcholek *w){
        if(w->lSyn!=NULL)
            this->inOrder(w->lSyn);
        cout << w->klucz << " ";
        if(w->pSyn!=NULL)
            this->inOrder(w->pSyn);
    }
    void preOrder(Wierzcholek *w){
        cout << w->klucz << " ";
        if(w->lSyn!=NULL)
            this->preOrder(w->lSyn);
        if(w->pSyn!=NULL)
            this->preOrder(w->pSyn);
    }
    void postOrder(Wierzcholek *w){
        if(w->lSyn!=NULL)
            this->postOrder(w->lSyn);
        if(w->pSyn!=NULL)
            this->postOrder(w->pSyn);
        cout << w->klucz << " ";
    }
    Wierzcholek *wyszukaj(int k){
        if(this->korzen->klucz==k)
            return this->korzen;
        else if(this->korzen->klucz>k){
            if(this->korzen->lSyn!=NULL){
                Wierzcholek *x=this->korzen->lSyn;
                while(x!=NULL){
                    if(x->klucz==k)
                        return x;
                    else if(x->klucz>k)
                        x=x->lSyn;
                    else
                        x=x->pSyn;
                }
                return NULL;
            }
            else
                return NULL;
        }
        else{
            if(this->korzen->pSyn!=NULL){
                Wierzcholek *x=this->korzen->pSyn;
                while(x!=NULL){
                    if(x->klucz==k)
                        return x;
                    else if(x->klucz>k)
                        x=x->lSyn;
                    else
                        x=x->pSyn;
                }
                return NULL;
            }
            else
                return NULL;
        }
    }
    Wierzcholek *minimum(Wierzcholek *w){
        Wierzcholek *x=w->lSyn;
        while(x!=NULL)
            x=x->lSyn;
        return x;
    }
    Wierzcholek *nastepnik(Wierzcholek *w){
        if(w->pSyn!=NULL)
            return this->minimum(w->pSyn);
        else{
            Wierzcholek *x=w;
            Wierzcholek *y=x->ojciec;
            while(y->pSyn==x && y!=NULL){
                x=y;
                y=y->ojciec;
            }
            return y;
        }
    }
    void usun(Wierzcholek *w){
        if(w->lSyn==NULL && w->pSyn==NULL){ //jest lisciem
            if(w->ojciec==NULL){
                this->korzen=NULL;
            }
            else{
                cout << "wyjscie" << endl;
                if(w->ojciec->lSyn==w){
                    cout << "wyjscie1" << endl;
                    w->ojciec->lSyn=NULL;
                }
                else{
                    cout << w->ojciec->klucz << endl;
                    w->ojciec->pSyn=NULL;
                }
            }
        }
        else if(w->lSyn==NULL || w->pSyn==NULL){ //ma jeden lisc
            Wierzcholek *x;
            if(w->lSyn!=NULL)
                x=w->lSyn;
            else
                x=w->pSyn;
            x->ojciec=w->ojciec;
            if(x->ojciec!=NULL){
                this->korzen==NULL;
            }
            else{
                if(w->ojciec->lSyn==w){
                    w->ojciec->lSyn==x;
                }
                else{
                    w->ojciec->pSyn==x;
                }
            }
        }
        else{ //ma dwa liscie
            Wierzcholek *x=this->nastepnik(w);
            if(w->lSyn==NULL && w->pSyn==NULL){ //jest lisciem
                if(w->ojciec==NULL){
                    this->korzen==NULL;
                }
                else{
                    if(w->ojciec->lSyn==w){
                        w->ojciec->lSyn==NULL;
                    }
                    else{
                        w->ojciec->pSyn==NULL;
                    }
                }
            }
            else if(w->lSyn==NULL || w->pSyn==NULL){ //ma jeden lisc
                Wierzcholek *x;
                if(w->lSyn!=NULL)
                    x=w->lSyn;
                else
                    x=w->pSyn;
                x->ojciec=w->ojciec;
                if(x->ojciec!=NULL)
                    this->korzen==NULL;
                else{
                    if(w->ojciec->lSyn==w)
                        w->ojciec->lSyn==x;
                    else
                        w->ojciec->pSyn==x;
                }
            }
        }
    }
};

int main(){
    Drzewo *drzewo=new Drzewo(7);
    Wierzcholek *b=new Wierzcholek(5);
    Wierzcholek *c=new Wierzcholek(10);
/*    Wierzcholek *d=new Wierzcholek(1);
    Wierzcholek *e=new Wierzcholek(6);
    Wierzcholek *f=new Wierzcholek(8);
    Wierzcholek *g=new Wierzcholek(15);
*/
    drzewo->korzen->lSyn=b;
    drzewo->korzen->pSyn=c;
/*    b->lSyn=d;
    b->pSyn=e;
    c->lSyn=f;
    c->pSyn=g;
*/
    b->ojciec=drzewo->korzen;
    c->ojciec=drzewo->korzen;
 /*   d->ojciec=b;
    e->ojciec=b;
    f->ojciec=c;
    g->ojciec=c;*/

    drzewo->inOrder(drzewo->korzen);
    Wierzcholek *z=drzewo->wyszukaj(2);
    if(z!=NULL)
        cout << '\n' << "Znaleziono element w drzewie!" << endl;
    else
        cout << '\n' << "Brak elementu w drzewie!" << endl;
/*    int k=e->klucz;
    Wierzcholek *n=drzewo->nastepnik(e);
    if(n!=NULL)
        cout << "Nastepnik " << k << " to: " << n->klucz << endl;
    else
       cout << "Brak nastepnika dla " << k << "!" << endl;*/
    drzewo->usun(c);
    drzewo->inOrder(drzewo->korzen);
    return 0;
}