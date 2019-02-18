/* AC - go through a string */
#include <iostream>
#include <string>
#include <map>

using namespace std;

string line;
map <char, int> mp;
char symbol, aux;
int cost, t, v, n_lines, ans;

int main(){
	cin >> t;
	while(t--){
		cin >> v;
		while(v--){
			cin >> symbol >> cost;
			cin.ignore();

			mp[symbol] = cost;
		}
		cin >> n_lines;
		cin.ignore();
		ans = 0;
		while(n_lines--){
			getline(cin, line);
			for(int i=0; i<line.size(); i++){
				if(mp[line[i]]) ans += mp[line[i]];
			}
		}
		printf("%d.%02d$\n", ans/100, ans%100);
		mp.clear();
	}

	return 0;
}