#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

string src, dest;
int nodes, edges, weight, dp[202][202], t;


void floyd(){
	for(int k=1; k<=nodes; k++){
		for(int i=1; i<=nodes; i++){
			for(int j=1; j<=nodes; j++){
				dp[i][j]= max(dp[i][j], min(dp[i][k], dp[k][j]));
			}
		}
	}
}

int main(int argc, char const *argv[]){
	t=1;
	while((cin >> nodes >> edges) and nodes ){
		map<string, int> cities;
		int index = 1;

		for(int i=1; i<=nodes; i++){
			for(int j=1; j<=nodes; j++){
				dp[i][j] = -1e5;
			}
			dp[i][i]=0;
		}

		for(int i=0; i<edges; i++){
			cin >> src >> dest >> weight;
			if(!cities[src]) cities[src] = index++;
			if(!cities[dest]) cities[dest] = index++;

			dp[cities[src]][cities[dest]] = weight;
			dp[cities[dest]][cities[src]] = weight;
		}



		cin >> src >> dest;
		floyd();


		cout << "Scenario #" << t++ << endl;
		cout << dp[cities[src]][cities[dest]] << " tons" << endl << endl;
	}

	return 0;
}