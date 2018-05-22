#include <iostream>

int **createTab2D(int rows,int colls){
    int **tab2D=new int*[rows];
    for(int i=0;i<rows;i++)
        tab2D[i]=new int[colls];
    return tab2D;
}

void printTab2D(int **tab2D,int rows,int colls){
    std::cout << std::endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<colls;j++)
            std::cout << tab2D[i][j] << " ";
        std::cout << std::endl;
    }
    return;
}

void z_o_change(int &z_o){
    if(z_o==1)
        z_o=0;
    else
        z_o=1;
    return;
}

void crossChange(int **tab2D,int row,int coll,int rows,int colls,int &ones){
    z_o_change(tab2D[row][coll]);
    if(tab2D[row][coll]==0)
        ones--;
    else
        ones++;

    z_o_change(tab2D[row-1][coll]);
    if(tab2D[row-1][coll]==0)
        ones--;
    else
        ones++;

    if(row<rows-1){
        z_o_change(tab2D[row+1][coll]);
        if(tab2D[row+1][coll]==0)
            ones--;
        else
            ones++;
    }

    if(coll>0){
        z_o_change(tab2D[row][coll-1]);
        if(tab2D[row][coll-1]==0)
            ones--;
        else
            ones++;
    }

    if(coll<colls-1){
        z_o_change(tab2D[row][coll+1]);
        if(tab2D[row][coll+1]==0)
            ones--;
        else
            ones++;
    }
    return;
}

int putZerosTab2D(int **tab2D,int rows,int colls,int &ones){
    int m,n;
    int steps=0;
    for(m=1;m<rows;m++)
        for(n=0;n<colls;n++)
            if(tab2D[m-1][n]==1){
                crossChange(tab2D,m,n,rows,colls,ones);
                steps++;
                std::cout << "Krok: " << steps << std::endl;
                std::cout << "Jedynki: " << ones << std::endl;
                printTab2D(tab2D,rows,colls);
            }
    if(ones==0)
        return steps;
    else
        return -1;
}

int main(){
    int m,n;
    int ones=0;
    std::cin >> m;
    std::cin >> n;
    int **zerowana_tablica=createTab2D(m,n);
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++){
            std::cin >> zerowana_tablica[i][j];
            if(zerowana_tablica[i][j]==1)
                ones++;
        }
    printTab2D(zerowana_tablica,m,n);
    std::cout << "Jedynki: " << ones << std::endl;

    int result=putZerosTab2D(zerowana_tablica,m,n,ones);
    if(result==-1){
        std::cout << "niemozliwe" << std::endl;
        printTab2D(zerowana_tablica,m,n);
    }
    else{
        std::cout << "Liczba krokow: " << result << std::endl;
    }
    return 0;
}
