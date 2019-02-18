/* AC -disjointSet - size of the set where it belong */
#include <iostream>
#include<string>

using namespace std;

#define MAX 100001

int a, b, idx, N, Q, r[MAX], ds[MAX], sz[MAX];
string aux;
void init(int N){
	for(int i=1; i<=N; i++){
		ds[i] = i; r[i] = 0; sz[i] = 1;
	}
}
int find(int i){return (ds[i] == i) ? i : (ds[i] = find(ds[i]));}

void unionSet(int i, int j){
	int x = find(i), y = find(j);
	if( x !=  y ){
		if(r[x] > r[y]){
			ds[y] = i;
			sz[x] += sz[y];
		}else{
			ds[x] = j;
			sz[y] += sz[x];
			if(r[x] == r[y]) r[y]++;
		}
	}
}
int main(){
	cin >> N >> Q;
	init(N);
	while(Q--){
		cin >> aux;
		if(aux == "Q"){
			cin >> idx;
			cout << sz[find(idx)] << endl;
		}
		else{
			cin >> a >> b;
			unionSet(a, b);
		}
	}
	return 0;
}

