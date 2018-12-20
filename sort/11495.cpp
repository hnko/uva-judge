/* AC - graph for count min swap to order an array */
#include <iostream>
#include <utility>
#include <algorithm>
#include <cstring>


using namespace std;
int n, ans, cycle, j;
int arr[100001];
bool visited[100001], marcelo;
pair<int, int> aux[100001];

void solve(){
	for(int i=0; i<n; i++){
		aux[i].first = arr[i];
		aux[i].second = i;
	}
	sort(aux, aux+n);
	memset(visited, false, sizeof visited);
	ans = 0;

	for(int i=0; i<n; i++){
		if(visited[i] or aux[i].second == i) continue;
		cycle = 0;
		j = aux[i].second;
		while(!visited[j]){
			visited[j] = true;
			cycle++;
			j = aux[j].second;
		}
		if(cycle > 0) ans += cycle-1;
	}
	marcelo = (ans&1) ? true : false;
}

int main(){
	while(cin >> n and n){
		for(int i=0; i<n; i++){
			cin >> arr[i];
		}
		solve();
		printf((marcelo) ? "Marcelo\n" : "Carlos\n");
	}	


}