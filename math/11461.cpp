/* AC - use sqrt - avoid python-> TLE */
#include <iostream>
#include <cmath>

using namespace std;

int arr[100001], a, b, cnt;

int main(){
	while(cin >> a >> b and a and b){
		cnt = 0;
		for(int i=a; i<=b; i++){
			if(((int)sqrt(i) * (int)sqrt(i)) == i) cnt++;
		}
		cout << cnt << endl;
	}

	return 0;
}