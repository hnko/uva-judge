/* prim - AC */
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;
typedef pair<int, int> ii;
vector<pair<int, int> > graph[10001];
bool visited[10001];
int T, CA, N, M, A, mst, weight, src, dest, t;

int prim(int src){
	mst = CA; /* mst gasto interno de nodos conectados*/
	A++;
	priority_queue<ii, vector<ii>, greater<ii> > q;
	q.push(make_pair(0, src));
	while(!q.empty()){
		ii node = q.top(); q.pop();
		if(visited[node.second]) continue;
		visited[node.second] = true;

		if (node.first >= CA){ A++; mst += CA;}
		else mst += node.first;

		for(auto neighbour : graph[node.second]){
			if (!visited[neighbour.second]){				
				q.push(neighbour);
			}
		}
	}
	return mst;
}

void solution(){
	T = 0; /* total gastado */
	A = 0; /* aeropuertos por construir */
	memset(visited, false, sizeof visited);
	for(int i=1; i<=N; i++){
		if(!visited[i]){
			T += prim(i);
		}
	}
}

int main(){
	cin >> t;

	for(int cases=0; cases<t; cases++){
		cin >> N >> M >> CA;
		for(int i=0; i<M; i++){
			cin >> src >> dest >> weight;
			graph[src].push_back(make_pair(weight, dest));
			graph[dest].push_back(make_pair(weight, src));
		}

		solution();
		printf("Case #%d: %d %d\n", cases+1, T, A);
		for(int i=1; i<=N; i++) graph[i].clear();
	}

	return 0;
}