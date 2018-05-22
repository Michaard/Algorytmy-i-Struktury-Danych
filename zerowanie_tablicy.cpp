#include <iostream>

unsigned short int **createArray2D(unsigned int rows,unsigned int colls){
    unsigned short int **array2D=new unsigned short int*[rows];
    for(unsigned int i=0;i<rows;i++)
        array2D[i]=new unsigned short int[colls];
    return array2D;
}

void z_o_change(unsigned short int &z_o){
    if(z_o==1)
        z_o=0;
    else
        z_o=1;
    return;
}

void crossChange(unsigned short int **array2D,unsigned int row,unsigned int coll,unsigned int rows,unsigned int colls,unsigned int &ones){
    z_o_change(array2D[row][coll]);
    if(array2D[row][coll]==0)
        ones--;
    else
        ones++;
    z_o_change(array2D[row-1][coll]);
    if(array2D[row-1][coll]==0)
        ones--;
    else
        ones++;
    if(row<rows-1){
        z_o_change(array2D[row+1][coll]);
        if(array2D[row+1][coll]==0)
            ones--;
        else
            ones++;
    }
    if(coll>0){
        z_o_change(array2D[row][coll-1]);
        if(array2D[row][coll-1]==0)
            ones--;
        else
            ones++;
    }
    if(coll<colls-1){
        z_o_change(array2D[row][coll+1]);
        if(array2D[row][coll+1]==0)
            ones--;
        else
            ones++;
    }
    return;
}

int putZerosTab2D(unsigned short int **array2D,unsigned int rows,unsigned int colls,unsigned int &ones){
    unsigned int m,n;
    unsigned int steps=0;
    for(m=1;m<rows;m++)
        for(n=0;n<colls;n++)
            if(array2D[m-1][n]==1){
                crossChange(array2D,m,n,rows,colls,ones);
                steps++;
            }
    if(ones==0)
        return steps;
    else
        return -1;
}

int main(){
    unsigned int m,n;
    unsigned int ones=0;
    std::cin >> m;
    std::cin >> n;
    unsigned short int **given_array=createArray2D(m,n);
    for(unsigned int i=0;i<m;i++)
        for(unsigned int j=0;j<n;j++){
            std::cin >> given_array[i][j];
            if(given_array[i][j]==1)
                ones++;
        }
    int result=putZerosTab2D(given_array,m,n,ones);
    if(result==-1){
        std::cout << "niemozliwe" << std::endl;
    }
    else{
        std::cout << result << std::endl;
    }
    return 0;
}
