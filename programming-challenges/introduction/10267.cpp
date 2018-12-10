/* AC - introduction - flood fill - dfs iterative */
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <stack>
#include <utility>
#include <algorithm>

using namespace std;
string line, name;
char M[251][251];
char V[251][251];
int tam_x, tam_y, x, y, x1, x2, y1, y2, min_x, max_x, min_y, max_y;
int dx[] = {1,  1,  0, -1, -1, -1, 0, 1};
int dy[] = {0, -1, -1, -1,  0,  1, 1, 1};
char character, prev_char, option;

void fill(int x, int y){
	stack<pair<int, int> > st;
	memset(V, false, sizeof V);

	st.push(make_pair(x, y));
	while( ! st.empty() ){
		pair<int, int> point = st.top(); st.pop();
		x = point.first;
		y = point.second;
	
		if(V[y][x]) continue;
		V[y][x] = true;
		M[y][x] = character;	

		for(int i=0; i<8; i++){

			if(x+dx[i] > 0 and x+dx[i] <= tam_x and y+dy[i] > 0 and y+dy[i] <= tam_y
				and M[y+dy[i]][x+dx[i]] == prev_char){
				
				st.push(make_pair(x+dx[i], y+dy[i]));
			}
		}
		
	}
}

int main(){
	while(true){
		getline(cin, line);
		stringstream ss;
		ss << line;

		ss >> option;
		if(option == 'I'){
			ss >> tam_x >> tam_y;
			memset(M, 'O', sizeof M);

		}else if(option == 'C'){
			memset(M, 'O', sizeof M);

		}else if(option == 'L'){
			ss >> x >> y >> character;
			M[y][x] = character;

		}else if(option == 'V'){
			ss >> x >> y1 >> y2 >> character;
			min_y = min(y1, y2);
			max_y = max(y1, y2);
			for(int i=min_y; i<=max_y; i++) M[i][x] = character;

		}else if(option == 'H'){
			ss >> x1 >> x2 >> y >> character;
			min_x = min(x1, x2);
			max_x = max(x1, x2);
			for(int i=min_x; i<=max_x; i++) M[y][i] = character;

		}else if(option == 'K'){
			ss >> x1 >> y1 >> x2 >> y2 >> character;
			min_y = min(y1, y2);
			max_y = max(y1, y2);
			min_x = min(x1, x2);
			max_x = max(x1, x2);
			for(int i=min_y; i<=max_y; i++){
				for(int j=min_x; j<=max_x; j++) M[i][j] = character;
			}

		}else if(option == 'F'){
			ss >> x1 >> y1 >> character;

			if(x1 <= tam_x and x1 > 0 and y1 <= tam_y and y1 > 0){
				prev_char = M[y1][x1];
				fill(x1, y1);
			}
		}else if(option == 'S'){
			ss >> name;
			cout << name << endl;
			for(int i=1; i<=tam_y; i++){
				for(int j=1; j<=tam_x; j++)
					cout << M[i][j];
				cout << endl;
			}
		}else if (option == 'X'){
			break;

		}else{
			continue;
		}
	}

	return 0;
}