/* AC - backtracking */
#include <iostream>
#include <vector>

using namespace std;
vector <int> numbers, best_paht;
int N, L, aux, total;

void solve(vector<int> path, int curr, int curr_sum){
	
	if ((curr_sum > total) or (curr_sum == total and path.size() > best_paht.size()) ){
		total = curr_sum; 
		best_paht = path;
	}
	if(curr == L) return;

	for(int i=curr; i<L; i++){
		if(curr_sum  + numbers[i] <= N){
			path.push_back(numbers[i]);
			solve(path, i+1, curr_sum  + numbers[i]);
			path.pop_back();

		}
	}
}
int main(){

	while(cin >> N){
		cin >> L;
		for(int i=0; i<L; i++){
			cin >> aux;
			numbers.push_back(aux);
		}
		total = 0;
		vector<int> path;
		solve(path, 0, 0);
		
		
		for(auto n : best_paht)	printf("%d ", n);
		printf("sum:%d\n", total);

		best_paht.clear();
		numbers.clear();
	}

	return 0;
}