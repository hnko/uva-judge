/* AC - iterate through two loops and easy equation */

#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
int cases, aux, base, x, y, z, l, r;
vector <int> in[5];
int input[100][100];
string line;

void solve(){
	for(int i=0; i<9; i+=2){
		for(int j=0; j<=i; j+=2){
			base = input[i][j];
			l = input[i+2][j];
			r = input[i+2][j+2];
		
			/*calculate*/
			input[i+2][j+1] = (input[i+2][j+1] == 0) ? (base-l-r)/2  : input[i+2][j+1]; //z
			input[i+1][j] = (input[i+1][j] == 0) ? l + input[i+2][j+1] : input[i+1][j]; //x = left + z
			input[i+1][j+1] = (input[i+1][j+1] == 0) ? r + input[i+2][j+1] : input[i+1][j+1]; // y = right + z
		}
	}

}

int main(){
	cin >> cases;
	cin.ignore();

	while(cases--){
		
		for(int i=0;  i<5; i++){
			stringstream ss;
			getline(cin, line);
			ss << line;
			while(ss >> aux) in[i].push_back(aux);
		}

		memset(input, 0, sizeof input);
		for(int i=0, t=0; i<9; i = i+2, t++){
			for(int j=0, r=0; j<=i; j = j+2, r++){
				input[i][j] = in[t][r];
			}
		}
		solve();

		for(int i=0; i<9; i++){
			for(int j= 0; j<=i; j++){
				if(j != i) printf("%d ", input[i][j]);
				else printf("%d\n", input[i][j]);
			}
		}
		for(int i=0; i<5; i++)in[i].clear();
	}

	return 0;
}