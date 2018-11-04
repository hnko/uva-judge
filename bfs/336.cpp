/* bfs - AC */
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
using namespace std;

int edges, src, dest, cnt, level, node, nodes, size_q, dist[35];
bool visited[35];
vector<int> graph[35];
map<int, int> mp;

void bfs(){
	memset(visited, false, sizeof visited); 
	memset(dist, -1, sizeof dist);

	queue<int> q;
	q.push(mp[src]);
	dist[mp[src]] = 0;
	visited[mp[src]] = true;

	while(!q.empty()){
		node = q.front(); q.pop();
		for(auto neighbour : graph[node]){
			if(!visited[neighbour]){
				visited[neighbour] = true;
				q.push(neighbour);
				dist[neighbour] = dist[node] + 1;
			}
		}	
	}
}

int main(){
	int cases=1;
	while((cin >> edges) and edges!=0){
		int index = 1;
		for(int i=0; i<edges; i++){
			cin >> src >> dest;
			if(!mp[src])  mp[src] = index++;
			if(!mp[dest]) mp[dest] = index++;

			graph[mp[src]].push_back(mp[dest]);
			graph[mp[dest]].push_back(mp[src]);
			
		}

		while((cin >> src >> level) and (src != 0 and dest != 0)){
			bfs();
			cnt = 0;
			for(int i=1; i<index; i++){
				if(dist[i] == -1 || dist[i] > level) cnt++;
			}
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", cases++, cnt, src, level);
		}
		for(int i=0; i<index; i++)graph[i].clear();
		mp.clear();

	}
	return 0;
}