#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;


int nodes, edges, src, dest, weight, tourist, result, t;
int cache[150][150];

int floyd(){
	for(int k=1; k<=nodes; k++){
		for(int i=1; i<=nodes; i++){
			for(int j=1; j<=nodes; j++){
				cache[i][j] = cache[j][i] = max(cache[i][j], min(cache[i][k], cache[k][j]));
			}
		}
	}
	return cache[src][dest]-1;
}


int main(int argc, char const *argv[]){
	t = 1;	
	while((cin >> nodes >> edges) && (nodes != 0)){

		for(int i=1; i<=nodes; i++){
			for(int j=1; j<=edges; j++){
				cache[i][j] = 0;
			}
		}

		for(int i=0; i<edges; i++){
			cin >> src >> dest >> weight;
			cache[src][dest] = weight;
			cache[dest][src] = weight;
		}
		cin >> src >> dest >> tourist;

		cout << "Scenario #" << t++ << endl;
		int out = floyd(); 
		out = (out != 0) ? ceil((tourist*1.0)/out) : 0;
		cout << "Minimum Number of Trips = " << out << endl << endl;

	}

	return 0;
}