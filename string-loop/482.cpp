/* AC  - use map - data structure */

#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

int t, n, p;
string v;
string perm, val;
map<int, string> mp;

int main(){
	cin >> t;
	cin.ignore(2);
	
	while(t--){
		getline(cin, perm);
		getline(cin, val);
		n = 0;
		stringstream ss, ss2;
		ss << perm;
		ss2 << val;
		while(ss >> p and ss2 >> v){
			n++;
			mp[p] = v;
		}
		for(int i=1; i<=n; i++){
			cout << mp[i] << endl;
		}
		cin.ignore();
		mp.clear();
		if(t)cout << endl;
	}

	return 0;
}