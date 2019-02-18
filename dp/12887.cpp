/* AC - catalan number */
#include <iostream>
using namespace std;

#define MAX 5000
int n, T;
long long int mod = 1000000007LL, arr[MAX+1];

void catalan(){
	arr[0] = arr[1] = 1;
	for(int i=2; i<=MAX; i++){
		arr[i] = 0;
		for(int j=0; j<i; j++){
			if((arr[i] += arr[j] * arr[i-j-1]) >= mod)
				arr[i] %= mod;
		}
	}
}



int main(){
	catalan();
	cin >> T;
	while (T--){
		cin >> n;
		cout << arr[n]<< endl;
	}

	return 0;
}