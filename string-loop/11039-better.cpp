/* AC - go through the vector*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int t, n, aux, ans;
bool last, next_;

bool comp(int a, int b){
	if(a < 0) a *= -1;
	if(b < 0) b *= -1;
	if(a<= b) return true;
	return false;
}

int main(int argc, char const *argv[]){
	
	cin >> t;
	while(t--){
		cin >> n;
		vector< int > arr;
		for(int i=0; i<n; i++){
			cin >> aux;
			arr.push_back(aux);
		}
		if(n > 0){
			sort(arr.begin(), arr.end(), comp);
			last = (arr[0] < 0) ? true : false;
		}
			
		ans = (n > 0) ? 1 : 0;
		for(int i=1; i<n; i++){
			next_ = (arr[i] > 0) ? false : true;
			if(last != next_ ) ans++;
			last = next_;
		}
		cout << ans << endl;

	}

	return 0;
}
