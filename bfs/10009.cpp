#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int t, index_c, edges, consults, visited[30], path[30];
string src, dest;
vector<int> graph[30];
vector<string> result;
map<string, int> mp;
map<int, string> cities;

void find_path(int i){
	if(path[i] != -1 ){
		find_path(path[i]);
		result.push_back(cities[i]);
	}
}

void bfs(){
	queue<int> q;
	q.push(mp[src]);
	path[mp[src]] = 0;
	while(!q.empty()){
		int node = q.front(); q.pop();
		if (cities[node] == dest) return;
		if(visited[node]) continue;
		visited[node] = true;
		for(auto neighbour : graph[node]){
			if(!visited[neighbour]){
				path[neighbour] = node;
				q.push(neighbour);
			}
		}
	}
}


int main(){
	cin >> t;
	while(t--){
		index_c=1;
		cin >> edges >> consults;
		for(int i=0; i<edges; i++){
			cin >> src >> dest;
			if(!mp[src]){
				mp[src] = index_c;
				cities[index_c] = src;
				index_c++;
			}
			if(!mp[dest]){
				mp[dest] = index_c;
				cities[index_c] = dest;
				index_c++;
			} 
			graph[mp[src]].push_back(mp[dest]);
			graph[mp[dest]].push_back(mp[src]);

		}

		for(int i=0; i<consults; i++){
			memset(visited, false, sizeof visited);
			memset(path, -1, sizeof path);
			result.clear();
			cin >> src >> dest;
			
			bfs();
			find_path(mp[dest]);
			
			for(auto city : result) cout << city[0];
			cout << endl;
		}
		if(t!=0)cout << endl;
		mp.clear(); cities.clear();
		for(int i=0; i<30; i++)graph[i].clear();
	}
	return 0;
}