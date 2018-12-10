#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[52][52], len, n;
int cuts[51];

int cut(int L, int R){
	if(L+1 >= R) return 0;
	if(dp[L][R] != -1) return dp[L][R];
	int ans = 1e6;
	for(int i=L+1; i<R; i++){
		ans = min(ans, (cut(L, i) + cut(i, R))+cuts[R] - cuts[L]);
	}
	return dp[L][R] = ans;
}

int main(){

	while((cin >> len) && len != 0){
		cin >> n;
		for(int i =1; i<=n; i++){
			cin >> cuts[i];
		}
		cuts[0] = 0; cuts[n+1] = len;
		memset(dp, -1, sizeof dp);
		cout << "The minimum cutting is " << cut(0, n+1) << "."<< endl;
	}
	return 0;
}