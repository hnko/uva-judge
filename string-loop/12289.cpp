/* AC  - iterate through array */
#include <iostream>
#include <string>

using namespace std;
string word;
int t;
int matches_one, matches_two;
char one[] = {'o', 'n', 'e'};
char two[] = {'t', 'w', 'o'};
int main(){
	cin >> t;
	while(t--){
		cin >> word;
		matches_one = matches_two = 0;
		if(word.size() > 3) cout << 3 << endl;
		else{
			for(int i=0; i<3; i++){
				if(one[i] ==word[i]) matches_one++;
				if(two[i] ==word[i]) matches_two++;
			}
			printf((matches_one > matches_two) ? "1\n" : "2\n");
		}
	}
}