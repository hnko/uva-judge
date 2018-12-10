/* AC - maxmin floyd */ 
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
#define INF 1e5

int nodes, edges, src, dest, weight, tourist, result, t;
double cache[202][202];
int x[202], y[202];

int floyd(){
	for(int k=1; k<=nodes; k++){
		for(int i=1; i<=nodes; i++){
			for(int j=1; j<=nodes; j++){
				cache[i][j] = max(cache[i][j], min(cache[i][k], cache[k][j]));
			}
		}
	}
	return cache[src][dest]-1;
}


int main(int argc, char const *argv[]){
	t = 1;	
	while((cin >> nodes) && (nodes != 0)){

		for(int i=1; i<=nodes; i++){
			for(int j=1; j<=edges; j++){
				cache[i][j] = 1e6;
			}
			cache[i][i] = 0;
		}
		for(int i=1; i<=nodes; i++){
			cin >> x[i] >> y[i];
		}
		for(int i=1; i<=nodes; i++){
			for(int j=1; j<=nodes; j++){
				printf("%lf ", cache[i][j]);
					
			}
			printf("\n");
		}
		for(int i=1; i<=nodes; i++){
			for(int j=1; j<=nodes; j++){
				cache[i][j] = cache[j][i] = sqrt(pow(abs(x[i]-x[j]), 2)+pow(abs(y[i]-y[j]),2));
				printf("%d %d\n", i, j);
					
			}
		}
		for(int i=1; i<=nodes; i++){
			for(int j=1; j<=nodes; j++){
				printf("%lf ", cache[i][j]);
					
			}
			printf("\n");
		}

		for(int k=1; k<=nodes; k++){
			for(int i=1; i<=nodes; i++){
				for(int j=1; j<=nodes; j++){
					cache[i][j] = min(cache[i][j], max(cache[i][k], cache[k][j]));
				}
			}
		}


		cout << "Scenario #" << t++ << endl;
		printf("Frog Distance = %.3f\n\n", cache[1][2]);

	}

	return 0;
}