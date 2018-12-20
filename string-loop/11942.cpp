/* AC - use is_sorted (C11) */
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;
string line;
vector<int > arr;
int aux, t;

bool cmp_r(int a, int b){return a>=b;}
bool cmp(int a, int b){return a<=b;}

int main(){
	cin >> t;
	cin.ignore();
	printf("Lumberjacks:\n");
	while(t--){
		getline(cin, line);
		
		stringstream ss;
		ss << line;
		while(ss >> aux) arr.push_back(aux);
		
		printf( (is_sorted(arr.begin(), arr.end(), cmp) or is_sorted(arr.begin(), arr.end(), cmp_r)) ?
		 "Ordered\n": "Unordered\n");
		arr.clear();
	}

	return 0;
}