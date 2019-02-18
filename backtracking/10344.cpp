/* AC - permutation - complete search - backtracking */

#include <iostream>
#include <algorithm>
#include<string>

using namespace std;
int n[5];
bool possible;

bool solve(int curr, int i){
	if(i == 5) return curr == 23;
	return solve(curr+n[i], i+1) or solve(curr-n[i], i+1) or solve(curr*n[i], i+1);
}

int main(){
	while((cin >> n[0] >> n[1] >> n[2] >> n[3] >> n[4]) and (n[0] or n[1] or n[2] or n[3] or n[4])){
		sort(n, n+5); /* sort for get all the possible permutations */
		possible = false;
		do{
			if (solve(n[0], 1)){
				possible = true;
				break;
			}
		}while (next_permutation(n, n+5));
		printf((possible) ? "Possible\n" : "Impossible\n");
	}
}