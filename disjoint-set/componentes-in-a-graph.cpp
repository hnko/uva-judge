/* AC - disjointSet*/
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 30010
int N, G, B, dt[MAX], sz[MAX], r[MAX], min_, max_;

void init(int N){
	for(int i=1; i<=2*N; i++){
		dt[i] = i;
		sz[i] = 1;
		r[i] = 0;
	} 
}

int find(int i){ return (dt[i] == i) ? i : (dt[i] = find(dt[i]));}

void unionSet(int i, int j){
	int x = find(i), y = find(j);
	if(x != y){
		if(r[x] > r[y]){
			dt[y] = x;
			sz[x] += sz[y];
		}else{
			dt[x] = y;
			sz[y] += sz[x];
			if(r[x] == r[y])r[y]++;
		}
	}
}


int main(){
	cin >> N;
	init(N);
	
	for(int i=0; i<N; i++){
		cin >> G >> B;
		unionSet(G, B);
	}
	min_ = 2*N; max_ = 0;
	for(int i=1; i<=2*N; i++){
		if(dt[i] == i and sz[i] > 1){ /* find just the roots */
			min_ = min(min_, sz[i]);
			max_ = max(max_, sz[i]);
		}
	}
	cout << min_ << " " << max_ << endl;
	return 0;
}