/* AC - backtracking */
#include <iostream>

using namespace std;
 
 int ans[9], M[5][5]={
 	{0,1,1,0,1},
 	{1,0,1,0,1},
 	{1,1,0,1,1},
 	{0,0,1,0,1},
 	{1,1,1,1,0}};
 
void  dfs(int idx, int curr){
	ans[idx] = curr;
	
	if(idx == 8){
		for(int i=0; i<9; i++)printf("%d", ans[i]+1);
		printf("\n");
		
		return;
	}
	for(int i=0; i<5; i++){
		if(M[curr][i]){
			M[curr][i] = M[i][curr] = 0;
			dfs(idx+1,i);
			M[curr][i] = M[i][curr] = 1;
		}
	}
}

 int main()
 
 {
 	dfs(0,0);
 	return 0;
 }