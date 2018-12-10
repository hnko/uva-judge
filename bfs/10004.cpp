#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[200];
int color[200];
int isbipartite(){
	queue<int> q;
	color[0] = 1;
	q.push(0);
	while(!q.empty()){
		int node = q.front(); q.pop();
		for(auto neighbour : adj[node]){
			if(color[neighbour] == -1){
				color[neighbour] = 1 - color[node];
				q.push(neighbour);
			}else if(color[neighbour] == color[node]){
				return false;
			}
		}
	}
	return true;
}

int main(int argc, char const *argv[]){
	int nodes, edges, src, dest;
	while(true){
		cin >> nodes; if(nodes == 0) return 0;
		cin >> edges;
		for(int i=0; i<edges; i++){
			cin >> src >> dest;
			adj[src].push_back(dest);
			adj[dest].push_back(src);
		}
		for(int i=0; i<nodes; i++) color[i]=-1;

		(isbipartite()) ? cout << "BICOLORABLE.\n" : cout << "NOT BICOLORABLE.\n";
		for(int i=0; i<nodes; i++) adj[i].clear();	
	}

	return 0;
}