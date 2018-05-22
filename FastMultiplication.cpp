#include <iostream>

using namespace std;

int iloscCyfr(int x){
    int i=1;
    while(x/10){
        i++;
        x=x%10;
    }
    return i;
}

int power(int x,int p){
    int result=x;
    if(p>0){
        for(int i=1;i<p;i++)
            result*=x;
    }
    return result;
}

int fastMul(int x, int y){
    int mm=iloscCyfr(x);
    if(mm<10)
        return x*y;
    else{
        int m=mm/2;
        int pow10=power(10,m);
        int pow10b=power(10,mm);
        int xl=x/(double)pow10;
        int xp=x%pow10;
        int yl=y/(double)pow10;
        int yp=y%pow10;

        int a=fastMul(xl,yl);
        int b=fastMul(xp,yp);
        int c=fastMul(xl+xp,yl+yp);
        int w=a*pow10b+(c-a-b)*pow10+b;
        return w;
    }
}

int main(){
    cout << fastMul(1224,2456) << endl;
}