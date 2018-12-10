/*RTE*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <cctype>
using namespace std;

vector<string> G;
int V[40][100];
char letter;

int dx_move[]={0,  0, 1, -1, 1, -1,  1, -1};
int dy_move[]={1, -1, 0,  0, 1, -1, -1,  1};
bool save(int x, int y){
	return x>=0 and x<G.size() and y>= 0 and y<G[x].size() and V[x][y] == 0 and G[x][y] == letter;
}

int floodfill(int x, int y){
	V[x][y] = 1;
	int ans = 1;
	for(int i=0; i<8; i++){
		int dx, dy;
		dx = x+dx_move[i];
		dy = y+dy_move[i];
		if(save(dx, dy)){
			ans += floodfill(dx, dy);
		}
		
	}
	return ans;
}

int main(){
	int t;
	string s;
	istringstream iss;
	getline(cin, s);

	iss.str(s);
	iss >> t;
	iss.clear();
	getline(cin, s);
	while(t--){
		while(true){
			getline(cin, s);
			if(isdigit(s[0])){
				break;
			}else{
				G.push_back(s);
			}
		}
		int x, y;
		do{
			iss.str(s);
			iss >> x >> y;
			//cout << x << y;
			memset(V, 0, sizeof V);
			iss.clear();
			letter = G[x-1][y-1];
			cout << floodfill(x-1, y-1) << endl;
		}while (getline(cin, s) and s!= "");

		if (t) cout << endl;
		G.clear();
	}

	return 0;
}