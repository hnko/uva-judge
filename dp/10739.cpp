/* AC - edit distance iterative */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int dp[1001][1001], t, add;
string word, reversed;

int edit_distance(){
	reversed = "";
	for(int i=word.size()-1; i>=0; i--) reversed += word[i];
		
	for(int i=0; i<=word.size(); i++){
		for(int j=0; j<=word.size(); j++){
			if (i == 0) dp[i][j] = j;
			else if ( j == 0) dp[i][j] = i;
			else{
				add = (word[i-1] == reversed[j-1]) ? 0 : 1;
				dp[i][j] = min(dp[i][j-1] +1,
								min(dp[i-1][j] +1, dp[i-1][j-1]+add)
								);
			}
		}
	}
	return dp[word.size()][word.size()];
}

int main(){

	cin >> t;
	for(int i=0; i<t; i++){
		cin >> word;

		printf("Case %d: %d\n", i+1, edit_distance()/2);
	}
	return 0;
}