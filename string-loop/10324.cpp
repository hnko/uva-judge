/* AC - loop through string */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int a, b, min_i, max_j, num_queries;
char previous;
bool ok;
string line;

int main(){

	int cases = 0;
	while(getline(cin, line) and !line.empty()){
		cin >> num_queries;
		
		
		printf("Case %d:\n", ++cases);
		for(int i=0; i<num_queries; i++){
			cin >> a >> b;
			min_i = min(a, b);
			max_j = max(a, b);
			ok = true;
			previous = line[min_i];
			for(int j = min_i+1; j<=max_j; j++){
				if(line[j] != previous){
					ok = false;
					break;
				}
			}
			printf((ok)? "Yes\n" : "No\n");
			cin.ignore();

		}
		
	}
}