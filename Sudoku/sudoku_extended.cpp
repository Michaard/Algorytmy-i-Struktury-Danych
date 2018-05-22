#include <iostream>
#define FULL_FIELD_X 21
#define FULL_FIELD_Y 9

using namespace std;

void wyswietl_sudoku(int** board){
    for(int i=0;i<FULL_FIELD_X;i++){
        for(int j=0;j<FULL_FIELD_Y;j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

bool field_filled(int& n){
    if(n==0)
        return false;
    else
        return true;
}

bool correct_input(int** board){
    for(int x=0;x<9;x++){
        for(int y=0;y<9;y++){
            if(board[x][y]!=0){
                for(int j=y+1;j<FULL_FIELD_Y;j++){
                    if(board[x][y]==board[x][j])
                        return false;
                }
                if(x<6){
                    for(int i=x+1;i<9;i++){
                        if(board[i][y]==board[x][y])
                            return false;
                    }
                }
                else if(x>=6 && x<9){
                    for(int i=x+1;i<9;i++){
                        if(board[i][y]==board[x][y])
                            return false;
                    }
                    for(int i=x+1;i<15;i++){
                        if(board[i][y]==board[x][y])
                            return false;
                    }
                }
                else if(x>=9 && x<12){
                    for(int i=x+1;i<15;i++){
                        if(board[i][y]==board[x][y])
                            return false;
                    }
                }
                else if(x>=12 && x<15){
                    for(int i=x+1;i<15;i++){
                        if(board[i][y]==board[x][y])
                            return false;
                    }
                    for(int i=x+1;i<21;i++){
                        if(board[i][y]==board[x][y])
                            return false;
                    }
                }
                else if(x>=15 && x<21){
                    for(int i=x+1;i<21;i++){
                        if(board[i][y]==board[x][y])
                            return false;
                    }
                }
                if(x<3){
                    if(y<3){
                        for(int i=0;i<x;i++){
                            for(int j=0;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                            for(int j=y+1;j<3;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        }
                        for(int i=x+1;i<3;i++){
                            for(int j=0;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                            for(int j=y+1;j<3;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        }
                    }
                    else if(y<6){
                        for(int i=0;i<x;i++){
                            for(int j=3;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                            for(int j=y+1;j<6;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        }
                        for(int i=x+1;i<3;i++){
                            for(int j=3;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                            for(int j=y+1;j<6;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        }
                    }
                    else if(y<9){
                        for(int i=0;i<x;i++){
                            for(int j=6;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                            for(int j=y+1;j<9;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        }
                        for(int i=x+1;i<3;i++){
                            for(int j=6;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                            for(int j=y+1;j<9;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        }
                    }
                }
                else if(x<6){
                    if(y<3){
                        for(int i=3;i<x;i++){
                            for(int j=0;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                            for(int j=y+1;j<3;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        }
                        for(int i=x+1;i<6;i++){
                            for(int j=0;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                            for(int j=y+1;j<3;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        }
                    }
                    else if(y<6){
                        for(int i=3;i<x;i++){
                            for(int j=3;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                            for(int j=y+1;j<6;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        }
                        for(int i=x+1;i<6;i++){
                            for(int j=3;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                            for(int j=y+1;j<6;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        }
                    }
                    else if(y<9){
                        for(int i=3;i<x;i++){
                            for(int j=6;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                            for(int j=y+1;j<9;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        }
                        for(int i=x+1;i<6;i++){
                            for(int j=6;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                            for(int j=y+1;j<9;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        }
                    }
                }
                else if(x<9){
                    if(y<3){
                        for(int i=6;i<x;i++){
                            for(int j=0;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                            for(int j=y+1;j<3;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        }
                        for(int i=x+1;i<9;i++){
                            for(int j=0;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                            for(int j=y+1;j<3;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        }
                    }
                    else if(y<6){
                        for(int i=6;i<x;i++){
                            for(int j=3;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                            for(int j=y+1;j<6;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        }
                        for(int i=x+1;i<9;i++){
                            for(int j=3;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                            for(int j=y+1;j<6;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        }
                    }
                    else if(y<9){
                        for(int i=6;i<x;i++){
                            for(int j=6;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                            for(int j=y+1;j<9;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        }
                        for(int i=x+1;i<9;i++){
                            for(int j=6;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                            for(int j=y+1;j<9;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        }
                    }
                }
                else if(x<12){
                    if(y<3){
                        for(int i=9;i<x;i++){
                            for(int j=0;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                            for(int j=y+1;j<3;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        }
                        for(int i=x+1;i<12;i++){
                            for(int j=0;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                            for(int j=y+1;j<3;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        }
                    }
                    else if(y<6){
                        for(int i=9;i<x;i++){
                            for(int j=3;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                            for(int j=y+1;j<6;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        }
                        for(int i=x+1;i<12;i++){
                            for(int j=3;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                            for(int j=y+1;j<6;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        }
                    }
                    else if(y<9){
                        for(int i=9;i<x;i++){
                            for(int j=6;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                            for(int j=y+1;j<9;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        }
                        for(int i=x+1;i<12;i++){
                            for(int j=6;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                            for(int j=y+1;j<9;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        }
                    }
                }
                else if(x<15){
                    if(y<3){
                        for(int i=12;i<x;i++){
                            for(int j=0;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                            for(int j=y+1;j<3;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        }
                        for(int i=x+1;i<15;i++){
                            for(int j=0;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                            for(int j=y+1;j<3;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        }
                    }
                    else if(y<6){
                        for(int i=12;i<x;i++){
                            for(int j=3;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                            for(int j=y+1;j<6;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        }
                        for(int i=x+1;i<15;i++){
                            for(int j=3;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                            for(int j=y+1;j<6;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        }
                    }
                    else if(y<9){
                        for(int i=12;i<x;i++){
                            for(int j=6;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                            for(int j=y+1;j<9;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        }
                        for(int i=x+1;i<15;i++){
                            for(int j=6;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                            for(int j=y+1;j<9;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        }
                    }
                }
                else if(x<18){
                    if(y<3){
                        for(int i=15;i<x;i++){
                            for(int j=0;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                            for(int j=y+1;j<3;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        }
                        for(int i=x+1;i<18;i++){
                            for(int j=0;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                            for(int j=y+1;j<3;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        }
                    }
                    else if(y<6){
                        for(int i=15;i<x;i++){
                            for(int j=3;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                            for(int j=y+1;j<6;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        }
                        for(int i=x+1;i<18;i++){
                            for(int j=3;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                            for(int j=y+1;j<6;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        }
                    }
                    else if(y<9){
                        for(int i=15;i<x;i++){
                            for(int j=6;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                            for(int j=y+1;j<9;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        }
                        for(int i=x+1;i<18;i++){
                            for(int j=6;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                            for(int j=y+1;j<9;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        }
                    }
                }
                else if(x<21){
                    if(y<3){
                        for(int i=18;i<x;i++){
                            for(int j=0;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                            for(int j=y+1;j<3;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        }
                        for(int i=x+1;i<21;i++){
                            for(int j=0;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                            for(int j=y+1;j<3;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        }
                    }
                    else if(y<6){
                        for(int i=18;i<x;i++){
                            for(int j=3;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                            for(int j=y+1;j<6;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        }
                        for(int i=x+1;i<21;i++){
                            for(int j=3;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                            for(int j=y+1;j<6;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        }
                    }
                    else if(y<9){
                        for(int i=18;i<x;i++){
                            for(int j=6;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        for(int i=18;i<x;i++)
                            for(int j=y+1;j<9;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        }
                        for(int i=x+1;i<21;i++){
                            for(int j=6;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                            for(int j=y+1;j<9;j++)
                                if(board[i][j]==board[x][y])
                                    return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

bool number_permitted(int** board,int x,int y,int number){
    for(int i=0;i<y;i++){
        if(board[x][i]==number)
            return false;
    }
    for(int i=y+1;i<9;i++){
        if(board[x][i]==number)
            return false;
    }
    if(x<6){
        for(int i=0;i<x;i++){
            if(board[i][y]==number)
                return false;
        }
        for(int i=x+1;i<9;i++){
            if(board[i][y]==number)
                return false;
        }
    }
    else if(x>=6 && x<9){
        for(int i=0;i<x;i++){
            if(board[i][y]==number)
                return false;
        }
        for(int i=x+1;i<9;i++){
            if(board[i][y]==number)
                return false;
        }
        for(int i=9;i<x;i++){
            if(board[i][y]==number)
                return false;
        }
        for(int i=x+1;i<15;i++){
            if(board[i][y]==number)
                return false;
        }
    }
    else if(x>=9 && x<12){
        for(int i=6;i<x;i++){
            if(board[i][y]==number)
                return false;
        }
        for(int i=x+1;i<15;i++){
            if(board[i][y]==number)
                return false;
        }
    }
    else if(x>=12 && x<15){
        for(int i=6;i<x;i++){
            if(board[i][y]==number)
                return false;
        }
        for(int i=x+1;i<15;i++){
            if(board[i][y]==number)
                return false;
        }
        for(int i=15;i<x;i++){
            if(board[i][y]==number)
                return false;
        }
        for(int i=x+1;i<21;i++){
            if(board[i][y]==number)
                return false;
        }
    }
    else if(x>=15 && x<21){
        for(int i=12;i<x;i++){
            if(board[i][y]==number)
                return false;
        }
        for(int i=x+1;i<21;i++){
            if(board[i][y]==number)
                return false;
        }
    }
    if(x<3){
        if(y<3){
            for(int i=0;i<x;i++){
                for(int j=0;j<y;j++)
                    if(board[i][j]==number)
                        return false;
                for(int j=y+1;j<3;j++)
                    if(board[i][j]==number)
                        return false;
            }
            for(int i=x+1;i<3;i++){
                for(int j=0;j<y;j++)
                    if(board[i][j]==number)
                        return false;
                for(int j=y+1;j<3;j++)
                    if(board[i][j]==number)
                        return false;
            }
        }
        else if(y<6){
            for(int i=0;i<x;i++){
                for(int j=3;j<y;j++)
                    if(board[i][j]==number)
                        return false;
                for(int j=y+1;j<6;j++)
                    if(board[i][j]==number)
                        return false;
            }
            for(int i=x+1;i<3;i++){
                for(int j=3;j<y;j++)
                    if(board[i][j]==number)
                        return false;
                for(int j=y+1;j<6;j++)
                    if(board[i][j]==number)
                        return false;
            }
        }
        else if(y<9){
            for(int i=0;i<x;i++){
                for(int j=6;j<y;j++)
                    if(board[i][j]==number)
                        return false;
                for(int j=y+1;j<9;j++)
                    if(board[i][j]==number)
                        return false;
            }
            for(int i=x+1;i<3;i++){
                for(int j=6;j<y;j++)
                    if(board[i][j]==number)
                        return false;
                for(int j=y+1;j<9;j++)
                    if(board[i][j]==number)
                        return false;
            }
        }
    }
    else if(x<6){
        if(y<3){
            for(int i=3;i<x;i++){
                for(int j=0;j<y;j++)
                    if(board[i][j]==number)
                        return false;
                for(int j=y+1;j<3;j++)
                    if(board[i][j]==number)
                        return false;
            }
            for(int i=x+1;i<6;i++){
                for(int j=0;j<y;j++)
                    if(board[i][j]==number)
                        return false;
                for(int j=y+1;j<3;j++)
                    if(board[i][j]==number)
                        return false;
            }
        }
        else if(y<6){
            for(int i=3;i<x;i++){
                for(int j=3;j<y;j++)
                    if(board[i][j]==number)
                        return false;
                for(int j=y+1;j<6;j++)
                    if(board[i][j]==number)
                        return false;
            }
            for(int i=x+1;i<6;i++){
                for(int j=3;j<y;j++)
                    if(board[i][j]==number)
                        return false;
                for(int j=y+1;j<6;j++)
                    if(board[i][j]==number)
                        return false;
            }
        }
        else if(y<9){
            for(int i=3;i<x;i++){
                for(int j=6;j<y;j++)
                    if(board[i][j]==number)
                        return false;
                for(int j=y+1;j<9;j++)
                    if(board[i][j]==number)
                        return false;
            }
            for(int i=x+1;i<6;i++){
                for(int j=6;j<y;j++)
                    if(board[i][j]==number)
                        return false;
                for(int j=y+1;j<9;j++)
                    if(board[i][j]==number)
                        return false;
            }
        }
    }
    else if(x<9){
        if(y<3){
            for(int i=6;i<x;i++){
                for(int j=0;j<y;j++)
                    if(board[i][j]==number)
                        return false;
                for(int j=y+1;j<3;j++)
                    if(board[i][j]==number)
                        return false;
            }
            for(int i=x+1;i<9;i++){
                for(int j=0;j<y;j++)
                    if(board[i][j]==number)
                        return false;
                for(int j=y+1;j<3;j++)
                    if(board[i][j]==number)
                        return false;
            }
        }
        else if(y<6){
            for(int i=6;i<x;i++){
                for(int j=3;j<y;j++)
                    if(board[i][j]==number)
                        return false;
                for(int j=y+1;j<6;j++)
                    if(board[i][j]==number)
                        return false;
            }
            for(int i=x+1;i<9;i++){
                for(int j=3;j<y;j++)
                    if(board[i][j]==number)
                        return false;
                for(int j=y+1;j<6;j++)
                    if(board[i][j]==number)
                        return false;
            }
        }
        else if(y<9){
            for(int i=6;i<x;i++){
                for(int j=6;j<y;j++)
                    if(board[i][j]==number)
                        return false;
                for(int j=y+1;j<9;j++)
                    if(board[i][j]==number)
                        return false;
            }
            for(int i=x+1;i<9;i++){
                for(int j=6;j<y;j++)
                    if(board[i][j]==number)
                        return false;
                for(int j=y+1;j<9;j++)
                    if(board[i][j]==number)
                        return false;
            }
        }
    }
    else if(x<12){
        if(y<3){
            for(int i=9;i<x;i++){
                for(int j=0;j<y;j++)
                    if(board[i][j]==number)
                        return false;
                for(int j=y+1;j<3;j++)
                    if(board[i][j]==number)
                        return false;
            }
            for(int i=x+1;i<12;i++){
                for(int j=0;j<y;j++)
                    if(board[i][j]==number)
                        return false;
                for(int j=y+1;j<3;j++)
                    if(board[i][j]==number)
                        return false;
            }
        }
        else if(y<6){
            for(int i=9;i<x;i++){
                for(int j=3;j<y;j++)
                    if(board[i][j]==number)
                        return false;
                for(int j=y+1;j<6;j++)
                    if(board[i][j]==number)
                        return false;
            }
            for(int i=x+1;i<12;i++){
                for(int j=3;j<y;j++)
                    if(board[i][j]==number)
                        return false;
                for(int j=y+1;j<6;j++)
                    if(board[i][j]==number)
                        return false;
            }
        }
        else if(y<9){
            for(int i=9;i<x;i++){
                for(int j=6;j<y;j++)
                    if(board[i][j]==number)
                        return false;
                for(int j=y+1;j<9;j++)
                    if(board[i][j]==number)
                        return false;
            }
            for(int i=x+1;i<12;i++){
                for(int j=6;j<y;j++)
                    if(board[i][j]==number)
                        return false;
                for(int j=y+1;j<9;j++)
                    if(board[i][j]==number)
                        return false;
            }
        }
    }
    else if(x<15){
        if(y<3){
            for(int i=12;i<x;i++){
                for(int j=0;j<y;j++)
                    if(board[i][j]==number)
                        return false;
                for(int j=y+1;j<3;j++)
                    if(board[i][j]==number)
                        return false;
            }
            for(int i=x+1;i<15;i++){
                for(int j=0;j<y;j++)
                    if(board[i][j]==number)
                        return false;
                for(int j=y+1;j<3;j++)
                    if(board[i][j]==number)
                        return false;
            }
        }
        else if(y<6){
            for(int i=12;i<x;i++){
                for(int j=3;j<y;j++)
                    if(board[i][j]==number)
                        return false;
                for(int j=y+1;j<6;j++)
                    if(board[i][j]==number)
                        return false;
            }
            for(int i=x+1;i<15;i++){
                for(int j=3;j<y;j++)
                    if(board[i][j]==number)
                        return false;
                for(int j=y+1;j<6;j++)
                    if(board[i][j]==number)
                        return false;
            }
        }
        else if(y<9){
            for(int i=12;i<x;i++){
                for(int j=6;j<y;j++)
                    if(board[i][j]==number)
                        return false;
                for(int j=y+1;j<9;j++)
                    if(board[i][j]==number)
                        return false;
            }
            for(int i=x+1;i<15;i++){
                for(int j=6;j<y;j++)
                    if(board[i][j]==number)
                        return false;
                for(int j=y+1;j<9;j++)
                    if(board[i][j]==number)
                        return false;
            }
        }
    }
    else if(x<18){
        if(y<3){
            for(int i=15;i<x;i++){
                for(int j=0;j<y;j++)
                    if(board[i][j]==number)
                        return false;
                for(int j=y+1;j<3;j++)
                    if(board[i][j]==number)
                        return false;
            }
            for(int i=x+1;i<18;i++){
                for(int j=0;j<y;j++)
                    if(board[i][j]==number)
                        return false;
                for(int j=y+1;j<3;j++)
                    if(board[i][j]==number)
                        return false;
            }
        }
        else if(y<6){
            for(int i=15;i<x;i++){
                for(int j=3;j<y;j++)
                    if(board[i][j]==number)
                        return false;
                for(int j=y+1;j<6;j++)
                    if(board[i][j]==number)
                        return false;
            }
            for(int i=x+1;i<18;i++){
                for(int j=3;j<y;j++)
                    if(board[i][j]==number)
                        return false;
                for(int j=y+1;j<6;j++)
                    if(board[i][j]==number)
                        return false;
            }
        }
        else if(y<9){
            for(int i=15;i<x;i++){
                for(int j=6;j<y;j++)
                    if(board[i][j]==number)
                        return false;
                for(int j=y+1;j<9;j++)
                    if(board[i][j]==number)
                        return false;
            }
            for(int i=x+1;i<18;i++){
                for(int j=6;j<y;j++)
                    if(board[i][j]==number)
                        return false;
                for(int j=y+1;j<9;j++)
                    if(board[i][j]==number)
                        return false;
            }
        }
    }
    else if(x<21){
        if(y<3){
            for(int i=18;i<x;i++){
                for(int j=0;j<y;j++)
                    if(board[i][j]==number)
                        return false;
                for(int j=y+1;j<3;j++)
                    if(board[i][j]==number)
                        return false;
            }
            for(int i=x+1;i<21;i++){
                for(int j=0;j<y;j++)
                    if(board[i][j]==number)
                        return false;
                for(int j=y+1;j<3;j++)
                    if(board[i][j]==number)
                        return false;
            }
        }
        else if(y<6){
            for(int i=18;i<x;i++){
                for(int j=3;j<y;j++)
                    if(board[i][j]==number)
                        return false;
                for(int j=y+1;j<6;j++)
                    if(board[i][j]==number)
                        return false;
            }
            for(int i=x+1;i<21;i++){
                for(int j=3;j<y;j++)
                    if(board[i][j]==number)
                        return false;
                for(int j=y+1;j<6;j++)
                    if(board[i][j]==number)
                        return false;
            }
        }
        else if(y<9){
            for(int i=18;i<x;i++){
                for(int j=6;j<y;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=18;i<x;i++)
                for(int j=y+1;j<9;j++)
                    if(board[i][j]==number)
                        return false;
            }
            for(int i=x+1;i<21;i++){
                for(int j=6;j<y;j++)
                    if(board[i][j]==number)
                        return false;
                for(int j=y+1;j<9;j++)
                    if(board[i][j]==number)
                        return false;
            }
        }
    }
    return true;
}

bool put_first_number_available(int** board,int init_x,int init_y,int number){
    if(number_permitted(board,init_x,init_y,number))
        return true;
    else
        return false;
}

bool put_number_available(int** board,int x,int y,int number){
    if(number_permitted(board,x,y,number))
        return true;
    else
        return false;
}

bool solve_sudoku(int** board,int x,int y,int number){
    board[x][y]=number;
    if(x==FULL_FIELD_X-1 && y==FULL_FIELD_Y-1){
        return true;
    }

    int new_x;
    int new_y;
    if(x!=FULL_FIELD_X-1){
        new_x=x+1;
        new_y=y;
    }
    else if(y!=FULL_FIELD_Y-1){
        new_y=y+1;
        new_x=0;
    }
    else{
        return true;
    }
    if(field_filled(board[new_x][new_y])){
        while(field_filled(board[new_x][new_y])){
            if(new_x!=FULL_FIELD_X-1){
                new_x=new_x+1;
                new_y=new_y;
            }
            else if(new_y!=FULL_FIELD_Y-1){
                new_y=new_y+1;
                new_x=0;
            }
            else{
                return true;
            }
        }
    }
    for(int i=1;i<=9;i++){
        if(put_number_available(board,new_x,new_y,i))
            if(solve_sudoku(board,new_x,new_y,i))
                return true;
    }
    board[x][y]=0;
    return false;
}

bool solve_sudoku_init(int** board){
    int x=0;
    int y=0;
    if(field_filled(board[x][y])){
        while(field_filled(board[x][y])){
            if(x!=FULL_FIELD_X)
                x++;
            else if(y!=FULL_FIELD_Y){
                x=0;
                y++;
            }
            else
                return true;
        }
    }
    for(int i=1;i<9;i++){
        if(put_first_number_available(board,x,y,i)){
            if(solve_sudoku(board,x,y,i))
                return true;
        }
    }
    return false;
}

int main(){
    int** board=new int*[FULL_FIELD_X];
    for(int i=0;i<FULL_FIELD_X;i++)
        board[i]=new int[FULL_FIELD_Y];

    for(int i=0;i<FULL_FIELD_X;i++)
        for(int j=0;j<FULL_FIELD_Y;j++)
            cin >> board[i][j];

    if(!correct_input(board))
        cout << "NIE" << endl;
    else if(solve_sudoku_init(board)){
        wyswietl_sudoku(board);
    }
    else
        cout << "NIE" << endl;

    return 0;
}
