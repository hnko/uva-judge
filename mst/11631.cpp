#include <iostream>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define N 200002

typedef pair<long long, long long> pii; vector<pii> graph[N+1];
bool marked[N+1]; /* all to false */

int sum_min_spanning_tree(int src){
	priority_queue<pii, vector<pii>, greater<pii> > q;
	q.push(make_pair(0, src));
	int min_cost = 0;

	while(!q.empty()){
		pii node = q.top(); q.pop();
		int id = node.second;
		if(marked[id] == true) continue;
		min_cost += node.first;
		marked[id] = true;
		for(auto &neighbour : graph[id]){
			if(marked[neighbour.second] == false){
				q.push(neighbour);
			}
		}
	}
/* check if all the nodes have been founded*/
	// for(int i=0; i<=n; i++) if not marked[i] return false
	return min_cost;
}
int main(int argc, char const *argv[]){
	long long edges, nodes, src, dest, weight, total;
	int start;
	while(cin >> nodes >> edges){
		if (nodes == 0 and edges == 0) return 0;
		total = 0;
		for(int i=0; i< edges; i++){
			cin >> src >> dest >> weight;
			if(i==0) start = src;
			total += weight;
			graph[src].push_back(make_pair(weight, dest));
			graph[dest].push_back(make_pair(weight, src));
		}
		memset(marked, false, sizeof marked);
		cout << total - sum_min_spanning_tree(start) << endl;
		for(int i=0; i<nodes; i++)graph[i].clear();
	}
	return 0;
}
