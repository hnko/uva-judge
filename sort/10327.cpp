/* AC - count inversions (Buble sort is accepted) */
#include <iostream>

using namespace std;

int arr[1001], ans, n;

int main(){

	while(cin >> n){
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		ans = 0;
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				if(arr[i] > arr[j]) ans++;
			}
		}
		printf("Minimum exchange operations : %d\n", ans);
	}
	return 0;
}

