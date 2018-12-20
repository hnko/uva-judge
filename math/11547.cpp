/* AC - avoid python round in the final division */
#include <iostream>
#include <algorithm>
using namespace std;

int solve(int a){
	a *= 567;
	a /=9;
    a +=7492;
    a *=235;
    a /=47;
    a -= 498;
    a /= 10;
    
    return abs(a%10);
}

int n, t;

int main(){
	cin >> t;
	while(t--){
		cin >> n;
		cout << solve(n) << endl;
	}
	
	return 0;
}