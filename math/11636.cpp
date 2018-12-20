/* AC - use logarithm */
#include <iostream>
#include <cmath>
using namespace std;
int cases, n;
/* approach to get to the optimal solution - other way, just think for a minute....

int dp[10001][2500];

int solve(int lines, int ans){
	if (lines == n) return ans;
	else if (lines > n) return 1e6;
	else{
		if( dp[lines][ans] != -1) return dp[lines][ans];
		aux = 1e6;
		for(int i=1; i<=lines; i++){
			aux = min(solve(lines+i, ans+1), aux);
		}
		return dp[lines][ans] = aux;
	}
	
}
*/

int main(){
	cases = 0;
	
	while(cin >> n and n > 0){
		printf("Case %d: %d\n", ++cases, (int)ceil(log(n)/log(2)));
	}

	return 0;
}