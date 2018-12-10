#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[101][50100];
int coins[101];

int solve(int i, int n, int sum, int limit){
	if(i == n) return sum;
	if (dp[i][sum] != -1) return dp[i][sum];

	int r1, r2;
	r1 = r2 = 0;
	if(sum + coins[i] <= limit){
		r1 = solve(i+1, n, sum+coins[i], limit);
	}
	if(sum <= limit){
	 	r2 = solve(i+1, n, sum, limit);
	}
	return dp[i][sum] = max(r1, r2);
	//return max(r1, r2);
}


int main(int argc, char const *argv[]){
	
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		int total=0;
		for(int i=0; i<n; i++){
			cin >> coins[i];
			total += coins[i];
		}
		memset(dp, -1, sizeof dp);
		//cout << solve(0, n, 0, (total+1)/2) << endl;
		int res = solve(0, n, 0, (total+1)/2);
		cout << abs(total - res*2) << endl;

	}
	return 0;
}

/*
    for (int coin = 1; coin <= n; coin++)
      for (int amount = 0; amount <= target; amount++)
        if (coins[coin] <= amount)
          dp[amount][coin] = max(dp[amount][coin-1], coins[coin] + dp[amount-coins[coin]][coin-1]);
        else
          dp[amount][coin] = dp[amount][coin-1];
*/
