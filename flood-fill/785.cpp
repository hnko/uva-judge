#include <iostream>
#include <string>
#include <vector>

 using namespace std;
int dr[] = {1, -1 , 0, 0};
int dc[] = {0, 0, 1, -1};
vector<string> v;
bool f = 0;
void floodfill(int r,int c,char cc){
    
    if(r < 0|| r >= v.size()||c < 0|| c >= v[r].size()) return;
    if(v[r][c] == 'X' || v[r][c] == cc && f)return;
    v[r][c] = cc;
    f = 1;
    for(int i = 0; i < 4;i++) {
        floodfill(r+dr[i],c+dc[i],cc);
    }
}
int main(){ 
    string s;
    
    while(getline(cin, s)){
        if(s[0] == '_'){
            for(int i = 0; i < v.size();i++){
                for(int j = 0; j < v[i].size(); j++) {
                    if(v[i][j] != 'X' &&v[i][j] != ' ') {
                        floodfill(i,j,v[i][j]);
                        f = 0;
                    } 
                }
            }
            for(int i = 0; i < v.size();i++){
                cout << v[i] << endl;
            }
            cout << s<< endl;
            v.clear();
                
        }
        else{
            v.push_back(s);
        }
    }
    return 0;
}