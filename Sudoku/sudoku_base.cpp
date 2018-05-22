#include <iostream>
#define FIELD 3
#define FULL_FIELD 9

using namespace std;

bool box_empty(int** board,int x,int y){
    if(board[x][y]==0)
        return true;
    else
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
                for(int j=y;j<3;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=x;i<3;i++)
                for(int j=0;j<y;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=x;i<3;i++)
                for(int j=y;j<3;j++)
                    if(board[i][j]==number)
                        return false;
        }
        else if(y<6){
            for(int i=0;i<x;i++)
                for(int j=3;j<y;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=0;i<x;i++)
                for(int j=y;j<6;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=x;i<3;i++)
                for(int j=3;j<y;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=x;i<3;i++)
                for(int j=y;j<6;j++)
                    if(board[i][j]==number)
                        return false;
        }
        else if(y<9){
            for(int i=0;i<x;i++)
                for(int j=6;j<y;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=0;i<x;i++)
                for(int j=y;j<9;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=x;i<3;i++)
                for(int j=6;j<y;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=x;i<3;i++)
                for(int j=y;j<9;j++)
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
                for(int j=y;j<3;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=x;i<6;i++)
                for(int j=0;j<y;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=x;i<6;i++)
                for(int j=y;j<3;j++)
                    if(board[i][j]==number)
                        return false;
        }
        else if(y<6){
            for(int i=3;i<x;i++)
                for(int j=3;j<y;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=3;i<x;i++)
                for(int j=y;j<6;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=x;i<6;i++)
                for(int j=3;j<y;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=x;i<6;i++)
                for(int j=y;j<6;j++)
                    if(board[i][j]==number)
                        return false;
        }
        else if(y<9){
            for(int i=3;i<x;i++)
                for(int j=6;j<y;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=3;i<x;i++)
                for(int j=y;j<9;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=x;i<6;i++)
                for(int j=6;j<y;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=x;i<6;i++)
                for(int j=y;j<9;j++)
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
                for(int j=y;j<3;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=x;i<9;i++)
                for(int j=0;j<y;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=x;i<9;i++)
                for(int j=y;j<3;j++)
                    if(board[i][j]==number)
                        return false;
        }
        else if(y<6){
            for(int i=6;i<x;i++)
                for(int j=3;j<y;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=6;i<x;i++)
                for(int j=y;j<6;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=x;i<9;i++)
                for(int j=3;j<y;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=x;i<9;i++)
                for(int j=y;j<6;j++)
                    if(board[i][j]==number)
                        return false;
        }
        else if(y<9){
            for(int i=6;i<x;i++)
                for(int j=6;j<y;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=6;i<x;i++)
                for(int j=y;j<9;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=x;i<9;i++)
                for(int j=6;j<y;j++)
                    if(board[i][j]==number)
                        return false;
            for(int i=x;i<9;i++)
                for(int j=y;j<9;j++)
                    if(board[i][j]==number)
                        return false;
        }
    }
    return true;
}

bool put_number_available(int** board,int x, int y,int number,int& newX,int& newY){
    if(x==FULL_FIELD-1){
        newX=0;
        if(y==FULL_FIELD-1)
            newY=0;
        else
            newY=y+1;
    }
    else{
        newX=x+1;
        newY=y;
    }

    if(box_empty(board,x,y) && number_permitted(board,x,y,number))
        return true;
    else
        return false;
}

bool solve_sudoku(int** board,int x,int y,int step){
    if(step>=FULL_FIELD*FULL_FIELD)
        cout << "Krok " << step << endl;
    int newX;
    int newY;
    if(step==FULL_FIELD*FULL_FIELD){
        for(int i=1;i<=9;i++){
            if(put_number_available(board,x,y,i,newX,newY)){
                board[x][y]=i;
                for(int i=0;i<FULL_FIELD;i++){
                    for(int j=0;j<FULL_FIELD;j++)
                        cout << board[i][j] << " ";
                    cout << endl;
                }
                return true;
            }
            else
                board[x][y]=0;
        }
        return false;
    }
    else if(!box_empty(board,x,y)){
        if(x!=FULL_FIELD-1)
            solve_sudoku(board,x+1,y,step+1);
        else if(y!=FULL_FIELD-1)
            solve_sudoku(board,0,y+1,step+1);
        else
            return true;
    }
    else{
        for(int i=1;i<=9;i++){
            if(put_number_available(board,x,y,i,newX,newY)){
                board[x][y]=i;
                if(solve_sudoku(board,newX,newY,step+1))
                    return true;
            }
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

    if(solve_sudoku(board,0,0,1)){
        cout << "Sudoku rozwiazane" << endl;
        for(int i=0;i<FULL_FIELD;i++){
            for(int j=0;j<FULL_FIELD;j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
    }
    else{
        cout << "NIE" << endl;
    }

    return 0;
}
