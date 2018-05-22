#include <iostream>

class Sudoku21x9{
private:
    const static unsigned int width=21;
    const static unsigned int lenght=9;
    const static unsigned int maxNumber=9;
    unsigned int** board;
    bool correctSetting();
    bool initSolution();
    bool recSolution(unsigned int,unsigned int,unsigned int);
    bool fieldFilled(unsigned int);
    bool putNumberAvailable(unsigned int,unsigned int,unsigned int);
public:
    Sudoku21x9();
    ~Sudoku21x9();
    void readSetting();
    void display();
    void solve();
};
Sudoku21x9::Sudoku21x9(){
    this->board=new unsigned int*[this->width];
    for(unsigned int i=0;i<this->width;i++)
        this->board[i]=new unsigned int[this->lenght];
}
Sudoku21x9::~Sudoku21x9(){
    for(unsigned int x=0;x<this->width;x++)
        delete[]board[x];
    delete[]this->board;
}
void Sudoku21x9::readSetting(){
    for(unsigned int x=0;x<this->width;x++)
        for(unsigned int y=0;y<this->lenght;y++)
            std::cin >> this->board[x][y];
}
void Sudoku21x9::display(){
    for(unsigned int x=0;x<this->width;x++){
        for(unsigned int y=0;y<this->lenght;y++)
            std::cout << this->board[x][y] << " ";
        std::cout << std::endl;
    }
}
bool Sudoku21x9::correctSetting(){
    for(unsigned int x=0;x<this->width;x++){
        for(unsigned int y=0;y<this->lenght;y++){
            if(this->board[x][y]!=0){
                for(unsigned int i=y+1;i<9;i++)
                    if(this->board[x][i]==this->board[x][y])
                        return false;
                if(x<6)
                    for(unsigned int i=x+1;i<9;i++)
                        if(this->board[i][y]==this->board[x][y])
                            return false;
                else if(x>=6 && x<9){
                    for(unsigned int i=x+1;i<9;i++)
                        if(this->board[i][y]==this->board[x][y])
                            return false;
                    for(unsigned int i=x+1;i<15;i++)
                        if(this->board[i][y]==this->board[x][y])
                            return false;
                }
                else if(x>=9 && x<12)
                    for(unsigned int i=x+1;i<15;i++)
                        if(this->board[i][y]==this->board[x][y])
                            return false;
                else if(x>=12 && x<15){
                    for(unsigned int i=x+1;i<15;i++)
                        if(this->board[i][y]==this->board[x][y])
                            return false;
                    for(unsigned int i=x+1;i<21;i++)
                        if(this->board[i][y]==this->board[x][y])
                            return false;
                }
                else if(x>=15 && x<21)
                    for(unsigned int i=x+1;i<21;i++)
                        if(this->board[i][y]==this->board[x][y])
                            return false;
                if(x<3){
                    if(y<3){
                        for(unsigned int i=0;i<x;i++){
                            for(unsigned int j=0;j<y;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                            for(unsigned int j=y+1;j<3;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        }
                        for(int i=x+1;i<3;i++){
                            for(unsigned int j=0;j<y;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                            for(unsigned int j=y+1;j<3;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        }
                    }
                    else if(y<6){
                        for(unsigned int i=0;i<x;i++){
                            for(unsigned int j=3;j<y;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                            for(unsigned int j=y+1;j<6;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        }
                        for(unsigned int i=x+1;i<3;i++){
                            for(unsigned int j=3;j<y;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                            for(unsigned int j=y+1;j<6;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        }
                    }
                    else if(y<9){
                        for(unsigned int i=0;i<x;i++){
                            for(unsigned int j=6;j<y;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                            for(unsigned int j=y+1;j<9;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        }
                        for(unsigned int i=x+1;i<3;i++){
                            for(unsigned int j=6;j<y;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                            for(unsigned int j=y+1;j<9;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        }
                    }
                }
                else if(x<6){
                    if(y<3){
                        for(unsigned int i=3;i<x;i++){
                            for(unsigned int j=0;j<y;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                            for(unsigned int j=y+1;j<3;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        }
                        for(unsigned int i=x+1;i<6;i++){
                            for(unsigned int j=0;j<y;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                            for(unsigned int j=y+1;j<3;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        }
                    }
                    else if(y<6){
                        for(unsigned int i=3;i<x;i++){
                            for(unsigned int j=3;j<y;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                            for(unsigned int j=y+1;j<6;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        }
                        for(unsigned int i=x+1;i<6;i++){
                            for(unsigned int j=3;j<y;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                            for(unsigned int j=y+1;j<6;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        }
                    }
                    else if(y<9){
                        for(unsigned int i=3;i<x;i++){
                            for(unsigned int j=6;j<y;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                            for(unsigned int j=y+1;j<9;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        }
                        for(unsigned int i=x+1;i<6;i++){
                            for(unsigned int j=6;j<y;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                            for(unsigned int j=y+1;j<9;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        }
                    }
                }
                else if(x<9){
                    if(y<3){
                        for(unsigned int i=6;i<x;i++){
                            for(unsigned int j=0;j<y;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                            for(unsigned int j=y+1;j<3;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        }
                        for(unsigned int i=x+1;i<9;i++){
                            for(unsigned int j=0;j<y;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                            for(unsigned int j=y+1;j<3;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        }
                    }
                    else if(y<6){
                        for(unsigned int i=6;i<x;i++){
                            for(unsigned int j=3;j<y;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                            for(unsigned int j=y+1;j<6;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        }
                        for(unsigned int i=x+1;i<9;i++){
                            for(unsigned int j=3;j<y;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                            for(unsigned int j=y+1;j<6;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        }
                    }
                    else if(y<9){
                        for(unsigned int i=6;i<x;i++){
                            for(unsigned int j=6;j<y;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                            for(unsigned int j=y+1;j<9;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        }
                        for(unsigned int i=x+1;i<9;i++){
                            for(unsigned int j=6;j<y;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                            for(unsigned int j=y+1;j<9;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        }
                    }
                }
                else if(x<12){
                    if(y<3){
                        for(unsigned int i=9;i<x;i++){
                            for(unsigned int j=0;j<y;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                            for(unsigned int j=y+1;j<3;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        }
                        for(unsigned int i=x+1;i<12;i++){
                            for(unsigned int j=0;j<y;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                            for(unsigned int j=y+1;j<3;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        }
                    }
                    else if(y<6){
                        for(unsigned int i=9;i<x;i++){
                            for(unsigned int j=3;j<y;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                            for(unsigned int j=y+1;j<6;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        }
                        for(unsigned int i=x+1;i<12;i++){
                            for(unsigned int j=3;j<y;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                            for(unsigned int j=y+1;j<6;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        }
                    }
                    else if(y<9){
                        for(unsigned int i=9;i<x;i++){
                            for(unsigned int j=6;j<y;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                            for(unsigned int j=y+1;j<9;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        }
                        for(unsigned int i=x+1;i<12;i++){
                            for(unsigned int j=6;j<y;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                            for(unsigned int j=y+1;j<9;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        }
                    }
                }
                else if(x<15){
                    if(y<3){
                        for(unsigned int i=12;i<x;i++){
                            for(unsigned int j=0;j<y;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                            for(unsigned int j=y+1;j<3;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        }
                        for(unsigned int i=x+1;i<15;i++){
                            for(int j=0;j<y;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                            for(unsigned int j=y+1;j<3;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        }
                    }
                    else if(y<6){
                        for(unsigned int i=12;i<x;i++){
                            for(unsigned int j=3;j<y;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                            for(unsigned int j=y+1;j<6;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        }
                        for(unsigned int i=x+1;i<15;i++){
                            for(unsigned int j=3;j<y;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                            for(unsigned int j=y+1;j<6;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        }
                    }
                    else if(y<9){
                        for(unsigned int i=12;i<x;i++){
                            for(unsigned int j=6;j<y;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                            for(unsigned int j=y+1;j<9;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        }
                        for(unsigned int i=x+1;i<15;i++){
                            for(unsigned int j=6;j<y;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                            for(unsigned int j=y+1;j<9;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        }
                    }
                }
                else if(x<18){
                    if(y<3){
                        for(unsigned int i=15;i<x;i++){
                            for(unsigned int j=0;j<y;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                            for(unsigned int j=y+1;j<3;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        }
                        for(unsigned int i=x+1;i<18;i++){
                            for(unsigned int j=0;j<y;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                            for(unsigned int j=y+1;j<3;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        }
                    }
                    else if(y<6){
                        for(unsigned int i=15;i<x;i++){
                            for(unsigned int j=3;j<y;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                            for(unsigned int j=y+1;j<6;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        }
                        for(unsigned int i=x+1;i<18;i++){
                            for(unsigned int j=3;j<y;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                            for(unsigned int j=y+1;j<6;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        }
                    }
                    else if(y<9){
                        for(unsigned int i=15;i<x;i++){
                            for(unsigned int j=6;j<y;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                            for(unsigned int j=y+1;j<9;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        }
                        for(unsigned int i=x+1;i<18;i++){
                            for(unsigned int j=6;j<y;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                            for(unsigned int j=y+1;j<9;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        }
                    }
                }
                else if(x<21){
                    if(y<3){
                        for(unsigned int i=18;i<x;i++){
                            for(unsigned int j=0;j<y;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                            for(unsigned int j=y+1;j<3;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        }
                        for(unsigned int i=x+1;i<21;i++){
                            for(unsigned int j=0;j<y;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                            for(unsigned int j=y+1;j<3;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        }
                    }
                    else if(y<6){
                        for(unsigned int i=18;i<x;i++){
                            for(unsigned int j=3;j<y;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                            for(unsigned int j=y+1;j<6;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        }
                        for(unsigned int i=x+1;i<21;i++){
                            for(unsigned int j=3;j<y;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                            for(unsigned int j=y+1;j<6;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        }
                    }
                    else if(y<9){
                        for(unsigned int i=18;i<x;i++){
                            for(unsigned int j=6;j<y;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        for(unsigned int i=18;i<x;i++)
                            for(unsigned int j=y+1;j<9;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        }
                        for(unsigned int i=x+1;i<21;i++){
                            for(unsigned int j=6;j<y;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                            for(unsigned int j=y+1;j<9;j++)
                                if(this->board[i][j]==this->board[x][y])
                                    return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}
bool Sudoku21x9::fieldFilled(unsigned int fieldValue){
    if(fieldValue==0)
        return false;
    else
        return true;
}
bool Sudoku21x9::putNumberAvailable(unsigned int x,unsigned int y,unsigned int number){
    for(unsigned int i=0;i<y;i++)
        if(this->board[x][i]==number)
            return false;
    for(unsigned int i=y+1;i<9;i++)
        if(this->board[x][i]==number)
            return false;
    if(x<6){
        for(unsigned int i=0;i<x;i++)
            if(this->board[i][y]==number)
                return false;
        for(unsigned int i=x+1;i<9;i++)
            if(this->board[i][y]==number)
                return false;
    }
    else if(x>=6 && x<9){
        for(unsigned int i=0;i<x;i++)
            if(this->board[i][y]==number)
                return false;
        for(unsigned int i=x+1;i<9;i++)
            if(this->board[i][y]==number)
                return false;
        for(unsigned int i=9;i<x;i++)
            if(this->board[i][y]==number)
                return false;
        for(unsigned int i=x+1;i<15;i++)
            if(this->board[i][y]==number)
                return false;
    }
    else if(x>=9 && x<12){
        for(unsigned int i=6;i<x;i++)
            if(this->board[i][y]==number)
                return false;
        for(unsigned int i=x+1;i<15;i++)
            if(this->board[i][y]==number)
                return false;
    }
    else if(x>=12 && x<15){
        for(unsigned int i=6;i<x;i++)
            if(this->board[i][y]==number)
                return false;
        for(unsigned int i=x+1;i<15;i++)
            if(this->board[i][y]==number)
                return false;
        for(unsigned int i=15;i<x;i++)
            if(this->board[i][y]==number)
                return false;
        for(unsigned int i=x+1;i<21;i++)
            if(this->board[i][y]==number)
                return false;
    }
    else if(x>=15 && x<21){
        for(unsigned int i=12;i<x;i++)
            if(this->board[i][y]==number)
                return false;
        for(unsigned int i=x+1;i<21;i++)
            if(this->board[i][y]==number)
                return false;
    }
    if(x<3){
        if(y<3){
            for(unsigned int i=0;i<x;i++){
                for(unsigned int j=0;j<y;j++)
                    if(this->board[i][j]==number)
                        return false;
                for(unsigned int j=y+1;j<3;j++)
                    if(this->board[i][j]==number)
                        return false;
            }
            for(int i=x+1;i<3;i++){
                for(unsigned int j=0;j<y;j++)
                    if(this->board[i][j]==number)
                        return false;
                for(unsigned int j=y+1;j<3;j++)
                    if(this->board[i][j]==number)
                        return false;
            }
        }
        else if(y<6){
            for(unsigned int i=0;i<x;i++){
                for(unsigned int j=3;j<y;j++)
                    if(this->board[i][j]==number)
                        return false;
                for(unsigned int j=y+1;j<6;j++)
                    if(this->board[i][j]==number)
                        return false;
            }
            for(unsigned int i=x+1;i<3;i++){
                for(unsigned int j=3;j<y;j++)
                    if(this->board[i][j]==number)
                        return false;
                for(unsigned int j=y+1;j<6;j++)
                    if(this->board[i][j]==number)
                        return false;
            }
        }
        else if(y<9){
            for(unsigned int i=0;i<x;i++){
                for(unsigned int j=6;j<y;j++)
                    if(this->board[i][j]==number)
                        return false;
                for(unsigned int j=y+1;j<9;j++)
                    if(this->board[i][j]==number)
                        return false;
            }
            for(unsigned int i=x+1;i<3;i++){
                for(unsigned int j=6;j<y;j++)
                    if(this->board[i][j]==number)
                        return false;
                for(unsigned int j=y+1;j<9;j++)
                    if(this->board[i][j]==number)
                        return false;
            }
        }
    }
    else if(x<6){
        if(y<3){
            for(unsigned int i=3;i<x;i++){
                for(unsigned int j=0;j<y;j++)
                    if(this->board[i][j]==number)
                        return false;
                for(unsigned int j=y+1;j<3;j++)
                    if(this->board[i][j]==number)
                        return false;
            }
            for(unsigned int i=x+1;i<6;i++){
                for(unsigned int j=0;j<y;j++)
                    if(this->board[i][j]==number)
                        return false;
                for(unsigned int j=y+1;j<3;j++)
                    if(this->board[i][j]==number)
                        return false;
            }
        }
        else if(y<6){
            for(unsigned int i=3;i<x;i++){
                for(unsigned int j=3;j<y;j++)
                    if(this->board[i][j]==number)
                        return false;
                for(unsigned int j=y+1;j<6;j++)
                    if(this->board[i][j]==number)
                        return false;
            }
            for(unsigned int i=x+1;i<6;i++){
                for(unsigned int j=3;j<y;j++)
                    if(this->board[i][j]==number)
                        return false;
                for(unsigned int j=y+1;j<6;j++)
                    if(this->board[i][j]==number)
                        return false;
            }
        }
        else if(y<9){
            for(unsigned int i=3;i<x;i++){
                for(unsigned int j=6;j<y;j++)
                    if(this->board[i][j]==number)
                        return false;
                for(unsigned int j=y+1;j<9;j++)
                    if(this->board[i][j]==number)
                        return false;
            }
            for(unsigned int i=x+1;i<6;i++){
                for(unsigned int j=6;j<y;j++)
                    if(this->board[i][j]==number)
                        return false;
                for(unsigned int j=y+1;j<9;j++)
                    if(this->board[i][j]==number)
                        return false;
            }
        }
    }
    else if(x<9){
        if(y<3){
            for(unsigned int i=6;i<x;i++){
                for(unsigned int j=0;j<y;j++)
                    if(this->board[i][j]==number)
                        return false;
                for(unsigned int j=y+1;j<3;j++)
                    if(this->board[i][j]==number)
                        return false;
            }
            for(unsigned int i=x+1;i<9;i++){
                for(unsigned int j=0;j<y;j++)
                    if(this->board[i][j]==number)
                        return false;
                for(unsigned int j=y+1;j<3;j++)
                    if(this->board[i][j]==number)
                        return false;
            }
        }
        else if(y<6){
            for(unsigned int i=6;i<x;i++){
                for(unsigned int j=3;j<y;j++)
                    if(this->board[i][j]==number)
                        return false;
                for(unsigned int j=y+1;j<6;j++)
                    if(this->board[i][j]==number)
                        return false;
            }
            for(unsigned int i=x+1;i<9;i++){
                for(unsigned int j=3;j<y;j++)
                    if(this->board[i][j]==number)
                        return false;
                for(unsigned int j=y+1;j<6;j++)
                    if(this->board[i][j]==number)
                        return false;
            }
        }
        else if(y<9){
            for(unsigned int i=6;i<x;i++){
                for(unsigned int j=6;j<y;j++)
                    if(this->board[i][j]==number)
                        return false;
                for(unsigned int j=y+1;j<9;j++)
                    if(this->board[i][j]==number)
                        return false;
            }
            for(unsigned int i=x+1;i<9;i++){
                for(unsigned int j=6;j<y;j++)
                    if(this->board[i][j]==number)
                        return false;
                for(unsigned int j=y+1;j<9;j++)
                    if(this->board[i][j]==number)
                        return false;
            }
        }
    }
    else if(x<12){
        if(y<3){
            for(unsigned int i=9;i<x;i++){
                for(unsigned int j=0;j<y;j++)
                    if(this->board[i][j]==number)
                        return false;
                for(unsigned int j=y+1;j<3;j++)
                    if(this->board[i][j]==number)
                        return false;
            }
            for(unsigned int i=x+1;i<12;i++){
                for(unsigned int j=0;j<y;j++)
                    if(this->board[i][j]==number)
                        return false;
                for(unsigned int j=y+1;j<3;j++)
                    if(this->board[i][j]==number)
                        return false;
            }
        }
        else if(y<6){
            for(unsigned int i=9;i<x;i++){
                for(unsigned int j=3;j<y;j++)
                    if(this->board[i][j]==number)
                        return false;
                for(unsigned int j=y+1;j<6;j++)
                    if(this->board[i][j]==number)
                        return false;
            }
            for(unsigned int i=x+1;i<12;i++){
                for(unsigned int j=3;j<y;j++)
                    if(this->board[i][j]==number)
                        return false;
                for(unsigned int j=y+1;j<6;j++)
                    if(this->board[i][j]==number)
                        return false;
            }
        }
        else if(y<9){
            for(unsigned int i=9;i<x;i++){
                for(unsigned int j=6;j<y;j++)
                    if(this->board[i][j]==number)
                        return false;
                for(unsigned int j=y+1;j<9;j++)
                    if(this->board[i][j]==number)
                        return false;
            }
            for(unsigned int i=x+1;i<12;i++){
                for(unsigned int j=6;j<y;j++)
                    if(this->board[i][j]==number)
                        return false;
                for(unsigned int j=y+1;j<9;j++)
                    if(this->board[i][j]==number)
                        return false;
            }
        }
    }
    else if(x<15){
        if(y<3){
            for(unsigned int i=12;i<x;i++){
                for(unsigned int j=0;j<y;j++)
                    if(this->board[i][j]==number)
                        return false;
                for(unsigned int j=y+1;j<3;j++)
                    if(this->board[i][j]==number)
                        return false;
            }
            for(unsigned int i=x+1;i<15;i++){
                for(int j=0;j<y;j++)
                    if(this->board[i][j]==number)
                        return false;
                for(unsigned int j=y+1;j<3;j++)
                    if(this->board[i][j]==number)
                        return false;
            }
        }
        else if(y<6){
            for(unsigned int i=12;i<x;i++){
                for(unsigned int j=3;j<y;j++)
                    if(this->board[i][j]==number)
                        return false;
                for(unsigned int j=y+1;j<6;j++)
                    if(this->board[i][j]==number)
                        return false;
            }
            for(unsigned int i=x+1;i<15;i++){
                for(unsigned int j=3;j<y;j++)
                    if(this->board[i][j]==number)
                        return false;
                for(unsigned int j=y+1;j<6;j++)
                    if(this->board[i][j]==number)
                        return false;
            }
        }
        else if(y<9){
            for(unsigned int i=12;i<x;i++){
                for(unsigned int j=6;j<y;j++)
                    if(this->board[i][j]==number)
                        return false;
                for(unsigned int j=y+1;j<9;j++)
                    if(this->board[i][j]==number)
                        return false;
            }
            for(unsigned int i=x+1;i<15;i++){
                for(unsigned int j=6;j<y;j++)
                    if(this->board[i][j]==number)
                        return false;
                for(unsigned int j=y+1;j<9;j++)
                    if(this->board[i][j]==number)
                        return false;
            }
        }
    }
    else if(x<18){
        if(y<3){
            for(unsigned int i=15;i<x;i++){
                for(unsigned int j=0;j<y;j++)
                    if(this->board[i][j]==number)
                        return false;
                for(unsigned int j=y+1;j<3;j++)
                    if(this->board[i][j]==number)
                        return false;
            }
            for(unsigned int i=x+1;i<18;i++){
                for(unsigned int j=0;j<y;j++)
                    if(this->board[i][j]==number)
                        return false;
                for(unsigned int j=y+1;j<3;j++)
                    if(this->board[i][j]==number)
                        return false;
            }
        }
        else if(y<6){
            for(unsigned int i=15;i<x;i++){
                for(unsigned int j=3;j<y;j++)
                    if(this->board[i][j]==number)
                        return false;
                for(unsigned int j=y+1;j<6;j++)
                    if(this->board[i][j]==number)
                        return false;
            }
            for(unsigned int i=x+1;i<18;i++){
                for(unsigned int j=3;j<y;j++)
                    if(this->board[i][j]==number)
                        return false;
                for(unsigned int j=y+1;j<6;j++)
                    if(this->board[i][j]==number)
                        return false;
            }
        }
        else if(y<9){
            for(unsigned int i=15;i<x;i++){
                for(unsigned int j=6;j<y;j++)
                    if(this->board[i][j]==number)
                        return false;
                for(unsigned int j=y+1;j<9;j++)
                    if(this->board[i][j]==number)
                        return false;
            }
            for(unsigned int i=x+1;i<18;i++){
                for(unsigned int j=6;j<y;j++)
                    if(this->board[i][j]==number)
                        return false;
                for(unsigned int j=y+1;j<9;j++)
                    if(this->board[i][j]==number)
                        return false;
            }
        }
    }
    else if(x<21){
        if(y<3){
            for(unsigned int i=18;i<x;i++){
                for(unsigned int j=0;j<y;j++)
                    if(this->board[i][j]==number)
                        return false;
                for(unsigned int j=y+1;j<3;j++)
                    if(this->board[i][j]==number)
                        return false;
            }
            for(unsigned int i=x+1;i<21;i++){
                for(unsigned int j=0;j<y;j++)
                    if(this->board[i][j]==number)
                        return false;
                for(unsigned int j=y+1;j<3;j++)
                    if(this->board[i][j]==number)
                        return false;
            }
        }
        else if(y<6){
            for(unsigned int i=18;i<x;i++){
                for(unsigned int j=3;j<y;j++)
                    if(this->board[i][j]==number)
                        return false;
                for(unsigned int j=y+1;j<6;j++)
                    if(this->board[i][j]==number)
                        return false;
            }
            for(unsigned int i=x+1;i<21;i++){
                for(unsigned int j=3;j<y;j++)
                    if(this->board[i][j]==number)
                        return false;
                for(unsigned int j=y+1;j<6;j++)
                    if(this->board[i][j]==number)
                        return false;
            }
        }
        else if(y<9){
            for(unsigned int i=18;i<x;i++){
                for(unsigned int j=6;j<y;j++)
                    if(this->board[i][j]==number)
                        return false;
            for(unsigned int i=18;i<x;i++)
                for(unsigned int j=y+1;j<9;j++)
                    if(this->board[i][j]==number)
                        return false;
            }
            for(unsigned int i=x+1;i<21;i++){
                for(unsigned int j=6;j<y;j++)
                    if(this->board[i][j]==number)
                        return false;
                for(unsigned int j=y+1;j<9;j++)
                    if(this->board[i][j]==number)
                        return false;
            }
        }
    }
    return true;
}
bool Sudoku21x9::initSolution(){
    unsigned int x=0;
    unsigned int y=0;
    if(this->fieldFilled(this->board[x][y])){
        while(this->fieldFilled(this->board[x][y])){
            if(x!=this->width-1){
                x++;
            }
            else if(y!=this->lenght-1){
                x=0;
                y++;
            }
            else
                return true;
        }
    }
    for(unsigned int number=1;number<=this->maxNumber;number++)
        if(this->putNumberAvailable(x,y,number))
            if(this->recSolution(x,y,number))
                return true;
    return false;
}
bool Sudoku21x9::recSolution(unsigned int x,unsigned int y,unsigned int initNumber){
    this->board[x][y]=initNumber;
    if(x==this->width-1 && y==this->lenght-1)
        return true;
    unsigned int newX;
    unsigned int newY;
    if(x!=this->width-1){
        newX=x+1;
        newY=y;
    }
    else if(y!=this->lenght-1){
        newX=0;
        newY=y+1;
    }
    else
        return true;
    if(this->fieldFilled(this->board[newX][newY])){
        while(this->fieldFilled(this->board[newX][newY])){
            if(newX!=this->width-1){
                newX=newX+1;
            }
            else if(newY!=this->lenght-1){
                newX=0;
                newY=newY+1;
            }
            else
                return true;
        }
    }
    for(unsigned int number=1;number<=this->maxNumber;number++){
        if(this->putNumberAvailable(newX,newY,number))
            if(this->recSolution(newX,newY,number))
                return true;
    }
    this->board[x][y]=0;
    return false;
}
void Sudoku21x9::solve(){
    if(!this->correctSetting())
        std::cout << "NIE" << std::endl;
    else if(this->initSolution()){
        this->display();
    }
    else
        std::cout << "NIE" << std::endl;
}

int main(){
    Sudoku21x9* sudoku=new Sudoku21x9();
    sudoku->readSetting();
    sudoku->solve();
    delete sudoku;
    return 0;
}
