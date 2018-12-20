/* AC - find subsequence */
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string s1, s2;
int i, index_;

bool solve(){
	for(i=0, index_=0; i<s2.size() and index_ < s1.size(); i++){
		if(s1[index_] == s2[i]) index_++;
	}
	return (index_ == s1.size()) ? true : false;
}

int main(){
	while(cin >> s1 >> s2){
		printf((solve()) ? "Yes\n" : "No\n");
	}

	return 0;
}