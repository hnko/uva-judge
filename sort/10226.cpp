#include <iostream>
#include <map>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>


using namespace std;
vector <string > trees;
map <string, int > mp;
string line;
int t, cnt;

int main(){
	cin >> t;
	cin.ignore(2);

	while(t--){
		cnt=0;
		while(getline(cin, line) and !line.empty()){
			cnt++;
			
			if(!mp[line]){
				trees.push_back(line);
				mp[line] = 1;
			}else{
				mp[line]++;
			}
		}
		
		sort(trees.begin(), trees.end());
		for(auto tree : trees){

			cout << tree <<  " ";
			printf("%0.4lf\n", (mp[tree]*1.0)/(cnt)*100);
		}
		if(t) cout << endl;
		mp.clear(); trees.clear();
	}

	return 0;
}