/* AC - multiply */
#include <iostream>

using namespace std;

long long  t, n, a, b, c, ans;

int main(){
	cin >> t;
	while(t--){
		cin >> n;
		ans = 0;
		for(int i=0; i<n; i++){
			cin >> a >> b >> c;
			ans += a*c;
		}
		cout << ans << endl;
	}

	return 0;
}