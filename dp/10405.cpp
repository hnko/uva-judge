/* AC - dp lcs */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s1, s2;
int arr[1001][1001];

int lcs(){
	int n1, n2;
	n1 = s1.size();
	n2 = s2.size();
	for(int i=0; i<=n1; i++){
		for(int j=0; j<=n2; j++){
			if(i==0 or j==0) arr[i][j] = 0;
			else if(s1[i-1] == s2[j-1]) arr[i][j] = 1 + arr[i-1][j-1];
			else arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
		}
	}
	return arr[n1][n2];
}


int main(int argc, char const *argv[]){
	
	while(getline(cin, s1)){
		getline(cin, s2);

		cout << lcs() << endl;
	}


	return 0;
}