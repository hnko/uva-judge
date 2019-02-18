/* AC - dp palindrome recursive print solution */
#include <iostream>
#include <string>
#include <cstring>

using namespace std;
string word;
int dp[1001][1001];

int palindrome(int i, int j){
	if (i > j) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	if (word[i] == word[j]) return dp[i][j] = palindrome(i+1, j-1);
	return dp[i][j] = min(palindrome(i+1, j)+1, palindrome(i, j-1)+1);
}

void print_solution(int i, int j){
	if(i > j) return;
	if(i == j){
		printf("%c", word[i]);
		return;
	}
	if( word[i] == word[j]){
		printf("%c", word[i]);
		print_solution(i+1, j-1);
		printf("%c", word[j]);
	}else if(dp[i][j-1] < dp[i+1][j]){
		printf("%c", word[j]);
		print_solution(i, j-1);
		printf("%c", word[j]);
	}else{
		printf("%c", word[i]);
		print_solution(i+1, j);
		printf("%c", word[i]);
	}
}

int main(){

	while(getline(cin, word)){
		memset(dp, -1, sizeof dp);
		printf("%d ", palindrome(0, word.size()-1));
		print_solution(0, word.size()-1);
		cout << endl;
	}
	return 0;
}