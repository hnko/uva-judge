/* AC - introduction - avoid recursive approach */
#include <iostream>
#include <algorithm>

using namespace std;

int cnt, start, finish, s, f;

int solve(int n){
	cnt++;
	while(n!=1){
		if(n&1) n = (3*n) + 1;
		else n /=2;
		cnt++;
	}
	return cnt;
}

int main(int argc, char const *argv[]){
	
	while(cin >> start >> finish){
		int max_ = 0;
		s = min(start, finish);
		f = max(start, finish);
		for(int i=s; i<=f; i++){
			cnt = 0; solve(i);
			max_ = max(max_, cnt);
		}
		printf("%d %d %d\n", start, finish, max_);
	}
	return 0;
}