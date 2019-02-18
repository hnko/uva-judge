/* AC - Fenwick */
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;
#define MAX 200002

int arr[MAX], tree[MAX], N, a, b, cases;
string option, line;

int LSB(int i){	return i&(-i);}

void init(){for(int i=1; i<=N; i++) arr[i] = tree[i] = 0;}

void adjust(int i, int value){
	while (i <= N){
		tree[i] += value;
		i = i + LSB(i);
	}
}
int sum_query(int i){
	if ( i == 0) return 0;
	
	int total = 0;
	while(i != 0){
		total += tree[i];
		i = i - LSB(i);
	}
	return total;
}

int query(int i, int j){
	return sum_query(j) - sum_query(i-1);
}


int main(){
	cases = 0;
	while(cin >> N and N){
		if (cases) cout << endl;
		printf("Case %d:\n", ++cases);
		init();
		for(int i=1; i<=N; i++){
			cin >> arr[i]; 
			adjust(i, arr[i]);
		}
		cin.ignore();

		while(getline(cin, line) and line != "END"){
			stringstream ss;
			ss << line;
			ss >> option;
			if(option == "M"){
				ss >> a >> b;
				printf("%d\n", query(a, b));
			}else{
				ss >> a >> b;
				adjust(a, b - arr[a]);
				arr[a] = b;
			}
		}
	}

	return 0;
}