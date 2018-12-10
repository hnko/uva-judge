from math import ceil
import sys

dp = [[0 for column in range(106)] for row in range(106)]
t = 1
while True:	
	try:
		nodes, edges = [int(i) for i in sys.stdin.readline().split()]
	except:
		break
	
	if nodes == 0 and edges == 0: break
		
	for i in range(1, nodes+1):
		for j in range(1, nodes+1):
			dp[i][j] = -1e6
		dp[i][i] = 0

	for _ in range(edges):
		src, dest, weight = [int(i) for i in sys.stdin.readline().split()]
		dp[src][dest] = dp[dest][src] = weight

	src, dest, weight = [int(i) for i in sys.stdin.readline().split()]

	for k in range(1, nodes+1):
		for i in range(1, nodes+1):
			for j in range(1, nodes+1):
				dp[i][j] = dp[j][i] = max(dp[i][j], min(dp[i][k], dp[k][j]))

	result = ceil(weight/(dp[src][dest]-1))
	print('Scenario #%d' % t)
	print('Minimum Number of Trips = %d\n' % result)
	t += 1
"""
#include <iostream>
#include <algorithm>
#include<cmath>
using namespace std;
int src, dest, weight, nodes, edges;
int dp[105][105];

int main(){
  int t=1;
  while(cin>>nodes >> edges){
    if(nodes == 0 and edges == 0) return 0;
    for(int i=1; i<=nodes; i++){
      for(int j=1; j<=nodes; j++){
        dp[i][j] = -1e6;
      }
      dp[i][i] = 0;
    }
    for(int i =0; i<edges; i++){
      cin >>src >>dest >>weight;
      dp[src][dest] = dp[dest][src] = weight;
    }
    cin >> src >> dest >> weight;
    for(int k=1; k<=nodes; k++){
      for(int i=1; i<=nodes; i++){
        for(int j=1; j<=nodes; j++){
          dp[i][j] = dp[j][i] = max(dp[i][j], min(dp[i][k], dp[k][j]));
        }
      }
    }
    int result = ceil(((double)weight*1.0) / (dp[src][dest]-1));
    printf("Scenario #%d\n", t++);
    printf("Minimum Number of Trips = %d\n\n", result);


  }

  return 0;
}

"""