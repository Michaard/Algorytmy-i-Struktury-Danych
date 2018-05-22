#include <iostream>
#define FULL_FIELD 9

using namespace std;

void wyswietl_sudoku(int** board){
    cout << endl;
    for(int i=0;i<FULL_FIELD;i++){
        for(int j=0;j<FULL_FIELD;j++)
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

bool wrong_input(int** board){
    for(int x=0;x<9;x++){
        for(int y=0;y<9;y++){
            if(board[x][y]!=0){
                for(int i=x+1;i<FULL_FIELD;i++){
                    if(board[x][y]==board[i][y])
                        return true;
                }
                for(int j=y+1;j<FULL_FIELD;j++){
                    if(board[x][y]==board[x][j])
                        return true;
                }
                if(x<3){
                    if(y<3){
                        for(int i=0;i<x;i++)
                            for(int j=0;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return true;
                        for(int i=0;i<x;i++)
                            for(int j=y+1;j<3;j++)
                                if(board[i][j]==board[x][y])
                                    return true;
                        for(int i=x+1;i<3;i++)
                            for(int j=0;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return true;
                        for(int i=x+1;i<3;i++)
                            for(int j=y+1;j<3;j++)
                                if(board[i][j]==board[x][y])
                                    return true;
                    }
                    else if(y<6){
                        for(int i=0;i<x;i++)
                            for(int j=3;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return true;
                        for(int i=0;i<x;i++)
                            for(int j=y+1;j<6;j++)
                                if(board[i][j]==board[x][y])
                                    return true;
                        for(int i=x+1;i<3;i++)
                            for(int j=3;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return true;
                        for(int i=x+1;i<3;i++)
                            for(int j=y+1;j<6;j++)
                                if(board[i][j]==board[x][y])
                                    return true;
                    }
                    else if(y<9){
                        for(int i=0;i<x;i++)
                            for(int j=6;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return true;
                        for(int i=0;i<x;i++)
                            for(int j=y+1;j<9;j++)
                                if(board[i][j]==board[x][y])
                                    return true;
                        for(int i=x+1;i<3;i++)
                            for(int j=6;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return true;
                        for(int i=x+1;i<3;i++)
                            for(int j=y+1;j<9;j++)
                                if(board[i][j]==board[x][y])
                                    return true;
                    }
                }
                else if(x<6){
                    if(y<3){
                        for(int i=3;i<x;i++)
                            for(int j=0;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return true;
                        for(int i=3;i<x;i++)
                            for(int j=y+1;j<3;j++)
                                if(board[i][j]==board[x][y])
                                    return true;
                        for(int i=x+1;i<6;i++)
                            for(int j=0;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return true;
                        for(int i=x+1;i<6;i++)
                            for(int j=y+1;j<3;j++)
                                if(board[i][j]==board[x][y])
                                    return true;
                    }
                    else if(y<6){
                        for(int i=3;i<x;i++)
                            for(int j=3;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return true;
                        for(int i=3;i<x;i++)
                            for(int j=y+1;j<6;j++)
                                if(board[i][j]==board[x][y])
                                    return true;
                        for(int i=x+1;i<6;i++)
                            for(int j=3;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return true;
                        for(int i=x+1;i<6;i++)
                            for(int j=y+1;j<6;j++)
                                if(board[i][j]==board[x][y])
                                    return true;
                    }
                    else if(y<9){
                        for(int i=3;i<x;i++)
                            for(int j=6;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return true;
                        for(int i=3;i<x;i++)
                            for(int j=y+1;j<9;j++)
                                if(board[i][j]==board[x][y])
                                    return true;
                        for(int i=x+1;i<6;i++)
                            for(int j=6;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return true;
                        for(int i=x+1;i<6;i++)
                            for(int j=y+1;j<9;j++)
                                if(board[i][j]==board[x][y])
                                    return true;
                    }
                }
                else if(x<9){
                    if(y<3){
                        for(int i=6;i<x;i++)
                            for(int j=0;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return true;
                        for(int i=6;i<x;i++)
                            for(int j=y+1;j<3;j++)
                                if(board[i][j]==board[x][y])
                                    return true;
                        for(int i=x+1;i<9;i++)
                            for(int j=0;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return true;
                        for(int i=x+1;i<9;i++)
                            for(int j=y+1;j<3;j++)
                                if(board[i][j]==board[x][y])
                                    return true;
                    }
                    else if(y<6){
                        for(int i=6;i<x;i++)
                            for(int j=3;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return true;
                        for(int i=6;i<x;i++)
                            for(int j=y+1;j<6;j++)
                                if(board[i][j]==board[x][y])
                                    return true;
                        for(int i=x+1;i<9;i++)
                            for(int j=3;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return true;
                        for(int i=x+1;i<9;i++)
                            for(int j=y+1;j<6;j++)
                                if(board[i][j]==board[x][y])
                                    return true;
                    }
                    else if(y<9){
                        for(int i=6;i<x;i++)
                            for(int j=6;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return true;
                        for(int i=6;i<x;i++)
                            for(int j=y+1;j<9;j++)
                                if(board[i][j]==board[x][y])
                                    return true;
                        for(int i=x+1;i<9;i++)
                            for(int j=6;j<y;j++)
                                if(board[i][j]==board[x][y])
                                    return true;
                        for(int i=x+1;i<9;i++)
                            for(int j=y+1;j<9;j++)
                                if(board[i][j]==board[x][y])
                                    return true;
                    }
                }
            }
        }
    }
    return false;
}

bool number_permitted(int** board,int x,int y,int number){
    for(int i=0;i<x;i++){
        if(board[i][y]==number)
            return false;
    }
    for(int i=x+1;i<FULL_FIELD;i++){
        if(board[i][y]==number)
            return false;
    }
    for(int i=0;i<y;i++){
        if(board[x][i]==number)
            return false;
    }
    for(int i=y+1;i<FULL_FIELD;i++){
        if(board[x][i]==number)
            return false;
    }
    if(x<3){
        if(y<3){
            for(int i=0;i<x;i++)
                for(int j=0;j<y;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=0;i<x;i++)
                for(int j=y+1;j<3;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=x+1;i<3;i++)
                for(int j=0;j<y;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=x+1;i<3;i++)
                for(int j=y+1;j<3;j++)
                    if(board[i][j]==number)
                        return false;
        }
        else if(y<6){
            for(int i=0;i<x;i++)
                for(int j=3;j<y;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=0;i<x;i++)
                for(int j=y+1;j<6;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=x+1;i<3;i++)
                for(int j=3;j<y;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=x+1;i<3;i++)
                for(int j=y+1;j<6;j++)
                    if(board[i][j]==number)
                        return false;
        }
        else if(y<9){
            for(int i=0;i<x;i++)
                for(int j=6;j<y;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=0;i<x;i++)
                for(int j=y+1;j<9;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=x+1;i<3;i++)
                for(int j=6;j<y;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=x+1;i<3;i++)
                for(int j=y+1;j<9;j++)
                    if(board[i][j]==number)
                        return false;
        }
    }
    else if(x<6){
        if(y<3){
            for(int i=3;i<x;i++)
                for(int j=0;j<y;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=3;i<x;i++)
                for(int j=y+1;j<3;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=x+1;i<6;i++)
                for(int j=0;j<y;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=x+1;i<6;i++)
                for(int j=y+1;j<3;j++)
                    if(board[i][j]==number)
                        return false;
        }
        else if(y<6){
            for(int i=3;i<x;i++)
                for(int j=3;j<y;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=3;i<x;i++)
                for(int j=y+1;j<6;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=x+1;i<6;i++)
                for(int j=3;j<y;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=x+1;i<6;i++)
                for(int j=y+1;j<6;j++)
                    if(board[i][j]==number)
                        return false;
        }
        else if(y<9){
            for(int i=3;i<x;i++)
                for(int j=6;j<y;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=3;i<x;i++)
                for(int j=y+1;j<9;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=x+1;i<6;i++)
                for(int j=6;j<y;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=x+1;i<6;i++)
                for(int j=y+1;j<9;j++)
                    if(board[i][j]==number)
                        return false;
        }
    }
    else if(x<9){
        if(y<3){
            for(int i=6;i<x;i++)
                for(int j=0;j<y;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=6;i<x;i++)
                for(int j=y+1;j<3;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=x+1;i<9;i++)
                for(int j=0;j<y;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=x+1;i<9;i++)
                for(int j=y+1;j<3;j++)
                    if(board[i][j]==number)
                        return false;
        }
        else if(y<6){
            for(int i=6;i<x;i++)
                for(int j=3;j<y;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=6;i<x;i++)
                for(int j=y+1;j<6;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=x+1;i<9;i++)
                for(int j=3;j<y;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=x+1;i<9;i++)
                for(int j=y+1;j<6;j++)
                    if(board[i][j]==number)
                        return false;
        }
        else if(y<9){
            for(int i=6;i<x;i++)
                for(int j=6;j<y;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=6;i<x;i++)
                for(int j=y+1;j<9;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=x+1;i<9;i++)
                for(int j=6;j<y;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=x+1;i<9;i++)
                for(int j=y+1;j<9;j++)
                    if(board[i][j]==number)
                        return false;
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
    //cout << "Pole [" << x << "," << y << "]" << endl;
    board[x][y]=number;
    if(x==FULL_FIELD-1 && y==FULL_FIELD-1){
        return true;
    }

    int new_x;
    int new_y;
    if(x!=FULL_FIELD-1){
        //cout << x << " != " << FULL_FIELD << endl;
        new_x=x+1;
        new_y=y;
    }
    else if(y!=FULL_FIELD-1){
        new_y=y+1;
        new_x=0;
    }
    /*else if(new_y==FULL_FIELD-1){
        if(new_x!=FULL_FIELD-1)
            new_x=x+1;
        else
            return true;
    }*/
    else{
        return true;
    }
    //cout << "Nowe wspolrzedne ustalone1 = " << new_x << " " << new_y << endl;
    if(field_filled(board[new_x][new_y])){
        //cout << "Pole " << new_x << "," << new_y << " zajete!" << endl;
        while(field_filled(board[new_x][new_y])){
            //cout << "Pole [" << new_x << "," << new_y << "] = " << board[new_x][new_y] << " !=" << 0 << endl;
            if(new_x!=FULL_FIELD-1){
                new_x=new_x+1;
                new_y=new_y;
            }
            else if(new_y!=FULL_FIELD-1){
                new_y=new_y+1;
                new_x=0;
            }
            /*else if(new_y==FULL_FIELD-1){
                if(new_x!=FULL_FIELD-1)
                    new_x=new_x+1;
                else
                    return true;
            }*/
            else{
                return true;
            }
            //cout << "Nowe wspolrzedne ustalone2 = " << new_x << " " << new_y << endl;
        }
    }
    //wyswietl_sudoku(board);
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
            //cout << "Pole [" << x << "," << y << "] = " << board[x][y] << " !=" << 0 << endl;
            if(x!=FULL_FIELD)
                x++;
            else if(y!=FULL_FIELD){
                x=0;
                y++;
            }
            /*else if(y==FULL_FIELD){
                if(x!=FULL_FIELD)
                    x++;
                else
                    return true;
            }*/
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
    int** board=new int*[FULL_FIELD];
    for(int i=0;i<FULL_FIELD;i++)
        board[i]=new int[FULL_FIELD];

    for(int i=0;i<FULL_FIELD;i++)
        for(int j=0;j<FULL_FIELD;j++)
            cin >> board[i][j];

    if(wrong_input(board))
        cout << "NIE bo zle wejscie" << endl;
    else if(solve_sudoku_init(board)){
        cout << "\nSudoku rozwiazane\n" << endl;
        for(int i=0;i<FULL_FIELD;i++){
            for(int j=0;j<FULL_FIELD;j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
    }
    else
        cout << "NIE" << endl;

    return 0;
}
