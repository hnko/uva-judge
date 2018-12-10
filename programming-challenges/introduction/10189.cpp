/* AC */
#include <iostream>

#include <string>

using namespace std;

string field[101];
 
 
 
int main(){

    int cnt = 0;
    int row, column;
    while(cin >> row >> column){
        if(row == 0 and column == 0) return 0;
        cin.ignore();
 
        for(int i = 0; i < row; i++)
            cin >> field[i];
 
 
        if(cnt) printf("\n");
 
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
 
                if( field[i][j] == '*' )
                    continue;
 
                int temp = 0;
 
                if( i + 1 < row and field[i + 1][j] == '*' )
                    ++temp;
                if( i + 1 < row and j + 1 < column and field[i + 1][j + 1] == '*' )
                    ++temp;
                if( j + 1 < column and field[i][j + 1] == '*' )
                    ++temp;
                if( i - 1 >= 0 and j + 1 < column and field[i - 1][j + 1] == '*' )
                    ++temp;
                if( i - 1 >= 0 and field[i - 1][j] == '*' )
                    ++temp;
                if( i - 1 >= 0 and j - 1 >= 0 and field[i - 1][j - 1] == '*' )
                    ++temp;
                if( j - 1 >= 0 and field[i][j - 1] == '*' )
                    ++temp;
                if( i + 1 < row and j - 1 >= 0 and field[i + 1][j - 1] == '*' )
                    ++temp;
 
 
            field[i][j] = temp + '0';
 
            }
        }
 
 
        printf("Field #%d:\n", ++cnt);
 
 
       for(int i = 0; i < row; ++i){
            for(int j = 0; j < column; ++j)
                cout << field[i][j];
            cout << endl;
       }
       for(int i=0; i<row; i++) field[i].clear();
 
    }
 
    return 0;
}