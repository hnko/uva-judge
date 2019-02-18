#include <iostream>
#include <cstring>
#include <vector>
#include <limits>
#include <algorithm>
#include<utility>
using namespace std;
#define MAX 51

int arr[MAX], N, S, T, cases, size_solution, dp[55][305];
vector<int> ans;

bool solve(){
	ans.clear();
	pair<int, int> solution[N+1][S+1];
	for(int i = 0; i<=N; i++){
		for (int j=0; j<=S; j++){
			solution[i][j] = make_pair(-1, -1);
			dp[i][j] = INT_MAX;
		}
	}
	dp[0][0] = 0, solution[0][0] = make_pair(-1, -1);
	
	for(int i=1; i<=N; i++){
		for(int j=0; j<=S; j++)
			dp[i][j] = dp[i-1][j], solution[i][j] = solution[i-1][j];
		
		for(int j=arr[i]; j<=S; j++){
			dp[i][j] = min(dp[i][j], min(dp[i][j-arr[i]] + 1, dp[i-1][j-arr[i]] + 1));
			if (dp[i][j] == dp[i-1][j-arr[i]] + 1)
				solution[i][j] = make_pair(i-1, j-arr[i]);
			if (dp[i][j] == dp[i][j-arr[i]] + 1)
				solution[i][j] = make_pair(i, j-arr[i]);
			printf("%d--\n",dp[i][j] );
/*
			if(dp[i][j-arr[i]] + 1 <= dp[i][j]){

				dp[i][j] = dp[i][j-arr[i]] + 1;
				//printf("%d\n",dp[i][j] );
				solution[i][j] = make_pair(i, j-arr[i]);
			}*/
		}
	}

	if(dp[N][S] == INT_MAX) return false;
	int s = S;
	pair<int, int> p = solution[N][S];
	while(p.first != -1){
		ans.push_back(s - p.second);
		s = p.second;
		p = solution[p.first][p.second]; 
	}
	return true;
}

int main(){

	cin >> T;
	cases = 0;
	while(T--){
		cin >> N >> S;
		
		for(int i=1; i<=N; i++) cin >> arr[i];
		printf("Case %d: ", ++cases);
		
		
		if(solve() ){
			int len = ans.size();
			printf("[%d] ", len);
			for(int i=0 ; i<len; i++)
				printf((i != len-1) ? "%d " : "%d\n", ans[i]);

		}else{
			printf("impossible\n");
		}
	}

	return 0;
}