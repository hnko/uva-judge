/* bfs - AC */
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#include <vector>

using namespace std;

int t, num_word;
string word, src, dest, line;
map<string, int> mp;
vector<int> graph[210];
vector<string> words;
int dist[210];
bool visited[210];

int bfs(int src, int dest){
	memset(dist, -1, sizeof dist);
	memset(visited, false, sizeof visited);
	queue<int> q;
	q.push(src);
	dist[src] = 0;

	while(!q.empty()){
		int node = q.front(); q.pop();
		if(visited[node]) continue;
		visited[node] = true;
		if(node == dest) return dist[node];
		for(auto neighbour : graph[node]){
			if(!visited[neighbour] and dist[neighbour] == -1){
				dist[neighbour] = dist[node] + 1;
				q.push(neighbour);
			}
		}
	}
	return -1;
}

bool are_connected(string a, string b){
	int diff = 0;
	if(a.length() != b.length()) return false;
	for(int i=0; i<a.length(); i++){
		if(a[i] != b[i]) diff++;
	}
	return (diff == 1) ? true : false;
}

int main(){
	cin >> t;
	while(t--){
		mp.clear();
		words.clear();
		num_word = 1;
		while(cin >> word and word != "*"){
			mp[word] = num_word++;
			words.push_back(word);
		}
		/* check if are connected */
		for(int i=0; i<num_word; i++){
			for(int j=i+1; j<num_word; j++){
				if(are_connected(words[i], words[j])){
					graph[mp[words[i]]].push_back(mp[words[j]]);
					graph[mp[words[j]]].push_back(mp[words[i]]);
				}
			}
		}

		cin.ignore();
		while(getline(cin, line) and line != ""){
			
			int space = line.find(" ");
			src = line.substr(0, space);
			dest = line.substr(space+1);
			cout << src << " " << dest << " " << bfs(mp[src], mp[dest]) << endl;
		}
		if(t!=0)cout << endl;
		line.clear(); src.clear(); dest.clear();
		for(int i= 1; i<num_word; i++) graph[i].clear();
	}
	
	return 0;
}