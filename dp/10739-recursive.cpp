/* AC - edit distance recursive */

#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[1001][1001], t, add;
string word;

int edit_distance(int i, int j){
	if(i>j) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	int ans;
	if(word[i] == word[j]) ans = edit_distance(i+1, j-1);
	else{
		ans = min(edit_distance(i+1, j)+1, min(edit_distance(i, j-1)+1, edit_distance(i+1, j-1)+1));
	}
	return dp[i][j] = ans;
	
}

int main(){

	cin >> t;
	for(int i=0; i<t; i++){
		cin >> word;
		memset(dp, -1, sizeof dp);
		printf("Case %d: %d\n", i+1, edit_distance(0, word.size()-1));
	}
	return 0;
}