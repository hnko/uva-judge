#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
int t, nodes, src, dest, num_connections, neighbour;
vector<int> graph[100000];
int dist[100000];
bool visited[100000];

int bfs(){
	memset(dist, -1, sizeof dist);
	memset(visited, false, sizeof visited);
	queue<int> q;
	q.push(src);
	dist[src] = 0;
	
	while(!q.empty()){
		int node = q.front(); q.pop();
		if(visited[node]) continue;
		visited[node] = true;
		if(node == dest) return dist[node]-1;
		for(auto neig : graph[node]){
			if(!visited[neig] and dist[neig] == -1){
				dist[neig] = dist[node] + 1;
				q.push(neig);
			}
		}
	}
	return -1;
}

int main(){
	cin >> t;
	while(t--){
		cin >> nodes;
		for( int i=0; i< nodes; i++){
			cin >> src >> num_connections;
			for(int j=0; j<num_connections; j++){
				cin >> neighbour;
				graph[src].push_back(neighbour);
			}
		}
		cin >> src >> dest;
		cout << src << " " << dest << " " << bfs() << endl;
		if(t!=0) cout<<endl;
		for(int i=0; i<nodes; i++) graph[i].clear();

	}
	return 0;
}