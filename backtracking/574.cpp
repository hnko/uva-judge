/* AC - backtracking */
#include <iostream>
#include <vector>
#include <map>

using namespace std;
int N, L, aux;
vector <int> numbers;
map <vector<int>, bool> mp;

void solve(int curr, int curr_sum, vector<int> arr){
	if(curr_sum > N) return;
	if(curr_sum == N){
		if(mp[arr]) return;
		mp[arr] = true;
		for(int i=0; i<arr.size(); i++){
			printf((i == arr.size()-1) ? "%d" : "%d+", arr[i]);
		}
		printf("\n");
	}

	for(int i=curr; i<L; i++){
		arr.push_back(numbers[i]);
		solve(i+1, curr_sum+numbers[i], arr);
		arr.pop_back();
	}
}

int main(){
	while((cin >> N >> L) and ( N and L)){
		for (int i=0; i<L; i++){
			cin >> aux;
			numbers.push_back(aux);
		}
		printf("Sums of %d:\n", N);
		vector <int> arr;
		solve(0, 0, arr);
		if (mp.size() == 0) printf("NONE\n");
		numbers.clear();
		mp.clear();
	}

	return 0;
}