/* bfs - AC */
#include <iostream>
#include <map>
#include <queue>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int t, index_city, path[1000];
bool visited[1000];
string src, dest;
map<string, int> mp;
map<int, string> cities;
vector<int> graph[1000];
vector<string> path_created;


void find_path(int curr){
	if(path[curr] != -1){
		find_path(path[curr]);
		path_created.push_back(cities[curr]);
	}
}

bool bfs(int start, int end){
	memset(visited, false, sizeof visited);
	memset(path, -1, sizeof path);

	queue<int> q;
	q.push(start);
	path[start] = 0;

	while(!q.empty()){
		int node = q.front(); q.pop();
		
		visited[node] = true;
		
		for(auto neighbour : graph[node]){
			if(!visited[neighbour]){
				visited[neighbour]=true;
				path[neighbour] = node;
				if(neighbour == end) return true;
				q.push(neighbour);
				
			}
		}
	}
	return false;
}


int main(){
	bool first=false;
	while( cin >> t){
		
		for(int i=0; i<1000; i++) graph[i].clear();
		index_city=1;
		while(t--){
			cin >> src >> dest;
			if(!mp[src]){
				mp[src] = index_city;
				cities[index_city] = src;
				index_city++;
			}
			if(!mp[dest]){
				mp[dest] = index_city;
				cities[index_city] = dest;
				index_city++;
			}
			graph[mp[src]].push_back(mp[dest]);
			graph[mp[dest]].push_back(mp[src]);
		}
	
		
		cin >> src >> dest;
		if(first) cout << endl;
		first = true;
		if(mp[src] and mp[dest] and bfs(mp[src], mp[dest])){	
			find_path(mp[dest]);
			string prev = path_created[0];
			for(int i=1; i<path_created.size(); i++){
				cout << prev << " " << path_created[i] << endl;
				prev = path_created[i];
			}
		}else{
			cout << "No route" << endl;
		}
		mp.clear(); cities.clear(); path_created.clear();
	}
	return 0;
}