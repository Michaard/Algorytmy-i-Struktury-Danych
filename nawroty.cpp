#include <iostream>
#define TAB_SIZE 5

using namespace std;

int tab[TAB_SIZE][TAB_SIZE];

bool czy_skok_dozwolony(int newX,int newY){
    if(newX<0||newX>4)
        return false;
    if(newY<0||newY>4)
        return false;
    return true;
}
bool miejsce_nie_bylo_wczesniej_odwiedzone(int newX, int newY)
{
    if(tab[newY][newX]==0)
        return true;
    else
        return false;
}

bool jump(int x,int y,int nr,int& newX,int& newY){
    switch(nr){
    case 1:
        newX=x+1;
        newY=y-2;
        break;
    case 2:
        newX=x+2;
        newY=y-1;
        break;
    case 3:
        newX=x+2;
        newY=y+1;
        break;
    case 4:
        newX=x+1;
        newY=y+2;
        break;
    case 5:
        newX=x-1;
        newY=y+2;
        break;
    case 6:
        newX=x-2;
        newY=y+1;
        break;
    case 7:
        newX=x-2;
        newY=y-1;
        break;
    case 8:
        newX=x-1;
        newY=y-2;
        break;
    }

    return czy_skok_dozwolony(newX,newY) && miejsce_nie_bylo_wczesniej_odwiedzone(newX,newY);
}

void wyswietl_tab(int tab[TAB_SIZE][TAB_SIZE]){
    for(int i=0;i<TAB_SIZE;i++){
        for(int j=0;j<TAB_SIZE;j++){
            cout << tab[i][j];
            if(tab[i][j]<10)
                cout << "  ";
            else
                cout << " ";
        }
        cout << endl;
    }
}

bool konik(int x,int y,int krok){

    tab[y][x]=krok;

    if(krok==TAB_SIZE*TAB_SIZE){
        //tab[y][x]=krok;
        wyswietl_tab(tab);
        return true;
    }
    else{
        int newX,newY;
        for(int i=1;i<=8;i++){
            if(jump(x,y,i,newX,newY)){
                konik(newX,newY,krok+1);
            }
        }
        tab[y][x]=0;
        return false;
    }
}

int main(){
    konik(0,4,1);
    return 0;
}
