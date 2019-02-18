/* AC - disjointSet */
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 30010

int r[MAX], s[MAX], p[MAX], T, N, M, A, B, ans;
void init(){
	ans = 1;
	for(int i=1; i<=N; i++){
		r[i] = 0; p[i] = i; s[i] = 1;
	}
}
int find(int i){ return (i == p[i]) ? i : (p[i] = find(p[i]));}
void unionSet(int i, int j){
	int x = find(i), y = find(j);
	if(x != y){
		if(r[x] > r[y]){
			p[y] = x; s[x] += s[y]; ans = max(ans, s[x]);
		}else{
			p[x] = y; s[y] += s[x]; ans = max(ans, s[y]);
			if(r[x] == r[y]) r[y]++;
		}
	}
}

int main(){
	cin >> T;
	while(T--){
		cin >> N >> M;
		init();
		for(int i=0; i<M; i++){
			cin >> A >> B;
			unionSet(A, B);
		}
		cout << ans << endl;
	}

	return 0;
}

