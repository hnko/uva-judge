/* AC - median */
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 50001

int r[MAX], c[MAX], N, T, row, column, x, y;

void solve(){
	sort(r, r+N); sort(c, c+N);
	if(N & 1){
		x = r[N/2];
		y = c[N/2];
	}else{
		x = r[(N-1)/2];
		y = c[(N-1)/2];
	}
}

int main(){
	cin >> T;
	while(T--){
		cin >> row >> column >> N;
		for(int i=0; i<N; i++){
			cin >> r[i] >> c[i];
		}
		x = y = 0;
		solve();
		printf("(Street: %d, Avenue: %d)\n", x, y);
	}

	return 0;
}